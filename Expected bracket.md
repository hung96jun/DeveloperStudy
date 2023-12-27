```C++
int solution(int n, int a, int b)
{
    int answer = 0;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b % 2 == 1)
		b++;
	int interval = b - a;
	
	while (interval > 0)
	{
		interval = interval / 2;
		answer++;
	}

    return answer;
}
```
a와 b의 간격을 구하고 그 간격이 2의 몇승인지 구하는 방법으로 구현. 테스트 케이스 40% 실패
문제가 되는 경우는 16, 17같은 경우이다. 이 경우 5값이 나와야하는데 차이값의 승수를 구하는 것이라 1값이 나온다.