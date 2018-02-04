## Assignment 4
## Experiment with Address Space of a Thread
### Observations

First time

Addresses of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0x7ff145875f3c | 0x7ff145875f40 | 0x7ff145875f44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 2 |  0x7ff145074f3c | 0x7ff145074f40 | 0x7ff145074f44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 3 | 0x7ff144873f3c | 0x7ff144873f40 | 0x7ff144873f44 | 0x60205c | 0x602054 | 0x602058 |

Values of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0 | 0 | 0 | 4 | 5 | 6 |
| Thread 2 | 0 | 0 | 0 | 7 | 8 | 9 |
| Thread 3 | 0 | 0 | 0 | 10 | 11 | 12 |

Second time

Addresses of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0x7f4fae82df3c | 0x7f4fae82df40 | 0x7f4fae82df44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 2 | 0x7f4fae02cf3c | 0x7f4fae02cf40 | 0x7f4fae02cf44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 3 | 0x7f4fad82bf3c | 0x7f4fad82bf40 | 0x7f4fad82bf44 | 0x60205c | 0x602054 | 0x602058 |

Values of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0 | -1367152896 | 32591 | 7 | 8 | 9 |
| Thread 2 | 0 | 0 | 0 | 7 | 8 | 9 |
| Thread 3 | 0 | 0 | 0 | 7 | 8 | 9 |

Third time

Addresses of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0x7f8909510f3c | 0x7f8909510f40 | 0x7f8909510f44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 2 | 0x7f8908d0ff3c | 0x7f8908d0ff40 | 0x7f8908d0ff44 | 0x60205c | 0x602054 | 0x602058 |
| Thread 3 | 0x7f890850ef3c | 0x7f890850ef40 | 0x7f890850ef44 | 0x60205c | 0x602054 | 0x602058 |

Values of variables

| Thread | local <br> variable i | local <br> variable j | local <br> variable k | global <br> variable a | global <br> variable b | global <br> variable c |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Thread 1 | 0 | 0 | 0 | 7 | 8 | 9 |
| Thread 2 | 0 | 0 | 0 | 7 | 8 | 9 |
| Thread 3 | 0 | 139523840 | 32649 | 10 | 11 | 12 |

<br>
<br>

1. 
