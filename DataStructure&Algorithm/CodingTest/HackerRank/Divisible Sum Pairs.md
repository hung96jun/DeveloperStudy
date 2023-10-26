n : 배열의 element 갯수
k : 나눔 값
ar 배열의 값 2개를 합했을때 k의 배수가 되는 경우의 수를 구하는 알고리즘
(단, k의 배수이므로 k의 약수는 포함되지 않음)

```C++
int divisibleSumPairs(int n, int k, vector<int> ar)
{
	int result = 0;

	for (int i = 0; i < ar.size(); i++)
	{
		int base = ar[i];

		for (int j = i + 1; j < ar.size(); j++)
		{
			if (((base + ar[j]) % k) == 0)
				++result;
		}
	}

	return result;
}
```