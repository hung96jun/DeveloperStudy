```C++
bool findNum(string& word, const string compair, int depth, int& result)
{
    if (word == compair) return true;

    char curWord;
    bool check = false;

    if (depth == word.size())
        depth = 4;

    if (word[depth] == 'N')
    {
        word[depth] = 'A';
        check = true;
    }
    else
    {
        char curChar = word[depth];

        if (curChar == 'A')
            word[depth] = 'E';
        else if (curChar == 'E')
            word[depth] = 'I';
        else if (curChar == 'I')
            word[depth] = 'O';
        else if (curChar == 'O')
            word[depth] = 'U';
        else if (curChar == 'U')
        {
            while (true)
            {
                word[depth] = 'N';
                depth--;
                result--;

                if (word[depth] != 'U')
                    break;
            }
            depth--;
        }
    }

    depth++;
    ++result;

    // 재귀
    for (int i = 0; i < 5; i++)
    {
        if (findNum(word, compair, depth, result))
            return true;
    }
}

int solution(string word) {
    int answer = 0;

    if (word.size() < 5)
    {
        int size = word.size();
        int index = 5 - size;

        for (int i = 0; i < index; i++)
            word += 'N';
    }

    string curWord = "NNNNN";
    findNum(curWord, word, 0, answer);

    return answer;
}
```
실패

```C++
const char changeChar[5] = { 'A', 'E', 'I', 'O', 'U' };

bool findNum(string& word, const string compair, int depth, int count, int& result)
{
    if (depth == 5)
        return false;

    if (word == compair)
        return true;

    word[depth] = changeChar[count];
    result++;

    for (int i = 0; i < 5; i++)
    {
        if (findNum(word, compair, depth + 1, i, result) == true)
            return true;

        if (depth + 1 <= 4)
            word[depth + 1] = 'N';
    }
}

int solution(string word) {
    int answer = 0;

    {
        int index = 5 - word.size();
        for (int i = 0; i < index; i++)
            word += "N";
    }

    string curWord = "NNNNN";
    for (int i = 0; i < 5; i++)
    {
        if (findNum(curWord, word, 0, i, answer) == true)
            break;
    }
    
    return answer;
}
```
Visual studio에서는 정상 동작되지만 프로그래머스에서는 결과값이 무조건 5만 나옴
레퍼런스로 answer값 변경이 되는건 맞는거같음. solution 함수 내부에서 반복문 돌리기 전에 answer값을 변경하고 돌리면 +5값이 나오긴함

```C++
const char changeChar[5] = { 'A', 'E', 'I', 'O', 'U' };

bool dfs(string& word, const string compair, int depth, int count, int& result)
{
    if (depth == 5)
        return false;

    word[depth] = changeChar[count];
    result++;
    
    if (word == compair)
        return true;

    for (int i = 0; i < 5; i++)
    {
        if (dfs(word, compair, depth + 1, i, result) == true)
            return true;

        if (depth + 1 <= 4)
            word[depth + 1] = 'N';
    }
    
    return false;
}

int solution(string word) {
    int answer = 0;

    {
        int index = 5 - (int)word.size();
        for (int i = 0; i < index; i++)
            word += "N";
    }

    string curWord = "NNNNN";
    for (int i = 0; i < 5; i++)
    {
        if (dfs(curWord, word, 0, i, answer) == true)
            break;
    }

    return answer;
}
```
프로그래머스에서도 정상적으로 동작

```C++
int solution(string word) {
    string v = string("AEIOU");
    int a = word.size();

    for(int i = 0, b = 1; i < word.size(); i++, b *= 5)
        a += v.rfind(word[i]) * 781 / b;

    return a;
}
```
수학적 규칙을 사용한 풀이1

```C++
int solution(string word)
{
    const int weights[5] = { 781, 156, 31, 6, 1 };
    int answer = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        int current;
        switch (word[i])
        {
        case 'A':
            current = 0;
            break;
        case 'E':
            current = 1;
            break;
        case 'I':
            current = 2;
            break;
        case 'O':
            current = 3;
            break;
        case 'U':
            current = 4;
            break;
        default:
            assert(false);
        }
        ++answer;
        answer += current * weights[i];
    }
    return answer;
}
```
수학적 규칙을 사용한 풀이2