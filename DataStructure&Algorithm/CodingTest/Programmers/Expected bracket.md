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

```C++
int solution(int n, int a, int b)
{
	int result = 0;

	while (a != b)
	{
		a++; b++;

		a /= 2;
		b /= 2;

		result++;
	}

	return result;
}
```
1과 2가 경기를 한다고 했을 때, 둘중 한팀은 이기고 1팀으로 올라가게 된다. 이때  2나누기 연산을 하게 되면 1은 0이, 2는 1이, 3은 1이 되는 원리를 사용하여 +1 후 / 2를 하여 한 루프에 한 경기를 하는 식으로 구현했다.
다른 사람 풀이도 비슷한 원리이다.