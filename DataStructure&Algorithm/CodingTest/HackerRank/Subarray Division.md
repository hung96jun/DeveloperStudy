s = 정수의 배열
d = 더한 값의 합
m = 인덱스의 길이
s 배열에서 m만큼의 숫자들을 더했을때 d의 값과 동일하면 result + 1

```C++
int birthDay(vector<int> s, int d, int m)
{
	int result = 0;
	int loop = s.size() - (m - 1);
	for (int i = 0; i < loop; i++)
	{
		int temp = 0;
		for (int j = 0; j < m; j++)
		{
			temp += s[i + j];
		}

		if (temp == d)
			++result;
	}

	return result;
}
```
