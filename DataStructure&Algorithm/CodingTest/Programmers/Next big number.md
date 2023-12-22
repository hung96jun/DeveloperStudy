자연수 n이 주어졌을 때 다음 조건을 충족하는 다음 큰 수를 구하는 문제
- n의 다음 큰 수는 n을 2진수로 변환했을 때 1의 개수가 동일해야 한다.
```C++
string convertBinary(int n, int& count)
{
    string result;

    while (n > 0)
    {
        if (n % 2 == 1)
            count++;

        result = to_string(n % 2) + result;
        n /= 2;
    }

    return result;
}

int solution(int n) 
{
    int answer = 0;
    int count = 0;
    string target = convertBinary(n, count);
    int value = n;

    while (true)
    {
        value++;
        int valueCount = 0;
        string valueStr = convertBinary(value, valueCount);

        if (count == valueCount)
        {
            answer = value;
            break;
        }
    }

    return answer;
}
```
위 코드로는 효율성도 정상적으로 통과가 된다.

```C++
int solution(int n) 
{
    int num = bitset<20>(n).count();

    while (bitset<20>(++n).count() != num);
    return n;
}
```
bitset을 사용한 풀이

bitset을 사용한 풀이가 더 효율적이고 깔끔하다.