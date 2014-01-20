/* 
NAME
     etime - return elapsed execution time

SYNOPSIS
     real function etime (tarray)
     real tarray(2)

DESCRIPTION
     These routine return elapsed runtime in seconds for the calling
     process. The argument array returns user time in the first 
     element and system time in	the second element.
     The function value is the sum of user and system time.

LAST MODIFICATION 
     January 24, 2000,  I. Cserny (cserny@atomki.hu)
*/

#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

float etime_(float *a)
{
   struct rusage t;
   getrusage(RUSAGE_SELF,&t);
   a[0] = (double)(t.ru_utime.tv_sec);
   a[0] = a[0] + (double)(t.ru_utime.tv_usec) / CLOCKS_PER_SEC;
   a[1] = (double)(t.ru_stime.tv_sec);
   a[1] = a[1] + (double)(t.ru_stime.tv_usec) / CLOCKS_PER_SEC;
}
