brown과 yellow의 총 갯수가 주어진다. brown은 yellow를 감싸는 사각형 테두리 형식으로 배치가 되고 yellow는 그 안을 채우는 형식으로 배치가 된다고 했을 때, 가로 세로의 값을 구하는 문제
```C++
vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int width = (brown - 4) / 2;

    for (int height = 1; height < width; height++)
    {
        int tempYellow = (width - height) * height;
        if (tempYellow == yellow)
        {
            answer[0] = (width - height) + 2;
            answer[1] = height + 2;
            
            break;
        }
    }

    return answer;
}
```