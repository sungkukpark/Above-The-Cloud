#include "DXUT.h"
#include "../Engine/Transform.h"
#include "../Engine/StaticMesh.h"
#include "../Engine/DynamicMesh.h"
#include "../Engine/Shader.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/SubjectManager.h"
#include "../Engine/Trail.h"
#include "../Engine/RaycastManager.h"
#include "../Engine/EnemyManager.h"
#include "test.h"

// FREE �Ǿ���ϴ� ������Ʈ���� componentgroup �ӿ� ����־����.

bool testfly = true;
test::test(void)
{
	testshader = dynamic_cast<Engine::Shader*>(Engine::ResourceManager::GetInstance()->LoadResource(L"dyshader"));
	testMesh = dynamic_cast<Engine::StaticMesh*>(Engine::ResourceManager::GetInstance()->LoadResource(L"test"));
	testdynamic = dynamic_cast<Engine::DynamicMesh*>(Engine::ResourceManager::GetInstance()->LoadResource(L"dynamic"));
	componentgroup.emplace(L"shader", testshader);

	transform = new Engine::Transform();
	componentgroup.emplace(L"Transform", transform);

	Engine::SubjectManager::GetInstance()->AddData(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM), transform);
	Engine::SubjectManager::GetInstance()->AddData(static_cast<UINT>(PlayerInfos::PLAYERHEALTH), &healthpoint);

	testdynamic->SetParent(&transform->worldMatrix);
	
	transform->scale = D3DXVECTOR3(0.01, 0.01, 0.01);

	UINT aniset = 1;
	testdynamic->SetAnimationSet(aniset);

	lefttrail = new Engine::Trail();
	lefttrail->Initalize(&transform->worldMatrix, 1024, 0.03f, 4, 3, L"TrailTexture");
	componentgroup.emplace(L"trail", lefttrail);

	righttrail = new Engine::Trail();
	righttrail->Initalize(&transform->worldMatrix, 1024, 0.03f, 4, 3, L"TrailTexture");
	componentgroup.emplace(L"trail2", righttrail);

	lefttrailpos[0] = { 0,0,0 };
	lefttrailpos[1] = { 0,0,0 };
	righttrailpos[0] = { 0,0,0 };
	righttrailpos[1] = { 0,0,0 };
}

test::~test(void)
{
}

void test::Update(const float& dt)
{
	GameObject::Update(dt);
	D3DXVec3TransformCoord(&lefttrailpos[0], &D3DXVECTOR3(509,-22,-189), &transform->worldMatrix);
	D3DXVec3TransformCoord(&lefttrailpos[1], &D3DXVECTOR3(490, -15, -189), &transform->worldMatrix);
	D3DXVec3TransformCoord(&righttrailpos[0], &D3DXVECTOR3(-509, -22, -189), &transform->worldMatrix);
	D3DXVec3TransformCoord(&righttrailpos[1], &D3DXVECTOR3(-490,-15,-189), &transform->worldMatrix);

	lefttrail->AddNewTrail(lefttrailpos[0], lefttrailpos[1], dt);
	righttrail->AddNewTrail(righttrailpos[0], righttrailpos[1], dt);

	directonVector = -(*reinterpret_cast<D3DXVECTOR3*>(&transform->worldMatrix._31));

	if (DXUTWasKeyPressed('U'))
	{
		UINT aniset = testfly ? 0 : 1;
		testfly = !testfly;
		testdynamic->SetAnimationSet(aniset);
	}

	if (DXUTIsKeyDown('W'))
		transform->Rotate(Engine::Transform::RotType::RIGHT, 1.0f * dt);
	
	if (DXUTIsKeyDown('S'))
		transform->Rotate(Engine::Transform::RotType::RIGHT, -1.0f * dt);
	
	if (DXUTIsKeyDown('A'))
		transform->Rotate(Engine::Transform::RotType::LOOK, -2.5f * dt);
	
	if (DXUTIsKeyDown('D'))
		transform->Rotate(Engine::Transform::RotType::LOOK, 2.5f * dt);

	if (DXUTWasKeyPressed('J'))
	{
		--healthpoint;
		Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERHEALTH));
	}

	transform->position += directonVector * dt * 300;
}

void test::LateUpdate(const FLOAT& dt)
{
	//for (int i = 0; i < Engine::EnemyManager::GetInstance()->enemymesh.size(); ++i)
//	{
		float a;
		D3DXVECTOR3 p;
		D3DXVECTOR3 dir = -*reinterpret_cast<D3DXVECTOR3*>(&transform->worldMatrix._31);
		D3DXVECTOR3 pos = *reinterpret_cast<D3DXVECTOR3*>(&transform->worldMatrix._41);
		if (Engine::RaycastManager::GetInstance()->PickMeshWithDirection(a, p, Engine::EnemyManager::GetInstance()->enemymesh[0],
			dir, pos, *Engine::EnemyManager::GetInstance()->enemyTransform[0]))
		{
			cout << "Distance : "<<a << endl<< " POSITION : " << p.x << " " << p.y << " " << p.z << endl;
		}

		//if (Engine::RaycastManager::GetInstance()->PickMeshWithMouse(a, p, Engine::EnemyManager::GetInstance()->enemymesh[0],
		//	*Engine::EnemyManager::GetInstance()->enemyTransform[0]))
		//{
		//	cout << "Distance : " << a << " POSITION : " << p.x << " " << p.y << " " << p.z << endl;
		//}
//	}


	GameObject::LateUpdate(dt);
}

void test::Render(const FLOAT& dt)
{
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	testdynamic->PlayAnimation(dt * 3);
	testshader->SetupTable();
	UINT pass = 0;
	LPD3DXEFFECT tempeffect = testshader->GetEffect();
	tempeffect->Begin(&pass, 0);
	tempeffect->BeginPass(0);
	testdynamic->RenderNoSkinnedMesh(tempeffect);
	tempeffect->EndPass();
	tempeffect->End();
	GameObject::Render(dt);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

void test::Free(void)
{
	GameObject::Free();
}
