s를 n개로 나눈 값의 합이 제일 큰 집합을 오름차순으로 반환하는 문제
```C++
vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) return { -1 };
    int value = s / n;
    int rest = s % n;
    answer.resize(n);
    fill_n(answer.begin(), answer.size(), value);

    for (int i = answer.size() - 1; i >= 0; i--)
    {
        if (rest <= 0) break;

        answer[i] += 1;
        rest--;
    }

    return answer;
}
```
