문자열 내림차순 정렬(대문자는 소문자보다 작은 것으로 간주)
```C++
int compare(const void* a, const void* b)
{
    if (*(char*)a < *(char*)b) return 1;
    if (*(char*)a == *(char*)b) return 0;
    if (*(char*)a > *(char*)b) return -1;

    return 0;
}

string solution(string s) {
    qsort(&s[0], s.size(), sizeof(s[0]), compare);

    return s;
}
```