- n : 나뉜 section의 총 갯수
- m : 페인트 롤러의 최대 길이
- section : 칠해야하는 section의 index
- 칠해야 하는 section을 m크기의 페인트 롤러를 사용했을 때 최소 몇번으로 칠할 수 있는지 구하는 문제
```C++
int solution(int n, int m, vector<int> section) 
{
    int answer = 0;

    int leftover = m;
    int start = 0;
    int end = 0;

    for (int i = 0; i < section.size(); i++)
    {
        start = section[i];

        for (int j = i + 1; j < section.size(); j++)
        {
            end = j;

            if (section[end] - start >= leftover)
            {
                end = j - 1;
                break;
            }
            else if (section[end] - start == leftover - 1)
            {
                end = j;
                break;
            }
        }

        answer++;

        if (section.size() <= 1)
            break;

        section.erase(section.begin(), section.begin() + end + 1);
        i--;
    }

    return answer;
}
```
