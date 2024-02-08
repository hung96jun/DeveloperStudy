![[Pasted image 20231126030603.png]]![[Pasted image 20231126030610.png]]![[Pasted image 20231126030622.png]]

- 마크 다운이란
	- MarkDown은 텍스트 기반의 마크업 언어로, HTML로 변환이 가능하다. 특수기호와 문자를 이용한 매우 간단한 구조의 문법을 사용하여 웹에서도 보다 빠르게 컨텐츠를 작성하고 보다 직관적으로 인식할 수 있다.
- 마크다운의 장점
	- 간결하다
	- 별도의 도구 없이 작성 가능하다.
	- 다양한 형태로 변환이 가능하다
	- 텍스트로 저장되기 때문에 용량이 적어 보관이 용이하다.
	- 텍스트파일이기 때문에 버전관리 시스템을 이용하여 변경이력을 관리할 수 있다.
	- 지원하는 프로그램과 플랫폼이 다양하다.
- 마크다운의 단점
	- 표준이 없다.
	- 표준이 없기 때문에 도구에 따라서 변환방식이나 생성물이 다르다.
	- 모든 HTMP 마크업을 대신하지 못한다.

- 문법(역슬래쉬 제외)
- Header
```MarkDown
- 큰제목 : 문서 제목
This is an H1
\=========================\

- 작은제목 : 문서 부제목
This is an H2
\-------------------------\

- 글머리 : 1~6까지 지원
# This is a H1
## This is a H2
### This is a H3
#### This is a H4
##### This is a H5
###### This is a H6
```
- 강조
```MarkDown
*single asterisks*       // 이탤릭
_single underscores_     // 이탤릭
**double asterisks**     // 굵게
__double underscores__   // 굵게
~~cancelline~~           // 취소선
```
- 체크 박스
```MarkDown
/- [ ] Temp/
```
- Callout 지원 리스트
	- [!note]
	- [!abstract], [!summary], [!tldr]
	- [!info]
	- [!todo]
	- [!tip], [!hint], [!important]
	- [!success], [!check], [!done]
	- [!question], [!help], [!faq]
	- [!warning], [!caution], [!attention]
	- [!failure], [!fail], [!missing]
	- [!danger], [!error]
	- [!bug]
	- [!example]
	- [!quote], [!cite]
- 참조
	- \[\[ FileName ]] :문서 참조
	- \!\[\[ FileName ]] : 문서 임베딩
	- \!\[\[ FileName#ID ]] : 문단 참조

## 접기 시작
<details>
<summary>접기/펼치기</summary>

## 접은 제목
접은 내용
</details>

## 접기 끝
