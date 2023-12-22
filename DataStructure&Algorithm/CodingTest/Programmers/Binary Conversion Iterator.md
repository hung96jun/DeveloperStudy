```C++
vector<int> solution(string s) {
    vector<int> answer;

    string value = s;
    int count = 0;
    int deleteCount = 0;
    int convertCount = 0;

    while(value.size() >= 2)
    {
        count = 0;
        for (int i = 0; i < value.size(); i++)
        {
            if (value[i] == '1')
                count++;
            else
                deleteCount++;
        }
        
        value.clear();

        while (count > 0)
        {
            if (count % 2 == 1)
                value = '1' + value;
            else
                value = '0' + value;

            count /= 2;
        }

        convertCount++;
    }

    answer.push_back(convertCount);
    answer.push_back(deleteCount);

    return answer;
}
```