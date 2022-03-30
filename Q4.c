/*4.Write a program, which get and set pthread scheduling policy and priority.
*/

#include <pthread.h>

pthread_t tid;
int ret;
struct sched_param param;
int priority;

/* sched_priority will be the priority of the thread */
sched_param.sched_priority = priority;
policy = SCHED_OTHER;

/* scheduling parameters of target thread */
ret = pthread_setschedparam(tid, 
policy, &param); 
