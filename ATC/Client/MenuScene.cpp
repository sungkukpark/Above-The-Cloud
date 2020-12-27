#include "DXUT.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Layer.h"
#include "test.h"
#include "testChild.h"
#include "Camera.h"
#include "../Engine/SubjectManager.h"
#include "MenuScene.h"


void MenuScene::Start(void)
{
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::STATIC, L"Resources/Meshes/Static/", L"Item (1).x", L"test")))
		cout << "�����޽��ߺҷ�������" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddMesh(MeshType::DYNAMIC, L"Resources/Meshes/Dynamic/", L"testdoubleanimation.x", L"dynamic")))
		cout << "���̳��͸޽úҷ�����" << endl;
	//if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddShader(L"Resources/Shaders/DefaultShader.fx", L"shader")))
	//	cout << "Shader Load Complete" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddShader(L"Resources/Shaders/DynamicMeshShader.fx", L"dyshader")))
		cout << "dyShader Load Complete" << endl;

	Engine::Layer* l = new Engine::Layer();
	layergroup.emplace(L"�׽�Ʈ", l);
	test* t = new test();
	Camera* c = new Camera();
	testChild* t1 = new testChild();
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", c);
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
	Scene::Exit();
}

void MenuScene::Free(void)
{
	Scene::Free();
}
