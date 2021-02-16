#include "DXUT.h"
#include "Layer.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "TextureEffect.h"
#include "Transform.h"
#include "EffectManager.h"
USING(Engine)

void EffectManager::SpawnTextureEffect(const D3DXVECTOR3& _position, const D3DXVECTOR3& _scale, Transform* _transform, const FLOAT& _alivetime, const std::wstring& _texturetag, const std::wstring& _layertag)
{
	
	TextureEffect* texeffect;
	// ���� ���� Tag�� �´� ���̾� �ӿ��� _alivetime������ ����ִ� GameObject �����ؼ� �־��ֱ�
	if (_transform != nullptr)
		texeffect = new TextureEffect(_texturetag, _position, _scale, _transform, _alivetime);
	else
		texeffect = new TextureEffect(_texturetag, _position, _scale, _alivetime);

	SceneManager::GetInstance()->AddGameObject(OBJ2, _layertag, texeffect);
	return;
}
