#include "DXUT.h"
#include "../Engine/Transform.h"
#include "../Engine/SubjectManager.h"
#include "../Engine/Singleton.h"
#include "PlayerObserver.h"
#include "Camera.h"

Camera::Camera(void)
{
	transform = new Engine::Transform();
	targetTransform = new Engine::Transform();
	componentgroup.emplace(L"Transform", transform);
	componentgroup.emplace(L"TargetTransform", targetTransform);

	targetTransform->position = { 0, 250, 0 };
	//targetTransform->Rotate(Engine::Transform::RotType::RIGHT, D3DXToRadian(-30.f));

	observer = new PlayerObserver();
	Engine::SubjectManager::GetInstance()->Subscribe(observer);
	Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM));

	targetTransform->SetParent(observer->GetTransform());
}

Camera::~Camera(void)
{
}

bool targetplane = true;

void Camera::Update(const float& dt)
{
	if (DXUTWasKeyPressed('C'))
	{
		lookback = !lookback;
		cameraDistance *= -1.0f;
	}

	if (DXUTWasKeyPressed('V'))
	{
		targetplane = !targetplane;
	}
	D3DXVECTOR3 look = *D3DXVec3Normalize(&D3DXVECTOR3(), reinterpret_cast<D3DXVECTOR3*>(&targetTransform->worldMatrix._31));
	D3DXVECTOR3 position = *reinterpret_cast<D3DXVECTOR3*>(&targetTransform->worldMatrix._41);
	
	transform->position = position + look * cameraDistance;

	look *= -1.f;

	//  up�� look���� => right
	D3DXVECTOR3 right;
	D3DXVec3Normalize(&right, reinterpret_cast<D3DXVECTOR3*>(&observer->GetTransform()->worldMatrix._11));

	right *= -1.f;

	// look�� right ���� => up
	D3DXVECTOR3 up;
	D3DXVec3Cross(&up, &look, &right);
	D3DXVec3Normalize(&up, &up);

	D3DXMATRIX matRot;
	D3DXMatrixIdentity(&matRot);
	memcpy(&matRot._11, &right, sizeof(D3DXVECTOR3));
	memcpy(&matRot._21, &up, sizeof(D3DXVECTOR3));
	memcpy(&matRot._31, &look, sizeof(D3DXVECTOR3));
	D3DXQuaternionRotationMatrix(&transform->quaternion, &matRot);

	GameObject::Update(dt);
}

void Camera::LateUpdate(const FLOAT& dt)
{
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	D3DXMATRIX matView;
	if (lookback)
	{
		D3DXVECTOR3 reverse = -(*reinterpret_cast<D3DXVECTOR3*>(&transform->worldMatrix._31));
		memcpy(&transform->worldMatrix._31, reverse, sizeof(D3DXVECTOR3));
	}
	
	D3DXMatrixInverse(&matView, 0, &transform->worldMatrix);
	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DXToRadian(70),
		static_cast<float>(DXUTGetD3D9BackBufferSurfaceDesc()->Width) /
		static_cast<float>(DXUTGetD3D9BackBufferSurfaceDesc()->Height),
		0.01, 50000);
	if(targetplane)
		DEVICE->SetTransform(D3DTS_VIEW, &matView);
	else
	{
		D3DXMATRIX im;
		D3DXMatrixIdentity(&im);
		D3DXMatrixTranslation(&im, 0, 0, 12);
		DEVICE->SetTransform(D3DTS_VIEW, &im);
	}
	DEVICE->SetTransform(D3DTS_PROJECTION, &matProj);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	D3DXVECTOR3 position = *reinterpret_cast<D3DXVECTOR3*>(&targetTransform->worldMatrix._41);
	D3DXMATRIX w;
	w = *D3DXMatrixScaling(&D3DXMATRIX(), 0.01f, 0.01f, 0.01f);
	w *= *D3DXMatrixTranslation(&D3DXMATRIX(), transform->position.x, transform->position.y, transform->position.z);
	GameObject::LateUpdate(dt);
}

void Camera::Render(const FLOAT& dt)
{
	GameObject::Render(dt);
}

void Camera::KeyInput(FLOAT _dt)
{

}

void Camera::Free(void)
{
	GameObject::Free();
}
