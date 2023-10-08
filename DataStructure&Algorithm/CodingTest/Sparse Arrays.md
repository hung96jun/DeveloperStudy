stringList : 비교 당하는 문자열의 배열
quries : 비교할 문자열의 배열
동일한 문자열이 몇개인지 순서에 맞게 배열로 반환

```C++
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) 
{
	vector<int> result;

	for (int i = 0; i < queries.size(); i++)
	{
		int count = 0;

		for (int j = 0; j < stringList.size(); j++)
		{
			if (queries[i] == stringList[j])
				++count;
		}

		result.push_back(count);
	}

	return result;
}
```