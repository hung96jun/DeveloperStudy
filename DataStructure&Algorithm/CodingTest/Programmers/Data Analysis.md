입력된 정보들을 ext 형식의 정보들에서 필요한 정보들만 추출하고 sort_by형식으로 정렬하는 문제

vector를 정렬할 방법이 없어 QuickSort 함수를 정의하여 사용
- 코드
```C++
int Partition(vector<vector<int>>& vec, int low, int high, int index)
{
    int value = vec[high - 1][index];
    int i = low;
    
    for (int j = low; j < high; j++)
    {
        if (value >= vec[j][index])
        {
            swap(vec[i], vec[j]);
            i++;
        }
    }

    return i;
}

void QuickSort(vector<vector<int>>& vec, int low, int high, int index)
{
    if (low >= high) return;
    int pivot = Partition(vec, low, high, index);
    QuickSort(vec, low, pivot - 1, index);
    QuickSort(vec, pivot, high, index);
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    int extCode = 0;
    int sortCode = 0;
    if (sort_by == "code") sortCode = 0;
    if (sort_by == "date") sortCode = 1;
    if (sort_by == "maximum") sortCode = 2;
    if (sort_by == "remain") sortCode = 3;

    if (ext == "code") extCode = 0;
    if (ext == "date") extCode = 1;
    if (ext == "maximum") extCode = 2;
    if (ext == "remain") extCode = 3;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][extCode] <= val_ext)
            answer.push_back(data[i]);
    }

    QuickSort(answer, 0, answer.size(), sortCode);

    return answer;
}
```