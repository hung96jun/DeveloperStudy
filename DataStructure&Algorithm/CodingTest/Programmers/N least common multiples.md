```C++
int solution(vector<int> arr) {
    int answer = 1;
    sort(arr.begin(), arr.end());
    int a, b, c;
    b = arr[0];
    int beforeValue = b;

    for (int i = 1; i < arr.size(); i++)
    {
        a = arr[i];
        b = beforeValue;

        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }

        beforeValue = beforeValue * arr[i] / a;
    }

    answer = beforeValue;

    return answer;
}
```
복수 값의 최소 공배수는 순차적으로 2개씩 연산하면 되고, 유클리드 호제법으로 구한 최대 공약수와 기존 값 2개를 곱한 값을 나누면 최소 공배수가 나오는 원리를 사용하여 풀이.

```C++
int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    return answer;
}
```
원리는 동일함. 하지만 재귀를 사용하여 코드가 간결하고 짧아짐. 시간 복잡도는 동일(소수점 2번째 자리수까지밖에 확인이 안되어 동일하다 생각)하지만 공간복잡도는 훨씬 이득이다.