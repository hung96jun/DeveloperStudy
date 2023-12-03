```C++
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    map<int, int> stocks;

    answer.resize(prices.size());
    fill_n(answer.begin(), answer.size(), -1);

    for (int i = 0; i < prices.size(); i++)
    {
        int curPrice = prices[i];

        if (stocks.count(curPrice) == 0)
        {
            stocks.insert({ curPrice, i });

            if (stocks.count(curPrice + 1) != 0)
            {
                int beforeCount = stocks[curPrice + 1];
                answer[beforeCount] = i - beforeCount;
                stocks[curPrice + 1] = i;
            }
        }

        else
        {
            stocks[curPrice] = i;
            

            if (stocks.count(curPrice + 1) != 0)
            {
                int beforeCount = stocks[curPrice + 1];
                answer[beforeCount] = i - beforeCount;
                stocks[curPrice + 1] = i;
            }
        }
    }

    for (pair<int, int> stock : stocks)
    {
        int index = stock.second;
        if (answer[index] != -1)
            continue;

        answer[index] = answer.size() - index - 1;
    }

    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] != -1)
            continue;

        answer[i] = answer.size() - i - 1;
    }


    return answer;
}
```
실패한 코드