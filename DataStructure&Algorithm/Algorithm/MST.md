### 최소 비용 신장 트리
- 신장 트리
	- 그래프 내의 모든 정점을 포함하는 트리이다. 절대 사이클이 있어서는 안되며 n개의 정점을 가지는 그래프의 신장 트리는 n - 1개의 간선을 가진다.![[Pasted image 20231019161037.png]]
	- 최소 비용 신장 트리는 가중치가 부여된 노드를 가장 적은 수의 간것ㄴ과 비용으로 연결된 트리를 의미한다. 최소 비용 신장 트리를 구현하는 방법으로는 Kruskal 알고리즘과 Prim알고리즘이 있고, 이 알고리즘들은 사이클을 포함하지 않고 반드시 n - 1개의 간선만을 사용한다.
	- ![[Pasted image 20231019161159.png]]
- Kruskal의 MST알고리즘
	- Kruskal 알고리즘은 탐욕법(Greedy Method)를 사용한다.
		- 그리디 알고리즘 : 선택의 순간마다 당장 눈앞에 보이는 최적의 상황만을 쫓아 최종적인 해답에 도달하는 방법. 선택의 순간에는 그 해가 최적이지만 최종적인 해답이 반드시 최적이라는 보장은 없음. 그러므로 탐욕법은 항상 최적으로 해답을 주는지 검증이 필요한데, Kruskal 알고리즘은 최적의 해답을 주는것이 증명되었다.
		- ![[Pasted image 20231019161348.png]]
		- 최소 비용 신장 트리를 만드는 과정![[Pasted image 20231019161415.png]]
		- 여기서 간선을 추가할 때 사이클이 생기지 않도록 방지해야하는데, 이것을 도와주는 것이 Kruskal의 union-find 알고리즘이다. union-find는 원소가 어떤 집합에 속하는지 알아냄으로써 Kruskal 알고리즘에서 사이클 검사에 사용한다.![[Pasted image 20231019161532.png]]
		- union을 실행했을 때![[Pasted image 20231019164500.png]]![[Pasted image 20231019164512.png]]
- Prim의 MST 알고리즘
	- Prim 알고리즘은 시작 정점에서부터 시작해 신장 트리 집합을 단계적으로 확장해나가는 방법. 인접한 정점중에서 최저 간선으로 연결된 정점 선택하여 신장 트리 집합에 추가됨. pseudo-code이다.![[Pasted image 20231019164932.png]]
	- Prim 알고리즘의 과정![[Pasted image 20231019165017.png]]
	- Prim 알고리즘은 주 반복문이 정점의 수 n만큼 반복하고, 내부 반복문이 n번 반복하므로 시간 복잡도는 O(n^2)이다.
	- 최단 경로
		- 최단 경로 문제는 정점 i와 정점 j를 연결하는 경로 중에서 간선들의 가중치 합이 최소가 되는 경로를 찾는 문제이다. 간선의 가중치는 비용, 거리, 시간 등으로 나타낸다.
		- 최단 경로 알고리즘은 2가지가 있다. 다익스트라(Dijkstra)알고리즘과 폴로이드-워셜(Floyd-Warshall)알고리즘이다. 다익스트라 알고리즘은 시작 정점에서 다른 정점까지의 최단경로를 구한다. 반면 폴로이드-워셜 알고리즘은 모든 정점에서 다른 모든 정점까지의 최단 경로를 구한다.
		- Dijkstra 알고리즘
			- 다익스트라 알고리즘은 시작 정점에서 다른 정점까지의 최단경로를 구한다. 시작 정점 v로부터 최단 경로가 이미 발견된 정점들의 집합인 S의 개념을 사용한다. S를 계속해서 업데이트해 나감. 여기서 1차원 배열인 distance의 역할이 중요한데, distance는 최단경로가 알려진 정점들만 이용해 다른 정점들까지의 최단경로의 길이를 저장해 놓은 곳
			- 각 단계에서 S안에 있지 않은 정점 중에서 가장 distance값이 작은 정점을 S에 추가한다.
			- 정점 w를 거쳐서 정점 u로 가는 가상적인 경로가 있다고 했을 때
				- 정점 v에서 정점 u까지의 정점 v에서 정점 w까지의 거리2와 정점 w에서 정점 u로 가는 거리 3을 합한 값이 된다.
				- 그러나 경로 2는 경로 1보다 항상 길 수 밖에 없다. 이유는 distance값이 가장 작은 정점 u이기 때문이다. 그렇기 때문에 경로 1로 추가한다.![[Pasted image 20231019170123.png]]
				- 새로운 정점이 S에 추가되면 distance값 갱신
```
distance[w] = min(distance[w], distance[u] + weight[u][w]);
```
							![[Pasted image 20231019170322.png]]
							![[Pasted image 20231019170431.png]]
							n개의 정점이 존재할때, 다익스트라 알고리즘의 주 반복문은 n번 반복하고, 내부 반복문은 2n번 반복하므로 O(n^2)의 복잡도를 가진다.
- Floyed-Warshall 알고리즘
	- 모든 정점 사이의 최단 경로를 한번에 모두 찾는 알고리즘, 2차원 배열을 이용해 3중 반복을 한다.
	- ![[Pasted image 20231019170916.png]]
	- https://myvelop.tistory.com/157