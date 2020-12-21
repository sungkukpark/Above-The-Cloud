#pragma once
#include "Singleton.h"

NAMESPACE(Engine)
class Resources;
class ResourceManager final :
    public Singleton<ResourceManager>
{
private:
    map<wstring, Resources*> resourcegroup;
protected:

public:
    HRESULT AddTexture(wstring _filepath, wstring _filename, wstring _tag);
    HRESULT AddMesh(MeshType _meshtype, wstring _filepath, wstring _filename, wstring _tag);

    Resources* LoadResource(wstring _tag);
};
END
