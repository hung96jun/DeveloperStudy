```C++
void function(const int distance, const int value, long long& result)
{
    int remaining = distance - value;
    if (remaining < 0)
        return;

    if (remaining == 0)
    {
        ++result;
        return;
    }

    for (int i = 1; i <= 2; i++)
    {
        function(remaining, i, result);
    }
}

long long solution(int n) {
    long long answer = 0;

    for (int i = 1; i <= 2; i++)
    {
        function(n, i, answer);
    }

    return answer % 1234567;
}
```
완전 탐색을 사용한 방법. long long형 자료형이 나올때부터 n값이 큰 수가 나올 가능성이 있다고 생각했다. 실제로 시간초과되는 테스트 케이스를 제외하고는 전부 통과.
문제는 어떻게 재귀의 횟수를 줄이는가이다.
