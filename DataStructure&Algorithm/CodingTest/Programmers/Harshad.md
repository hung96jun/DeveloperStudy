- x의 값이 주어졌을 때 각 자릿수들을 전부 더한 값이 x의 약수일 경우 하샤드 수라고 한다. (18 -> 1 + 8 = 9 -> 18 % 9 = 0)
```C++
bool solution(int x) {
    string temp = to_string(x);
    int harshad = 0;
    
    for(int i = 0; i <temp.size(); i++)
    {
        harshad += temp[i] - 48;
    }
    
    return x % harshad == 0;
}
```