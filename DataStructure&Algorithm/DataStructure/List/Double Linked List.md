- Head 노드를 기준으로 메모리를 동적 할당하여 노드를 추가하며, 데이터를 저장하고, 각 노드들은 데이터 공간과 이전 노드, 다음 노드의 주소를 가리키는 공간으로 구성된다.
- 메모리 구조
	![[Pasted image 20240716174408.png]]
- 기능
	- 추가
		- 
	- 삽입
		- 삽입될 이전 노드와 데이터를 매개변수로 입력받아 해당 노드 뒤의 노드로 생성하여 삽입한다.
	- 삭제
		- 
- 코드
```C++
template<typename T>
struct DNode
{
	DNode* Prev = nullptr;
	DNode* Next = nullptr;
	T Data;
};

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList()
	{
		Head = new DNode<T>();
		Tail = new DNode<T>();

		Head->Next = Tail;
		Tail->Prev = Head;
	}
	~DoubleLinkedList()
	{
		DNode<T>* node = Head;
		while (node->Next != nullptr);
		{
			node = Head;
			Head = node->Next;
			delete node;
			node = nullptr;
		}

		delete Head;
		delete Tail;
		Head = nullptr;
		Tail = nullptr;

		Size = 0;
	}

	void PushBack(T Data)
	{
		if (Size == 0)
			Head->Data = Data;

		else if (Size == 1)
			Tail->Data = Data;

		else
		{
			DNode<T>* node = new DNode<T>();
			node->Data = Data;

			Tail->Next = node;
			node->Prev = Tail;
			Tail = node;
		}

		++Size;
	}

	void Insert(DNode<T>* Prev, T Data)
	{
		DNode<T>* node = new DNode<T>();
		node->Data = Data;

		node->Next = Prev->Next;
		node->Prev = Prev;

		node->Next->Prev = node;
		Prev->Next = node;

		++Size;
	}


	void Erase(T Data)
	{
		DNode<T>* node = Find(Data);
		if (node == nullptr) return;

		node->Prev->Next = node->Next;
		node->Next->Prev = node->Prev;

		delete node;
		node = nullptr;

		--Size;
	}

	DNode<T>* Find(T Data)
	{
		DNode<T>* node = Head;

		while (node->Next != nullptr)
		{
			if (node->Data == Data)
				return node;

			node = node->Next;
		}

		return nullptr;
	}

	const int GetSize() { return Size; }

private:
	DNode<T>* Head = nullptr;
	DNode<T>* Tail = nullptr;
	int Size = 0;
};
```