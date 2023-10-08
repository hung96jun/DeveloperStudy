주어진 매개변수에서 a에 대한 공배수와, b에 대한 공약수 중에서 동일한 값이 몇 개인지 추출하는 문제
- 유클리드 알고리즘([[Euclidean-Algorithm]])

```C++
int compair(const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;

    if ((*x) > (*y))
        return 1;
    else if ((*x) < (*y))
        return -1;

    return 0;
}

int GCD(const int high, const int low)
{
    int a, b, c = 0;
    a = high;
    b = low;

    if (a < b)
    {
        c = a;
        a = b;
        b = c;

        c = 0;
    }

    while (b != 0)
    {
        c =  a % b;
        a = b;
        b = c;
    }

    return a;
}

int LowMultiple(const int high, const int low)
{
    return (high * low) / GCD(high, low);
}

int GetTotalX(vector<int> multiple, vector<int> divisor)
{
    int result = 0;

    // 정렬
    qsort(&multiple[0], multiple.size(), sizeof(int), compair);
    qsort(&divisor[0], divisor.size(), sizeof(int), compair);

    int multipleSize = multiple.size();
    int divisorSize = divisor.size();

    int lowMultiple = multiple[0];
    if (multipleSize > 1)
    {
        for (int i = 1; i < multipleSize; i++)
        {
            // 최소 공배수
            lowMultiple = LowMultiple(multiple[i], lowMultiple);
        }
    }

    int highDivisor = divisor[0];
    if (divisorSize > 1)
    {
        for (int i = 1; i < divisorSize; i++)
        {
            // 최대 공약수
            highDivisor = GCD(divisor[i], highDivisor);
        }
    }

    int index = 1;
    while (true)
    {
        int value = lowMultiple * index;
        if (value > highDivisor)
            break;

        if(highDivisor % value == 0)
            ++result;

        ++index;
    }

    return result;
}
```
