순서가 보존되는 선형 자료구조의 한 종류, LIFO(Last In First Out) 메커니즘을 갖는다.
- 특징
	- 데이터를 받는 순서대로 정렬
	- LIFO, 선입 후출 방식을 사용
	- 동적 메모리
- 시간 복잡도
	- 탐색 : 순차 탐색 O(n)
	- 추가/삭제 : 가장 앞에 데이터를 추가하거나 가장 뒤에 데이터를 삭제하기 때문에 O(1)

>[!tip]
>DFS나 재귀 구현에 사용됨

>[!tip] 장점
>- 동적인 메모리 크기
>- 데이터를 받는 순서대로 정렬된다.
>- 빠른 런타임

>[!tip] 단점
>- 한 번에 하나의 데이터만 처리 가능하다.

```C++
template<typename T>
struct Node
{
	Node() {}
	Node(T data) : data(data) {}
	~Node() { front = nullptr; next = nullptr; }
	
	Node* front = nullptr;
	Node* next = nullptr;

	T data;
};

template<typename T>
class Stack
{
public:
	Stack()
	{
		begin = new Node<T>();
		end = new Node<T>();

		begin->next = end;
		end->front = begin;
	}
	~Stack()
	{
		Clear();

		begin->next = nullptr;
		end->front = nullptr;

		delete begin;
		delete end;
	}

	void Push(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* nextNode = begin->next;

		begin->next = newNode;
		newNode->next = nextNode;

		nextNode->front = newNode;
		size++;
	}

	T Pop()
	{
		T result = begin->next->data;
		Node<T>* nextNode = begin->next;
		begin->next = nextNode->next;
		nextNode->next->front = begin;
		
		delete nextNode;
		size--;

		return result;
	}

	void Clear()
	{
		while (size > 0)
			Pop();

		size = 0;
	}

	const int Size() const { return size; }

private:
	Node<T>* begin = nullptr;
	Node<T>* end = nullptr;

	int size = 0;
};
```