![[Pasted image 20231026090555.png]]
- Visited 변수를 사용하는 순열 알고리즘
- [[DFS]](깊이 우선 탐색) : 한 노드의 자식을 끝까지 순회한 후 다시 돌아와서 다른 형제들의 자식을 타고 내려가면서 순회
- 과정
	- DFS를 돌면서 모든 인덱스에 방문해 output 배열에 값을 넣는다.
	- 이미 들어간 값은 visited를 true로 변경해서 중복해서 값이 들어가지 않도록 한다.
	- 이러한 과정을 depth가 r값과 같아질 때까지 반복한다.
```C++
/**
* @param    vec         사용할 vector
* @param    visited     방문했는지 체크할 vector
* @param    output      vec에서 값을 가져와 배치하여 실제 사용할 vector
* @param    depth       현재 depth
* @param    max         vector의 size
* @param    useDepth    사용할 vector의 depth값(고정)
*/
void permutation_dfs(vector<int> vec, vector<bool>& visited, vector<int>& output, int depth, int max, int useDepth)
{
    // 순열 1개가 완성되었을 때
    if (depth == useDepth)
    {
        for (int i = 0; i < max; i++)
        {
            cout << output[i] << ", ";
        }

        cout << endl;
        return;
    }

    // 순열 배치
    for (int i = 0; i < max; i++)
    {
        // 방문하지 않은 index일 경우
        if (visited[i] != true)
        {
            visited[i] = true;
            output[depth] = vec[i];
            permutation_dfs(vec, visited, output, depth + 1, max, useDepth);
            visited[i] = false;
        }
    }
}
```
