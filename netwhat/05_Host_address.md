## Practice Problem

### 05. Host address

---

#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.128.0 subnet mask?

```
A. 65536
B. 65532
C. 16380
D. 32768
E. 32770
F. 65530
G. 32766
H. 16382
I. 32764

Answer : G. 32766
Solution : 
Host address의 범위는 맨 앞의 네트워크 주소와 맨 뒤의 브로드캐스트 주소를 뺀 나머지이다.
255.255.128.0 == 11111111.11111111.10000000 .00000000
(2^15) - 2 = 32768 - 2 = 32766
```

---

#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.255.128 subnet mask?

```
A. 128
B. 60
C. 126
D. 62
E. 252
F. 258
G. 124
H. 58
I. 64

Answer : 126
Solution : 
Host address의 범위는 맨 앞의 네트워크 주소와 맨 뒤의 브로드캐스트 주소를 뺀 나머지이다.
255.255.255.128 == 11111111.11111111.11111111 .10000000
(2^7) - 2 = 128 - 2 = 126
```

---

#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.224.0.0 subnet mask?

```
A. 4194306
B. 4194302
C. 1048578
D. 4194300
E. 2097148
F. 4194298
G. 1048574
H. 2097150
I. 1048576


Answer : H. 2097150
Solution : 
Host address의 범위는 맨 앞의 네트워크 주소와 맨 뒤의 브로드캐스트 주소를 뺀 나머지이다.
255.224.0.0 == 11111111.11100000.00000000 .00000000
(2^11) - 2 = 2097152 - 2 = 2097150
```

---

#### Q. You have an interface on a router with the IP address of 124.144.156.248/21. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?

```
A. 1020
B. 2050
C. 2044	
D. 4090
E. 2046
F. 2048
G. 4092
H. 2042
I. 4094

Answer : E. 2046
Solution : 
2^(32 - n) - 2 = 정답 // n은 서브넷마스크 /00
2^(32 - 21) - 2 = 2048 - 2 = 2046
```

---

#### Q. You have an interface on a router with the IP address of 240.19.3.205/12. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?

```
A. 1048576
B. 2097154
C. 1048574
D. 524284
E. 1048578
F. 2097148
G. 1048572

Answer : C. 1048574
Solution : 
2^(32 - n) - 2 = 정답 // n은 서브넷마스크 /00
2^(32 - 12) - 2 = 1048576 - 2 = 1048574
```

---

#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 158.167.18.156/15 resides?

```
A. 158.166.0.1- 158.167.255.253
B. 158.165.255.253- 158.167.255.254
C. 158.166.0.1- 158.167.255.254
D. 158.166.0.2- 158.168.0.2

Answer : C. 158.166.0.1- 158.167.255.254
Solution :
Host IP의 범위는 (Network + 1) ~ (Broadcats - 1)이다.
(Network)158.166.0.0 (Broadcast) 158.167.255.255
```

---

#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 1.93.149.6/17 resides?

```
A. 1.93.127.255- 1.93.255.250
B. 1.93.128.1- 1.94.0.1
C. 1.93.128.1- 1.93.255.251
D. 1.93.128.1- 1.93.255.254
E. 1.93.128.1- 1.94.0.3

Answer : D. 1.93.128.1- 1.93.255.254
Solution : 
Host IP의 범위는 (Network + 1) ~ (Broadcats - 1)이다.
(Network)1.93.128.0 (Broadcast) 1.93.255.255
```

---

#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 233.249.146.36/21 resides?

```
A. 233.249.143.255-233.249.151.250
B. 233.249.144.4-233.249.152.0
C. 233.249.144.1-233.249.151.254
D. 233.249.144.6-233.249.152.1
E. 233.249.144.0-233.249.151.249

Answer : C. 233.249.144.1-233.249.151.254
Solution : 
Host IP의 범위는 (Network + 1) ~ (Broadcats - 1)이다.
(Network)233.249.144.0 (Broadcast) 233.249.151.255
```

---

#### Q. If the IP address 123.48.189.194/21 is assigned to an Ethernet port of a router, what host address could communicate with it?

```
A. 101.219.223.235
B. 75.153.38.143
C. 5.200.165.154
D. 13.28.168.153
E. 172.1.223.196
F. 43.241.96.42
G. 123.48.189.109
H. 253.99.227.186

Answer : G. 123.48.189.109
Solution : 
Host IP의 범위는 (Network + 1) ~ (Broadcats - 1)이다.
(Network)123.48.184.0 (Broadcast) 123.48.191.255
```

------

- Source : https://github.com/adblanc/netwhat42-train