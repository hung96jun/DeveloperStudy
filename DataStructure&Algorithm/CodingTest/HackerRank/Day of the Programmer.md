윤년을 판단하여 프로그래머의 날짜를 구하는 문제
- 단, 율리우스력과 그레고리력의 차이가 있어 윤년 계산에 페이크가 발생함
- 율리우스력에서 그레고리력으로 바뀌는 년도는 1918년으로 해당 연도에는 1월 31일 다음날이 2월 14일이다.
- 율리우스력에서는 4년을 기준으로 윤년을 계산했다.
- 그레고리력에서는 4년을 기준으로 윤년이지만, 100년을 기준으로 윤년이 아니고, 400년을 기준으로 윤년이다.
```C++
string dayOfProgrammer(int year) 
{
	int date = 256;
	string result = ".09." + to_string(year);

	if (year == 1918)
	{
		result = "26" + result;
	}

	else if (year < 1918)
	{
		if (year % 4 == 0)
			result = "12" + result;
		else
			result = "13" + result;
	}

	else
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			result = "12" + result;
		else
			result = "13" + result;
	}

	return result;
}
```