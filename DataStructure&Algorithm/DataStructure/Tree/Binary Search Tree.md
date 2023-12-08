이진 탐색 트리는 다음과 같은 규칙을 가진다.
- 각 노드에 값이 있다.
- 값들은 전순서가 있다.
- 노드의 왼쪽 서브트리에는 그 노드의 값보다 작은 값들을 지닌 노드들로 이루어져 있다.
- 노드의 오른쪽 서브트리에는 그 노드의 값보다 큰 값을 지닌 노드들로 이루어져 있다.
- 좌우 하위 트리는 각각이 다시 이진 탐색 트리여야 한다.
>[!tip] 전순서
>전순서 집합은 임의의 두 원소를 비교할 수 있는 부분 순서 집합이다.

탐색
- 이진 탐색 트리에서 x를 가진 노드를 검색하고자 할때, 트리에 해당하는 노드가 존재하면 해당 노드를 리턴하고, 존재하지 않으면 NULL을 반환한다.
- 검색하고자 하는 값을 루트노드와 먼저 비교하고, 일치할 경우 루트노드를 반환한다.
	- 불일치하고 검색하고자 하는 값이 루트노드의 값보다 작을 경우 왼쪽 서브트리에서 재귀적으로 검색한다.
	- 불일치하고 검색하고자 하는 값이 루트노드의 값과 같거나 클경우 오른쪽 서브트리에서 재귀적으로 검색한다.

삽입
- 삽입을 하기 전, 검색을 수행한다.
- 트리를 검색한 후 키와 일치하는 노드가 없으면 마지막 노드에서 키와 노드의 크기를 비교해서 왼쪽이나 오른쪽에 새로운 노드를 삽입한다.

삭제
삭제하려는 노드의 자식 수에 따라
- 자식 노드가 없는 노드(리프 노드) 삭제 : 해당 노드를 단순 삭제한다.
- 자식 노드가 1개인 노드 삭제 : 해당 노드를 삭제하고 그 위치에 해당 노드의 자식 노드를 대입한다.
- 자식 노드가 2개인 노드 삭제 : 삭제하고자 하는 노드의 값을 해당 노드의 왼쪽 서브트리에서 가장 큰 값으로 변경하거나, 오른쪽 서브트리에서 가장 작은 값으로 변경 후, 해당 노드(왼쪽 서브트리에서 가장 큰 값을 가지는 노드 또는 오른쪽 서브트리에서 가장 작은 값을 가지는 노드)를 삭제한다.

```C++
template<typename T>
struct Node
{
	Node() {}
	Node(T data, Node<T>* parent = nullptr) : data(data), parent(parent) {}
	~Node()
	{
		parent = nullptr;
		leftChild = nullptr;
		rightChild = nullptr;

		data = -1;
	}

	bool IsHasChils() { return leftChild != nullptr || rightChild != nullptr; }

	Node<T>* parent = nullptr;
	Node<T>* leftChild = nullptr;
	Node<T>* rightChild = nullptr;
	T data;
};

template<typename T>
class Tree
{
public:
	Tree() {}
	~Tree() 
	{
		while (root != nullptr)
		{
			Delete(root->data);
		}

		root = nullptr;
	}

	void Insert(T data)
	{
		Node<T>* node = new Node<T>(data);
		if (root == nullptr)
			root = node;
		else
		{
			Node<T>* parentNode = root;
			

			while (true)
			{
				// left
				if (parentNode->data > data)
				{
					if (parentNode->leftChild != nullptr)
						parentNode = parentNode->leftChild;
					else
					{
						parentNode->leftChild = node;
						node->parent = parentNode;
						break;
					}
				}

				// right
				else if (parentNode->data < data)
				{
					if (parentNode->rightChild != nullptr)
						parentNode = parentNode->rightChild;
					else
					{
						parentNode->rightChild = node;
						node->parent = parentNode;
						break;
					}
				}
			}
		}
	}

	Node<T>* Find(T data)
	{
		Node<T>* node = root;

		while (node->data != data)
		{
			if (node == nullptr)
				return nullptr;
			else if (node->data < data)
				node = node->rightChild;
			else if (node->data > data)
				node = node->leftChild;
		}

		return node;
	}

	void Delete(T data)
	{
		Node<T>* node = Find(data);
		Node<T>* changeNode = nullptr;

		changeNode = RightLowNode(node);
		if (changeNode != nullptr)
		{
			DeleteNode(node, changeNode);
			return;
		}

		changeNode = LeftHighNode(node);
		if (changeNode != nullptr)
		{
			DeleteNode(node, changeNode);
			return;
		}

		delete root;
		root = nullptr;
	}

private:
	Node<T>* LeftHighNode(Node<T>* node)
	{
		Node<T>* result = node->leftChild;
		if (result == nullptr)
			return nullptr;

		while (result->rightChild != nullptr)
		{
			result = result->rightChild;
		}

		return result;
	}

	Node<T>* RightLowNode(Node<T>* node)
	{
		Node<T>* result = node->rightChild;
		if (result == nullptr) 
			return nullptr;

		while (result->leftChild != nullptr)
		{
			result = result->leftChild;
		}

		return result;
	}

	void DeleteNode(Node<T>*& deleteNode, Node<T>* changeNode)
	{
		Node<T>* parent = deleteNode->parent;

		// changeNode의 자식 노드가 있을 경우
		if (changeNode->IsHasChils() == true)
		{
			Node<T>* child = nullptr;

			if (changeNode->parent->leftChild == changeNode)
			{
				child = changeNode->leftChild != nullptr ? changeNode->leftChild : changeNode->rightChild;
				changeNode->parent->leftChild = child;
				child->parent = changeNode->parent;
			}
			else if (changeNode->parent->rightChild == changeNode)
			{
				child = changeNode->rightChild != nullptr ? changeNode->rightChild : changeNode->leftChild;
				changeNode->parent->rightChild = changeNode->rightChild != nullptr ? changeNode->rightChild : changeNode->leftChild;
				child->parent = changeNode->parent;
			}
		}

		// changeNode의 자식 노드가 없을 경우
		else
		{
			if (changeNode->parent->leftChild == changeNode)
				changeNode->parent->leftChild = nullptr;
			else if (changeNode->parent->rightChild == changeNode)
				changeNode->parent->rightChild = nullptr;
		}

		changeNode->parent = deleteNode->parent;
		changeNode->leftChild = deleteNode->leftChild;
		changeNode->rightChild = deleteNode->rightChild;

		delete deleteNode;
		deleteNode = nullptr;

		// if not root node
		if (parent != nullptr)
		{
			if (parent->leftChild == deleteNode)
				parent->leftChild = changeNode;
			else if (parent->rightChild == deleteNode)
				parent->rightChild = changeNode;
		}

		// if root node
		else
		{
			root = nullptr;
			root = changeNode;

			if (root->leftChild != nullptr)
				root->leftChild->parent = changeNode;
			if (root->rightChild != nullptr)
				root->rightChild->parent = changeNode;
		}
	}

private:
	Node<T>* root = nullptr;
};
```