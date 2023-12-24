```C++
vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> pairs;

    for (int i = 0; i < s.size(); i++)
    {
        if (pairs.count(s[i]) == 0)
        {
            answer.push_back(-1);
            pairs.insert({ s[i], i });
        }

        else
        {
            int index = answer[s[i]];
            answer.push_back(i - index);
            pairs[s[i]] = i;
        }
    }

    return answer;
}
```