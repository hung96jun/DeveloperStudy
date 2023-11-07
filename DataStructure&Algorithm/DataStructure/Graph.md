그래프는 비선형 자료구조로, 노드(Node)/정점(Vertex)과 이들 사이를 연결하는 엣지(Edge)로 구성된 자료구조이다.
- 특징
	- 그래프는 방향(Direction)이 다를 수도, 없을(Undirection) 수도 있다.
	- 다양한 구조로 설계된다. 구조에 따라서 시간 복잡도가 달라지고 다양하게 응용이 가능하다.
	- 새로운 요소들의 추가/삭제가 용이하고 효율적이다.
	- 시간 복잡도/공간 복잡도를 이야기할때 노드(N)/정점(V)/엣지(E)의 수를 사용하여 표현
- 시간 복잡도
	- 두 노드의 연결 확인 : 인접 행렬의 경우 고유 인덱스로 바로 접근 가능하여 O(1)의 시간 복잡도를 갖는다. 인접 리스트의 경우 한 노드의 인접 리스트 안의 특정 노드가 있는지 확인해야 하기 때문에, 최악의 경우 전체를 봐야함으로 O(N)/O(V)의 시간 복잡도를 갖는다.
	- 한 노드에 연결된 모든 노드 확인 : 인접 행렬의 경우 특정 노드를 나타내는 행렬을 탐색하여 연결된 노드를 가져와야 하기 때문에, O(N)/O(V)의 시간 복잡도를 갖는다. 인접 리스트의 경우 연결된 노드의 갯수는 곧 엣지의 갯수이므로, 엣지의 갯수만 확인하면 되므로 O(E)의 시간 복잡도를 갖는다.
	- 추가/삭제 : 추가의 경우 노드/정점이나 엣지 모두 O(1)의 시간 복잡도를 가짐. 하지만, 삭제의 경우 노드/정점의 경우 특정 노드/정점을 찾는 시간과 그와 연결된 엣지를 삭제해야 하므로 O(N+E)/O(V+E)의 시간 복잡도를 가짐. 엣지의 경우 특정 엣지를 찾는 시간이 소요되므로 O(E)의 시간복잡도를 가짐
>[!tip] 장점
>- 새로운 요소들의 추가/삭제가 용이하고 효율적이다.
>- 구조의 응용이 가능하다.

>[!tip] 단점
>- 충돌이 발생할 수 있다.
