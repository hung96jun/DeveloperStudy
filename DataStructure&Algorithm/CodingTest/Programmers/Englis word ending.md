```C++
vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    map<string, bool> beforeWord;
    string curWord = words[0];
    int person = 1;
    int count = 1;
    bool check = true;
    beforeWord.insert({ curWord, false });
    person++;

    for (int i = 1; i < words.size(); i++)
    {
        if (person > n)
        {
            person = 1;
            count++;
        }

        if (beforeWord.count(words[i]) == 0)
            beforeWord.insert({ curWord, false });
        else
        {
            check = false;
            break;
        }

        cout << curWord << endl;

        if (curWord[curWord.size() - 1] != words[i][0])
        {
            check = false;
            break;
        }

        curWord = words[i];
        person++;
    }

    if (check == true)
        answer = { 0, 0 };
    else
        answer = { person, count };

    return answer;
}
```