- 문자열을 매개변수로 받아와 수와 문자를 조합하여 규칙에 맞는 결과값을 반환하는 문제
- 총 3번의 점수 기회가 주어지며, 점수, 제곱수, 배수의 순서대로 문자열이 입력된다
- 배수의 수는 있을수도 있고 없을수도 있으며, 그 다음 점수에 배수의 값이 있을 경우 앞 점수의 배수의 값과 조합될 수 있다.
```C++
int GetNumber(string value)
{
	int result = 0;

	for (int i = 0; i < value.size(); i++)
	{
		if (value[i] - '0' > 10 || value[i] - '0' < 0)
			continue;

		result = (result * 10) + (value[i] - '0');
	}

	return result;
}

int solution(string dartResult) {
	int answer = 0;
	int index = 0;
	
	vector<vector<int>> expressions;
	for (int i = 0; i < 3; i++)
	{
		vector<int> expression;
		int score = 0;
		int multiple = 1;
		string value = dartResult.substr(index, 2);

		score = GetNumber(value);
		if (score >= 10)
			index++;		
		
		if (dartResult[index + 1] == 'D')
			score = pow(score, 2);
		else if (dartResult[index + 1] == 'T')
			score = pow(score, 3);

		expression.push_back(score);
		if (index + 2 < dartResult.size())
		{
			if (dartResult[index + 2] == '*')
			{
				multiple = 2;
				index += 3;

				if (i > 0)
				{
					expressions[i - 1][1] *= 2;
				}
			}
			else if (dartResult[index + 2] == '#')
			{
				multiple = -1;
				index += 3;
			}
			else
				index += 2;
		}
		expression.push_back(multiple);
		expressions.push_back(expression);
	}

	for (vector<int> expression : expressions)
	{
		answer += expression[0] * expression[1];
	}

	return answer;
}
```

```C++
int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
```
>[!tip] stringstream(sstream)
>문자열을 공백과 \n을 기준으로 int형, string형, float형 등 다양하게 자를 수 있도록 하는 클래스
>문자열에서 동작하는 스트림 클래스로 외부에서 입출력을 받아오는 것이 아닌 string 값을 받아 동작하는 클래스로, 문자열에서 원하는 자료형의 데이터를 추출할 때 사용한다.
>sstream 라이브러리에 포함되어 있다.

