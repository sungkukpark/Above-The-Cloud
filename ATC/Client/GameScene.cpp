#include "DXUT.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Layer.h"
#include "Plane.h"
#include "Cloud.h"
#include "SkySphere.h"
#include "PlaneCamera.h"
#include "../Engine/SubjectManager.h"
#include "../Engine/GraphicsManager.h"
#include "AimPoint.h"
#include "HealthPointGroup.h"
#include "Monster1.h"
#include "../Engine/ObjectManager.h"
#include "../Engine/CollisionManager.h"
#include "LockPoint.h"
#include "GameScene.h"


void GameScene::Start(void)
{
	Engine::GraphicsManager::GetInstance()->CreateSprite();
	Engine::Layer* l = new Engine::Layer();
	Engine::Layer* effect = new Engine::Layer();
	layergroup.emplace(L"�׽�Ʈ", l);
	layergroup.emplace(L"Effect", effect);
	SkySphere* s = new SkySphere();

	HealthPointGroup* h = new HealthPointGroup();
	
	Cloud* t1 = new Cloud();

	Monster1* sp = new Monster1();

	Engine::ObjectManager::GetInstance()->AddObjectAtLayer<Plane>(L"�׽�Ʈ", L"�׽�Ʈ");
	PlaneCamera* c = new PlaneCamera();
	AimPoint* ui = new AimPoint(L"AimPoint");
	LockPoint* ui2 = new LockPoint();
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", c);
	Scene::AddGameObject(L"�׽�Ʈ", L"UI", ui);
	Scene::AddGameObject(L"�׽�Ʈ", L"UI", ui2);
	Scene::AddGameObject(L"�׽�Ʈ", L"UI", h);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", s);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t1);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", sp);
}

void GameScene::Update(const FLOAT& dt)
{
	Engine::CollisionManager::GetInstance()->UpdateData();
	if (DXUTWasKeyPressed('P'))
		Engine::SceneManager::GetInstance()->SetScene(L"�޴�");
	Scene::Update(dt);
}

void GameScene::LateUpdate(const FLOAT& dt)
{
	Engine::CollisionManager::GetInstance()->CheckCollision(PLAYER, MONSTER);
	Engine::CollisionManager::GetInstance()->CheckCollision(MISSILE, MONSTER);
	Engine::CollisionManager::GetInstance()->CheckCollision(PLAYER, MONSTERMISSILE);
	Scene::LateUpdate(dt);
}

void GameScene::Render(const FLOAT& dt)
{
	Scene::Render(dt);
}

void GameScene::Exit(void)
{
	Engine::CollisionManager::GetInstance()->ClearData();
	Engine::SubjectManager::GetInstance()->ClearObservers();
	Engine::GraphicsManager::GetInstance()->DeleteSprite();
	Scene::Exit();
}

void GameScene::Free(void)
{
	Scene::Free();
}
