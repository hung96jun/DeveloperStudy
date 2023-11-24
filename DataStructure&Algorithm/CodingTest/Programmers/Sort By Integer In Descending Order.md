```C++
int compair(const void* a, const void* b)
{
    if (*(const char*)a > *(const char*)b)
        return -1;
    else if (*(const char*)a < *(const char*)b)
        return 1;
    else
        return 0;
}

long long solution(long long n) {
    string temp = to_string(n);
    qsort(&(temp[0]), temp.size(), sizeof(temp[0]), compair);

    return atol(temp.c_str());
}
```
처음 qsort를 했을 때 3번째 인자를 sizeof(const char*)를 넣었을 때 문자열이 깨졌다. 그래서 0번째 원소의 sizeof를 하니 정상적으로 동작됐다.