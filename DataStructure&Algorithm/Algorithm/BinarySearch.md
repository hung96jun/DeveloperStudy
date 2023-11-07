- 정렬된 리스트(배열)에서 원하는 값의 index를 찾는 알고리즘
- 반드시 리스트를 정렬해서 사용해야 한다는 단점
- 탐색할 때 검사 범위가 절반으로 감소(O(logN))

- min과 max값을 사용하여 검사 범위를 알려줘야한다.
- 검사는 min과 max 중간에 있는 index를 사용한다.

- 검사 범위에서 중간 값을 선택해서 찾고자하는 값과 동일한지 검사
- 찾고자 하는 값이면 해당 값을 반환
- 찾고자하는 값보다 작으면 검사 범위를 큰 쪽으로 잡아야함
	- mid, max
- 찾고자하는 값보다 크면 검사 범위를 작은 쪽으로 잡아야함
	- min, mid
- 1~4번을 반복하여 원하는 값이 나오면 해당 값을 반환
- 위의 과정을 반복하여 더이상 원하는 값이 없으면 반환
	- min > max