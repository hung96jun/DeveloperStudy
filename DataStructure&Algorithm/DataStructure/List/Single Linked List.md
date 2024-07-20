- Head 노드를 기준으로 메모리를 동적 할당하여 노드를 추가하며, 데이터를 저장하고, 각 노드들은 데이터 공간과 다음 노드의 주소를 가리키는 공간으로 구성된다.
- 메모리 구조
	![[Pasted image 20240709204352.png]]
	- Stack영역의 포인터가 동적할당(heap 영역에 생성)한 노드를 가리키는 구조로 되어있으며, heap 영역의 각 노드들은 다음 노드를 가리킨다.
- 기능
	- 추가
		- 값를 입력받아 제일 뒤의 노드에 추가
	- 삽입
		- 노드와 값를 입력받아 해당 노드 뒤에 노드를 추가
	- 삭제
		- 값을 입력받아 해당 값을 가진 노드를 삭제
- 코드
```C++
template<typename T>
struct Node
{
	bool operator==(const Node<T>& other)
	{
		return (Next == other.Next) && (Data == other.Data);
	}

	Node* Next = nullptr;
	T Data;
};

template<typename T>
class SingleLinkedList
{
public:
	SingleLinkedList()
	{
		Head = new Node<T>();
	}
	~SingleLinkedList()
	{
		while (Head != Tail)
		{
			Node<T>* node = Head;
			Head = Head->Next;
			delete node;
			node = nullptr;
		}

		delete Head;
		Head = nullptr;
		Tail = nullptr;

		Size = 0;
	}

	void PushBack(T Data)
	{
		if (Tail == nullptr)
		{
			Tail = new Node<T>();
			Head->Next = Tail;
			Tail->Data = Data;
		}
		else
		{
			Node<T>* node = new Node<T>();
			node->Data = Data;

			Tail->Next = node;
			Tail = node;
		}

		++Size;
	}

	const bool Insert(T Prev, T Data)
	{
		Node<T>* node = Find(Prev);
		if (node == nullptr) return false;

		Node<T>* newNode = new Node<T>();
		newNode->Next = node->Next;
		node->Next = newNode;
		newNode->Data = Data;

		++Size;

		return true;
	}

	Node<T>* Find(T Data)
	{
		if (Tail == nullptr)
			return nullptr;

		Node<T>* node = Head;
		while (node != nullptr)
		{
			if (node->Data == Data)
				break;

			node = node->Next;
		}

		return node;
	}

	const bool Erase(T Data)
	{
		if (Tail == nullptr)
			return false;

		Node<T>* node = Head;
		Node<T>* prev = nullptr;
		while (node->Next != nullptr)
		{
			if (node->Next->Data == Data)
			{
				prev = node;
				node = node->Next;
				break;
			}

			node = node->Next;
		}

		if (node == Tail)
			Tail = prev;

		prev->Next = node->Next;
		node->Next = nullptr;

		delete node;
		node = nullptr;

		--Size;

		return true;
	}

	const unsigned int GetSize() const { return Size; }

private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	int Size = 0;
};
```