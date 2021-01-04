#pragma once
#include "../Engine/StaticUI.h"
NAMESPACE(Engine)
class PlayerObserver;
class Transform;
END
class AimPoint final : // ���� Static���� Sprite�� �ѹ� �ٲ㼭, Screen��ǥ�� �ѹ� �������!
    public Engine::StaticUI
{
private:
    Engine::Transform* playerTransform;
protected:
public:
    explicit AimPoint(wstring _texturetag);
    virtual ~AimPoint(void);

    void Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;

    void Free(void) override;
};

