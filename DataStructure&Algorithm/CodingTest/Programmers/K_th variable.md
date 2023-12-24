```C++
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temps;

    for (int i = 0; i < commands.size(); i++)
    {
        temps = array;
        temps.erase(temps.begin() + (commands[i][1]), temps.end());
        temps.erase(temps.begin(), temps.begin() + (commands[i][0] - 1));
        
        sort(temps.begin(), temps.end());

        answer.push_back(temps[commands[i][2] - 1]);
    }

    return answer;
}
```
정상 동작
```C++
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}
```
다른사람 풀이. 원리는 동일. erase동작을 하지 않음으로써 그만큼 효율성이 더 올라감. sort자체가 범위를 지정하는 것이기 때문에 erase를 사용하지 않아도 됬었음