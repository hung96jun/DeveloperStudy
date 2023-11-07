- N : 최대 라운드 수(answer의 index수라고 볼 수 있음)
- stages : 유저별 클리어한 라운드의 배열
- 실패율을 연산하여 실패율이 높은 순으로 라운드를 vector에 입력하여 반환
```C++
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> rounds;
    int userCount = stages.size();

    for (int i = 0; i < stages.size(); i++)
    {
        if (rounds.count(stages[i]) == 0)
        {
            pair<int, int> round;
            round.first = stages[i];
            round.second = 1;

            rounds.insert(round);
        }

        else
            rounds[stages[i]]++;
    }

    vector<float> rates;
    for (int i = 1; i <= N; i++)
    {
        // 스테이지에 머무는 사람이 없을 경우
        if (rounds.count(i) == 0)
        {
            rates.push_back(0);
        }

        else
        {
            int curRoundUser = rounds[i];
            float rate = (float)curRoundUser / (float)userCount;
            rates.push_back(rate);
            userCount -= curRoundUser;
        }
    }
    vector<float> temp;
    temp = rates;
    sort(temp.begin(), temp.end());

    for (int i = rates.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < rates.size(); j++)
        {
            if (rates[j] == -1) continue;
            if (temp[i] == rates[j])
            {
                rates[j] = -1;
                answer.push_back(j + 1);
            }
        }
    }

    return answer;
}
```
문제 해결은 됐지만 최적화가 필요할 것 같다.