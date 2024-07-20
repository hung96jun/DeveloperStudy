이번 달까지 선물을 주고 받은 기록을 바탕으로 다음 달에 가장 많은 선물을 받는 사람은 몇 개를 받는지를 구하는 문제
- 두 사람이 선물을 주고 받은 기록이 있다면, 이번 달 까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받는다.
	- a가 b에게 5번 선물, b가 a에게 3번 선물 -> 다음달엔 a가 b에게 선물을 하나 받는다.
- 두 사람이 선물을 주고 받은 기록이 하나도 없거나 주고 받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받는다.
	- 선물 지수는 이번 달 까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값이다.
	- 예를 들어 a가 친구들에게 준 선물이 3개고 받은 선물이 10개라면 a의 선물 지수는 -7. 이런식으로 지수가 계산이 되고, 이번 달 주고 받은 선물 개수가 정확히 같거나 없을 경우 다음달에 선물 지수가 높은 사람이 선물을 하나 더 받는다.
	- 만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고 받지 않는다.

- 코드
```C++
int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    vector<vector<int>> score;
    map<string, int> index;
    vector<int> temp;

    temp.resize(friends.size());
    score.resize(friends.size());

    // 초기화
    for (int i = 0; i < friends.size(); i++)
    {
        index.insert(pair<string, int>(friends[i], i));
        score[i].resize(friends.size());
    }

    // 상대에게 준 선물 연산, 지수 연산
    for (int i = 0; i < gifts.size(); i++)
    {
        int my, you;
        int size = gifts[i].find(' ');
        my = index[gifts[i].substr(0, size)];
        you = index[gifts[i].substr(size + 1)];

        score[my][you]++;
        temp[my]++;
        temp[you]--;
    }

    // 결과값 도출
    for (int i = 0; i < friends.size(); i++)
    {
        int value = 0;
        for (int j = 0; j < friends.size(); j++)
        {
            int myGift, youGift;
            myGift = score[i][j];
            youGift = score[j][i];

            if (myGift > youGift)
                value++;
            else if (myGift == youGift && temp[i] > temp[j])
                value++;
        }

        if (answer < value)
            answer = value;
    }

    return answer;
}
```