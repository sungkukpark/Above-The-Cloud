#include "DXUT.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Layer.h"
#include "Plane.h"
#include "Cloud.h"
#include "SkySphere.h"
#include "Camera.h"
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
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"skysphere.X", L"SkySphere")))
		cout << "�����޽��ߺҷ�������" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::DYNAMIC, L"Resources/Meshes/Dynamic/", L"Plane.X", L"dynamic")))
		cout << "���̳��͸޽úҷ�����" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddShader(L"Resources/Shaders/DynamicMeshShader.fx", L"dyshader")))
		cout << "dyShader Load Complete" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddShader(L"Resources/Shaders/DefaultShader.fx", L"defaultShader")))
		cout << "defaultShader Load Complete" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/AimPoint.png", L"AimPoint")))
		cout << "�ؽ��ĵ� �ƴ�" << endl; 
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/heart.png", L"Heart")))
		cout << "2�ؽ��ĵ� �ƴ�" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/trail.dds", L"TrailTexture")))
		cout << "Ʈ�����ؽ��� �ƴ�" << endl;

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::DYNAMIC, L"Resources/Meshes/Dynamic/", L"Monster1.X", L"Monster1")))
		cout << "���̳��͸޽úҷ�����" << endl;

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"cloud.X", L"Cloud")))
		cout << "�������Ͷ�" << endl;
	
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"missilepivottest.X", L"Missile")))
		cout << "missileON" << endl;

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/muzzleflash.png", L"muzzleFlash", 1)))
		cout << "�����÷��� ON" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/Lock.png", L"LockPoint", 1)))
		cout << "LOCKPOINT ON" << endl;

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"MonsterBullet.X", L"MonsterBullet")))
		cout << "MB OK" << endl;
	
	Engine::GraphicsManager::GetInstance()->CreateSprite();
	Engine::Layer* l = new Engine::Layer();
	Engine::Layer* effect = new Engine::Layer();
	layergroup.emplace(L"�׽�Ʈ", l);
	layergroup.emplace(L"Effect", effect);
	//test* t = new test();
	SkySphere* s = new SkySphere();

	HealthPointGroup* h = new HealthPointGroup();
	
	Cloud* t1 = new Cloud();

	Monster1* sp = new Monster1();

	//Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t);
	Engine::ObjectManager::GetInstance()->AddObjectAtLayer<Plane>(L"�׽�Ʈ", L"�׽�Ʈ");
	Camera* c = new Camera();
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

void GameScene::Update(const float& dt)
{
	Engine::CollisionManager::GetInstance()->UpdateData(); // Active�� false�� �ֵ��� ���� �����
	Scene::Update(dt); // �� ������ Release�� ���ش�.
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
