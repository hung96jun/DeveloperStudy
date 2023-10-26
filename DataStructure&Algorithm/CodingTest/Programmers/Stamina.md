- k : 피로도 최대치
- dungeons : 최소 필요 피로도와 사용 피로도가 쌍으로 이루어진 2중 배열
- 피로도 최대치를 사용하여 가장 많은 던전을 탐험했을때 몇개의 던전을 탐험할수 있는지 반환(던전은 한번씩만 탐험 가능하다.)
```C++
/**
* @param    vec         사용할 vector의 레퍼런스
* @param    depth       현재 depth
* @param    max         vector의 size
* @param    useDepth    사용할 vector의 depth값(고정)
*/
void permutation(vector<int>& vec, int depth, int max, int useDepth, int& result, int maxStamina, vector<vector<int>> dungeons)
{
    // 순열 1개가 완성되었을 때
    if (depth == useDepth)
    {
        int stamina = maxStamina;
        int count = 0;
        for (int i = 0; i < max; i++)
        {
            int necessaryStamina = dungeons[vec[i]][0];
            int useStamina = dungeons[vec[i]][1];

            if (stamina >= necessaryStamina)
            {
                count++;
                stamina -= useStamina;
            }
        }

        if (result < count)
            result = count;

        return;
    }

    // 순열 배치
    for (int i = depth; i < max; i++)
    {
        swap(vec[i], vec[depth]);
        permutation(vec, depth + 1, max, useDepth, result, maxStamina, dungeons);
        swap(vec[i], vec[depth]);
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -1;
    vector<int> vec;
    for (int i = 0; i < dungeons.size(); i++)
    {
        vec.push_back(i);
    }

    permutation(vec, 0, vec.size(), vec.size(), answer, k, dungeons);

    return answer;
}
```
위 코드는 순열 완전 탐색 알고리즘을 사용하여 해결