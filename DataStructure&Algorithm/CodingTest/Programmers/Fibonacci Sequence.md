n 번째 피보나치 수열을 1234567로 나눈 나머지 값을 반환하는 문제
```C++
void fibonacci(int a, int b, int n, int& value)
{
    if (n == 0)
    {
        value = a + b;
        return;
    }

    fibonacci(b % 1234567, (b + a) % 1234567, n - 1, value);
}

int solution(int n) {
    int answer = 0;

    fibonacci(0, 1, n - 2, answer);

    return answer % 1234567;
}
```
처음 그냥 피보나치 수열값을 구한 후 나눔나머지 값을 반환했을 때 에러가 발생. 이유는 피보나치 수열의 47번째 수는 2971215073으로 int형의 범위를 넘어 오버플로우가 발생했기 때문.![[Pasted image 20231223202406.png]]
힌트를 활용하여 수정 후 정상 완료

```C++
typedef vector<vector<long long>> matrix;

matrix operator* (matrix& a, matrix& b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

long long fibonacci(int n)
{
    matrix res = { {1, 0},{0, 1} };
    matrix fib = { {1, 1},{1, 0} };
    while (n) {
        if (n % 2 == 1) res = res * fib;
        fib = fib * fib;
        n *= 0.5;
    }
    return res[0][1];
}

int solution(int n) {
    
    return fibonacci(n);
}
```
다른 사람의 문제풀이. 코드 자체는 복잡하지만 시간복잡도는 월등히 빠르다.
하지만 결과값이 너무 다르게 나오는것으로 보아 문제가 개편되어 그런것 같다.