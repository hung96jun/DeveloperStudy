AVL 트리는 스스로 균형을 잡는 이진 탐색 트리이다. 트리의 높이가 h일 때 이진 탐색 트리의 시간 복잡도는 O(h)이다. 한쪽으로 치우친 편향 이진트리가 되면 트리의 높이가 높아지기 때문에 이를 방지하기위해 높이 균형을 유지하는 AVL 트리를 사용하게 됬다.

- 특징
	- AVL 트리는 이진 탐색 트리의 속성을 가진다.
	- 왼쪽, 오른쪽 서브 트리의 높이 차이가 최대 1이다.
	- 어떤 시점에서 높이 차이가 1보다 커지면 회전(rotation)을 통해 균형을 잡아 높이 차이를 줄인다.
	- AVL 트리는 높이를 logN으로 유지하기 때문에 삽입, 검색, 삭제의 시간 복잡도는 O(logN)이다.

- Balance Factor(BF)
	Balance Factor(BF)는 왼쪽 서브트리의 높이에서 오른쪽 서브트리의 높이를 뺀 값이다.
	Balance Factor(k) = height(left(k)) - height(right(k))
	- BF가 1이면 왼쪽 서브트리가 오른쪽 서브트리보다 높이가 한 단계 높다는 것을 의미.
	- BF가 0이면 왼쪽 서브트리와 오른쪽 서브트리의 높이가 같다는 것을 의미.
	- BF가 -1이면 왼쪽 서브트리가 오른쪽 서브트리보다 높이가 한 단계 낮다는 것을 의미.
	![[Pasted image 20231204073748.png]]

- 시간 복잡도

|operation|Average|Worst|
|---|---|---|
|Access|Θ(logN)|O(logN)|
|Search|Θ(logN)|O(logN)|
|Insert|Θ(logN)|O(logN)|
|Delete|Θ(logN)|O(logN)|

- 회전
	AVL 트리는 이진 탐색 트리이기 때문에 모든 작업은 이진 탐색 트리에서 사용하는 방식으로 수행된다.
	검색 및 순회 연산은 BF를 변경하지 않지만 삽입 및 삭제에서는 BF가 변경될 수 있다. 삽입 삭제 시 불균형 상태(BF가 -1, 0, 1이 아닌 경우)가 되면 AVL 트리는 불균형 노드를 기준으로 서브트리의 위치를 변경하는 rotation 작업을 수행하여 트리의 균형을 맞추게 된다.
	삽입 삭제시 노드들의 배열에 따라 4rkwl (LL, RR, LR, RL) 불균형이 발생할 수 있으며 각 상황마다 rotation에 방향을 달리하여 트리의 균형을 맞춘다.
	- LL(Left Left) case
		![[Pasted image 20231204074209.png]]
		- y노드의 오른쪽 자식 노드를 z노드로 변경
		- z노드의 왼쪽 자식 노드를 y노드 오른쪽 서브트리(T2)로 변경
		- y는 새로운 루트 노드가 된다.
	- RR(Right Right) case
		![[Pasted image 20231204074305.png]]
		- y노드의 왼쪽 자식 노드를 z노드로 변경
		- z노드 오른쪽 자식 노드를 y노드 왼쪽 서브트리(T2)로 변경
		- y는 새로운 루트 노드가 된다.
	- LR(Left Right) case
		![[Pasted image 20231204074354.png]]
		y는 z의 외쪽 자식 노드이고, x는 y의 오른쪽 자식 노드인 경우 left, right 순으로 총 두번의 rotation을 수행하여 균형을 맞춘다.
	- RL(Right Left) case
		![[Pasted image 20231204074441.png]]
		y는 z의 오른쪽 자식 노드이고, x는 y의 왼쪽 자식 노드인 경우, right, left 순으로 총 두번의 rotation을 수행하여 균형을 맞춘다.