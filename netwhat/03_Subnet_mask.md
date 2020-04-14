## Practice Problem

### 03. Subnet mask

------

#### Q. What is the CIDR notation of the 255.255.128.0 subnet mask?

```
A. /8
B. /16
C. /9
D. /17

Answer : D. /17
Solution : 서브넷 마스크는 슬래시('/')뒤에 2진수 표기일 때 '1'인 비트 수를 써서 표기가 가능하다.
  255.      255.       128.       0.
11111111 .11111111 .100000000 .00000000
이므로 답은 D

```

------

#### Q. What is the CIDR notation of the 255.255.192.0 subnet mask?

```
A. /5
B. /31
C. /18
D. /14

Answer : C. /18
Solution : 
  255.     255.       192.      0.
11111111.11111111 .11000000.00000000
```

------

#### Q. What is the subnet mask of /24?

```
A. 255.255.255.255
B. 255.255.255.0
C. 255.0.0.0
D. 255.255.128.0
E. 255.192.0.0
F. 255.224.0.0

Answer : B. 255.255.255.0
Solution : 
  255.     255.     255.       0.
11111111.11111111.11111111 .00000000
```

------

- Source : https://github.com/adblanc/netwhat42-train

