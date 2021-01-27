#pragma once
#include "Singleton.h"
NAMESPACE(Engine)
class GameObject;
class CollisionManager :
    public Singleton<CollisionManager>
{
private:
    D3DXVECTOR3 rayDir = { 0,0,0 };
    D3DXVECTOR3 rayPos = { 0,0,0 };
    list<GameObject*> colliderdatas[OBJEND];
    
    void GetRay(D3DXMATRIX _world);

    void GetWorldMouse(void);


    bool CheckSphereCollision(const D3DXVECTOR3& _srcpos,
                              const FLOAT& _srcradius,
                              const D3DXVECTOR3& _dstpos,
                              const FLOAT& _dstradius);


protected:
public:
    void PushData(ObjectTag _tag , GameObject* _data);

    void CheckCollision(ObjectTag _src, ObjectTag _dst);

    bool MouseRaySphereInteresection(out float& _distanceOut,
        out D3DXVECTOR3& _targetposition,
        in ObjectTag _dsttag);
    // 1. Ray�� Object(Tag)�� �浹�ϸ�, bool ���� -> �����Լ� ȣ��
    // 2. 
    

    void UpdateData(void);

    void ClearData(void);
};
END