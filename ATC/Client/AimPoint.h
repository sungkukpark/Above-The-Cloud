#pragma once
#include "../Engine/StaticUI.h"
NAMESPACE(Engine)
class PlayerObserver;
class Transform;
END
class PlayerObserver;
class AimPoint final :
    public Engine::StaticUI // dynamic���� ��ü -> 
{
private:
    PlayerObserver* ob = nullptr;
    bool lookback = false;
    bool pointlock = true;
protected:
public:
    explicit AimPoint(wstring _texturetag);
    virtual ~AimPoint(void);

    INT Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;

    void Free(void) override;
};

