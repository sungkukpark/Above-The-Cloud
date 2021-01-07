#pragma once
#include "Singleton.h"
NAMESPACE(Engine)
class EffectManager :
    public Singleton<EffectManager>
{
private:
protected:
public:
    void SpawnTextureEffect(const D3DXVECTOR3& _position,
                            const D3DXMATRIX& _world,
                            const FLOAT& _alivetime,
                            const wstring& _texturetag,
                            const wstring& _layertag = L"Effect");
};
END