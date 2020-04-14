# libft
### 1. Evaluation Log
- try 1 - 2020/04/09 (scroe : 57)

  - used a function that wasn't in the assignment.
- try 2 - 2020/04/10 (score : 82)

  - In my split function, the segment fault

  - In my putnbr_fd function, no verification of "fd"
- try 3 - 2020/04/12 (score : 115)

  - **OK**
___
### 2. Objective
- to code a C library regrouping functions.
- the functions will be allowed to use in all other projects.
___
### 3. List of Functions
- **memory**
```
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void	*dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t s, size_t n);
```
- **is_sth, to_sth**
```
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
```
- **string(lib)**
```
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *hatstack, const char *needle, size_t len);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strncmp(const char *s1, const char *s2, size_t n);
```
- **string(non-lib)**
```
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
size_t			ft_atoi(const char *str);
```
- **put_fd**
```
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
```
- **linked_list**
```
int			ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
---

### 4. Reference

- **Subject File - libft**
  - **https://cdn.intra.42.fr/pdf/pdf/9448/en.subject.pdf**
- **Tester - libft**

  - war-machine
    - https://github.com/ska42/libft-war-machine

  - unit-test
    - https://github.com/alelievr/libft-unit-test

  - Libfttest
    - https://github.com/jtoty/Libftest