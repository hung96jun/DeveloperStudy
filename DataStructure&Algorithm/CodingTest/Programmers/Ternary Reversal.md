```C++
int solution(int n) {
    int answer = 0;
    string ternary = "";

    while (n > 0)
    {
        ternary = to_string(n % 3) + ternary;
        n /= 3;
    }

    for (int i = ternary.size() - 1; i >= 0; i--)
    {
        int value = 0;
        if (ternary[i] == '1')
            value = 1;
        else if (ternary[i] == '2')
            value = 2;

        answer += pow(3, i) * value;
    }

    return answer;
}
```