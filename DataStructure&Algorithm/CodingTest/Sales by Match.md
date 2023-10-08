n : 배열의 max
입력된 배열에서 동일한 값을 한 쌍으로 몇쌍이 나오는지 반환
```C++
int sockMerchant(int n, vector<int> ar) 
{
	map<int, int> maps;

	for (int i = 0; i < n; i++)
	{
		if (maps.count(ar[i]) == 0)
		{
			pair<int, int> pa;
			pa.first = ar[i];
			pa.second = 1;

			maps.insert(pa);
		}

		else
		{
			maps[ar[i]]++;
		}
	}

	int result = 0;

	for (pair<int, int> pa : maps)
	{
		result += pa.second / 2;
	}

	return result;
}
```