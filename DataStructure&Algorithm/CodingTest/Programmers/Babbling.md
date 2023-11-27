- 주어진 문자열 배열 안에서 매개변수로 들어온 문자열 배열이 성립되면 answer++
- 주어진 문자열에서 같은 단어가 반복될 수는 없다.
- 하지만 같은 문자열이 들어올 수 있다.
```C++
int solution(vector<string> babbling) {
    int answer = 0;

    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];

        int index = -1;

        while (true)
        {
            bool check = false;         // 동일한 문자열 연속될 경우
            bool eraseCheck = false;

            for (int j = 0; j < 4; j++)
            {
                string curStr = curBabbling[j];
                size_t curIndex = str.find(curStr);
                if (curIndex != 0)
                    continue;

                if (index == j)
                {
                    check = true;
                    break;
                }

                eraseCheck = true;

                str.erase(0, curStr.size());
                index = j;
            }

            if (check == true || eraseCheck == false)
                break;

            if (str.size() == 0)
            {
                answer++;
                break;
            }
        }
    }

    return answer;
}
```
