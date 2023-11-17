```C++
long long solution(int a, int b) {
    long long answer = 0;
    
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a < b)
    {
        answer += a + b;
        a++;
        b--;
    }

    if (a == b)
        answer += a;

    return answer;
}
```

```C++
long long solution(int a, int b) {
    long long answer = 0;

    if (a > b) 
        a ^= b ^= a ^= b;

    answer = (long long)b * -~b / 2 - (long long)a * ~- a / 2;
    return answer;
}
```
비트 연산을 사용한 풀이

```C++
long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}
```
시그마 공식을 사용한 풀이
