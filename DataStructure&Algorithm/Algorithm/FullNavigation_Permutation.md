- 순열이란 n개의 값 중에서 r개의 숫자를 순서를 고려해 나열한 모든 경우의 수이다.
- nPr = n * (n - 1) * (n - 2) * ... * n - r + 1
	- ex) { 1, 2, 3 }총 3개의 값 중에서 3개의 숫자를 순서를 고려해 나열하면
	- 1, 2, 3/ 1, 3, 2/ 2, 1, 3/ 2, 3, 1/ 3, 1, 2/ 3, 2, 1로 총 6개로 나타낼 수 있다.
- Swap을 이용한 순열![[Pasted image 20231026085630.png]]
	- 과정
		- 0 번째 인덱스 원소를 0번째부터 n - 1번째까지 위치를 바꾼다(ABS, BAC, CBA)
		- 1번 과정을 진행해서 나온 경우들을, 1번째 인덱스 원소를 1번재부터 n - 1번재까지 위치를 바꾼다.
		- 이러한 과정을 n - 1번 반복한다.
	- 주의할점
		- 순열들의 순서가 보장되지 않는다.
			- ex) C, A, B가 먼저 나오는게 아니라 C, B, A가 먼저 노출될 수 있음
```C++
/**
* @param    vec         사용할 vector의 레퍼런스
* @param    depth       현재 depth
* @param    max         vector의 size
* @param    useDepth    사용할 vector의 depth값(고정), max값을 넘을 수 없음
*/
void permutation(vector<int>& vec, int depth, int max, int useDepth)
{
    // 순열 1개가 완성되었을 때
    if (depth == useDepth)
    {
        for (int i = 0; i < max; i++)
        {
            cout << vec[i] << ", ";
        }
        cout << endl;
        return;
    }

    // 순열 배치
    for (int i = depth; i < max; i++)
    {
        swap(vec[i], vec[depth]);
        permutation(vec, depth + 1, max, useDepth);
        swap(vec[i], vec[depth]);
    }
}
```
