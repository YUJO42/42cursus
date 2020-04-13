#### 1. What is an IP address

- **IP Address** : 컴퓨터 네트워크에서 장치들이 서로 인식하고 통신하기 위해 사용하는 주소.
  - IPv4 (32bit) : 일반적으로 사용하는 IP주소 (0.0.0.0 ~ 255.255.255.255 형태)
  - IPv6 (128bit) : IPv4의 고갈로 크기를 128비트로 늘린 주소

***

#### 2. What is a Netmask

- **Netmask** : 네트워크 주소 부분의 비트를 1로 치환한 것이 넷마스크다.
  - IP 주소와 넷마스크를 AND연산 하면 네트워크 주소를 얻을 수 있다.

---

#### 3. What is the subnet of an IP with Netmask

- **Subnet Mask** : 서브넷 마스크는 IP주소에 대한 네트워크 아이디와 호스트 아이디를 구분하기 위해 사용.
- 표기법
  - 슬래시 뒤에 2진수 표기일 때 '1'인 비트 수를 써서 표기할 수 있음
  - 255.000.000.000 == 11111111 00000000 00000000 00000000 == /**8**
  - 255.255.000.000 == 11111111 11111110 00000000 00000000 == /**15**
  - 255.255.255.255 == 11111111 11111111 11111111 11111111 == /**32**

---

#### 4. What is the broadcast address of a subnet

-  **Broadcast adrress** : 특정 네트워크에 속하는 모든 호스트들이 듣게되는 주소, 네트워크 주소와는 반대로 특정 네트워크의 맨 마지막 주소를 브로드캐스트 주소로 사용
  - C 클래스 하나로 네트워크를 구성하고 네트워크 주소가 192.168.2.0 이라고 한다면
  - 브로드캐스트 주소는 192.168.2.255
  - 일반적인 네트워크 IP주소는 그 네트워크에 속하는 모든 IP주소 가운데 맨 첫번째 IP 주소를 사용하고 브로드캐스트 IP주소는 그 네트워크에 속하는 모든 IP주소 가운데 맨 마지막 IP주소를 사용

---

#### 5. What are the different ways to represent an ip address with the Netmask

1. 주소가 220.105.101.0 인 클래스 C 네트워크가 있을 때 초기 넷 마스크는 255.255.255.0으로 설정
2. 네트워크를 8개의 서브 네트워크로 분할하기 위해 주소의 호스트 부분에서 3비트를 가져옴 (2^3 = 8)
3. 네트워크 주소 220.105.101.0
   - 11011100 01101001 01100101 00000000
4.  넷 마스크는 255.255.255.0
   - 11111111 11111111 11111111 00000000
5.  8개의 서브 네트워크가 필요하기 때문에 넷 마스크는 쿼드 표기법으로
   - 11111111 11111111 11111111 11100000 or 255.255.255.224
6.  주소의 호스트 부분이 5비트로 줄었고 2^5간격을 기준으로 새 네트워크 주소가 생긴다.
   - 220.105.101.0
   - 220.105.101.32
   - 220.105.101.64
   - 220.105.101.96
   - 220.105.101.128
   - 220.105.101.160
   - 220.105.101.192
   - 220.105.101.224

---

#### 6. What are the differences between public and private IPs

- **공인 IP주소** :  공인된 할당기관에서 할당해준 IP주소, 인터넷 상에서 사용할 수 있음.
- **사설 IP주소** :  내부 네트워크에서만 사용하는 IP주소, 인터넷 상에서 사용할 수 없음.(폐쇄형)

---

#### 7. What is a class of IP addresses

- **IP주소의 클래스** : 하나의 IP주소에서 네트워크 영역과 호스트 영역을 나누는 방법이자, 약속
- 일반적으로 사용되는 클래스
  - A CLASS : 1.0.0.1 ~ 126.255.255.254      // 반드시 0으로 시작
  - B CLASS : 128.0.0.1 ~ 191.255.255.254 // 반드시 10으로 시작
  - C CLASS : 192.0.0.1 ~ 223.255.255.254 // 반드시 110으로 시작
- 멀티캐스트 용도로 사용되는 클래스
  - D CLASS : 224.0.0.0 ~ 239.255.255.255 // 서브넷 마스크가 없음, 일반적으로 사용 불가
- 예약된 (연구용으로도 사용) 클래스
  - E CLASS : 240.0.0.0 ~ 254.255.255.254 // 네트워크와 호스트를 구별하지 않는다, 사용할 수 없다.

---

#### 8. What is TCP

- **TCP**(*Transmission Control Protocol*) : 인터넷상에서 데이터를 메세지의 형태로 보내기 위해 IP와 함께 사용하는 프로토콜
  - 연결형 서비스로 가상 회선 방식을 제공
  - 흐름 제어 및 혼잡 제어
  - 높은 신뢰성을 보장
  - UDP보다 속도가 느림

---

#### 9. What is UDP

- **UDP** : (*User Datagram Protocol*) : 데이터를 데이터그램 단위로 처리하는 프로토콜
  - 비연결형 서비스로 데이터그램 방식을 제공
  - 정보를 주고 받을 때 정보를 보내거나 받는다는 신호절차를 거치지 않는다.
  - 신뢰성이 낮다.
  - TCP보다 속도가 빠르다.

---

#### 10. What are the network layers

- 네트워크 계층은 라우팅, 패킷, 포워딩을 담당함.

- **ICMP** (*Internet Control Message Protocol*)

  - 인터넷 제어 메세지 프로토콜
  - 네트워크 컴퓨터의 OS에서 오류메세지를 전송받는 데 주로 쓰임

  ![](https://t1.daumcdn.net/cfile/tistory/990C0F3359FDD3F80C)

  

---

#### 11. What is the OSI model

- **OSI**(*Open System Interconnection*) : 컴퓨터 네트워크 프로토콜 디자인과 통신을 7계층으로 나눠 설명한 것

![](https://lh3.googleusercontent.com/proxy/ZApeP9pxevdkxqlDJfmNDkdcpdQr7K-h6aeEb7z-bNUN_kK28BtekS1q3tuK89tTRCOZ9O0iRW49P7_qpEiE9ofHDqRQj_V8UxUkG1-dS9BSqSV0AhwDJqima61-XzE7v84vExbxrF5Ehqhcnh6BNqk)

- 참고 : [https://ko.wikipedia.org/wiki/OSI_%EB%AA%A8%ED%98%95](https://ko.wikipedia.org/wiki/OSI_모형)

---

#### 12. What is a DHCP server and the DHCP protocol



---

#### 13. What is a DNS server and the DNS protocol



---

#### 14. What are the rules to make 2 devices communicate using IP addresses



---

#### 15. How does routing work with IP



---

#### 16. What is a default gateway for routing



___

#### 17. What is a port from an IP point of view and what is it used for when connecting to another device



---