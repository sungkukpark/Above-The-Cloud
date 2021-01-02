#include "DXUT.h"
#include "../Engine/SubjectManager.h"
#include "PlayerObserver.h"
#include "../Engine/Transform.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/StaticMesh.h"
#include "testChild.h"

testChild::testChild(void)
{
	observer = new PlayerObserver();
	Engine::SubjectManager::GetInstance()->Subscribe(observer);
	Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM));

	t = new Engine::Transform();
	componentgroup.emplace(L"Transform", t);
	t->scale = D3DXVECTOR3(0.1f, 0.1f, 0.1f);

	testsphere = dynamic_cast<Engine::StaticMesh*>(Engine::ResourceManager::GetInstance()->LoadResource(L"Cloud"));
}

testChild::~testChild(void)
{
}

void testChild::Update(const float& dt)
{
	if (DXUTIsKeyDown('L'))
	//cout << t->position.x << " " << t->position.y << " " << t->position.z << endl;
	if (DXUTIsKeyDown(VK_LEFT))
	{
		t->position.x -= 100 * dt;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		t->position.x += 100 * dt;
	}
	if (DXUTIsKeyDown(VK_UP))
	{
		t->position.z += 100 * dt;
	}
	if (DXUTIsKeyDown(VK_DOWN))
	{
		t->position.z -= 100 * dt;
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
	DEVICE->SetTransform(D3DTS_WORLD, &t->worldMatrix);
	GameObject::LateUpdate(dt);
}

void testChild::Render(const FLOAT& dt)
{
	testsphere->RenderMesh();
	GameObject::Render(dt);
}

void testChild::Free(void)
{
	observer->Release();
}
