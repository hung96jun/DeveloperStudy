API는 정의 및 프로토콜 집합을 사용하여 두 소프트웨어 구성 요소가 서로 통신할 수 있게 하는 메커니즘.
Application Programming Interface의 약자, 애플리케이션은 고유 기능을 가진 모든 소프트웨어를 나타내며, 인터페이스는 두 애플리케이션 간의 서비스 계약이다. 해당 계약은 요청과 응답을 사용하여 두 애플리케이션이 서로 통신하는 방법을 정의함. API 문서에는 개발자가 이러한 요청과 응답을 구성하는 방법에 대한 정보가 들어있음.

---
작동 방식
API 아키텍처는 일반적으로 클라이언트와 서버 측면에서 설명되며, 요청을 보내는 애플리케이션을 클라이언트라고 하고 응답을 보내는 애플리케이션을 서버라고 함.
API가 생성된 시기와 이유에 따라 API는 네 가지 방식으로 작동할 수 있다.
- SOAP API : 단순 객체 접근 프로토콜을 사용함. 클라이언트와 서버는 XML을 사용하여 메시지를 교환. 과거에 많이 사용되었으며 유연성이 떨어짐.
- RPC API : 원격 프로시저 호출. 클라이언트가 서버에서 함수나 프로시저([[Procedure]])를 완료하면 서버가 출력을 클라이언트로 다시 전송함.
- Websocket API : JSON 객체를 사용하여 데이터를 전달하는 또 다른 최신 웹 API 개발. WebSocket API는 클라이언트 앱과 서버 간의 양방향 통신을 지원. 서버가 연결된 클라이언트에 콜백 메시지를 전송할 수 있어 REST API보다 효율적.
- REST API : 현재 웹에서 볼 수 있는 가장 많이 사용되고 유연한 API. 클라이언트가 서버에 요청을 데이터로 전송. 서버가 이 클라이언트 입력을 사용하여 내부 함수를 시작하고 출력 데이터를 다시 클라이언트에 반환.
	- Representational State Transfer의 약자. REST는 클라이언트가 서버 데이터에 액세스 하는 데 사용할 수 있는 GET, PUT, DELETE 등의 함수 집합을 정의. 클라이언트와 서버는 HTTP를 사용하여 데이터를 교환
	- REST API의 주된 특징은 무상태인 것이다. 무상태는 서버가 요청 간에 클라이언트 데이터를 저장하지 않음을 의미하며, 서버에 대한 클라이언트 요청은 웹 사이트를 방문하기 위해 브라우저에 입력하는 URL과 유사함. 서버의 응답은 웹 페이지의 일반적인 그래픽 렌더링이 없는 일반 데이터.