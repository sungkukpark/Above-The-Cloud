#include "DXUT.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Layer.h"
#include "test.h"
#include "testChild.h"
#include "SkySphere.h"
#include "Camera.h"
#include "../Engine/SubjectManager.h"
#include "../Engine/GraphicsManager.h"
#include "AimPoint.h"
#include "HealthPointGroup.h"
#include "MenuScene.h"


void MenuScene::Start(void)
{
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"skysphere.X", L"SkySphere")))
		cout << "�����޽��ߺҷ�������" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::DYNAMIC, L"Resources/Meshes/Dynamic/", L"testdoubleanimation.x", L"dynamic")))
		cout << "���̳��͸޽úҷ�����" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddShader(L"Resources/Shaders/DynamicMeshShader.fx", L"dyshader")))
		cout << "dyShader Load Complete" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/AimPoint.png", L"AimPoint")))
		cout << "�ؽ��ĵ� �ƴ�" << endl; 
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/heart.png", L"Heart")))
		cout << "2�ؽ��ĵ� �ƴ�" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/trail.dds", L"TrailTexture")))
		cout << "Ʈ�����ؽ��� �ƴ�" << endl;

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"cloud.X", L"Cloud")))
		cout << "�������Ͷ�" << endl;
	Engine::GraphicsManager::GetInstance()->CreateSprite();
	Engine::Layer* l = new Engine::Layer();
	layergroup.emplace(L"�׽�Ʈ", l);
	test* t = new test();
	Camera* c = new Camera();
	SkySphere* s = new SkySphere();

	AimPoint* ui = new AimPoint(L"AimPoint");
	HealthPointGroup* h = new HealthPointGroup();
	

	testChild* t1 = new testChild();
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", c);
	Scene::AddGameObject(L"�׽�Ʈ", L"UI", ui);
	Scene::AddGameObject(L"�׽�Ʈ", L"UI", h);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", s);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t1);
}

void MenuScene::Update(const float& dt)
{
	Scene::Update(dt);
}

void MenuScene::LateUpdate(const FLOAT& dt)
{
	
	Scene::LateUpdate(dt);
}

void MenuScene::Render(const FLOAT& dt)
{
	Scene::Render(dt);
}

void MenuScene::Exit(void)
{
	cout << "����Ʈ" << endl;
	Engine::SubjectManager::GetInstance()->ClearObservers();
	Engine::GraphicsManager::GetInstance()->DeleteSprite();
	Scene::Exit();
}

void MenuScene::Free(void)
{
	Scene::Free();
}
