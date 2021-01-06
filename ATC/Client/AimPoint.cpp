#include "DXUT.h"
#include "../Engine/SubjectManager.h"
#include "PlayerObserver.h"
#include "Camera.h"
#include "../Engine/Transform.h"
#include "AimPoint.h"

AimPoint::AimPoint(wstring _texturetag) :
	Engine::StaticUI(_texturetag)
{
	PlayerObserver* ob = new PlayerObserver();
	Engine::SubjectManager::GetInstance()->Subscribe(ob);
	Engine::SubjectManager::GetInstance()->Notify(static_cast<UINT>(PlayerInfos::PLAYERTRANSFORM));
	playerTransform = ob->GetTransform();
}

AimPoint::~AimPoint(void)
{
}

void AimPoint::Update(const FLOAT& dt)
{
	Engine::StaticUI::Update(dt);
	D3DXVECTOR3 playerLook = -(*reinterpret_cast<D3DXVECTOR3*>(&playerTransform->worldMatrix._31));
	D3DXVECTOR3 pos = playerTransform->position + playerLook * 5000;

	D3DXMATRIX			matView, matProj;
	D3DVIEWPORT9		viewPort;
	D3DXVECTOR3			screenPos;
	DEVICE->GetViewport(&viewPort);

	DEVICE->GetTransform(D3DTS_VIEW, &matView);
	DEVICE->GetTransform(D3DTS_PROJECTION, &matProj);
	D3DXVec3TransformCoord(&screenPos, &pos, &matView);
	D3DXVec3TransformCoord(&screenPos, &screenPos, &matProj);

	// ��ũ�� ��ǥ �ֻ���� <0, 0> �̴ϱ� x�� + 1�� �ؾ� ����� �ȴ�.
	screenPos.x = (screenPos.x + 1) * (viewPort.Width / 2);

	// ��ũ�� ��ǥ�� +�� ������ ������ ����, 
	// y�� +�� ������ ���� ���⿡ ��ũ�� ��ǥ�� ���߱� ���ؼ� + 1�� ���ش�.
	// ��ũ�� ��ǥ�� ���� �ֻ���� <0, 0> �̱⿡ -�� Screenpos�� + 1�� ���༭ �߰��� ������Ѵ�
	screenPos.y = (-screenPos.y + 1) * (viewPort.Height / 2);

	// ����������, ������ǥ�� ���� �ֻ���� -1, 1�̰� ��ũ����ǥ�� ���� �ֻ���� 0, 0�̱⿡
	// ������ǥ���� ��ũ����ǥ�� ��ȯ�ϱ� ���Ͽ� -1���� +1�� �Ͽ� 0, 1���� -1�� �Ͽ� 0�� �����.
	// �ڿ� ����Ʈ / 2 �� ���ϴ� ������ �߰��� ��ġ�� ��ǥ�� 0, 0 �̱⿡ �׷��� �Ѵ�.

	transform->position = screenPos;
	//POINT p;
	//p.x = transform->position.x;
	//p.y = transform->position.y;
	//ClientToScreen(DXUTGetHWND(), &p);
	//::SetCursorPos(p.x, p.y);
}

void AimPoint::LateUpdate(const FLOAT& dt)
{
	Engine::StaticUI::LateUpdate(dt);
}

void AimPoint::Render(const FLOAT& dt)
{
	if (!Camera::GetInstance()->lookback)
		Engine::StaticUI::Render(dt);
}

void AimPoint::Free(void)
{
	Engine::StaticUI::Free();
}
