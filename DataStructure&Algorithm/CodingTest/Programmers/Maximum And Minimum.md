```C++
string solution(string s) {
    vector<int> values;

    int index = 0;
    string temp = "";
    while (true)
    {
        temp += s[index];

        if (s[index] == ' ')
        {
            values.push_back(atoi(temp.c_str()));
            temp = "";
        }
        if (s.size() - 1 == index)
        {
            values.push_back(atoi(temp.c_str()));
            break;
        }
        ++index;
    }

    sort(values.begin(), values.end());
    return string(to_string(*(values.begin())) + " " + to_string(*(values.end() - 1)));
}
```
더 좋은 방법이 없을까 싶었는데 다른 사람 풀이를 봐도 동일한 풀이밖에 안보인다