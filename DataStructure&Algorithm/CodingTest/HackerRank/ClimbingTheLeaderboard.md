- parameter
	- ranked : 현재 랭킹
	- Player : 추가된 랭커
- player의 모든 점수가 랭킹 몇위인지 vector로 반환하는 문제
- 일반적인 for문 탐색을 사용시 timeover나는 문제로 최적화에 신경써야 하는 문제
- 순차탐색을 사용한 풀이(타임오버)
```C++
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> rankes;
	vector<int> results;

	for (int i = 0; i < ranked.size(); i++)
	{
		if (rankes.size() == 0)
			rankes.push_back(ranked[i]);
		else if (rankes[rankes.size() - 1] != ranked[i])
			rankes.push_back(ranked[i]);
	}

	for (int playerValue : player)
	{
		int count = 1;

		for (int rankValue : rankes)
		{
			if (playerValue < rankValue)
				count++;
			else
				break;
		}

		results.push_back(count);
	}

	return results;
}
```

- 이진 탐색을 사용한 풀이(타임오버)
```C++
int binarySearch(int value, vector<int> rankes, int min, int max)
{
	if (value > rankes[0]) return 0;
	if (value < rankes[max]) return ++max;
	if (min > max) return max;

	int mid = (min + max) / 2;

	if (value > rankes[mid])
	{
		if (value < rankes[mid - 1 < min ? min : mid - 1])
			return mid;

		return binarySearch(value, rankes, min, mid - 1);
	}
	else if (value < rankes[mid])
	{
		if (value > rankes[mid + 1 > max ? max : mid + 1])
			return ++mid;

		return binarySearch(value, rankes, mid + 1, max);
	}

	return mid;
}

int compair(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return -1;
	else if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> results;
	
	vector<int>::iterator it = unique(ranked.begin(), ranked.end());
	ranked.erase(it, ranked.end());

	for (int playerValue : player)
	{
		int count = 1;

		count += binarySearch(playerValue, ranked, 0, ranked.size() - 1);
	
		results.push_back(count);
	}
	
	return results;
}
```

- 어거지 풀이
```C++
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
	vector<int> results;

	vector<int>::iterator it = unique(ranked.begin(), ranked.end());
	ranked.erase(it, ranked.end());
	
	int temp = ranked.size() / 3;

	for (int value : player)
	{
		int min = 0;
		int max = 0;

		{
			// 1등 체크
			if (value >= ranked[0])
			{
				results.push_back(1);
				continue;
			}
			// 꼴등 체크
			else if (value < *(ranked.end() - 1))
			{
				results.push_back(ranked.size() + 1);
				continue;
			}
			// 공동 꼴등 체크
			else if (value == *(ranked.end() - 1))
			{
				results.push_back(ranked.size());
				continue;
			}
		}

		if (value < ranked[0] && value >= ranked[temp])
		{
			min = 0;
			max = temp;
		}
		else if (value < ranked[temp] && value >= ranked[temp * 2])
		{
			min = temp + 1;
			max = temp * 2;
		}
		else if (value < ranked[temp * 2] && value >= ranked[ranked.size() - 1])
		{
			min = temp * 2 + 1;
			max = ranked.size() - 1;
		}

		for (int i = min; i <= max; i++)
		{
			if (value >= ranked[i])
			{
				results.push_back(i + 1);
				break;
			}
		}
	}
	
	return results;
}
```
