문자열의 사이즈가 4또는 6이고, 숫자로만 구성되었을 경우 true 반환, 그 외에는 false 반환
```C++
bool solution(string s) {
    
    if((s.size() == 4 || s.size() == 6) == false)
        return false;
    
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    }
    
    return true;
}
```
기본으로 풀은 해답, 또한 isdigit이라는 함수로 매개변수 char형을 받는 함수가 있다. 이 함수는 해당 문자가 숫자로 이루어져있는 값인지 판별한는 함수이다.