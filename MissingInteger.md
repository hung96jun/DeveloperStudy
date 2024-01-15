- 문제
```
This is a demo task.

Write a function:

> int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an ****efficient**** algorithm for the following assumptions:

> - N is an integer within the range [1..100,000];
> - each element of array A is an integer within the range [−1,000,000..1,000,000].
```

- 답
```C++
int solution(vector<int>& A)
{
    sort(A.begin(), A.end());
    vector<int>::iterator it = unique(A.begin(), A.end());
    A.erase(it, A.end());

    if (A[0] > 1 || *(A.end() - 1) <  1)
        return 1;

    int result = 1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] < 1)
            continue;

        if (result != A[i])
            break;

        result++;
    }

    return result;
}
```
문제를 차분히 읽고 집중해서 하나하나 풀면 금방 끝나는 문제이다.