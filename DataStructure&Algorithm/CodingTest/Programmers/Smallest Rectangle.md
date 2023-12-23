```C++
int solution(vector<vector<int>> sizes) 
{
    int width, height;
    width = height = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        int tempWidth = sizes[i][0];
        int tempHeight = sizes[i][1];

        if (tempWidth < tempHeight)
        {
            int temp = tempWidth;
            tempWidth = tempHeight;
            tempHeight = temp;
        }

        if (width < tempWidth)
            width = tempWidth;

        if (height < tempHeight)
            height = tempHeight;
    }

    return width * height;
}
```

```C++
int solution(vector<vector<int>> sizes)
{
    int answer=0;
    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
}
```
다른 사람의 풀이. 원리 자체는 동일하지만 좀더 깔끔하게 처리되었다.