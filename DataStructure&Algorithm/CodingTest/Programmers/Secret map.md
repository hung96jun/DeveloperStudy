```C++
string getBinary(int value)
{
    string result = "";

    while (value > 0)
    {
        if (value % 2 == 1)
            result = "#" + result;
        else
            result = " " + result;
        value /= 2;
    }

    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++)
    {
        string route = getBinary(arr1[i] | arr2[i]);
        while (route.size() < n)
        {
            route = " " + route;
        }
        answer.push_back(route);
    }

    return answer;
}
```
비트 연산을 사용하여 해결