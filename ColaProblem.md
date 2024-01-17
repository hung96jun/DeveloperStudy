n개의 콜라가 있을 때 a개의 콜라를 반납하면 b개의 콜라를 준다. 이때 받을 수 있는 콜라의 개수는?
```C++
int solution(int a, int b, int n) 
{
    int result = 0;

    while (n >= a)
    {
        int temp = n % a;
        n = (n / a) * b;
        result += n;
        n += temp;
    }

    return result;
}
```