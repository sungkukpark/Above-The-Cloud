#include "DXUT.h"
#include "../Engine/Transform.h"
#include "../Engine/StaticMesh.h"
#include "../Engine/Shader.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Collider.h"
#include "../Engine/CollisionManager.h"
#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(void) :
	direction(0,0,0)
{
	// NEED TRAIL

	transform = new Engine::Transform();
	transform->scale = { 1.7,1.7,1.7 };
	componentgroup.emplace(L"Transform", transform);
	mesh = dynamic_cast<Engine::StaticMesh*>(Engine::ResourceManager::GetInstance()->LoadResource(L"MonsterBullet"));
	componentgroup.emplace(L"StaticMesh", mesh);
	shader = dynamic_cast<Engine::Shader*>(Engine::ResourceManager::GetInstance()->LoadResource(L"dyshader"));
	componentgroup.emplace(L"Shader", shader);
	collider = new Engine::Collider(1.1f, &transform->position);
	colliderdata.center = &transform->position;
	colliderdata.radius = 1.1f;
	colliderdata.tag = L"MonsterBullet";

	transform->position = { 99999,99999,99999 };

	componentgroup.emplace(L"collider", collider);

	transform->scale = { 0.05f, 0.05f, 0.05f };

	memcpy(&transform->worldMatrix._41, transform->position, sizeof(D3DXVECTOR3));
}

MonsterBullet::~MonsterBullet(void)
{
}

void MonsterBullet::SetInformation(const D3DXVECTOR3& _position, const D3DXVECTOR3& _direction)
{
	transform->position = _position;
	direction = _direction;
	alivetime = 3.f;
	Engine::CollisionManager::GetInstance()->PushData(MONSTERMISSILE, this);
}

void MonsterBullet::CollisionEvent(const wstring& _objectTag, GameObject* _gameObject)
{
	if (_objectTag == L"player")
	{
		transform->position = { 99999,99999,99999 };
		isActive = false;
	}
}

INT MonsterBullet::Update(const FLOAT& dt)
{
	transform->position += direction * 500 * dt;
	if (alivetime <= 0)
		isActive = false;
	else
		alivetime -= dt;
	GameObject::Update(dt);
	return OBJALIVE;
}

void MonsterBullet::LateUpdate(const FLOAT& dt)
{
	GameObject::LateUpdate(dt);
}

void MonsterBullet::Render(const FLOAT& dt)
{
	if (isActive == false)
		return;
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	shader->SetupTable(transform->worldMatrix);
	UINT pass = 0;
	LPD3DXEFFECT tempeffect = shader->GetEffect();
	tempeffect->Begin(&pass, 0);
	tempeffect->BeginPass(0);
	mesh->RenderMesh(tempeffect);
	tempeffect->EndPass();
	tempeffect->End();
	//collider->RenderCollider();

	GameObject::Render(dt);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

void MonsterBullet::Free(void)
{
	GameObject::Free();
}
