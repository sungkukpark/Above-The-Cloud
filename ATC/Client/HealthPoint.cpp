#include "DXUT.h"
#include "../Engine/Transform.h"
#include "HealthPoint.h"

HealthPoint::HealthPoint(wstring _texturetag) :
	Engine::StaticUI(_texturetag)
{
	transform->position.x = 30;
	transform->position.y = 30;
	transform->scale = { 2,2,2 };
}

HealthPoint::~HealthPoint(void)
{
}

void HealthPoint::Update(const FLOAT& dt)
{
	Engine::StaticUI::Update(dt);
}

void HealthPoint::LateUpdate(const FLOAT& dt)
{
	Engine::StaticUI::LateUpdate(dt);
}

void HealthPoint::Render(const FLOAT& dt)
{
	Engine::StaticUI::Render(dt);
}

void HealthPoint::Free(void)
{
	Engine::StaticUI::Free();
}
