arr : 1~5까지의 수가 랜덤으로 중복되어 저장되어 있는 배열
arr 배열 안에서 가장 많이 들어 있는 수중 제일 작은 수를 구하는 알고리즘
```C++
int migratoryBirds(vector<int> arr) 
{
	map<int, int> counting;
	int result = 0;
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		pair<int, int> temp;
		temp.first = i + 1;
		temp.second = 0;

		counting.insert(temp);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		(*counting.find(arr[i])).second++;
	}

	/**
	* 제일 작은 수부터 입력되어 있으므로 제일 작은 수가 선입력
	* 그렇기때문에 큰 수가 카운팅이 많이 되있어도 대입되지 않는다.
	*/
	for (pair<int, int> temp : counting)
	{
		if (count < temp.second)
		{
			result = temp.first;
			count = temp.second;
		}
	}

	return result;
}
```