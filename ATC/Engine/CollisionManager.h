#pragma once
#include "Singleton.h"
NAMESPACE(Engine)
class CollisionManager :
    public Singleton<CollisionManager>
{
    // 1. ����ִ� ��� �� (�Ѿ� ����) ���ӿ�����Ʈ���� �ݶ��̴��� �÷��̾�� üũ�ؼ� Bound �ȿ� ���Դ� �ϸ� ������ ������
    // �׷����� ���� �־������? 1. IsHit���� bool���� ���� �ϳ��� player�ӿ��� if(CM::GINS()->isHit()) hp--; �̷��� �ؾ��ҵ�
    // �� list�� ��� ���ӿ�����Ʈ���� collider �������� ����־���ҵ� �ǽð����� �����ǰ� �ؾ��ҰͰ����� �� �����ҵ�
    // �� GameObject�� Collider������ �������ְ�
    // �� Collider������ ������ �ִٰ� ��ü�� �����ɶ� �׿� �ش��ϴ� collider��ȣ�� ���������ִ� ������ �ϸ� �ɵ�
    // �׷� DeleteColliderData(��ȣ)
    // map[��ȣ(list)].clear()?

    // map value == list�� key == ENUM ���� �ϰ�
    // �׳� ������Ʈ �� ������ ������ �ɵ�
};
END