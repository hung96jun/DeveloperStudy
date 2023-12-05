배열의 맨 앞과 맨 뒤를 이어붙인 큐 구조로, 요소가 끝까지 다 찼다고 했을 때 그 뒤에 비어져있는 0번 인덱스에 값을 채울 수 있게 설계되었다. [[Queue]]의 문제점이 개선된 것이 환형 큐이다.
배열의 Front와 Rear를 회전시켜 현재 요소들에서 제일 앞과 제일 뒤의 다음을 알 수 있다.
>[!tip] 활용
>- 자료를 생성하는 작업과 그 자료를 이용하는 작업이 비동기적으로 일어나는 경우
>- 자료를 생성하는 작업이 여러 곳에서 일어나는 경우
>- 자료를 이용하는 작업이 여러 곳에서 일어나는 경우
>- 자료를 생성하는 작업과 그 자료를 이용하는 작업이 양쪽 다 여러 곳에서 일어나는 경우
>- 자료를 처리하여 새로운 자료를 생성하고, 나중에 그 자료를 또 처리해야 하는 작업의 경우

- 규칙
	- 정해진 개수의 저장 공간을 빙 돌려가며 이용
	- 큐가 가득 차면 더 이상 원소를 넣을 수 없음
- 연산
	- size
	- isEmpty
	- isFull
	- enqueue
	- dequeue
	- peek

```C++
template<typename T>
class CircularQueue
{
public:
	CircularQueue() = delete;
	CircularQueue(int capacity) : capacity(capacity)
	{
		datas = new T[capacity];
		front = &datas[capacity - 1];
		rear = &datas[capacity - 1];
	}
	~CircularQueue()
	{
		delete[] datas;
		
		front = nullptr;
		rear = nullptr;
		datas = nullptr;
	}

	const int Size() const { return size; }

	void Enqueue(T data)
	{
		index++;
		if (index == capacity)
			index = 0;

		datas[index] = data;
		front = &datas[index];

		size++;
	}

	T Dequeue()
	{
		if (size == 0) return -1;

		T result = *front;
		index--;
		if (index < 0)
			index = capacity - 1;

		front = &datas[index];

		size--;
		return result;
	}

	T Peek()
	{
		return *front;
	}

	const bool IsFull()
	{
		return size == capacity;
	}

	const bool IsEmpty()
	{
		return size == 0;
	}

private:
	T* front = nullptr;
	T* rear = nullptr;

	T* datas;
	const int capacity = 0;
	int size = 0;
	int index = -1;
};
```