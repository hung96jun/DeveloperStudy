- 입력된 두 문자열의 교집합과 합집합을 구하여 자카드 유사도(J(A, B) = 교집합/합집합)을 나타내는 문제(자카드 유사도 * 65536을 곱하여 소수점 아래수를 버리고 정수부만 출력)
```C++
void stringCutting(vector<string>& vec, string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        string temp;

        if (i < str.size() - 1)
            temp = { str[i], str[i + 1] };
        else
            break;

        vec.push_back(temp);
    }
}

void organize(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (((str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122) ||
            (str[i] >= 48 && str[i] <= 57)) == false)
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;

    organize(str1);
    organize(str2);

    vector<string> divideStr1, divideStr2;
    stringCutting(divideStr1, str1);
    stringCutting(divideStr2, str2);

    int interSet = 0;       // intersection
    int unionSet = 0;

    for (int i = 0; i < divideStr1.size(); i++)
    {
        bool check = false;

        for (int j = 0; j < divideStr2.size(); j++)
        {
            if (_stricmp(divideStr1[i].c_str(), divideStr2[j].c_str()) == 0)
            {
                check = true;
                divideStr2.erase(divideStr2.begin() + j);
                interSet++;
                break;
            }
        }

        if(check == true)
        {
            divideStr1.erase(divideStr1.begin() + i);
            i--;
        }
    }

    unionSet = divideStr1.size() + divideStr2.size() + interSet;
    float answerTemp = (float)interSet / (float)unionSet;

    return 65536 * answerTemp;
}
```
- 위 코드는 정상적으로 동작한다 생각했지만 틀린 코드인거 같다.
```C++
void stringCutting(vector<string>& vec, string str)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        string temp;

        if ((str[i] >= 65 && str[i] <= 90) == false ||
            (str[i + 1] >= 65 && str[i + 1] <= 90) == false)
            continue;

        temp = str.substr(i, 2);
        vec.push_back(temp);
    }
}

int solution(string str1, string str2) {
    int answer = 0;

    // 영소문자를 영대문자로 일괄 수정
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    // 문자열을 2개씩 끊어서 vector에 저장
    vector<string> divideStr1, divideStr2;
    stringCutting(divideStr1, str1);
    stringCutting(divideStr2, str2);
    
    int interSet = 0;       // 교집합
    int unionSet = 0;       // 합집합

    for (int i = 0; i < divideStr1.size(); i++)
    {
        bool check = false;

        for (int j = 0; j < divideStr2.size(); j++)
        {
            if (_stricmp(divideStr1[i].c_str(), divideStr2[j].c_str()) == 0)
            {
                check = true;
                divideStr2.erase(divideStr2.begin() + j);
                interSet++;
                break;
            }
        }

        if(check == true)
        {
            divideStr1.erase(divideStr1.begin() + i);
            i--;
        }
    }

    // 겹치지 않는 수 + 교집합 갯수
    unionSet = divideStr1.size() + divideStr2.size() + interSet;
    if (unionSet == 0) return 65536;

    float answerTemp = (float)interSet / (float)unionSet;

    return 65536 * answerTemp;
}
```
- 위 코드는 성공한 코드이며, 영문자를 제외한 문자를 삭제 후 커팅을 하는 것이 아닌 커팅을 했을때 영문자를 제외한 문자가 포함되있을 경우 해당 커팅됨 문자들 자체를 제외해야 한다는 점에서 문제가 발생했다.