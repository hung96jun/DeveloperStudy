```C++
int solution(int num) {
    int answer = 0;
    long long value = num;

    while (true)
    {
        if (answer == 500)
            return -1;

        if (value != 1)
            value & 1 ? (value = value * 3 + 1) : (value = value / 2);
        else
            break;

        answer++;
    }

    return answer;
}
```
문제 자체는 어려운 문제가 아니었지만, 연산 도중 num값이 int의 허용 범위를 넘어가 오버 플로우가 발생. 그 과정에서 연산 값이 잘린값으로 연산이 계속되어 626331 테스트 케이스가 -1값을 반환해야 하는데 488이란 값을 반환하는 현상이 발생함
