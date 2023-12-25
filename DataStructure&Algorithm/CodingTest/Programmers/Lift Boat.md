```C++
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    for (int i = 0; i <= people.size() / 2; i++)
    {
        int firstPeople = people[i];
        int pairIndex = -1;

        for (int j = people.size() - 1; j > i; j--)
        {
            int secondPeople = people[j];

            if (firstPeople + secondPeople <= 100)
            {
                pairIndex = j;
                break;
            }
        }

        if (pairIndex == -1)
            continue;

        people.erase(people.begin() + pairIndex);
        people.erase(people.begin() + i);
        i--;
        answer++;
    }

    answer += people.size();

    return answer;
}
```
테스트 케이스 몇개만 통과, 효율성 전부 시간초과

```C++
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = people.size() - 1; j > i; j--)
        {
            if (people[i] + people[j] <= limit)
            {
                people.erase(people.begin() + j);
                people.erase(people.begin() + i);

                i--;
                answer++;
                break;
            }
        }
    }

    answer += people.size();

    return answer;
}
```
테스트케이스 전부 통과, 효율성 전부 시간초과

```C++
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i, j;
    i = 0;
    j = people.size() - 1;

    while (i < j)
    {
        for (; j > i; j--)
        {
            if (people[i] + people[j] <= limit)
            {
                answer++;
                j--;
                break;
            }
        }

        i++;
    }

    answer = answer + (people.size() - (answer * 2));

    return answer;
}
```
위와 비슷한 방식과 환형 큐의 이론을 합쳐서 구현. 성공.