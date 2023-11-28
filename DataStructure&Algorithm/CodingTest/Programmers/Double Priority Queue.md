- 주어진 명령어에따라 값을 입력, 삭제를 한다.
- 하나 잘못 본것은 반환값은 최솟값과 최댓값만 반환한다는 점이다.
```C++
vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (string operation : operations)
    {
        int index = -1;

        char oper = operation[0];
        size_t size = operation.size();
        string numStr = operation;
        numStr.erase(0, 2);
        int num = atoi(numStr.c_str());

        switch (oper)
        {
        case 'I':
        {
            answer.push_back(num);
        }
            break;
        case 'D':
        {
            sort(answer.begin(), answer.end());

            if (answer.size() == 0) continue;

            if (num == 1)       // 최댓값 삭제
                answer.erase(answer.end() - 1);

            else if (num == -1) // 최솟값 삭제
                answer.erase(answer.begin());
        }
            break;
        default:
            break;
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
        return { 0, 0 };

    int last = *(answer.end() - 1);

    return { last, answer[0] };
}
```
입력은 계속 push_back으로만 하고, 삭제하기 전에 정렬 후 삭제. 결과값 내기 전 한번 더 정렬을 하여 값 추출을 쉽게 하여 마무리.
```C++
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
```
[[multiset]]을 사용한 풀이