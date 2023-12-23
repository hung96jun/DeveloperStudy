```C++
int solution(vector<int> number) {
    int answer = 0;

    for (int i = 0; i < number.size(); i++)
    {
        int value = 0;
        value += number[i];

        for (int j = i + 1; j < number.size(); j++)
        {
            value += number[j];

            for (int k = j + 1; k < number.size(); k++)
            {
                value += number[k];

                if (value == 0)
                    answer++;

                value -= number[k];
            }

            value -= number[j];
        }
    }

    return answer;
}
```
처음에는 완탐으로 모든 경우의 수를 구하려고 했었지만 문제에서 3개의 값을 더했을때라는 제한이 있었다. 문제를 천천히 정확히 읽고 넘어가야 한다.

```C++
int solution(vector<int> number) {
    int answer = 0;
    for (int i = 0; i < number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            for (int k = j + 1; k < number.size(); k++)
                if (number[i]+number[j]+number[k] == 0) answer++;
        }
    }
    return answer;
}
```
다른 사람의 풀이이다. 동일한 방식으로 문제를 풀었지만 변수를 생성해서 하는 것보다는 그냥 값들만 연산시켜 결과를 도출시키는 방법이 더 깔끔하게 처리된다.