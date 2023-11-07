- Numbers : 주어진 모든 수
- Target : 주어진 수를 연산해서 동일해야하는 값
- 연산자를 바꿔서 주어진 모든 수들의 연산결과가 Target이 나왔을때 몇개가 동일한지
```C++
const int charValue = 48;

void permutation(vector<bool>& vec, int depth, int max, const vector<int> numbers, const int target, int& count, map<string, bool>& temp)
{
    if (depth == max)
    {
        int value = 0;
        string str = "";

        for (int i = 0; i < max; i++)
        {
            if (vec[i] == true)
            {
                value += numbers[i];
                str += "+" + to_string(numbers[i]);
            }
            else
            {
                value -= numbers[i];
                str += "-" + to_string(numbers[i]);
            }
        }

        if (value != target) return;

        if (temp.count(str) == 0)
        {
            pair<string, int> check;
            check.first = str;
            check.second = 0;

            temp.insert(check);
            count++;
        }
        
        return;
    }

    for (int i = depth; i < max; i++)
    {
        swap(vec[i], vec[depth]);
        permutation(vec, depth + 1, max, numbers, target, count, temp);
        swap(vec[i], vec[depth]);
    }
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    vector<bool> sign;      // false is negative, ture is positive
    sign.resize(numbers.size());
    fill_n(sign.begin(), sign.size(), true);

    int count = 0;
    int temp = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        temp += numbers[i];
    }

    if (target == temp)
        return 1;

    for (int i = 0; i < numbers.size(); i++)
    {
        temp -= numbers[i];
    }

    if (target == temp)
        return 1;

    map<string, bool> results;

    for(int i = 0; i < numbers.size() - 1; i++)
    {
        sign[i] = false;
        permutation(sign, 0, numbers.size(), numbers, target, count, results);
    }

    return results.size();
}
```
결과는 나오는거같지만 타임오버나옴
