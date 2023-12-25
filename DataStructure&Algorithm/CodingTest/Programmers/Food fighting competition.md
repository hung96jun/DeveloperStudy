```C++
string solution(vector<int> food) {
    string answer = "";

    for (int i = 1; i < food.size(); i++)
    {
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer += to_string(i);
        }
    }

    string first = answer;
    sort(answer.rbegin(), answer.rend());
    first += "0" + answer;

    return first;
}
```