price는 count될때마다 count배수만큼 증가, money가 부족할 경우 부족한 값을 반환, 아닐 경우 0을 반환
```C++
long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long base = price + (price * count);
    answer = base * (count / 2);

    if (count % 2 == 1)
    {
        answer += price * (count / 2 + 1);
    }

    return answer > money ? (long long)answer - money : 0;
}
```
base의 자료형을 int형으로 했다가 테스트 케이스 몇개 실패하여 long long형으로 수정 후 정상 완료