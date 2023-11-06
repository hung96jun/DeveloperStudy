- number : 최대 수
- limit : 최대 약수의 갯수
- power : 최대 약수의 갯수가 넘어갈경우 해당 갯수를 power값으로 대체
- 1~n까지의 수에서 약수의 갯수가 몇개인지 구하는 문제로, 간단한 문제지만 <font color="red">TimeOver를 유도</font>한다.
```C++
int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int divideCount = 0;
        int last = 0;

        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
                divideCount += 2;

            if (j * j == i)
                last = j;
        }

        // 제곱근 확인
        if (last * last == i)
        {
            divideCount--;
        }

        if (divideCount > limit)
            divideCount = power;

        answer += divideCount;
    }

    return answer;
}
```
- 제곱근을 확인할때 (float)sqrt(i)와 (int)sqrt(i)를 비교했었지만 i값이 4여도 해당 조건문에 적중하지 않아 다른 방식(last * last == i)을 사용
- TimeOver를 방지하기 위해 약수의 최대값이 n의 제곱근을 넘지 않는다는 점을 이용