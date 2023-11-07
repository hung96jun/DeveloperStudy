- n의 양수값이 들어왔을 때 k진수로 변환하여 나온 값들중에 0을 기준으로 수를 나눠서 해당 수가 소수일경우 answer를 증가
```C++
string conversion(int n, int k)
{
    int curNum = n;
    string result = "";

    while (curNum > 0)
    {
        int value = curNum % k;
        result += to_string(value);
        curNum /= k;
    }

    reverse(result.begin(), result.end());

    return result;
}

bool primNumber(long long n)
{
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string number = conversion(n, k);
    vector<int> values;

    string value;

    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] != '0')
        {
            value += number[i];
        }

        if (value.size() > 0 && (number[i] == '0' || i == number.size() - 1))
        {
            long long temp = stol(value.c_str());
            
            if (temp > 1 && primNumber(temp) == true)
                answer++;

            value = "";
        }
    }

    return answer;
}
```
1번 테스트 케이스가 실패가 나와서 temp의 자료형을 int형에서 long long형으로 바꿨을 때 성공. 즉, int형보다 큰 값이 나와서 실패가 됬던것