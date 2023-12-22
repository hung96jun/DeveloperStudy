```C++
void dps(const vector<int>& d, int index, int value, int count, const int target, int& answer)
{
    value += d[index];
    ++count;

    if (index == d.size() - 1)
    {
        if (value <= target)
        {
            if (answer < count)
                answer = count;
            return;
        }
    }

    if (value > target)
    {
        if (answer < count - 1)
            answer = count - 1;
        return;
    }

    for (int i = index + 1; i < d.size(); i++)
    {
        dps(d, i, value, count, target, answer);
    }
}

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.rbegin(), d.rend());

    for (int i = 0; i < d.size(); i++)
    {
        dps(d, i, 0, 0, budget, answer);
    }

    return answer;
}
```
1~6까지는 정상 성공 결과가 나오지만 7번부터는 시간초과가 나옴
내림차순으로 정렬을 했지만 그래도 시간초과

```C++
int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    int value = 0;
    for (int i = 0; i < d.size(); i++)
    {
        value += d[i];
        if (value > budget)
            break;
        answer++;
    }

    return answer;
}
```
문제를 너무 어렵게 생각해서 깊이우선탐색 알고리즘을 사용했던게 문제. 오른차순으로 정렬후 카운팅하면 저절로 작은 수들부터 들어가게 되니 첫 반복문으로 문제가 해결되는 것이었다.
