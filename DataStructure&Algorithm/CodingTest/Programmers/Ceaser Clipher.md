```C++
string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            continue;
        }

        bool check = s[i] >= 65 && s[i] <= 90;  // 대문자 체크
        if (check == true && s[i] + n > 90)
            s[i] = s[i] - 26;
        else if (check == false && s[i] + n > 122)
            s[i] = s[i] - 26;

        char temp = s[i] + n;

        answer += temp;

    }

    return answer;
}
```

```C++
string caesar(string s, int n)
{
    string answer = "";

  for( int i = 0 ; i < s.length() ; i++)
  {
    if ( s[i] == ' ') 
    {
      answer += s[i];
    }
    else
    {
      int start = (s[i] >= 'a')? 'a' : 'A';
      answer += start + (s[i]-start + n)%26;
    }
  }

    return answer;
}
```
다른 사람 풀이. 원리는 비슷하나, 기존 값에서 더한 값의 문자 제한 값을 나눔 나머지 값으로 더하여 결과값을 나타내 더 깔끔하게 처리했다.