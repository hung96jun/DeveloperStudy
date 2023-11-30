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

```C++
void bfs(const vector<vector<int>> maps, vector<vector<bool>>& visited, int x, int y, const int endX, const int endY, int count, int& result)
{
    if (count > result) return;

    visited[y][x] = true;
    count++;

    if ((x == endX && y == endY) && count < result)
    {
        result = count;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextX, nextY;
        nextX = x;
        nextY = y;
        switch (i)
        {
        case 0:     // down
            if (nextY < endY)
                nextY++;
            else
                continue;
            break;
        case 1:     // up
            if (nextY > 0)
                nextY--;
            else
                continue;
            break;
        case 2:     // right
            if (nextX < endX)
                nextX++;
            else
                continue;
            break;
        case 3:     // left
            if (nextX > 0)
                nextX--;
            else
                continue;
            break;
        }

        if (maps[nextY][nextX] == 0)
            continue;
        if (visited[nextY][nextX] == true)
            continue;
        
        bfs(maps, visited, nextX, nextY, endX, endY, count, result);
        visited[nextY][nextX] = false;
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = INT_MAX;
    vector<vector<bool>> visited;
    int endX, endY;
    endY = maps.size();
    endX = maps[0].size();

    visited.resize(endY);
    for (vector<bool>& visit : visited)
    {
        visit.resize(endX);
        fill_n(visit.begin(), visit.size(), false);
    }

    bfs(maps, visited,  0, 0, endX - 1, endY - 1, 0, answer);

    return answer == INT_MAX ? -1 : answer;
}
```
다시 풀어봤을 때 테스트 케이스는 전부 통과됐지만 효율성에서 전부 실패가 나왔다.