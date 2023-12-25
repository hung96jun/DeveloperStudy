```C++
vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}
```
unique를 사용하여 중복제거하는 방법. 테스트 정상 통과

```C++
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for(int i = 0;i<numbers.size();++i){
        for(int j = i+1 ; j< numbers.size();++j){
            st.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(st.begin(), st.end());
    return answer;
}
```
다른 사람의 풀이이 set을 사용한 방법. 평균적으로는 이 방법이 더 빠르지만 특정 상황에서는 unique를 사용한 방법이 더 빠르다. 특정 상황의 시간값이 제일 큰것으로 보아 결과값이 많으면 많을수록 unique를 사용하는 방법이 더 빠른것 같다.(어느정도가 기준인지는 모르겠다.)