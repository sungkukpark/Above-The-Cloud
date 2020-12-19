#pragma once
#include "Resources.h"

NAMESPACE(Engine)
class StaticMesh final :
    public Resources
{
private:
    LPD3DXMESH          oriMesh         = nullptr;
    LPD3DXMESH          mesh            = nullptr;
    LPD3DXBUFFER        adjacencyBuffer = nullptr;
    LPD3DXBUFFER        subsetBuffer    = nullptr;
    LPD3DXMATERIAL      subset          = nullptr;
    LPDIRECT3DTEXTURE9* textures        = nullptr;
    D3DXVECTOR3*        vertexPosition  = nullptr;
    INDEX16*            index           = nullptr;
    ULONG               subsetCount     = 0;
    ULONG               numVertex       = 0;
    ULONG               stride          = 0;
    ULONG               numFaces        = 0;
protected:
public:
    explicit StaticMesh(void);
    explicit StaticMesh(const StaticMesh& cp);
    virtual ~StaticMesh(void);

    HRESULT LoadMesh(wstring _filepath, wstring _filename);

    Resources* Clone(void) override;
    void Free(void) override;
};
END