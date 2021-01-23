#include "DXUT.h"
#include "../Engine/SubjectManager.h"
#include "PlayerObserver.h"
#include "../Engine/Transform.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/StaticMesh.h"
#include "../Engine/ObjectManager.h"
#include "../Engine/Collider.h"
#include "../Engine/CollisionManager.h"
#include "testChild.h"

testChild::testChild(void)
{
	observer = new PlayerObserver();
	Engine::SubjectManager::GetInstance()->Subscribe(observer);
	Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM));

	t = new Engine::Transform(/*observer->GetTransform()*/);
	componentgroup.emplace(L"Transform", t);
	t->scale = D3DXVECTOR3(0.1f, 0.1f, 0.1f);
	t->position = { 5,5,50 };
	testsphere = dynamic_cast<Engine::StaticMesh*>(Engine::ResourceManager::GetInstance()->LoadResource(L"Cloud"));

	Engine::EnemyManager::GetInstance()->enemymesh.push_back(testsphere->GetMesh());
	Engine::EnemyManager::GetInstance()->enemyTransform.push_back(&t->worldMatrix);

	collider = new Engine::Collider(2, &t->position, ObjectTag::MONSTER);
	Engine::CollisionManager::GetInstance()->PushData(MONSTER, this);

	colliderdata.center = &t->position;
	colliderdata.radius = 1;
	colliderdata.tag = L"player";
	colliderdata.ishit = false;
}

testChild::~testChild(void)
{
}

void testChild::Update(const float& dt)
{
	//if (DXUTIsKeyDown('L'))
	//cout << t->position.x << " " << t->position.y << " " << t->position.z << endl;
	if (DXUTIsKeyDown(VK_LEFT))
	{
		t->position.x += 100 * dt;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		t->position.x -= 100 * dt;
	}
	if (DXUTIsKeyDown(VK_UP))
	{
		t->position.z -= 100 * dt;
	}
	if (DXUTIsKeyDown(VK_DOWN))
	{
		t->position.z += 100 * dt;
	}
	if (DXUTIsKeyDown('N'))
	{
		t->position.y += 100 * dt;
	}
	if (DXUTIsKeyDown('M'))
	{
		t->position.y -= 100 * dt;
	}

	GameObject::Update(dt);
}

void testChild::LateUpdate(const FLOAT& dt)
{
	GameObject::LateUpdate(dt);
}

void testChild::Render(const FLOAT& dt)
{
	DEVICE->SetTransform(D3DTS_WORLD, &t->worldMatrix);
	testsphere->RenderMesh();
	collider->RenderCollider();
	GameObject::Render(dt);
}

void testChild::Free(void)
{
	observer->Release();
}
