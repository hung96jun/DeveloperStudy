두 배열에 입력된 값들의 내적 합을 반환하는 문제
```C++
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    for(int i =0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }
    
    return answer;
}
```
간단히 반복문을 돌려 해결

```C++
int solution(vector<int> a, vector<int> b) {    
    return inner_product(a.begin(),a.end(),b.begin(),0);
}
```
numeric 라이브러리에 있는 inner_product 함수
- param1 first1
- param2 last1
- param3 first2
- param4 init
왜 첫 번재 에는 first와 last가 있는데 두번째에는 first만 넣는지 이해가 안됨