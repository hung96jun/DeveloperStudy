- 주어진 2개의 <font color="red">문자열</font>의 배열이 있을 때, 1번 문자열 배열 안에서 2번 문자열 배열과 동일한 문자열 배열이 존재할 경우 Yes를 반환, 아닐경우 No를 반환
- 실패 - 이유는 첫 번째 문자열이 동일할경우 다음으로 넘어가는데 다음 문자열이 틀릴 경우 실패함(즉, 페이크에 취약하다)
```C++
string gridSearch(vector<string> G, vector<string> P)
{
	int row, column, count;
	row = -1;
	column = -1;
	count = 0;

	int selectLine = 0;
	int selectIndex = 0;

	bool check = false;

	for (int i = 0; i < G.size(); i++)
	{
		for (int j = (column >= 0 ? column : 0); j < G[i].size(); j++)
		{
			if (check == false && G[i][j] == P[0][0])
			{
				check = true;
				row = i;
				column = j;
			}

			if (check == false && G[i].size() - j < P[0].size())
				break;

			if (check == true)
			{
				if (G[i][j] != P[selectLine][selectIndex])
				{
					selectLine = 0;
					selectIndex = 0;
					check = false;

					column = 0;

					continue;
				}

				selectIndex++;

				if (selectIndex == P[0].size())
					break;
			}
		}

		if (check == true && selectIndex == P[0].size())
		{
			selectIndex = 0;
			selectLine++;
		}

		else
		{
			selectLine = 0;
			selectIndex = 0;
			column = 0;
			check = false;
		}

		if (selectLine >= P.size())
			break;
	}

	if (selectLine >= P.size())
		return "YES";

	return "NO";
}
```

- 성공
```C++
vector<int> strPartsFind(string str, string target)
{
	vector<int> result;
	int index = -1;

	index = str.find(target);
	if (index == -1)
		return result;

	result.push_back(index);

	while (true)
	{
		index = str.find(target, index + 1);
		if (index == -1)
			return result;

		result.push_back(index);
	}
}

string gridSearch(vector<string> G, vector<string> P)
{
	int curIndex = 0;
	vector<string> finds;
	
	for (int i = 0; i < G.size(); i++)
	{
		vector<int> temp = strPartsFind(G[i], P[curIndex]);
		if (temp.size() != 0)
		{
			bool check = true;

			for (int j = 0; j < temp.size(); j++)
			{
				check = true;

				for (int k = 0; k < P.size(); k++)
				{
					string str = G[i + k].substr(temp[j], P[k].size());
					if (str != P[k])
					{
						check = false;
						break;
					}
				}

				if (check == true)
					break;
			}

			if (check == true)
				return "YES";
		}
	}

	return "NO";
}
```