- Phone_book : 주어진 문자열 배열안에서 접두사가 있을경우 false, 아닐경우 true를 반환
```C++
bool solution(vector<string> phone_book) {
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        string target = phone_book[i];

        for (int j = i + 1; j < phone_book.size(); j++)
        {
            string cur = phone_book[j];
            if (target.size() > cur.size())
                continue;

            cur = cur.substr(0, target.size());
            if (target == cur)
                return false;
        }
    }

    return true;
}
```
효율성 2개 실패, 테스트 케이스 3개 실패
```C++
bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); i++)
    {
        string target = phone_book[i];

        for (int j = 0; j < phone_book.size(); j++)
        {
            if (j == i) continue;

            string cur = phone_book[j];
            if (target.size() > cur.size())
                continue;

            cur = cur.substr(0, target.size());
            if (target == cur)
                return false;
        }
    }

    return true;
}
```
효율성 2개 실패, 1번 풀이의 문제점은 앞에 체크한것을 넘어간것이 문제가 됬다.
```C++
bool solution(vector<string> phone_book) {    
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }

    return true;
}
```
인터넷에서 찾은 비슷한 풀이, sorting을 하여 비교대상과 비교받을것의 순서를 미리 맞춰서 비교 대상 뒤에 비교 받을 문자열이 올수있게 하여 바로 다음것만 체크할 수 있게 구현한것 같다.