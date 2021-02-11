#include "DXUT.h"
#include "Transform.h"
#include "Texture.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "UIBase.h"
USING(Engine)

UIBase::UIBase(void)
{

}

UIBase::UIBase(std::wstring _texturetag)
{
	texture = dynamic_cast<Texture*>(ResourceManager::GetInstance()->LoadResource(_texturetag));
	componentgroup.emplace(L"Texture", texture);
	transform = new Transform();
	componentgroup.emplace(L"Transform", transform);
}

UIBase::UIBase(std::wstring _texturetag, Transform* _parent)
{
	texture = dynamic_cast<Texture*>(ResourceManager::GetInstance()->LoadResource(_texturetag));
	componentgroup.emplace(L"texture", texture);
	transform = new Transform(_parent);
	componentgroup.emplace(L"Transform", transform);
}

UIBase::~UIBase(void)
{
}

void UIBase::SetUITexture(const UINT& _index)
{
	currentTextureindex = _index;
}

INT UIBase::Update(const FLOAT& dt)
{
	GameObject::Update(dt);
	return OBJALIVE;
}

void UIBase::LateUpdate(const FLOAT& dt)
{
	GameObject::LateUpdate(dt);
}

void UIBase::Render(const FLOAT& dt)
{
	GameObject::Render(dt);
}

void UIBase::Free(void)
{
	GameObject::Free();
}
