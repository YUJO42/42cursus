# get_next_line

### 1. Evaluation Log

- 

------

### 2. Objective

- to code a function that returns a line ending with a newline, read from a file descriptor
- to learn a highly interesting new concept in C programming: `static variables`

------

### 3. Codes

1. Mandatory Part: [***gnl.c***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line.c), [***gnl_utils.c***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line_utils.c), [***gnl.h***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line.h)
   - ***function description*** : returns a line read from a file descriptor, without the newline
   - ***compile option*** : gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
   - since libft is not allowed, up to 5 functions can be added in gnl_utils.c
2. Bonus Part: [***gnl_bonus.c***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line_bonus.c), [***gnl_utils_bonus.c***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line_utils_bonus.c), [***gnl_bonus.h***](https://github.com/365kim/42_cursus/blob/master/2_get_next_line/get_next_line_bonus.h)
   - ***requirement 1***: to succeed get_next_line with a single static variable.
   - ***requirement 2***: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.

---

### 4. Reference

- **Subject File - get_next_line**
  - https://cdn.intra.42.fr/pdf/pdf/9854/en.subject.pdf

- **Tester - get_next_line**
  - gnlkiller
    - 
  - GNL_lover
    - 
  - gnl-war-machine
    - 