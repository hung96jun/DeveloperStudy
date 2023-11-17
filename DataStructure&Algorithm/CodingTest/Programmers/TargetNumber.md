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
```C++
void dfs(vector<int> numbers, int target, int result, int index, int& count)
{
    if (index == numbers.size())
    {
        if (result == target)
        {
            count++;
        }

        return;
    }

    int sum = result + numbers[index];
    int dif = result - numbers[index];
    int nextIndex = ++index;

    dfs(numbers, target, sum, nextIndex, count);
    dfs(numbers, target, dif, nextIndex, count);
}

int solution(vector<int> numbers, int target)
{
    int result = 0;
    dfs(numbers, target, 0, 0, result);

    return result;
}
```
트리 구조를 생각했을때, ![[Pasted image 20231108094145.png]]
위 이미지를 코드로 구현한 것이다. 재귀를 돌면서 +연산을 다 하며 맨 마지막까지 연산 후, 위로 한칸씩 다시 돌아가며 +연산과 -연산을 다시 하면서 결과를 찾아내는 것으로 첫 번째 코드에서는 중복된 연산을 수차례 하기 때문에 타임오버가 났지만 위 코드 같은경우에는 중복된 연산을 하지 않기때문에 깔끔한 결과를 만들어낼 수 있다.
