- 노드 기반 선형 자료구조의 한 종류이다.
- 임의의 위치에 원소 추가, 제거 하는 작업이 O(1)의 시간 복잡도로 빠르다는 장점이 있다.
- 노드 기반이기 때문에 임의의 원소에 바로 접근할 수 없고 반복자를 통해 순차적으로 접근해야 한다는 단점이 있다.

```C++
template<typename T>
struct Node
{
	Node() {}
	Node(T data) {}

	Node<T>* front = nullptr;
	Node<T>* next = nullptr;
	T data;
};

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		begin = new Node<T>();
		end = new Node<T>();

		begin->next = end;
		end->front = begin;
	}

	~LinkedList()
	{
		Clear();
	}

	T operator[](const int i)
	{
		int index = 0;
		Node<T>* result = begin;

		while (i != index)
		{
			result = result->next;
			++index;
		}

		return result->data;
	}

	void Insert(T data)
	{
		size++;

		if (size == 1)
		{
			begin->data = data;
			return;
		}

		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		newNode->next = end;
		end->front->next = newNode;

		newNode->front = end->front;
		end->front = newNode;
	}

	void Insert(Node<T>* parent, T data)
	{
		Node<T>* before = parent;
		Node<T>* next = before->next;

		Node<T>* newNodde = new Node<T>();
		newNodde->data = data;

		before->next = newNodde;
		newNodde->front = before;

		next->front = newNodde;
		newNodde->next = next;

		size++;
	}

	void Delete(Node<T>* node)
	{
		Node<T>* before = node->front;
		Node<T>* next = node->next;

		next->front = before;
		if (before != nullptr)
			before->next = next;
		else
		{
			begin = next;
		}

		delete node;

		size--;
	}

	void Clear()
	{
		Node<T>* node = begin;

		while (true)
		{
			if (node == end)
			{
				delete node;
				break;
			}

			Node<T>* nextNode = node->next;
			delete node;
			node = nextNode;
		}
		
		size = 0;
	}

	const int Size() const { return size; }

	Node<T>* Find(const int i)
	{
		int index = 0;
		Node<T>* result = begin;

		while (i != index)
		{
			result = result->next;
			++index;
		}

		return result;
	}

private:
	Node<T>* begin = nullptr;
	Node<T>* end = nullptr;

	int size = 0;
};
```