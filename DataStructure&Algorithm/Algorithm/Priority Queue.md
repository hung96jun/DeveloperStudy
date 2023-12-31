- Queue는 선입 선출(First In First Out) 구조로 저장되는 선형 자료구조
- 하지만 우선순위 큐는 들어가는 순서에 상관없이 우선순위가 높은 데이터가 먼저 나온다.
- 속성
	- 모든 항목에는 우선순위가 존재한다.
	- 우선순위가 높은 요소는 우선순위가 낮은 요소보다 먼저 queue에서 제외된다.
	- 두 요소의 우선순위가 같으면 queue의 순서에 따라 제공된다.
	- ![[Pasted image 20231019154801.png]]
- 기능
	- enqueue() : queue에 새 요소 삽입
	- dequeue() : queue에 최대 우선순위 요소를 삭제하고 그 값을 반환
	- peek() : queue에서최대 우선순위 요소를 반환
- 구현
	- 일반적인 우선순위 큐 구현 방식에는 배열, 연결 리스트, 힙이 있다.
	- 시간 복잡도
	- ![[Pasted image 20231019154919.png]]
	- 힙 방식이 최악에 경우라고 O(logN)을 보장하기 때문에 일반적으로 힙을 가지고 구현
	- enqueue()
		- 삽입 ![[Pasted image 20231019155013.png]]
		- 힙 끝에 새 요소를 삽입
		- 부모 노드와 비교하여 힙 속성을 위배하는 경우 부모 노드의 값을 바꾼다.
		- 힙 속성이 유지될 때까지 위 작업을 잔복한다.
	- heapify()
		- 힙 속성 유지![[Pasted image 20231019155137.png]]
		- 자식 노드와 우선순위를 비교
		- 만일 자식 노드 우선순위가 높으면 왼쪽 자식 중 우선순위가 높은 노드와 교환
		- 힙 속성이 유지될 때까지 1, 2번 과정을 반복
	- dequeue()
		- 최대 우선순위 요소를 삭제하고 그 값을 반환하는 작업![[Pasted image 20231019155234.png]]
		- 루트 노드의 값을 추출
		- heap 마지막 요소를 루트 노드에 배치
		- 마지막 요소는 제거
		- 루트 노드부터 heapify를 수행

---

- 우선순위가 가장 높은 데이터를 가장 먼저 삭제하는 자료구조
- 데이터를 우선순위에 따라 처리하고 싶을 때 사용
- <font color="red">즉, 전체적으로 정렬되지는 않아도 된다. 중요한것은 추출되는 데이터는 우선순위가 높은 데이터가 먼저 추출된다는 것이다.</font>

|자료구조|추출되는 데이터|
|---|---|
|스택|가장 나중에 삽입된 데이터|
|큐|가장 먼저 삽입된 데이터|
|우선순위 큐|가장 우선순위가 높은 데이터|

- 구현 방법
	1. 단순히 리스트를 이용하여 구현
	2. 힙을 이용하여 구현
- 데이터의 개수가 N일 때, 구현 방식에 따라서 시간 복잡도를 비교한 내용
	- 리스트
		- 삽입 시간 : O(1)
		- 삭제 시간 : O(N)
	- 힙
		- 삽입 시간 : O(logN)
		- 삭제 시간 : O(logN)
- 단순히 N개의 데이터를 힙에 넣었다가 모두 꺼내는 장법은 정렬과 동일하다.(힙 정렬)
	- 이 경우 시간 복잡도는 O(NlogN)

- 힙의 특징
	- 힙은 완전 이진 트리 자료구조의 일종
	- 힙에서는 항상 루트 노드를 제거
	- 최소 힙
		- 루트 노드가 가장 작은 값을 가진다.
		- 따라서 값이 작은 데이터가 우선적으로 제거된다.
	- 최대 힙
		- 루트 노드가 가장 큰 값을 가진다.
		- 따라서 값이 큰 데이터가 우선적으로 제거된다.

- 완전 이진트리
	- 루트 노드부터 시작하여 왼쪽 자식 노드, 오른쪽 자식 노드 순서대로 데이터가 차례대로 삽입되는 트리를 의미.

- 최소 힙 구성 함수(Min-Heapify)
	- (상향식)부모 노드로 거슬러 올라가며, 부모보다 자신의 값이 더 작은 경우 위치를 교체![[Pasted image 20231201181129.png]]
	- 새로운 원소가 삽입되었을 때 O(logN)의 시간 복잡도로 힙 성질을 유지하도록 할 수 있다.![[Pasted image 20231201181253.png]]

- 힙에서 원소가 제거될 때
	- 원소가 제거되었을 때 O(logN)의 시간 복잡도로 힙 성질을 유지할 수 있다.
		- 원소를 제거할 때는 가장 마지막 노드가 루트 노드의 위치에 오도록 한다.![[Pasted image 20231201181411.png]]
		- 이후 루트 노드에서부터 하향식으로(더 작은 자식 노드로) Heapify를 진행![[Pasted image 20231201181521.png]]