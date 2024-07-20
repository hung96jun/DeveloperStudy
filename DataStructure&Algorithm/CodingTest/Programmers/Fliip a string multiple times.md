- 주어진 문자열에서 주어진 vector의 구간의 문자들을 뒤집어서 결과값을 도출하는 문제
- 사용한 함수
	- reverse : algorithm 라이브러리에 정의되있는 함수로 입력된 구간을 뒤집어서 반환하는 함수

````C++
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;

    for (int i = 0; i < queries.size(); i++)
    {
        reverse(answer.begin() + queries[i][0], answer.begin() + queries[i][1] + 1);
    }

    return answer;
}
```