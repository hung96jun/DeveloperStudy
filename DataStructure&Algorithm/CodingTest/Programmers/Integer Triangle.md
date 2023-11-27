- 피라미드 형식으로 구성된 int값들의 2차원 배열에서 현재 위치에서 아래 좌 우의 값을 더해가 마지막에 제일 큰 값을 구하는 문제
```C++
void dfs(vector<vector<int>> triangle, int depth, int index, int value, int& result)
{
    value += triangle[depth][index];

    if (depth == triangle.size() - 1)
    {
        if (result < value)
            result = value;

        return;
    }

    dfs(triangle, depth + 1, index, value, result);
    dfs(triangle, depth + 1, index + 1, value, result);
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    dfs(triangle, 0, 0, 0, answer);
    
    return answer;
}
```
깊이우선 탐색을 사용한 풀이, 4~8번, 10번 문제에서 타임오버

```C++
int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 0; i < triangle.size() - 1; i++)
    {
        int before = triangle[i + 1][0];
        triangle[i + 1][0] += triangle[i][0];  // 다음 줄의 제일 왼쪽 값만 현재 줄의 제일 왼쪽 값을 미리 더한다.

        for (int j = 0; j < triangle[i].size(); j++)
        {
            int value = triangle[i][j];
            int *left, *right;  // 값을 더할 때 사용할거라 주소 접근을 사용
            left = &triangle[i + 1][j];  // 다음 줄의 왼쪽 주소
            right = &triangle[i + 1][j + 1];  // 다음 줄의 오른쪽 주소
            int rightValue = *right;
            
            if (*left < before + value)  // 다음 줄의 왼쪽 값은 이전 줄의 오른쪽 값이므로 비교 후 더 큰 값 대입
                *left = before + value;
            
            before = rightValue;
            *right += value;
        }
    }

    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());

    return answer;
}
```
문제 자체는 동적 계획법 문제로 나왔는데, 아직 동적 계획법 문제를 많이 안풀어봐서 풀이가 동적 계획법인지는 모르겠다.