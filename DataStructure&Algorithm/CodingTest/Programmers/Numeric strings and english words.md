숫자와 숫자를 영어로 표현하여 섞인 문자열이 매개변수로 입력. 숫자를 영어로 표현한 것들만 숫자로 변환하여 int값으로 반환하는 문제
```C++
int solution(string s) {
    string answer = "";
    map<string, int> numbers;
    numbers.insert({ "zero", 0});
    numbers.insert({"one", 1});
    numbers.insert({"two", 2});
    numbers.insert({"three", 3});
    numbers.insert({"four", 4});
    numbers.insert({"five", 5});
    numbers.insert({"six", 6});
    numbers.insert({"seven", 7});
    numbers.insert({"eight", 8});
    numbers.insert({ "nine", 9});

    for(int index = 0; index < s.size(); index++)
    {
        if (s[index] >= 48 && s[index] <= 57)
        {
            answer += s[index];
            continue;
        }

        for (pair<string, int> n : numbers)
        {
            int length = n.first.size();
            string str = s.substr(index, length);

            if (str == n.first)
            {
                answer += n.second + 48;
                index += length - 1;
                break;
            }
        }
    }

    return atoi(answer.c_str());
}
```

- 다른 사람 풀이
```C++
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
```
되게 간단하고 신기한 풀이이다. regex_replace 함수는 2번째 매개변수의 값을 3번째 매개변수의 값으로 치환 시켜주는 함수이다.
