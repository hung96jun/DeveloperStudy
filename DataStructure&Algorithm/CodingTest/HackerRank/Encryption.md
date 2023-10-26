- 문자열을 암호화 하는 문제
- 문자열을 균등한 2차원 배열로 저장(세로 <= 가로)하여 세로로 문자열을 출력하는 문제
	- abcdefghi의 문자열이 주어지면 adg beh cfi형식으로
```C++
string encryption(string s)
{
	int count = sqrt(s.size());
	int leave = s.size() - (count * count);
	int line = count;
	
	if (leave > 0)
	{
		line = count;
		count++;
	}

	vector<vector<char>> rewrite;

	for (int i = 0; i < count; i++)
	{
		bool breakCheck = false;
		vector<char> lineRewrite;
		lineRewrite.resize(count, '/');
		for (int j = 0; j < count; j++)
		{
			char temp = s[j + (i * count)];
			lineRewrite[j] = (s[j + (i * count)]);

			if (j + (i * count) + 1 == s.size())
			{
				breakCheck = true;
				break;
			}
		}
		rewrite.push_back(lineRewrite);

		if (breakCheck == true)
			break;
	}

	string result = "";

	for (int i = 0; i < rewrite[0].size(); i++)
	{
		for (int j = 0; j < rewrite.size(); j++)
		{
			if (rewrite[j][i] == '/')
				continue;

			result += rewrite[j][i];
		}

		result += " ";
	}

	return result;
}
```