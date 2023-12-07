트리는 비선현 자료구조로, 노드로 구성된 계층적 자료구조이다. 최상위(Root) 노드를 만들고, 부모(Parent) 노드에 자식(Child) 노드를 추가하고, 그리고 그 자식 노드가 부모 노드로서 또 다른 자식 노드를 추가하는 구조를 가짐
- 특징
	- 트리에 또 다른 트리가 있는 재귀적 자료구조
	- 데이터를 순차적으로 저장하지 않는, 비선형 자료구조
	- 이진 트리(Binary Tree), 이진 탐색 트리(BST, Binary Search Tree), 균형 트리(Balanced Tree), 힙 트리(Heap Tree) 등 다양한 종류가 존재함
>[!tip] 장점
>- (Dynamic) Array나 LinkedList에서는 삽입이나 삭제를 수행하는데 O(N)의 시간 복잡도를 가진다.
>	- Array : Index로 빠르게 접근 가능하지만, Shift 과정에서 O(N) 소요
>	- Dynamic Array : Index로 빠르게 접근 가능하지만, 작업 외 데이터들을 임시 배열로 복사/이동 하는 과정에서 O(N) 소요
>	- Linked List : 작업 데이터를 찾기 위해 순회하는 과정에서 O(N) 소요
>- Tree는 편항 Tree가 아닌 이상 일반적으로 삽입/삭제 수행시 O(logN)의 시간 복잡도를 가진다.
>- 계층적 관계를 표현하는데 유용함

>[!tip] 단점
>- 편한 Tree가 되었을 경우 배열과 같은 형태를 띄게 됨으로 데이터 탐색을 순차 탐색을 해야 한다는 문제가 발생한다. 이 때에 시간 복잡도는 O(N)을 가진다.


- Tree의 구성 요소
	- Node : Tree를 구성하는 각각의 요소
	- Edge : Tree를 구성하기 위해 노드와 노드를 연결하는 선의 역할
	- Root Node : Tree 구조에서 최상위에 있는 노드
	- Parent Node : 자식 노드를 가진 노드
	- Child Node : 부모 노드를 가진 노드
	- Sibiling Node : 같은 부모를 가진 자식 노드
	- Terminal Node : 자식 노드가 없는 노드(Leaf Node)
	- Internal Node : 자식 노드가 있는 노드(Branch Node)
- Tree에 사용되는 용어
	- Depth : 어떤 노드에서 루트 노드까지 가장 긴 경로의 간전(Edge)의 수
	- Height : 어떤 노드에서 단말 노드(Terminal Node)까지 가장 긴 경로의 간선(Edge)의 수
	- Level : 루트 노드로부터 임의의 노드까지의 깊이(루트 노드의 레벨 = 1)
	- Degree : 노드의 자식 수
	- Path : 한 노드에서 다른 노드에 이르는 길 사이에 놓여있는 노드들의 순서
	- Path Length : 해당 경로를 잇는 총 노드의 수
	- Size : 자신을 포함한 자손의 노드 수
	- Width : 해당 레벨에 있는 노드 수
	- Breadth : 리프 노드의 수
	- Distance : 두 노드 사이의 최단 경로에 있는 간선(Edge)의 tn
	- Order : 부모 노드가 가질 수 있는 최대 자식의 수(이진 트리의 Order = 2)
- 이진 트리 탐색
	1. in-order(중위 순회) : 왼쪽 자식 노드(L), 내 노드(P), 오른쪽 자식 노드(R) 순서로 방문
	2. pre-order(전위 순휘) : 내 노드(P), 왼쪽 자식 노드(L), 오른쪽 자식 노드(R) 순서로 방문
	3. post-order(후위 순회) : 왼쪽 자식 노드(L), 오른쪽 자식 노드(R), 내 노드(P) 순서로 방문
	4. level-order(레벨 순회) : 내 노드(P), 내 노드로부터 깊이 1인 노드들, 내 노드로부터 깊이 2인 노드들, ..., 내 노드로부터 깊이 N인 노드들(N : 트리의 깊이)(깊이 우선 탐색([[DFS]]))
- Tree의 종류
	- [[Binary Tree]] : 자식 노드가 최대 2개까지만 허용하는 트리
	- Ternary Tree : 자식 노드가 3개 이상 존재하는 트리
	- Skewed Binary Tree : 모든 노드가 부모의 왼쪽 혹은 오른쪽으로 편항 되어 있는 트리
	- [[Binary Search Tree]] : 부모 노드의 왼쪽 자식 노드에는 부모 노드보다 작은 값이, 오른쪽 자식 노드에는 부모 노드보다 큰 값이 들어가 있어야 하는 트리. 값을 찾는데 편리한 조건(전위 순회, 중위 순회, 후위 순회 - 루트 노드의 방문 순서가 기존, 레벨 순회)
	- [[Complete Binary Tree]] : 왼쪽에서 오른쪽으로 순서대로 차곡차곡 채워져 있는 이진 트리
	- [[Full Binary Tree]] : 모든 노드가 0 또는 2개의 자식 노드를 갖는 트리
	- [[Perfect Binary Tree]] : 모든 노드의 차수가 2이며, 모든 단말 노드의 레벨도 동일한 경우
	- [[Balanced Binary Tree]] : 균형 이진 트리는 왼쪽과 오른쪽 트리의 높이 차이가 1만큼 나는 트리이다. 
	- [[Red-Black Tree]] : 자가 균형 이진 탐색 트리(self-balancing binary seach tree)로, 대표적으로 연관 배열 등을 구현하는데에 사용되는 자료구조.
	- [[AVL]] : 스스로 균형을 잡는 이진 탐색 트리