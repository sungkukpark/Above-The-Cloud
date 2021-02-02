# Above The Cloud
--------
고등학교 졸업 직전 제작하는 3D 비행슈팅게임

여태까지 1년 반동안 공부했던 프로그래밍 기술들의 대부분이라고 생각할 정도로 많은 기능들이 들어가 있게 할 예정입니다.
--------

 + 업데이트 로그
 
 + 2020 12 19 기본 프레임워크 제작 - 1
 
 + 2020 12 20 기본 프레임워크 제작 - 2 (모델 띄워지는지 확인, 엔진/클라이언트 코드 정리 필요)
 
 + 2020 12 21 기본 프레임워크 제작 - 3 (모델 출력, 셰이더를 사용한 출력 확인 완료, 코드 정리 완료 & 구조 다듬기 완료)

 + 2020 12 22 기본 프레임워크 제작 - 4 (다이나믹메시 출력 확인, UI 출력, 다중 애니메이션 확인 필요)

 + 2020 12 23 기본 프레임워크 제작 - 5 (다이나믹메시 튜닝, 출력 확인 완료, 구조 다듬고 애니메이션 확인 필요)

 + 2020 12 24 기본 프레임워크 제작 - 6 (다중 애니메이션 확인 완료, 플레이어 움직임 구현 시작)

 + 2020 12 25 플레이어 구현 - 1 (움직임 구현 완료, 카메라 부착 위치 로컬포지션 확인, 트레일 추가 필요)

 + 2020 12 26 플레이어 구현 - 2 (카메라 위치에 사용할 플레이어 로컬행렬을 구하기 위해서, Observer를 통하여 플레이어의 Transform 포인터를 건네받는 테스트 완료)
 
 + 2020 12 27 플레이어 구현 - 3 (카메라 위치에 사용할 test 메시들을 상하좌우NM키로 출력, 조정하기 완료, 그 자리에 한번 넣어보며 수정하는 툴 제작 필요)

 + 2020 12 28 플레이어 구현 - 4 (카메라 구현 완료, 카메라가 플레이어에 의존해 Slerp를 시키는거 필요, 트레일 제작 시작)

 + 2020 12 29 기본 프레임워크 제작 - 7 (텍스쳐 불러오기 완료, Sprite로 한번 출력해보기, 트레일 이식 필요)

 + 2020 12 30 기본 프레임워크 제작 - 8 (트레일 UV 이식 완료, 프로젝트에 넣고 테스트 필요)
 
 + 2020 12 31 기본 프레임워크 제작 - 9 (트레일 제작 완료, 트레일 + 텍스쳐 출력 확인 필요)
 
 + 2021 1 1 플레이어 구현 - 5 (카메라 Slerp, 트레일 + 텍스쳐 출력 확인 완료, UI 배치, 메모리 누수 + 런타임 버그 확인 필요)
 
 + 2021 1 2 UI 구현 - 1 (UI 출력 확인, 플레이어 forward를 따라가는 AimPoint 배치 설계 필요)
 
 + 2021 1 3 UI 구현 - 2 (AimPoint 배치 구현 완료, Sprite로 교체 및 HP Sprite 배치 & 출력 필요)
 
 + 2021 1 4 UI 구현 - 3 (HP 구현 완료, 몬스터 모델링 리깅 후 간단한 몬스터 & 플레이어 총 + 이펙트 제작 필요)
 
 + 2021 1 5 몬스터 구현 - 1 (몬스터 1 모델링 완료, 몬스터 1 제작, 이펙트 제작, NDC SCS 확인 필요)
 
 + 2021 1 6 플레이어 구현 - 6 (Raycast 완료, 본 출력 오류, 플레이어 forward가 정말 forward로 가는지 확인 필요)
 
 + 2021 1 7 기본 프레임워크 제작 - 10 (Raycast 수정 완료, 이펙트 매니저 제작, 싱글톤들 한번에 해제하는 구조 설계 필요)
 
 + 2021 1 8 기본 프레임워크 제작 - 11 (Effect 제작 완료, 다이나믹메시 오류 확인, 셰이더 빛반사 필요)
 
 + 2021 1 9 기본 프레임워크 제작 - 12 (Collider 제작중, 다이나믹메시 오류 확인, 미사일 제작 필요)
 
 + 2021 1 10 기본 프레임워크 제작 - 13 (Collider 제작 완료, 미사일 모델링 & 제작 시작)
 
 + 2021 1 11 플레이어 구현 - 7 (미사일 제작중, 싱글톤으로 template Create객체<Missile>() 하는거 만들어야함)
 
 + 2021 1 12 기본 프레임워크 제작 - 14 (ObjectManager 구현 완료, 미사일 제작 & 다이나믹 메시 오류 확인 필요)
 
 + 2021 1 14 플레이어 구현 - 8 (미사일 제작중)
 
 + 2021 1 23 기본 프레임워크 제작 - 15 (CollisionManager 변경 중, Raycast를 CollisionManager 속에 붙이기, DynamicUI Release되기 직전에 텍스쳐 Alpha 오류 확인 필요)
 
 + 2021 1 25 플레이어 구현 - 9 (미사일 구현 완료, 다이나믹메시 오류 확인 완료)
 
 + 2021 1 27 플레이어 구현 - 10 (미사일 트레일, 간단한 셰이더 제작, 마우스 & 스피어 맞은 곳 리턴 (이펙트를 위해서), 맞은 곳과 플레이어 dir를 내적해서 예외처리 필요)
 
 + 2021 1 28 플레이어 구현 - 11 (미사일 트레일 완료, 내적 완료, 맞은 곳 리턴, 몬스터 제작 필요)
 
 + 2021 1 29 몬스터 구현 - 2 (패턴 설계, 몬스터 총알, 플레이어 미사일 Lock 설계 필요)

 + 2021 1 30 기본 프레임워크 제작 - 16 (이펙트매니저, 콜리전매니저 다듬기 완료, 맞은 곳의 이펙트를 어떻게 띄울지 생각해보기)
 
 + 2021 1 31 UI 구현 - 4 (미사일 록 UI 제작중, 몬스터 패턴 설계 후 제작 필요)
 
 + 2021 2 1 UI 구현 - 5 (미사일 록 UI 제작 완료, 몬스터 패턴 설계 후 제작 시작)
 
 + 2021 2 2 몬스터 구현 - 3 (몬스터 패턴 설계 완료, 스피어몬스터 제작 시작)
