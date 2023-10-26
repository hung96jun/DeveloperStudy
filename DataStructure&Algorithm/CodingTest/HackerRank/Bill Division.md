k : 더해지면 안되는 값의 Index
b : 더해진 값에서 빼는 값
bill : 전부 더해져야 하는 값
```C++
void bonAppetit(vector<int> bill, int k, int b) 
{
	int value = 0;

	for (int i = 0; i < bill.size(); i++)
	{
		if (i == k) continue;
		value += bill[i];
	}

	value *= 0.5f;
	value = b - value;

	if (value <= 0)
	{
		cout << "Bon Appetit";
		return;
	}

	cout << value;
}
```