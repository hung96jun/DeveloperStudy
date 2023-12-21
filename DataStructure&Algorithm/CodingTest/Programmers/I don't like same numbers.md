매개변수로 전달된 배열을 연속되지 않은 숫자들만 추출하는 문제
```C++
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for(int a : arr)
    {
        if(answer[answer.size() - 1] != a)
            answer.push_back(a);
    }
    
    return answer;
}
```
앞의 값과 비교하여 다른 값이면 추가하는 방법으로 해결

```C++
vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}
```
Unique 함수를 사용한 방법

Unique 함수
- 중복된 원소를 제거하며 앞에서부터 중복되지 않게 채워간다.![[Pasted image 20231220103244.png]]
- 위 사진을 보면 원소를 제거한다기 보다는 중복되지 않은 순차로 앞에서부터 값을 변경하는 것처럼 보인다. 이유는 결과값에서 6이후 값들은 기존 벡터 원소와 동일하기 때문이다.

평균적으로 내가 한 방법이 더 효율성이 좋지만, 어떠한 경우에는 Unique를 사용한 방법이 더 빠르게 나왔다(프로그래머스 실행 결과 중 효율성 테스트3 번의 경우)
