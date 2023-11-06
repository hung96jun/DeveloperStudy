- 변수
	위 두 가지는 동일한 동작을 한다.
```C++
const int a;  // a의 int 형식의 값을 변경 불가
int const b;  // a의 자체 값 변경 불가
```
- 포인터
	- const int * : const는 바로 뒤의 단독으로 쓰일 수 있는 최소 단위 int랑 묶인다.
	- int const * : const는 의미 있는 최소 단위 * value가 const와 묶인다.
	- int * const : const는 의미 있는 최소 단위 value와 묶인다.
```C++
	int val = 10;
	int other = 20;

	const int* a = &val;  // a가 int 형태의 값을 변경 불가
	int const* b = &val;  // b가 *b 형태의 값을 변경 불가
	int* const c = &val;  // c가 c자체 형태의 값을 변경 불가

	//*a = 30;     // error
	a = &other;    // 사용 가능

	//*b = 30;     // error
	b = &other;    // 사용 가능

	*c = 30;       // 사용 가능
	//c = &other;  // error
```
- 더블 포인터
```C++
int val = 10;
int* pointer = &val;

const int** a = &pointer;  // a가 int형태일때, 해당 값을 변경 불가
int const** b = &pointer;  // b가 **b형태일때, 해당 값을 변경 불가
int* const* c = &pointer;  // c가 *c형태일때, 해당 값을 변경 불가
int** const d = &pointer;  // d가 d 자체 형태일때, 해당 값을 변경 불가

int otherValue = 15;
int* otherPointer = &otherValue;

a = &otherPointer;    // 사용 가능
*a = &otherValue;     // 사용 가능
**a = otherValue;     // error : int 형태인 **a값은 수정 불가능

b = &otherPointer;    // 사용 가능
*b = &otherValue;     // 사용 가능
**b = otherValue;     // error : int 형태인 **b값은 수정 불가능

c = &otherPointer;    // 사용 가능
*c = &otherValue;     // error : *c 형태인 *c값은 수정 불가능
**ㅊ = otherValue;    // 사용 가능

d = &otherPointer;    // error : d 형태인 d값은 수정 불가능
*d = otherValue;      // 사용 가능
**d = otherValue;     // 사용 가능
```
- 레퍼런스
```C++
int value = 10;

const int& ref1 = value;
int const& ref2 = value;
int& const ref3 = value;

ref1 = 3;  // error : ref1이 int형태일 때 변경 불가능
ref2 = 6;  // error : ref2이 &ref 형태일 때 변결 불가능
ref3 = 9;  // 컴파일러마다 다름

const int otherValue = 10;
int& ref = othervalue;  // error : ref를 통해서 const화된 value 값을 변경할 위험이 있으므로                         // const int& ref = value; 형태로 사용해야함
```
- 함수
```C++

```