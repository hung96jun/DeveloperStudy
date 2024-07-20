1~n번으로 분류되는 개인 정보 n개가 있을 때, 약관 종류는 여러가지가 있으며
각 약관마다 개인정보 보관 유효 지간이 정해져 있다.
수집된 개인 정보는 유ㅠ효 기간 전까지만 보관 가능하며, 유효 기간이 지났으면
반드시 파기해야 한다.

예를 들어 a약관 유효 기간이 12달이고 2021년 1월 5일에 수집된 개인 정보가 a
약관으로 수집됐다면 개인 정보는 2022년 1월 4일까지 보관 가능하며 2022년 
1월 5일부터 파기해야 할 개인정보이다.

모든 달은 28일까지 있다고 가정

파기해야 할 정보의 번호를 반환

- 코드
```C++
	vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termsType;
    for (string temp : terms)
    {
        pair<char, int> p;
        p.first = temp[0];
        p.second = atoi(temp.substr(2, temp.size()).c_str());

        termsType.insert(p);
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        int year = atoi(privacies[i].substr(0, 4).c_str());
        int month = atoi(privacies[i].substr(5, 7).c_str());
        int date = atoi(privacies[i].substr(8, 10).c_str());
        int size = privacies[i].size();
        char type = privacies[i][size - 1];

        int term = termsType[type];
        month += term;
        if (month > 12)
        {
            month -= 12;
            ++year;
        }
        --date;
        if (date == 0)
        {
            month--;
            date = 28;
            if (month < 1)
            {
                --year;
                month = 12;
            }
        }
        
        string strMonth = to_string(month);
        string strDate = to_string(date);
        if (strMonth.size() == 1)
            strMonth = "0" + strMonth;
        if (strDate.size() == 1)
            strDate = "0" + strDate;

        string str = to_string(year) + "." + strMonth + "." + strDate;
        if (str < today)
            answer.push_back(i);
    }

    return answer;
}
```

- 연습 문제는 통과, 테케 다수 실패
- 아마 기간 지난 후 연 월 일 연산에서 문제 발생한 것 같음
- 연 월 일 계산
	- 연
		- 월이 12월이 넘어갔을 경우 년도 증가
	- 월
		- 일이 0일일 경우 월 감소
	- 일
		- 일이 0일일 경우 28일로 변경
		- 일은 연산상 28일을 넘어갈 수 없으니 1일 변경은 없음
```C++
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termsType;
    for (string temp : terms)
    {
        pair<char, int> p;
        p.first = temp[0];
        p.second = atoi(temp.substr(2, temp.size()).c_str());

        termsType.insert(p);
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        int year = atoi(privacies[i].substr(0, 4).c_str());
        int month = atoi(privacies[i].substr(5, 7).c_str());
        int date = atoi(privacies[i].substr(8, 10).c_str());
        int size = privacies[i].size();
        char type = privacies[i][size - 1];

        int term = termsType[type];
        date -= 1;
        if (date == 0)
        {
            date = 28;
            month -= 1;
        }
        month += term;
        if (month > 12)
        {
            year += month / 12;
            month = month % 12;
        }
        
        string strMonth = to_string(month);
        string strDate = to_string(date);
        if (strMonth.size() == 1)
            strMonth = "0" + strMonth;
        if (strDate.size() == 1)
            strDate = "0" + strDate;

        string str = to_string(year) + "." + strMonth + "." + strDate;
        if (str < today)
            answer.push_back(i + 1);
    }

    return answer;
}
```
- 개선된 코드, 17번 테케 실패
	- month의 추가 연산에서 month = month % 12 + 1이 맞는것 같은데 이럴경우 실패 케이스가 더 많아진다