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