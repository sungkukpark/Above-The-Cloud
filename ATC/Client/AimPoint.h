#pragma once
#include "../Engine/StaticUI.h"
NAMESPACE(Engine)
class PlayerObserver;
class Transform;
END
class AimPoint final :
    public Engine::StaticUI // dynamic���� ��ü -> 
{
private:
    Engine::Transform* playerTransform;
    bool lookback = false;
protected:
public:
    explicit AimPoint(wstring _texturetag);
    virtual ~AimPoint(void);

    void Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;

    void Free(void) override;
};

