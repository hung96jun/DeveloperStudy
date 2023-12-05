우선순위 큐([[Prority Queue]])를 위하여 만들어진 자료구조
- 완전 이진트리의 일종으로 우선순위 큐를 위하여 만들어진 자료구조
- 여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조
- 힙은 일종의 반정렬 상태(느슨한 정렬 상태)를 유지한다.
	- 큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있다는 정도
	- 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리를 의미한다.
- 힙 트리에서는 중복된 값을 허용한다.(이진 탐색 트리에서는 중복된 값을 허용하지 않는다.)

### 힙 종류
- 최대 힙
	- 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
	- Key(부모 노드) >= Key(자식 노드)
- 최소 힙
	- 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리
	- Key(부모 노드) <= Key(자식 노드)

### 힙 구현
- 힙을 저장하는 표준적인 자료구조는 배열이다.
- 구현을 쉽게 하기 위하여 배열의 첫 번째 인덱스인 0은 사용되지 않는다.
- 특정 위치의 노드 번호는 새로운 노드가 추가되어도 변하지 않는다.
	- 예를 들어 루트의 인덱스는 1, 왼쪽 노드는 2, 오른쪽 노드는 3
- 힙에서의 부모 노드와 자식 노드의 관계
	- 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2
	- 오른쪽 자식의 인덱스 = (부모의 인덱스) * 2 + 1
	- 부모의 인덱스 = (자식의 인덱스) / 2
	- ![[Pasted image 20231001214437.png]]

### 힙의 삽입
- 힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 이어서 삽입
- 새로운 노드를 부모 노드들과 교환해서 힙의 성질을 만족시킴
- ![[Pasted image 20231001214507.png]]

### 힙의 삭제
- 최대 힙에서 최댓값은 루트 노드이므로 루트 노드가 삭제된다.
	- 최대 힙에서 삭제 연산은 최댓값을 가진 요소를 삭제하는 것
- 삭제된 루트 노드에는 힙의 마지막 노드를 가져옴
- 힙을 재구성
- ![[Pasted image 20231001214525.png]]

- 노드와 백터를 사용한 구현
```C++
template<typename T>
struct Node
{
	Node() {}
	Node(const T data, const int level) : data(data), level(level) {}
	Node(Node<T>* parent, const T data, const int level) : parent(parent), data(data), level(level) {}
	~Node()
	{
		if (parent != nullptr)
		{
			if (parent->leftChild == this)
				parent->leftChild = nullptr;
			else if (parent->rightChild == this)
				parent->rightChild = nullptr;
		}

		parent = nullptr;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	void ChangeLevel(const int level) { level = level; }

	bool operator==(const Node<T>& other)
	{
		return (parent == other.parent && leftChild == other.leftChild &&
			rightChild == other.rightChild && data == other.data);
	}

	Node<T>* parent = nullptr;
	Node<T>* leftChild = nullptr;
	Node<T>* rightChild = nullptr;

	T data;
	int level = 0;
};

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue()
	{
		nodes.push_back(nullptr);
	}
	~PriorityQueue()
	{
		while (root != nullptr)
			Pop();

		nodes.clear();
	}

	void Insert(T data)
	{
		if (root == nullptr)
		{
			root = new Node<T>(data, 0);
			nodes.push_back(root);
		}
		else
		{
			int parentIndex = (int)(nodes.size()) / 2;
			Node<T>* parentNode = nodes[parentIndex];
			if (parentNode->leftChild != nullptr && parentNode->rightChild != nullptr)
				parentNode = nodes[parentIndex + 1];

			int level = parentNode->level + 1;
			Node<T>* newNode = new Node<T>(parentNode, data, level);
			
			if (parentNode->leftChild == nullptr)
				parentNode->leftChild = newNode;
			else if (parentNode->rightChild == nullptr)
				parentNode->rightChild = newNode;
			
			nodes.push_back(newNode);

			ParentHeapify(newNode);
		}
	}

	T Pop()
	{
		if (root == nullptr) return -1;

		T result = root->data;

		int index = (int)(nodes.size() - 1);
		Node<T>* lastNode = nodes[index];
		root->data = lastNode->data;

		// delete node
		{
			delete nodes[index];
			nodes[index] = nullptr;
			nodes.erase(nodes.begin() + index);

			if (nodes.size() == 1)
				root = nullptr;
		}

		ChildHeapify(root);

		return result;
	}

	T Top() { return root->data; }

private:
	void ParentHeapify(Node<T>* node)
	{
		if (node->parent == nullptr) return;

		Node<T>* parentNode = node->parent;
		if (parentNode->data < node->data)
			Swap(parentNode, node);
		else
			return;

		ParentHeapify(parentNode);
	}

	void ChildHeapify(Node<T>* node)
	{
		if (node == nullptr) return;

		if (node->leftChild == nullptr &&
			node->rightChild == nullptr) return;

		Node<T>* childNode = nullptr;
		if (node->rightChild != nullptr)
		{
			childNode = node->rightChild;
			if (node->data < childNode->data)
				Swap(childNode, node);
		}

		if (node->leftChild != nullptr)
		{
			childNode = node->leftChild;
			if (node->data < childNode->data)
				Swap(childNode, node);
		}

		ChildHeapify(childNode);
	}

	void Swap(Node<T>* node1, Node<T>* node2)
	{
		T tempData = node1->data;
		node1->data = node2->data;
		node2->data = tempData;
	}

private:
	Node<T>* root = nullptr;
	vector<Node<T>*> nodes;
};
```

- 백터만 사용한 구현
```C++
template<typename T>
class PriorityQueue
{
public:
	PriorityQueue() 
	{
		datas.push_back(-1);
	}
	~PriorityQueue() 
	{
		datas.clear();
	}

	void Push(T data)
	{
		datas.push_back(data);

		int index = (int)(datas.size()) - 1;
		while (datas[index / 2] < datas[index] && index != 1)
		{
			Swap(index, index / 2);
			index = index / 2;
		}

		size++;
	}

	T Pop()
	{
		T result = datas[1];

		Swap(1, (int)(datas.size()) - 1);
		datas.erase(datas.begin() + datas.size() - 1);

		int index = 1;
		
		while (index * 2 < datas.size() - 1)
		{
			if ((int)(datas.size()) - 1 >= index * 2 + 1)
			{
				T left, right;
				left = datas[index * 2];
				right = datas[index * 2 + 1];

				if (left > right)
				{
					if (left > datas[index])
					{
						Swap(index, index * 2);
						index = index * 2;
					}
				}
				else if (right > left)
				{
					if (right > datas[index])
					{
						Swap(index, index * 2 + 1);
						index = index * 2 + 1;
					}
				}
			}

			else
			{
				if (datas[index * 2] > datas[index])
				{
					Swap(index, index * 2);
					index = index * 2;
				}
			}
		}

		size--;
		return result;
	}

	T Top() { return datas[1]; }

private:
	void Swap(int index1, int index2)
	{
		T temp = datas[index1];
		datas[index1] = datas[index2];
		datas[index2] = temp;
	}

private:
	vector<T> datas;
	int size = 0;
};
```