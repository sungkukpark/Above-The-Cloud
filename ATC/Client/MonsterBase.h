#pragma once
#include "../Engine/GameObject.h"
NAMESPACE(Engine)
class Transform;
class DynamicMesh;
class Trail;
class Shader;
class Collider;
END
class PlayerObserver;

class MonsterBase :
    public Engine::GameObject
{
private:
protected:
    INT Hp = 5;
    Engine::Transform* transform;
    Engine::Shader* shader;
    Engine::Trail* trail;
    Engine::DynamicMesh* mesh;
    Engine::Collider* collider;
    PlayerObserver* observer;

public:
    explicit MonsterBase(void);
    virtual ~MonsterBase(void);

    void GetHit(const FLOAT& _damageamount);

    virtual void Movement(void) {};
    queue<function<bool(void)>> movementqueue; // queue��, bool lambda�� ��Ƽ� ������ �Ǵ� ������ �����ٸ� r true�� pop��Ų��������.

    void CollisionEvent(const wstring& _objectTag, GameObject* _gameObject) override;
    
    INT Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;

    void Free(void) override;
};

