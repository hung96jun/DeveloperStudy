- 일단 많이 어려움
- n : 문자열의 size
- k : 교체 가능한 횟수
- s : 문자열
- 숫자로 이루어진 문자열에서 교체 가능한 횟수로 문자열을 교체하여 회문(앞으로, 뒤로 읽어도 동일한 - 기러기 같은)이 되도록 형성

- 남은 교체 가능 횟수가 짝수이고, 교체 해야 하는 갯수가 하나일때
	- 양쪽 다 9로 변경
- 남은 교체 가능 횟수가 짝수이고, 교체 해야 하는 갯수가 0개일때
	- 첫 번째와 마지막 문자를 9로 변경
- 남은 교체 가능 횟수와 교체 해야 하는 갯수가 동일할때
	- otherData에 있는 정보로 변경

- 우선순위
	- 제일 앞과, 제일 뒤가 9가 되어야 한다.
	- 