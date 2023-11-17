```C++
vector<int> solution(long long n) {
    vector<int> answer;
    string temp = to_string(n);
    
    for(int i = temp.size() - 1; i >= 0; i--)
    {
        char value = temp[i] - 48;
        answer.push_back(value);
    }
    
    return answer;
}
```