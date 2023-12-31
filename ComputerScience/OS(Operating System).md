### 운영체제란
- 사용자가 컴퓨터를 쉽게 다룰 수 있게 해주는 인터페이스
	- 컴퓨터 자원을 효율적으로 관리하기 위한 시스템
	- 공통된 소프트웨어 플렛폼
	- 컴퓨터 응용 프로그램 관리자
- 하드웨어와 소프트웨어를 관리하는 소프트웨어 전체
	- pc용 window, mac 뿐만 아니라 MP3플레이어를 키면 전원이 들어와 장치를 사용하거나, 핸드폰에 사용되는 안드로이드 또한 운영체제이다. 단, 이런 식으로 전자기기에 공장 출고시 설치되며 응용 프로그램 설치를 통한 기능 추가를 할 수 없는 것은 보통 <font color="red">펌웨어(firmware)</font>라고 한다. 이런 기기들의 펌웨어 자체가 ==일종의 응용프로그램 역할==을 한다.
- 각종 하드웨어 자원과 소프트웨어 자원을 효율적으로 운영관리함으로써 사용자가 시스템을 이용하는데 편리함을 제공하는 소프트웨어
	- 장치 드라이버는 대체로 OS를 거쳐서 설치되므로 운영체제는 펌웨어 다음으로 하드웨어와 가장 직접적으로 관련되는 소프트웨어이다.

### 종류
- Window
	- 마이크로 소프트
	- 그래픽카드와 같은 다양한 하드웨어에 대응할 수 있으며 인터페이스 또한 사용자 친화적
	- 다른 OS에 비해 RAM이 많이 사용되며 용량 또한 많이 차지함. 또한 리눅스 커널이 내장되어 있지 않아 UNIX-LIKE 프로그램을 설치하지 못하는 경우가 있다.
- Mac
	- Apple
	- 유저 인터페이스적으로 가장 뛰어나다는 평가를 받는다.
	- UNIX의 특징을 가지고 있기 때문에 커널 또한 자유롭다.
	- 애플 하드웨어 기기에서만 동작되는 독자적인 OS라 다른 기기에서 사용할 수 없다.
	- 위의 이유때문에 NVIDIA 그래픽카드를 사용해야 하는 딥러닝과 같은 작업에는 적합하지 않다.
- ubuntu
	- Canonical
	- Debian기반의 OS
	- 유니티 환경 지원으로 데스크톱 용도로 사용할 수 있으며 오픈소스 OS이기때문에 무료로 사용 가능
	- 리눅스와 다르게 전용 GUI지원을 하기 때문에 초심자가 사용하기 편한편
	- 한글을 지원하지 않기 때문에 따로 설치를 진행해야 하며 한글, 카카오톡과 같은 프로그램이 동작하지 않음

### 목적과 구성
- 운영체제의 4가지 목적
	- 처리 능력 : 운영체제는 시스템의 생산성을 나타내는 단위로, 일정 시간 동안 처리하는 일의 양을 의미
	- 응답 시간 : 작업 의뢰 후 시스템에서 결과가 얻어질 때까지의 시간
	- 신뢰도 : 주어진 문제를 얼마나 정확하게 처리하는가에 대한 정도
	- 사용 가능도 : 시스템을 얼마나 빠르게 사용할 수 있는가에 대한 정도
![[Pasted image 20231101085634.png]]
- 사용자 인터페이스(쉘)
	- 쉘 : 사용자나 응용 프로그램이 운영체제와 의사소통에 필요한 것
	- 장치 관리 : 키보드, 모니터와 같은 주변 장치를 제어하는 요소
	- 파일 관리 : 파일을 만들고 수정하고 이름을 부여하는 요소
	- 메모리 관리 : RAM의 일정 부분을 할당하거나 RAM 내애 있는 프로그램들의 경계를 설정해 서로 침범하지 못하게 하는 요소
	- 처리기 관리 : CPU의 처리 능력을 각 작업에 효과적으로 배분하도록 관리

### 구성 요소
- 하드웨어 -> 커널(Kernel) -> 셸(Shell) ->애플리케이션(Application)이 실행
	- 사용자는 기본적으로 셸을 통해 애플리케이션을 실행
- 부트 로더
	- 컴퓨터가 켜졌을 때 운영체제에 필요한 조치를 취하고 하드 디스크 드라이브에 기록되어 있는 운영체제를 실행하는 프로그램. 주로 BIOS 방식의 경우 MBR(Master Boot Record)이라는 하드 디스크의 첫 번째 섹터 구간에 기록되어 있음. 그러나 MBR은 512바이트에 불과하기 때문에 MS-DOS같이 간단한 운영체제가 아닌 현대의 운영체제의 경우 MBR상의 부트로더가 하드 디스크 드라이브상의 2차 부트 로더를 호출하여 부트 로더의 크기 제한을 없애는 방안을 주로 사용함
	- 최신 운영체제는 예전의 BIOS와 MBR에서 UEFI와 GPT로 바뀌고 있다.
- 커널(Kernel) : 응용프로그램이 요청한 처리를 하드웨어에 나누어 처리를 요구하며, 시스템 호출 수행, 메모리 제어 등 운용체제에서는 없어서는 안되는 요소
	- 운영체제에서 가장 핵심이 되는 프로그램. 커널은 드라이버를 이용하여 CPU나 그래픽카드와 같은 하드웨어를 제어하고 여러 응용 프로그램이 갖가지 다른 하드웨어 위에서 돌아가도록 호환성을 보장하기 위해 API를 제공함. 모든 응용 프로그램들에게 동일한 환경을 제공해서 하드웨어나 여타 환경이 달라지더라도 프로그램을 그대로 사용할 수 있도록 플랫폼을 제공해주기 위함.
	- 응용 프로그램이 운영체제의 API를 호출하는 실제 구동과정은 CPU에서 응용 프로그램이 실행되다가 <font color="red">레지스터</font>에 적절한 값을 넣어주고 커널 호출 인터럽트를 걸어주면 문맥 교환(Context Switching)이 일어나서 CPU 레지스터, 파이프라인, 논리 주소를 쓰는 캐시까지 모조리 비워지고 커널이 실행됨. 커널에서 요청한 API를 수행한 다음에는 실행되던 응용프로그램의 중단된 시점의 명령어부터 다시 fetch시킴.
	- Window에서는 ntoskrnl.exe가 <font color="red">Window 커널</font>프로그램에 해당함. Linux에서는 커널을 사용자가 세팅을 선택해서 컴파일하여 사용할 수도 있고 부팅때 어떤 커널을 부팅시킬지 선택할 수도 있다.
- 셸(Shell) : 화면에 사용자가 볼 수 있는 요소, 사용자의 지시를 해석하여 커널에게 전달해주는 역할
	- Linux에서는 bash, bsh, csh와 같은 프로그램들이 해당됨. Window에서는 cmd.exe(CLI)나 explorer.exe(GUI)가 해당됨. cmd.exe와 같은 텍스트 기반의 유저 인터페이스를 CLU(Command Line Interface)라고 부르며, 그래픽 기반의 유저 인터페이스는 GUI(Graphic User Interface)라고 부른다. Linux계열에서는 GNOME이나 KDE등 GUI는 셸 위에서 돌아가는 응용프로그램이다.
>[!Tip] 
 Unix계열 운영체제에서 사용되는 셸에는 Bourne Shell(sh), Korn Shell(ksh), Bourne Again Shell(bash), C Shell(csh), TC Shell(tcsh) 등이 있으며, Microsoft Windows에는 explorer.exe가 셸 프로그램이며, Mac OS에선 Finder가 셸 역할이다.
- 종류
	- 임베디드(Embedded) 운영체제
		- 임베디드 장비에는 실시간 운영체제(RTOS)나 Linux가 설치되는 경우가 많음
		- 가볍고, 효율적이며, 설치공간이 작고, 장치 요구 사항에 맞게 작동한다는 등 안정적으로 설계된다는 장점이 있음
		- 일상에서 쉽게 발견할 수 있는 형태는 펌에워에 가까운 형태이며, 단순히 하드웨어 작동을 위한 OS가 있다.(피쳐폰, MP3, PMP, 냉장고, TV 등)
		- 실시간 운영체제 또는 RTOS(Real-Time Operating System)는 원하는 작업을 요구되는 시간 내에 처리할 수 있는 걸 보장하는 운영체제이며 보통 임베디드 장비에 설치됨.
	- 서버 운영체제
		- Linux, UNIX(BSD, 솔라리스 등), Window, MaxOS 등이 있으며, 커널은 해당 OS의 데스크탑용 커널과 거의 동일하며, 여러가지 기능을 서버 운영에 맞게 수정해서 나오는 경우가 대부분. 시본 탑재 소프트웨어도 서버 운영에 맞는 것으로 이루어져있음
		- 서버 운영체제는 네트워크 지향적이며 가상화를 지원하고 확장성 등의 특징을 갖고 있으며, 컴퓨터 네트워크를 실행하거나 사용자에게 서비스를 제공하는 수단이 중요
	- 모바일 운영체제
		- 스마트폰, 태블릿 컴퓨터, PDA 등의 운영체제이다. 대표적 Android(Linux 계열)와 IOS(BDS 계열)가 있다.
	- 데스크탑 운영체제
		- 데스크톱 랩탑 운영체제로는 Windows, MacOS< Linux가 많이 사용된다.
		- Windows
			- 기본적으로 안정적이고 표준적인 GUI를 갖고 있으며, 많은 서드파티 프로그램의 지원을 받음. 그 서드파티의 층이 막대하며 오픈소스 프로그램도 상당하므로, 그래픽(성능, 전용 호환성과 각종API 지원) 전문 용도에서는 MacOS모다 수후, 전문적인 그래픽 작업 성능 또한 많은 소프트웨어 회사들과 하드웨어 회사들 기술 지원 덕에 매우 뛰어남.
			- 커널에 접근하기 쉬우며, 기본적 골격은 유지해야 하지만 어느 정도 운영체제 개조가 가능. 시스템 파일도 중요 파일을 제외하곤 접근 뿐만 아닌 수정도 가능하기 때문에 커널만 Windows이고 아예 색다른 Windows를 구축하는 것도 가능하다. 다만 시스템 파일의 소스까지는 볼 수 없으며, 그 알고리즘을 알기 위해선 역어셈블리나 리버스 엔지니어링을 해야한다.
			- 지속적인 관리 없이 프로그램을 설치하면 불필요한 레지스트리가 축적되고 여러 드라이버들이 꼬이는 상황이 발생하여 속도가 느려진다. 레지스트리는 Windows의 거의 모든 설정 정보들을 저장하고 있기 때문에 잘못 꼬이면 부팅조차 되지 않는 상황이 발생할 수 있다.
			- 개발자 문서화는 다른 OS와 비교하면 뛰어난 수준 개발자 네트워크인 MSDN에 쌓인 정보량은 어마어마하다.
		- UNIX
			- UNIX계열 운영체제를 사용하고자 하면 많은 선택들이 있음. 쉽게 수정할 수 있는 베포판부터 모든것을 수정할 수 있는 베포판 또한 있다. 이렇게 종류가 많은 이유는 Linux 그 자체는 운영체제가 아닌 단지 <font color="red">커널</font>일 뿐이고 그 커널을 사용하는 수많은 운영체제가 Linux의 이름을 달고 출시되기 때문.
		- MaxOS
			- Apple Mac OS는 Mac전용으로 탑재되는 운영체제로 IPhone OS(현 IOS)도 여기에 기반으로 개발. GUI를 보편화 시킨 회사가 개발한 만큼 그래픽적으로 Winows나 Linux계열보다 화려함. 인터페이스는 직관적이고 사용하기 쉽다는 얘기도 있다.
			- 모든 하드웨어가 정형화되어 있기 때문에 대부분의 관리 작업은 사용자가 모르게 자동으로 동작. 시스템 설정은 외부 프로그램은 물론, 사용자에게까지 접근 권한 자체를 주지 않아 안정성이 높음. 다만 안정성이 높다는건 관리자 권한을 얻기 어렵다는 점뿐, 시스템 자체적인 안정성과는 별개. 메모리 관리를 맥에서 직접 설계한 대로만 사용하는데, 현재 문제가 많음
			- 서드파티 소프트웨어의 수는 Windows에 비해 훨씬 부족하지만, 품질만 놓고 보면 빠지는건 없는 수준으로 볼 수 있음. 
			- 가장 큰 단점으로 하위호환 문제가 있다. 애플이 새 플랫폼으로 이주하며 레거시 지원을 잘 안하기 때문이다.