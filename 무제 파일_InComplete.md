- 문제
```
You are given N counters, initially set to 0, and you have two possible operations on them:

> - _increase(X)_ − counter X is increased by 1,
> - _max counter_ − all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

> - if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
> - if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:

A[0] = 3 A[1] = 4 A[2] = 4 A[3] = 6 A[4] = 1 A[5] = 4 A[6] = 4

the values of the counters after each consecutive operation will be:

(0, 0, 1, 0, 0) (0, 0, 1, 1, 0) (0, 0, 1, 2, 0) (2, 2, 2, 2, 2) (3, 2, 2, 2, 2) (3, 2, 2, 3, 2) (3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.

Write a function:

> vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:

A[0] = 3 A[1] = 4 A[2] = 4 A[3] = 6 A[4] = 1 A[5] = 4 A[6] = 4

the function should return [3, 2, 2, 4, 2], as explained above.

Write an ****efficient**** algorithm for the following assumptions:

> - N and M are integers within the range [1..100,000];
> - each element of array A is an integer within the range [1..N + 1].
```

- 과정
```C++
vector<int> solution(int N, vector<int>& A) 
{
    vector<int> result;
    result.resize(N);
    fill_n(result.begin(), N, 0);

    int maxValue = 0;

    int firstIndex = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == N + 1)
        {
            fill_n(result.begin(), N, maxValue);
        }
        else
        {
            result[A[i] - 1]++;
            if (result[A[i] - 1] > maxValue)
                maxValue = result[A[i] - 1];
        }
    }

    for (int r : result)
        cout << r << ", ";

    return result;
}
```
타임 오버

```C++
vector<int> solution(int N, vector<int>& A)
{
    vector<int> result;
    result.resize(N);
    fill_n(result.begin(), N, 0);

    int maxValue = 0;

    int firstIndex = 0;
    
    // Max Count
    while (true)
    {
        vector<int>::iterator it = find(A.begin() + firstIndex, A.end(), N + 1);                    // N + 1 찾기
        if (it == A.end())                                                                          // 없을경우 반환문 탈출
        {
            fill_n(result.begin(), N, maxValue);
            break;
        }

        int beforeFirstIndex = firstIndex;                                                          // begin 범위
        firstIndex = it - A.begin();                                                                // end 범위

        int bigValue = *max_element(A.begin() + beforeFirstIndex, A.begin() + firstIndex);          // 가장 자주 나온 index 값 찾기
        maxValue += count(A.begin() + beforeFirstIndex, A.begin() + firstIndex, bigValue);          // 해당 값이 몇번 나왔는지

        firstIndex++;
    }

    // Last part
    for (int i = firstIndex; i < A.size(); i++)
        result[A[i] - 1]++;

    for (int r : result)
        cout << r << ", ";

    return result;
}
```
문제에서 N + 1의 경우 현재 값들 중 제일 큰 값으로 배열을 초기화 시킨 후 남은 연산을 계속 하는것이라 while 문에서 find와 fill_n을 사용하여 동작하게 구현했다. 하지만 똑같이 타임 오버

1번 풀이로는 오답없이 타임오버가 있지만 2번 풀이로는 타임오버 없이 오답만 있다. 
