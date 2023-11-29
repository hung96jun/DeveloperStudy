작업은 1시간에 1만큼 할 수있다.
작업 피로도는 w * w로 작업의 제곱이다.
- works : 남은 작업량 들
- n : 작업 시간
이 문제의 요점은 최대한 높은 값을 낮추어 작업량들의 밸런스를 맞추는것 같다.
```C++
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> queue;
    
    for (int a : works)
    {
        queue.push(a);
    }

    for (int i = 0; i < n; i++)
    {
        int work = queue.top();
        if (work == 0) break;        
        queue.pop();
        work -= 1;
        queue.push(work);
    }

    int size = queue.size();
    for (int i = 0; i < size; i++)
    {
        int work = queue.top();
        queue.pop();
        answer += work * work;
    }

    return answer;
}
```
우선순위큐(priority queue)를 사용한 풀이. 우선순위 큐의 top 호출했을 시 0이 나왔다는 것은 제일 큰 값이 0이기 때문에 반복문을 탈출하여 필요없는 연산을 줄임