순서가 보존되는 선형 자료구조의 한 종류, FIFO(First in First Out)메커니즘 사용
- 데이터를 받는 순서대로 정렬
- FIFO, 선입 선출 방식을 사용
- 동적 메모리
- 스택과는 달리 front원소와 back 원소에 접근할 수 있다.
- 시간 복잡도
	- 탐색 : 순차 탐색 사용 O(n)
	- 추가/삭제 : 가장 위에 데이터를 추가하거나 삭제하기 때문에 O(1)
- 문제점
	- queue는 생성시 맨 앞을 나타내는 front, 끝을 나타내는 rear, 초기 인덱스는 -1이다. 큐에 요소를 추가하면 rear+1을 하며 큐의 값을 때면 맨 앞의 값이 반환되며 front+1을 한다. 그 때문에 삽입 삭제가 반복될 경우 rear가 맨 마지막 인덱스를 가리키고, 앞에는 비어 있을 수는 있지만 꽉 찼다고 인식하게 된다. 실제 데이터를 삭제할 때마다 한 칸 앞으로 이동시키지 않고, 인덱스 단위로 큐의 연산을 진행하기 때문이다. 이 문제를 해결하기 위해 나온것이 환형 큐([[Circular Queue]])이다.

>[!tip]
>BFS나 캐시를 구현에 사용됨

>[!tip] 장점
>- 동적인 메모리 크기
>- 데이터를 받는 순서대로 정렬된다.
>- 빠른 런타임

>[!tip] 단점
>- 가장 오래된 요소만 가져온다.
>- 한 번에 하나의 데이터만 처리 가능하다.

```C++
template<typename T>
struct Node
{
	Node() {}
	Node(T data) : data(data) {}
	~Node() {}

	Node<T>* front = nullptr;
	Node<T>* next = nullptr;
	T data;
};

template<typename T>
class Queue
{
public:
	Queue() 
	{
		begin = new Node<T>();
		end = new Node<T>();

		begin->next = end;
		end->front = begin;
	}
	~Queue()
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
		Node<T>* node = end->front;

		node->next = newNode;
		newNode->front = node;

		newNode->next = end;
		end->front = newNode;

		size++;
	}

	T Pop()
	{
		Node<T>* node = begin->next;
		T result = node->data;
		Node<T>* nextNode = node->next;

		delete node;

		begin->next = nextNode;
		nextNode->front = begin;
		size--;

		return result;
	}

	void Clear()
	{
		while (size != 0)
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