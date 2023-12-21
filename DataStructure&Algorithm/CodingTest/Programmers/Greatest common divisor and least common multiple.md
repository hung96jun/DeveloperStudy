두 수의 최대 공약수와 최소 공배수를 구하는 문제
```C++
vector<int> solution(int n, int m) {
    vector<int> answer;

    if (n > m)
    {
        int temp = m;
        m = n;
        n = temp;
    }

    int a, b, c;
    a = n;
    b = m;

    while (a != 0)
    {
        c = b % a;
        b = a;
        a = c;
    }

    answer.push_back(b);
    answer.push_back((n * m / b));
    
    return answer;
}
```
유클리드 호제법([[Euclidean-Algorithm]])을 사용한 풀이
