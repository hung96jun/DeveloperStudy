```C++
double solution(vector<int> arr) {
    double answer = 0;
    
    for(int a : arr)
    {
        answer += a;
    }
    
    answer /= arr.size();
    
    return answer;
}
```

```C++
double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0);
    
    return answer / arr.size();
}
```
- accumulate : int형식의 배열의 주어진 index안의 값들의 합을 반환함, 3번째 인자는 init