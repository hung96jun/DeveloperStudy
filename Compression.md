- 문자열이 매개변수로 전달되었을 때 해당 문자열을 압축하여 값을 추출하여 vector에 담는 문제
	1. 현재 사전에는 `KAKAO`의 첫 글자 `K`는 등록되어 있으나, 두 번째 글자까지인 `KA`는 없으므로, 첫 글자 `K`에 해당하는 색인 번호 11을 출력하고, 다음 글자인 `A`를 포함한 `KA`를 사전에 27 번째로 등록한다.
	2. 두 번째 글자 `A`는 사전에 있으나, 세 번째 글자까지인 `AK`는 사전에 없으므로, `A`의 색인 번호 1을 출력하고, `AK`를 사전에 28 번째로 등록한다.
	3. 세 번째 글자에서 시작하는 `KA`가 사전에 있으므로, `KA`에 해당하는 색인 번호 27을 출력하고, 다음 글자 `O`를 포함한 `KAO`를 29 번째로 등록한다.![[Pasted image 20231108102759.png]]![[Pasted image 20231108102812.png]]
```C++
void findKey(map<string, int>& keys, string target, int index, string& curKey, vector<int>& result)
{
    if (index == target.size())
        return;

    string find = curKey + target[index];

    if (keys.count(find) == 0)
    {
        pair<string, int> key;
        key.first = find;
        key.second = keys.size() + 1;

        keys.insert(key);
        find = target[index];
    }

    if (find.size() > 1)
    {
        result.erase(result.end() - 1);
    }

    result.push_back(keys[find]);

    findKey(keys, target, ++index, find, result);
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> keys;
    char key = 'A';

    for (int i = 1; i <= 26; i++)
    {
        pair<string, int> keyPair;
        keyPair.first = key++;
        keyPair.second = i;
        
        keys.insert(keyPair);
    }

    string curKey = "";
    findKey(keys, msg, 0, curKey, answer);

    return answer;
}
```
값을 추출하는 것은 문제없이 됬지만 KAKAO를 예로 들어 K, A, K, KA, O의 값을 추출하게 되었다. K, KO는 동일한 문자가 들어가있기 때문에 K값을 지우고 KO값을 다시 넣을 수 있도록 앞에서 찾은 value값을 삭제하는 기능을 추가하여 해결.