```C++
int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());

    while (true)
    {
        if (scoville.size() == 1) return -1;

        int first, second;
        first = scoville[0];
        second = scoville[1];

        if (first > K)
            break;

        scoville.erase(scoville.begin(), scoville.begin() + 2);
        first += second * 2;

        scoville.push_back(first);

        sort(scoville.begin(), scoville.end());
        answer++;
    }

    return answer;
}
```
실패, 효율성도 실패
```C++
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scovilleQueue(scoville.begin(), scoville.end());
    
    while (true)
    {
        if (scovilleQueue.size() == 1)
        {
            if (scovilleQueue.top() < K)
                return -1;

            break;
        }
        int first = scovilleQueue.top();
        if (first >= K) break;

        scovilleQueue.pop();
        int second = scovilleQueue.top();
        scovilleQueue.pop();

        first += second * 2;
        scovilleQueue.push(first);

        answer++;
    }

    return answer;
}
```
우선순위 큐([[Priority Queue]])를 사용한 구현