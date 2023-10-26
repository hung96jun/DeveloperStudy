- 입력된 문자열의 재배열해서 사전적 순차로 입력된 문자열 다음으로 큰 문자열을 재배열해서 반환하는 문제
```C++
string biggerIsGreater(string w)
{
    string s;
    s = w;

    do {
        string result = s;

        if (result > w)
            return result;

    } while (next_permutation(s.begin(), s.end()));

    return "no answer";
}
```
- next_permutation 함수는 시작과 끝의 범위를 지정하여 해당 범위의 다음으로 큰 값을 만들어내는 함수이다.
	- 반환값은 bool형
	- 입력된 iterator를 가지고 재배열하여 참조 반환