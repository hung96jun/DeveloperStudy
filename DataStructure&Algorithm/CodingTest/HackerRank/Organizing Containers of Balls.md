- 2차원 배열로 값이 들어온다.
- 컨테이너와 타입의 갯수를 행렬로 나타낼 수 있다.![[Pasted image 20231019180235.png]]
- 컨테이너들끼리 공들을 swap할 수 있으며 모든 컨테이너에 타입별로 공들을 넣을수 있으면 Possible, 불가능하면 Impossible
- 이론상 각각의 컨테이너가 담고있는 swap되지 않은 공의 갯수가 모든 컨테이너의 각각의 타입별 공의 갯수와 동일하면 가능할 것 같다.
```C++
string SwapResult(map<int, int> balls, vector<int> containerCount)
{
	string result;

	for (pair<int, int> ball : balls)
	{
		int index = -1;

		for (int i = 0; i < containerCount.size(); i++)
		{
			if (ball.second == containerCount[i])
			{
				index = i;
				break;
			}
		}

		if(index > -1)
			containerCount.erase(containerCount.begin() + index);
	}

	if (containerCount.size() == 0)
		result = "Possible";
	else
		result = "Impossible";

	return result;
}

string organizingContainers(vector<vector<int>> container)
{
	vector<int> containerCount;
	containerCount.resize(container.size());

	map<int, int> balls;

	for (int i = 0; i < container.size(); i++)
	{
		for (int j = 0; j < container[i].size(); j++)
		{
			containerCount[i] += container[i][j];
			balls[j] += container[i][j];
		}
	}

	return SwapResult(balls, containerCount);;
}
```