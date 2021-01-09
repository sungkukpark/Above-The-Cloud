#pragma once
#include "Singleton.h"
NAMESPACE(Engine)
class CollisionManager :
    public Singleton<CollisionManager>
{
private:
    list<Collider*> collisiondatas;
protected:
public:
    void PushData(Collider* _data);

    void CheckSphereCollision(Collider* _col1, Collider* _col2);

    void UpdateData(void);
};
END