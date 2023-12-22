```C++
string solution(string s) {
    string answer = "";
    int index = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            answer += ' ';
            continue;
        }

        ++index;

        if (index % 2 == 1)
            answer += toupper(s[i]);
        else if (index % 2 == 0)
            answer += tolower(s[i]);
    }

    return answer;
}
```
문제를 잘못읽어서 실수했었던 케이스. 문제를 제대로 이해하고 풀어야함