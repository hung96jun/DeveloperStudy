- computers : 현재 index computer가 연결되어 있는 computer의 index 배열
```C++
void dfs(vector<vector<int>> computers, vector<bool>& visited, int n, int curIndex, int& count)
{
    if (visited[curIndex] == true) return;
    visited[curIndex] = true;
    count++;

    for (int i = 0; i < n; i++)
    {
        if (i == curIndex) continue;
        if (visited[i] == true) continue;
        if (computers[curIndex][i] == 0) continue;
        dfs(computers, visited, n, i, count);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited;
    visited.resize(n);
    fill_n(visited.begin(), visited.size(), false);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        dfs(computers, visited, n, i, count);
        if (count > 0)
            answer++;
    }

    return answer;
}
```