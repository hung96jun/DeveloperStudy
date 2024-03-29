- 동적 계획법은 기본적인 아이디어로 <font color="red">하나의 큰 문제를 여러 개의 작은 문제로 나누어 그 결과를 저장하여 다시 큰 문제를 해결할 때 사용하</font>는 것으로 특정한 알고리즘이 아닌 하나의 문제 패러다임으로 불 수 있다.
	- 큰 문제를 작은 문제로 쪼개서 그 답을 저장해두고 재활용한다.
- 사용 조건
	- Overlapping Subproblems : 겹치는 부분 문제
	- Optimal Substructure : 최적 부분 구조
- Overlapping Subproblems
	- DP는 기본적으로 문제를 나누고 그 문제의 결과값을 재활용해서 전체 답을 구한다. 그래서 <font color="red">동일한 작은 문제들이 반복하여 나타나는 경우에 사용이 가능하</font>다.
	- 즉, DP는 부분 문제의 결과를 저장하여 재 계산하지 않을 수 있어야 하는데, 해당 <font color="red">부분 문제가 반복적으로 나타나지 않는다면 재사용이 불가능하니 부분 문제가 중복되지 않는 경우에는 사용할 수 없다.</font>
	- ![[Pasted image 20231020120647.png]]
- Optimal Substructure
	- <font color="red">부분 문제의 최적 결과값을 사용해 전체 문제의 최적 결과를 낼 수 있는 경우</font>를 의미한다. 그래서 특정 문제의 정답은 문제의 크기에 상관없이 항상 동일하다.
	- ![[Pasted image 20231020120804.png]]
- DP 파악하기
	- DP로 풀 수 있는 문제인지 확인
		- 현재 문제가 작은 문제들로 이루어진 하나의 함수로 표현될 수 있는지 판단(즉, <font color="red">위의 조건들이 충족되는 문제인지 체그</font>)
	- 문제의 변수 파악
		- DP는 현재 변수에 따라 그 결과값을 찾고 그것을 전달하여 재사용하는 것을 거친다. 즉, 문제 내 변수의 개수를 알아내야 한다.
		- 유명한 <font color="red">Knapsack</font> 문제에서는 index, 무게로 2가지의 변수를 사용한다.
	- 변수 간 관계식 만들기(점화식)
	- 저장
		- 변수간 관계식이 정상 생성됬으면 <font color="red">변수의 값에 따른 결과를 저장</font>해야한다. 이것을 <font color="red">Memoization</font>이라 한다.
		- 변수 값에 따른 결과를 저장할 배열등을 미리 만들고 그 결과를 나올 때마다 배열 내에 저장하고 그 저장된 값을 재사용하는 방식으로 문제를 해결한다.
	- 기저 상태 파악
		- <font color="red">가장 작은 문제의 상태를 알아야</font>한다.
	- 구현
		- 반복문을 사용하여 구현
		- 재귀를 사용하여 구현
- Divide and Conquer(분할 정복)와 차이점
	- 분할 정복과 동적 프로그래밍은 <font color="red">주어진 문제를 작게 쪼개서 하위 문제로 해결하고 연계적으로 큰 문제를 해결한다는 점은 동일하다.</font>
	- 차이점은, 분할정복은 <font color="red">분할된 하위 문제가 동일하게 중복이 일어나지 않은 경우에 사용되며</font>, 동일한 중복 문제가 발생한다면 동적 프로그래밍을 쓴다는 것이다.

- Dynamic Programming에서 중복을 없애려면 Memoization을 한다.
	- Memoization : 계산한 결과를 저장하고 필요하면 다시 꺼내 사용하는 방법. 테이블을 이용하여 계산 결과를 저장한다.
	- ![[Pasted image 20240115044237.png]]
	Recursion을 통해 트리를 계속 만들어 가는 것이 아닌, 만들어진 값을 반복을 통해 테이블에 저장해두었던 '값'만을 불러오는 것이 DP Programming의 방법이다.
	recursion은 top-down 방식이라 얘기하며, 전체 n을 나누어 부분 문제로 n - 1, n - 2로 줄어든다.
- Dynamic Programming의 구현 방식에는 두 가지 방법이 있다.
	- Top-Down : 큰 문제를 작은 문제로 쪼개면서 풀이를 한다. 재귀로 구현
	- Bottom-UP : 작은 문제부터 차례대로 푼다. 반복문으로 구현
	Top-Down과 Bottom-Up의 시간 복잡도 차이는 문제에 따라 다를 수 있기 때문에 정확히 알 수는 없다. Top-Down은 재귀호출을 하기 때문에 스택의 사용으로 시간이 더 걸릴 것이라고 생각할 수 있지만, 실제로는 그 차이가 크지 않다. 다만 파이썬의 경우 재귀 호출시 Stack Overflow가 발생할 수 있기 때문에 주의해야 한다.
- DP를 사용하여 문제를 해결하는 일반적인 과정
	- Formulate the problem recursively
		문제를 해결하는 recursive algorithm 혹은 점화식을 찾아내야 한다.
		Folumate the problem recursively -> hard part
		- specification : 문제를 명확히 기술
		- Solution : 명확한 점화식 판별
	- Build solutions to your recurrence from the bottm up
		Base case로부터 차곡차곡 답을 찾아간다.
	- Identify the subproblems : 0에서 n사이의 sub 문제를 푼다.
	- Choose a memoization data structure : 값들을 기억한다.
	- Identify deppenencies : 종속성
	- Find a good evalution order : 계산 순서를 판별
	- Analyze space and running time : 시간 복잡도 분석
	- Write down the algorithm : for loop를 통해 풀이
	- 점화식을 판별하는 것은 창의력이 필요하다.
- Dynmaic Programming 기법 적용
	- LIS 시퀀스 구하기
		Lisbigger 알고리즘은 A\[i . . . n] 에서 A\[i] 값보다 큰 값들을 선택해 recursion 하는 알고리즘이다.
		이것을 Dynamic Programming을 통해 풀게되면
		- Lisbigger(i, j)를 저장하기 좋은 자료구조는 2차원 배열이다. 
		- i는 \[0 . . . n]는 \[1 . . . n] 범위를 가진다.![[Pasted image 20240115045446.png]]
		- O(n ^ 2)의 공간과 O(n^2)의 시간이 필요.
	- LIS 길이 구하기
		- LISfirst(i) = 1 + max{ (LISfirst(j)) | (j > i) && (A\[j]) > (A\[i]) }
		- ![[Pasted image 20240115045748.png]]
		- 배열 LISfirst\[1 . . . n]에 저장(= 총 n개의 배열 / sub-problem)
		- 안쪽 for문 n, 바깥 for문 n
		- return 값은 LISfirst\[0] - 1이다.
		- O(n)의 공간과 O(n^2)의 시간이 필요하다.
	- Subset Su,
		- input : set X of positive integers and target integer T
		- ouptut : true or false
		- ![[Pasted image 20240115045958.png]]
		- X라는 배열이 이미 고정되었다고 가정![[Pasted image 20240115063034.png]]
		- 다이나믹![[Pasted image 20240115063042.png]]
		- 저장하기 좋은 자료구조는 2차원 배열(i와 t의 범위 : 1 <= i <= n, 0 <= t <= T)
		- S\[i, t]를 계산하기 위해 S\[i + 1, \*]가 필요
			- 행은 아래에서 위로 (n to 1), 각 행에서는 순서 상관 없음.
		- 2차원 배열(1 <= i <= n, 0 <= t <= T) -> n^2 공간
		- 안쪽 for문 T, 바깥 for문 n -> nT 시간
			- 원래 코드의 시간 복잡도는 O(2^2)인데, Dynamic Programming을 통해 구한 O(nT)를 보면 O(2^2)보다 더 빨라보이지만, t가 T보다 더 큰 값만큼 돌아간다고 가정하면, 시간 복잡도는 2^2보다 더 커진다. 따라서 다이나믹 프로그래밍을 한다고 항상 빨랒지는 것은 아니다.
- 정리
	- 테이블을 통해 반복을 피하는 Smart Recursion 방식.
	- 재귀를 사용하는 것보다 속도가 빠름
	- 가장 어려운 부분은 문제를 설정하는 것이다. -> 점화식 설정
	- 부분 문제에 대한 올바른 점화식(어떻게 계ㅖ산할 것인가)을 찾고 정의를 선언