#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

/*struct rusage {*/
   /*struct timeval ru_utime; [> user CPU time used <]*/
   /*struct timeval ru_stime; [> system CPU time used <]*/
   /*long   ru_maxrss;        [> maximum resident set size <]*/
   /*long   ru_ixrss;         [> integral shared memory size <]*/
   /*long   ru_idrss;         [> integral unshared data size <]*/
   /*long   ru_isrss;         [> integral unshared stack size <]*/
   /*long   ru_minflt;        [> page reclaims (soft page faults) <]*/
   /*long   ru_majflt;        [> page faults (hard page faults) <]*/
   /*long   ru_nswap;         [> swaps <]*/
   /*long   ru_inblock;       [> block input operations <]*/
   /*long   ru_oublock;       [> block output operations <]*/
   /*long   ru_msgsnd;        [> IPC messages sent <]*/
   /*long   ru_msgrcv;        [> IPC messages received <]*/
   /*long   ru_nsignals;      [> signals received <]*/
   /*long   ru_nvcsw;         [> voluntary context switches <]*/
   /*long   ru_nivcsw;        [> involuntary context switches <]*/
/*};*/

void printBufValue(const struct rusage a);
void printBufReference(const struct rusage *a);

int main (void) 
{
  struct rusage buffer;

  long long i, j; 
  
  for (i = 0, j = 0; i < 10000000; i++)
  {
    j+=i+i;
  }

  getrusage(RUSAGE_SELF, &buffer);

  printf("user seconds without microseconds: %ld\n", buffer.ru_utime.tv_sec);
  printf("user microseconds: %d\n", buffer.ru_utime.tv_usec);
  printf("total user seconds: %e\n", 
    (double) buffer.ru_utime.tv_sec + 
    (double) buffer.ru_utime.tv_usec / (double) 1000000
  );
  printBufValue(buffer);
  printBufReference(&buffer);
}

void printBufValue(const struct rusage a)
{
  printf("Time when passing by value: %d\n", a.ru_utime.tv_usec);
}

void printBufReference(const struct rusage *a)
{
  printf("Time when passing by reference: %d\n", a->ru_utime.tv_usec);
}
