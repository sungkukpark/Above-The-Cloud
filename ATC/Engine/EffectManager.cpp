#include "DXUT.h"
#include "Layer.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "TextureEffect.h"
#include "EffectManager.h"
USING(Engine)

void EffectManager::SpawnTextureEffect(const D3DXVECTOR3& _position, Transform* _transform, const FLOAT& _alivetime, const wstring& _texturetag, const wstring& _layertag)
{
	// ���� ���� Tag�� �´� ���̾� �ӿ��� _alivetime������ ����ִ� GameObject �����ؼ� �־��ֱ�
	TextureEffect* texeffect = new TextureEffect(_texturetag, _position, _transform, _alivetime);
	//texeffect->CreateTextureEffect(_texturetag, _position, _transform);
	SceneManager::GetInstance()->AddGameObject(L"Effect", _layertag, texeffect);
	return;
}
