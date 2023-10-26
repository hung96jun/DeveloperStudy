- 주어진 1~n까지의 수 사이에서 소수가 몇개인지 반환하는 문제
```C++
int solution(int n) {
    int answer = 0;

    for (int i = 2; i < n; i++)
    {
        bool check = true;

        int sqrtNum = sqrt(i);

        for (int j = 2; j < sqrt(i); j++)
        {
            if (i % j == 0)
            {
                check = false;
                break;
            }
        }

        if (check == true)
            answer++;
    }

    return answer;
}
```
위 방법은 문제는 해결됬지만 효율성 테스트에서 전부 실패가 나왔다.
- 에라토스테너스의 채
	- 수학자 에라토스테네스가 만들어낸 <font color="red">소수를 찾는</font>방법
	- f(x) = x / 1p(x)의 수열을 가지고 만든 공식
```C++
int solution(int n)
{
	int answer = 1;		// add to 2 number

	cout << "2, ";
	for (int i = 3; i <= n; i += 2)
	{
		if (i == 3 || i == 5 || i == 7)
		{
			answer++;
			cout << i << ", ";
			continue;
		}

		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
			continue;

		cout << i << ", ";
		answer++;
	}

	return answer;
}
```
결과적으로 위 코드는 실패했다. 이유는 에라토스테네의 채같은경우 n^2의 수까지밖에 판별을 못한다. 위의 코드 같은경우 소수 7까지 판별했으니 7보다 큰 11의 배수같은경우 소수 판별을 하지 못하기 때문에 실패하게 된다.
```C++
int solution(int n)
{
	int answer = 1;		// add to 2 number

	vector<int> primNums;

	primNums.push_back(2);
	for (int i = 3; i <= n; i += 2)
	{
		if (i == 3 || i == 5 || i == 7)
		{
			answer++;
			primNums.push_back(i);
			continue;
		}

		int check = false;
		for (int primNum : primNums)
		{
			if (i % primNum == 0)
			{
				check = true;
				break;
			}
		}

		if (check == false)
		{
			answer++;
			primNums.push_back(i);
		}
	}

	return answer;
}
```
위 코드는 2번 코드의 확장으로 작성한 코드이다. 소수를 판별하면서 현재 값이 소수일경우 primNum에 추가하여 에라토스테네스의 채를 무한히 사용할 수 있는 코드이지만, 효율성이 실패했다.
```C++
int solution(int n) {
	int answer = 0;
	vector<int> nonPrims;
	nonPrims.resize(n + 1);
	fill_n(nonPrims.begin(), n + 1, 0);

	for (int i = 2; i <= n; i++)
	{
		if (nonPrims[i] == 0)
		{
			answer++;
	
			for (int j = 1; i * j <= n; j++)
			{
				nonPrims[i * j] = 1;
			}
		}
	}

	return answer;
}
```
위 코드는 에라토스테네스의 채의 완성형이다. 
- vector를 사용하여 n만큼의 크기로 resize
- resize된 vector를 0으로 초기화
- 값을 vector의 key값으로 사용하여 현재 값이 소수일경우 answer증가, 현재 값의 배수의 값들을 key값으로 1로 대입을 반복