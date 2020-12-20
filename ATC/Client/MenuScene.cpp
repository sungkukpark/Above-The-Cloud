#include "DXUT.h"
#include "../Engine/Layer.h"
#include "../Client/test.h"
#include "../Client/Camera.h"
#include "MenuScene.h"


void MenuScene::Start(void)
{
	cout << "�� ��~��" << endl;
	Engine::Layer* l = new Engine::Layer();
	layergroup.emplace(L"�׽�Ʈ", l);
	test* t = new test();
	Camera* c = new Camera();
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", t);
	Scene::AddGameObject(L"�׽�Ʈ", L"�׽�Ʈ", c);
	
}

void MenuScene::Update(const float& dt)
{
	Scene::Update(dt);
}

void MenuScene::LateUpdate(void)
{
	Scene::LateUpdate();
}

void MenuScene::Render(void)
{
	Scene::Render();
}

void MenuScene::Exit(void)
{
	cout << "����Ʈ" << endl;
	Scene::Exit();
}

void MenuScene::Free(void)
{
	Scene::Free();
}
