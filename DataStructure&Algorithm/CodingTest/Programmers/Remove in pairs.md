연속된 문자가 동일할경우 제거하는 방식으로 모든 문자가 제거되면 1을 아니면 0을 반환하는 문제
```C++
int solution(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(s.begin() + i);
            s.erase(s.begin() + i);
            i < 1 ? i -= 1 : i -= 2;
        }
    }

    return s.size() > 0 ? 1 : 0;
}
```
정상적으로 동작하지만 효율성에서 떨어진다.
```C++
int solution(string s)
{
    stack<char> strStack;

    for (int i = 0; i < s.size(); i++)
    {
        char top = '~';
        if (strStack.size() == 0)
            strStack.push(s[i]);
        else
        {
            top = strStack.top();

            if (top == s[i])
                strStack.pop();
            else if (top != s[i])
                strStack.push(s[i]);
        }
    }

    return strStack.size() == 0;
}
```
stack을 이용한 풀이. 효율성도 훨씬 올라갔다.