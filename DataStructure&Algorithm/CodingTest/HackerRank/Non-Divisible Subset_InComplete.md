- s : int형의 배열
- k : int형 값
- s의 값을 각각 1개씩 더하여 k의 배수가 나오지 않는 경우의 정수 갯수를 반환

- 배열의 값 2개를 더했을 때 k값으로 나누어 지지 않는 총 갯수를 구하는 문제인데 잘 이해가 안된다.
- 배열의 값들을 전부 k의 나눔 나머지 값으로 배열을 만든다. 즉, 0 ~ k-1까지의 값이 키값이 되고(나눔 나머지 값들이), value값으로는 배열에서 k의 나눔 나머지 연산을 했을때의 갯수가 된다.
	- 만일 key값이 0~5까지 즉, k의 값이 6일 경우에 대칭에 해당하는 key값들 1+5, 2+4, 3+3에 해당하는 값들은 나눔 나머지가 0이 되기 때문에 해당하는 key의 갯수중에서 큰 값만 고르면 된다.
	- 나눔 나머지가 0인 경우 즉 key = 0에 해당하는 값은 <font color="red">특별한데</font> 1개만 카운팅한다.(6, 12, 18 등이 있어도 1개만) 이유는 3 + 3을 했을때는 어떻게 조합해도 무조건 0으로 떨어지기 때문이다<font color="red">(?)</font>
	- 한가지 더 <font color="red">특별한</font>경우는 <font color="red">짝수</font>인 경우인데, k/2 + k/2 = k이기 때문에 이것도 최대 1개만 사용할 수 있다.
```C++
int nonDivisibleSubset(int k, vector<int> s)
{
	vector<int> s1;
	s1.resize(k);
	fill_n(s1.begin(), k, 0);

	for (int i = 0; i < s.size(); i++)
		s1[s[i] % k] += 1;

	int result = 0;

	if (k % 2 == 0)
		result = 1;

	if (s1[0] != 0)
		result += 1;

	for (int i = 1; i < (k + 1) / 2; i++)
	{
		result += max<int>(s1[k - i], s1[i]);
	}

	return result;
}
```