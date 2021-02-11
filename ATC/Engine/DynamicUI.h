#pragma once
#include "UIBase.h"
NAMESPACE(Engine)
class DynamicUI : // Buffer ����� Billboard. Enemy Lock & AimPoint���� ���� UI�� ���� Ŭ����
    public UIBase
{
private:
    bool isbillboard = true;
    void CreateBuffer(void);
protected:
    LPDIRECT3DVERTEXBUFFER9 vb;
    LPDIRECT3DINDEXBUFFER9 ib; 
    DWORD vtxsize = 0;
    DWORD vtxcnt = 0;
    DWORD vtxFVF = 0;
    DWORD tricnt = 0;
    DWORD idxsize = 0;
    D3DFORMAT idxfmt;
public:
    explicit DynamicUI(std::wstring _texturetag, bool _billboardenable = true);
    explicit DynamicUI(std::wstring _texturetag, Transform* _parent, bool _billboardenable = true);
    virtual ~DynamicUI(void);

    INT Update(const FLOAT& dt) override;
    void LateUpdate(const FLOAT& dt) override;
    void Render(const FLOAT& dt) override;

    void Free(void) override;
};
END