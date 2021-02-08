#include "DXUT.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/SceneManager.h"
#include "LoadScene.h"

LoadScene::LoadScene(void)
{
}

LoadScene::~LoadScene(void)
{
}

void LoadScene::Start(void)
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

	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/Start.png", L"Start", 1)))
		cout << "Start ON" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/Select.png", L"Select", 1)))
		cout << "Select Mode ON" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/Settings.png", L"Settings", 1)))
		cout << "Settings ON" << endl;
	if (SUCCEEDED(Engine::ResourceManager::GetInstance()->AddTexture(L"Resources/Textures/Exit.png", L"Exit", 1)))
		cout << "Exit ON" << endl;

	Engine::SceneManager::GetInstance()->SetScene(L"�޴�");
}

void LoadScene::Update(const FLOAT& dt)
{
	Scene::Update(dt);
}

void LoadScene::LateUpdate(const FLOAT& dt)
{
	Scene::LateUpdate(dt);
}

void LoadScene::Render(const FLOAT& dt)
{
	Scene::Render(dt);
}

void LoadScene::Exit(void)
{
	Scene::Exit();
}

void LoadScene::Free(void)
{
	Scene::Free();
}
