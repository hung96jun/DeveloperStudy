```C++
vector<int> solution(vector<int> arr) {
    if(arr.size() == 1)
        return vector<int>(1, -1);
    
    int value = 2147483647;
    int index = 0;
    
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(arr[i] < value)
        {
            value = arr[i];
            index = i;
        }
    }
    
    arr.erase(arr.begin() + index);
    
    return arr;
}
```
메모리를 아끼기 위해 매개변수로 들어온 arr값에서 해당하는 값을 삭제 후 반환하는 방법을 사용
```C++
vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) {
        return { -1 };
    }
    arr.erase(std::min_element(arr.begin(), arr.end()));
    return arr;
}
```
algorithm 라이브러리에 min_element라는 함수가 있음. 해당 함수는 배열의 범위 안에서 가장 작은 요소를 찾아서 값을 반환하는 함수. <font color="yellow">하지만 결국 내부적으로는 반복문을 돌려서 값을 반환하는게 아닐까라는 추측을 함.</font> 그래도 iteractor 반환으로 erase 함수에 깔끔하게 적용시킬 수 있다는 장점이 있는거 같음.
