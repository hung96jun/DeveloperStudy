- n : 진수
- t : 반환할 문자열의 사이즈
- m : 게임에 참가하는 인원
- p : 순서
- n진수로 369게임을 하는것과 비슷하다. 자신의 순서가 돌아왔을 때 단 하나의 수를 말하는것으로 자신이 말할 수를 t개만큼 반환하는 문제이다.
```C++
string GetNumber(int n, int maxIndex)
{
    char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    string result = "";

    int num = 0;
    int temp = num;

    string nNumber = "";

    while (maxIndex >= 0)
    {
        int index = temp % n;
        temp = temp / n;
        nNumber += arr[index];

        if (temp == 0)
        {
            num++;
            temp = num;
            maxIndex -= nNumber.size();

            for (int i = nNumber.size() - 1; i >= 0; i--)
            {
                result += nNumber[i];
            }

            nNumber = "";            
        }
    }

    return result;
}

string solution(int n, int t, int m, int p) 
{
    string answer = "";

    string temp = GetNumber(n, t * (m + 1));
    int count = 1;
    int index = 0;
    
    while (answer.size() < t)
    {
        if (count == p)
            answer += temp[index];

        if (count == m)
            count = 1;

        else
            ++count;

        ++index;
    }

    return answer;
}
```
ex) 2진수일때 : 0 1 1 0 1 1 1 0 0 1 0 1 1 1 0 1 1 1 1 0 0 0에서 자신이 1번이고 3명이서 한다고 했을 때, (0, 3, 6, 9, 12, 15)번째의 수 즉(001111)이 반환되어야 한다는 것이다.