붕대 감기는 t초동안 ㅂ붕대를 감으면서 1초마다 x만큼의 체력을 회복, t초 연속으로 붕대를 감는데 성공하면 y만큼의 체력을 추가로 회복. 최대 체력 이상 회복 불가.
- 기술 사용 중 피격시 기술 취소, 피격중 체력 회복 불가.
	- 피격이 끝나거나, 붕대 감기가 끝나고 즉시 다시 붕대 감기를 사용하며, 연속 성공 시간은 0으로 초기화
	- 피격시 정해진 피해량만큼 체력 감소. 이때, 현재 체력이 0이하가 되면 캐릭터가 죽으며 더 이상 회복 불가.
- 붕대 감기 기술의 저보, 캐릭터가 가진 최대 체력과 몬스터의 공격 패턴이 주어질 때 캐릭터가 끝까지 생존할 수 있는지
- 모든 공겨기 끝난 후 남은 체력을 반환. 사망시 -1

- 코드
```C++
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int maxHealth = health;
    int stage = 0;
    int stack = 0;
    int maxStage = attacks[attacks.size() - 1][0];
    int stackCount = bandage[0];
    int pattern = 0;

    while (health > 0 && stage <= maxStage)
    {
        int heal = bandage[1];

        if (stack >= stackCount)
            heal += bandage[2];

        if (stage == attacks[pattern][0])
        {
            heal = 0;
            heal -= attacks[pattern][1];
            ++pattern;
            stack = 0;
        }

        health += heal;
        if (health >= maxHealth)
            health = maxHealth;

        ++stage;
        ++stack;
    }

    if (health <= 0)
        return -1;

    return health;
}
```
- 16, 18, 20 실패, 원인 모름