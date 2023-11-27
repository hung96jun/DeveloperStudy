- 1과 0으로 이루어진 2차원 문자열 배열 안에서 0, 0부터 n, n까지 최단거리를 구하는 문제
```C++
void bfs(const vector<vector<int>> maps, vector<vector<bool>>& visited, int x, int y, int count, int& result)
{
    if (maps[y][x] == 0)
        return;
    if (visited[y][x] == true)
        return;

    visited[y][x] = true;
    ++count;

    if (result != -1 && count > result)
        return;

    int goalX, goalY;
    goalX = maps[0].size() - 1;
    goalY = maps.size() - 1;

    if (x == goalX && y == goalY)
        result = count;

    int xAxis, yAxis;
    for (int i = 0; i < 4; i++)
    {
        xAxis = x;
        yAxis = y;

        switch (i)
        {
        case 0:
            if (maps[0].size() - 1 > x)
                xAxis = x + 1;
            break;
        case 1:
            if (maps.size() - 1 > y)
                yAxis = y + 1;
            break;
        case 2:
            if(x > 0)
                xAxis = x - 1;
            break;
        case 3:
            if(y > 0)
                yAxis = y - 1;
            break;
        default:
            break;
        }

        bfs(maps, visited, xAxis, yAxis, count, result);
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    int ySize = maps.size() - 1;
    int xSize = maps[0].size() - 1;

    if (maps[ySize - 1][xSize] == 0 && maps[ySize][xSize - 1] == 0)
        return -1;

    vector<vector<bool>> visited;
    visited.resize(ySize + 1);
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i].resize(xSize + 1);
        fill_n(visited[i].begin(), xSize, false);
    }

    bfs(maps, visited, 0, 0, 0, answer);

    return answer;
}
```
문제 1개 참조 오류, 4개 실패, 효율성 똥
solution 함수에서 return -1 부분을 지우니 참조오류는 해결됨

- 인터넷 참고
	- 최단 거리를 구하는 문제는 BFS를 사용하면 쉽게 풀 수 있음
