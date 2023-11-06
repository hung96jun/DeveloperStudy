- Priorities : 정렬되지 않은 우선순위들의 배열
- location : 정렬되지 않은 상태의 우선순위 배열에서 찾을 index값
- 우선순위는 내림차순으로 높은수가 먼저 호출되어야 한다.
- 현재 실행될 프로세스가 우선순위가 낮을 경우 가장 우선순위가 높은 프로세스가 호출되어야 한다.
	![[Pasted image 20231026041138.png]]
- 위 그림과 같이 우선순위가 높은것이 먼저 호출되고 그 앞에 있는 프로세스들은 통으로 뒤로 이동된다.
- 이렇게 되서 location에 있던 프로세스가 몇 번째에 호출되는지에 대한 문제이다.
```C++
int compair(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return -1;
    else if (*(int*)a < *(int*)b)
        return 1;
    else
        return 0;
}

int solution(vector<int> priorities, int location)
{
    int answer = 1;
    queue<int> priorityQueue;
    vector<int> priority;
    int targetNum = priorities[location];
    int target = location;
    for (int i = 0; i < priorities.size(); i++)
    {
        // 큐에 저장
        priorityQueue.push(priorities[i]);
        // 우선순위 세팅을 위해 저장
        priority.push_back(priorities[i]);
    }

    // 내림차순 정렬
    qsort(&(priority[0]), priority.size(), sizeof(int), compair);

    int i = 0;
    while (true)
    {
        // 현재 실행되는 우선순위가 targetNum보다 높은 경우
        if (targetNum < priority[i])
        {
            while (true)
            {
                int process = priorityQueue.front();
                priorityQueue.pop();

                // 무조건 실행
                {
                    // target이 맨 뒤로 갈 경우
                    if (target == 0)
                        target = priorityQueue.size();
                    // target이 앞으로 땡겨지는 경우
                    else
                        target--;
                }

                // 현재 실행되야 하는 프로세스인 경우
                if (priority[i] == process)
                {
                    answer++;
                    break;
                }
                // 현재 실행되야 하는 프로세스가 아닌 경우 Queue의 맨뒤로 이동
                else
                {
                    priorityQueue.push(process);
                }
            }
        }
        // 현재 실행되는 프로세스의 우선순위가 targetNum인 경우
        else
        {
            while (true)
            {
                int process = priorityQueue.front();
                // target이 되는 프로세스가 뒤에 있는 경우
                if (target > 0)
                {
                    // 프로세스가 실행되는 경우
                    if (process == targetNum)
                    {
                        priorityQueue.pop();
                        target--;
                        answer++;
                    }
                    // 프로세스 우선순위가 다른 경우 버림
                    else
                    {
                        priorityQueue.pop();
                        target--;
                    }
                }
                else
                    return answer;
            }
        }

        i++;
    }

    return answer;
}
```
걸린 시간 약 1시간 반