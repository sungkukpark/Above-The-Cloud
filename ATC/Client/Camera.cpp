#include "DXUT.h"
#include "../Engine/Transform.h"
#include "../Engine/SubjectManager.h"
#include "PlayerObserver.h"
#include "Camera.h"

Camera::Camera(void)
{
	transform = new Engine::Transform();
	componentgroup.emplace(L"Transform", transform);
	transform->position = { 0,282, 905 };
	observer = new PlayerObserver();
	Engine::SubjectManager::GetInstance()->Subscribe(observer);
	Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM));
	transform->SetParent(observer->GetTransform());
}

Camera::~Camera(void)
{
}

void Camera::Update(const float& dt)
{
	if (DXUTWasKeyPressed('O'))
	{
		lookback = !lookback;
		transform->position.z = -transform->position.z;
	}

	GameObject::Update(dt);
}

void Camera::LateUpdate(const FLOAT& dt)
{
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//1. Temp World �ϳ� ����
	//2. �� ���带 ī�޶� lerp�� õõ�� ���󰡱�

	// �÷��̾� �����ǿ� �Ҵ�� �� ��ġ�� ī�޶� lerp�ϰ�
	// quaternion�� �Ȱ��� ī�޶� slerp��Ű�� �ǳ�?



	cout << transform->curQuaternion.x << " " << transform->curQuaternion.y << " " << transform->curQuaternion.z << " " << transform->curQuaternion.w << endl;
	D3DXMATRIX matView;
	if (!lookback)
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
	DEVICE->SetTransform(D3DTS_VIEW, &matView);
	DEVICE->SetTransform(D3DTS_PROJECTION, &matProj);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	GameObject::LateUpdate(dt);
}

void Camera::Render(const FLOAT& dt)
{
	GameObject::Render(dt);
}

void Camera::Free(void)
{
	GameObject::Free();
}
