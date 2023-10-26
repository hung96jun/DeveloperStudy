- int 메모리에 담을수 없을 수도있는 큰 수를 연산하는 문제
```C++
void multiple(int x, vector<int>& answer, int& digits)
{
	int carry = 0;	// 올림수, 곱셈 결과 윗 자리로 올라가는 수

	// 각 자리 연산
	for (int i = 0; i < digits; i++)
	{
		int multiplied = answer[i] * x + carry;		// 현재 자릿수에 맞는 연산 값을 추출.
													// + carry는 1의 자리에서는 0으로 나온다, 반복문을 돌면서 carry의 값을 연산하고
													// 10의 자리수부터 carry의 값이 0이 아닐 수가 있다.
		answer[i] = multiplied % 10;	// 배열에 들어갈 각 자릿수
		carry = multiplied / 10;		// 올림수를 구함
	}

	while (carry)
	{
		answer[digits] = carry % 10;	// 가장 높은 자리의 수
		carry /= 10;					// carry 값을 0으로 만듬
		digits++;						// 자릿수 추가
	}
}

void extraLongFactorials(int n)
{
	int maxArray = 200;

	vector<int> result;
	result.resize(maxArray);
	fill_n(result.begin(), maxArray, 0);
	result[0] = 1;
	int result_size = 1;		// 결과값의 자릿수, 나중에 배열을 출력할 때 사용

	for (int x = 2; x <= n; x++)
	{
		multiple(x, result, result_size);
	}

	for (int i = result_size - 1; i >= 0; i--)
		cout << result[i];
}
```