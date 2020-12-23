#pragma once
#include "../Engine/GameObject.h"
NAMESPACE(Engine)
class StaticMesh;
class DynamicMesh;
class Transform;
class Shader;
END
class test final :
    public Engine::GameObject
{
private:
protected:
public:
    explicit test(void);
    virtual ~test(void);
    
    Engine::Shader* testshader   = nullptr;
    Engine::StaticMesh* testMesh = nullptr;
    Engine::DynamicMesh* testdynamic = nullptr;
    Engine::Transform* transform = nullptr;

    void Update(const float& dt) override;
    void LateUpdate(void) override;
    void Render(void) override;

    void Free(void) override;
};

