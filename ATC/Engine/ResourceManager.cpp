#include "DXUT.h"
#include "Resources.h"
#include "StaticMesh.h"
#include "DynamicMesh.h"
#include "Shader.h"
#include "Texture.h"
#include "ResourceManager.h"
USING(Engine)
HRESULT ResourceManager::AddTexture(std::wstring _filepath, std::wstring _tag, const UINT& _texturecount)
{
	auto& iter = resourcegroup.find(_tag);
	if (iter != resourcegroup.end())
	{
		std::wstring error = _tag;
		MessageBox(DXUTGetHWND(), error.c_str(), L"�ߺ� �ؽ���", MB_ICONERROR | MB_OK);
		return E_FAIL;
	}
	
	Texture* texture = new Texture();
	texture->LoadTexture(_filepath, _texturecount);
	
	resourcegroup.emplace(_tag, texture);
	return S_OK;
}

HRESULT ResourceManager::AddMesh(MeshType _meshtype, std::wstring _filepath, std::wstring _filename, std::wstring _tag)
{
	auto& iter = resourcegroup.find(_tag);
	if (iter != resourcegroup.end())
	{
		std::wstring error = _tag;
		MessageBox(DXUTGetHWND(), error.c_str(), L"�ߺ� �޽�", MB_ICONERROR | MB_OK);
		return E_FAIL;
	}

	if (_meshtype == MeshType::STATIC)
	{
		StaticMesh* staticmesh = new StaticMesh();
		if (FAILED(staticmesh->LoadMesh(_filepath, _filename)))
		{
			std::wstring error = _filepath + _filename;
			MessageBox(DXUTGetHWND(), error.c_str(), L"����ƽ �޽� �ε� FAIL", MB_ICONERROR | MB_OK);
			return E_FAIL;
		}
		resourcegroup.emplace(_tag, staticmesh);
	}
	else if(_meshtype == MeshType::DYNAMIC)
	{
		DynamicMesh* dynamicmesh = new DynamicMesh();
		if (FAILED(dynamicmesh->LoadMesh(_filepath, _filename)))
		{
			std::wstring error = _filepath + _filename;
			MessageBox(DXUTGetHWND(), error.c_str(), L"���̳��� �޽� �ε� FAIL", MB_ICONERROR | MB_OK);
			return E_FAIL;
		}
		resourcegroup.emplace(_tag, dynamicmesh);
	}
	return S_OK;
}

HRESULT ResourceManager::AddShader(std::wstring _filepath, std::wstring _tag)
{
	auto& iter = resourcegroup.find(_tag);
	if (iter != resourcegroup.end())
	{
		std::wstring error = _tag;
		MessageBox(DXUTGetHWND(), error.c_str(), L"�ߺ� ���̴�", MB_ICONERROR | MB_OK);
		return E_FAIL;
	}
	Shader* shader = new Shader();
	if(FAILED(shader->CreateShader(_filepath)))
		return E_FAIL;
	resourcegroup.emplace(_tag, shader);
	return S_OK;
}

Resources* ResourceManager::LoadResource(std::wstring _tag)
{
	auto& iter = resourcegroup.find(_tag);
	if (iter != resourcegroup.end())
		return resourcegroup[_tag]->Clone();
	return nullptr;
}

void ResourceManager::ReleaseResources(void)
{
	for (auto& iter : resourcegroup)
	{
		iter.second->Release();
	}
	resourcegroup.clear();
}
