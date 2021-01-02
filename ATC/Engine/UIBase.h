#pragma once
#include "GameObject.h"

NAMESPACE(Engine)
class Transform;
class Texture;
class UIBase :
    public GameObject
{
private:
protected:
    LPD3DXSPRITE uiSprite;
    Transform* transform;
    Texture* texture;

public:
    // 1. ������ ���� ù��°
    // 2. front�� �̾ƿͼ� ������ ��ȯ
    // 3. Non-Cull �ʿ�
    
    // Sprite Create�Ҷ� ���� Ȯ�� �ʿ� (���� ���ϸ� Constructer��, �ϸ� Singleton���� RenderManager��)!
    // UI������ ���� �ʿ� Transform
    
    // UI�� �ʿ��Ѱ͵�
    // 1. ��ġ
    // 2. RHW || Billboard
    // 3. Render��� (Non-Effect || Effect)
    // 4. UI Animation
    // 5. UI Clipping Bound (For HP bar and others)

    // �����Ҷ� memcpy�� 8byte��ŭ�� ���������� �ɵ� (��ġ).
    
    // Aimpoint�� Billboard�� 2D -> 3D ��ǥ ��ȯ ���Ѽ� Forward���⿡ ����ָ� �ɵ�? �Ƹ��� ��
    
    explicit UIBase(void);
    explicit UIBase(wstring _texturetag);
    virtual ~UIBase(void);

    void SetPosition(const D3DXVECTOR2& _position);

    void SetUITexture(const UINT& _index);
    
    void Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;
};
END
