```C++
vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    long long temp = x;
    for(int i = 0; i < n; i++)
    {
        answer.push_back(temp);
        temp += x;
    }
    
    return answer;
}
```