#pragma once
#include "Base.h"

NAMESPACE(Engine)
class Layer;
class Component;
class GameObject :
	public Base
{
private:
protected:
	friend class Layer;
	friend class CollisionManager;
	friend class ObjectManager;

	map<wstring, Component*> componentgroup;
	list<Component*> compo;
	bool isActive = true;
	ColliderData colliderdata;
public:

	explicit GameObject(void) {};
	virtual ~GameObject(void) {};
	
	void ResetDevice(void);
	void LostDevice(void);

	virtual void CollisionEvent(const wstring& _objectTag, GameObject* _gameObject) {};
	ColliderData* GetColliderData(void) { return &colliderdata; };

	Component* GetComponent(const wstring& componenttag)
	{
		auto iter = componentgroup.find(componenttag);
		if (iter != componentgroup.end())
			return componentgroup[componenttag];
		return nullptr;
	};

	virtual INT Update(const FLOAT& dt);
	virtual void LateUpdate(const FLOAT& dt) {};
	virtual void Render(const FLOAT& dt);

	void SetActive(bool _active) { isActive = _active; };

	void Free(void) override;
};
END
