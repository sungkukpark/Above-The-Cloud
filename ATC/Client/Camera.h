#pragma once
#include "../Engine/GameObject.h"
NAMESPACE(Engine)
class Transform;
END
class Camera final :
    public Engine::GameObject
{
private:
protected:
    Engine::Transform* transform = nullptr;
    Engine::Transform* targetTransform = nullptr;
    float cameraDistance = 10.f;

public:
    bool lookback = false; 
    PlayerObserver* observer;
    explicit Camera(void);
    virtual ~Camera(void);

    void Update(const float& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;
    void KeyInput(FLOAT _dt);

    void Free(void) override;
};

