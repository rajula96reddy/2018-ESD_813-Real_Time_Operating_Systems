## Assignment 3
## Experiment with Address Space of a Process
### Observations

First time

| Thread | local <br> variable j | local <br> variable k | local <br> variable l | global <br> variable <br> g_first | global <br> variable <br> g_second | global <br> variable <br> g_third |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Parent | 0x7ffc98e9215c | 0x7ffc98e92160 |  0x7ffc98e92164 | 0x60107c | 0x601080 | 0x601084 |
| Child 1 | 0x7ffc98e9215c | 0x7ffc98e92160 |  0x7ffc98e92164 | 0x60107c | 0x601080 | 0x601084 |
| Child 2 | 0x7ffc98e9215c | 0x7ffc98e92160 |  0x7ffc98e92164 | 0x60107c | 0x601080 | 0x601084 |
| Child 3 | 0x7ffc98e9215c | 0x7ffc98e92160 |  0x7ffc98e92164 | 0x60107c | 0x601080 | 0x601084 |

Second time

| Thread | local <br> variable j | local <br> variable k | local <br> variable l | global <br> variable <br> g_first | global <br> variable <br> g_second | global <br> variable <br> g_third |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Parent | 0x7ffd4ae78f1c | 0x7ffd4ae78f20 |  0x7ffd4ae78f24 | 0x60107c | 0x601080 | 0x601084 |
| Child 1 | 0x7ffd4ae78f1c | 0x7ffd4ae78f20 |  0x7ffd4ae78f24 | 0x60107c | 0x601080 | 0x601084 |
| Child 2 | 0x7ffd4ae78f1c | 0x7ffd4ae78f20 |  0x7ffd4ae78f24 | 0x60107c | 0x601080 | 0x601084 |
| Child 3 | 0x7ffd4ae78f1c | 0x7ffd4ae78f20 |  0x7ffd4ae78f24 | 0x60107c | 0x601080 | 0x601084 |

Third time

| Thread | local <br> variable j | local <br> variable k | local <br> variable l | global <br> variable <br> g_first | global <br> variable <br> g_second | global <br> variable <br> g_third |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Parent | 0x7ffda5991fcc | 0x7ffda5991fd0 |  0x7ffda5991fd4 | 0x60107c | 0x601080 | 0x601084 |
| Child 1 | 0x7ffda5991fcc | 0x7ffda5991fd0 |  0x7ffda5991fd4 | 0x60107c | 0x601080 | 0x601084 |
| Child 2 | 0x7ffda5991fcc | 0x7ffda5991fd0 |  0x7ffda5991fd4 | 0x60107c | 0x601080 | 0x601084 |
| Child 3 | 0x7ffda5991fcc | 0x7ffda5991fd0 |  0x7ffda5991fd4 | 0x60107c | 0x601080 | 0x601084 |

<br>
<br>
1. The values of the local variables are changing for every iteration while the values of the global variables are not. This is because the local variables are declared & initialized inside the function while the global variables are not declared that way.
2. All the values for a given iteration w.r.t all the processes are same. This is because, for a fork memory is copied instead of creating a new memory. And also all the memory handled by the processes are virtual which in turn map to a physical one. Hence all processes have the same values for all the variables.
