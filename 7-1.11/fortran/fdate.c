/*

NAME
     fdate - return date and time in an	ASCII string

SYNOPSIS
     subroutine	fdate(string)
     character*24 string

DESCRIPTION
     Fdate returns the current date and	time as	a 24 character string in the
     format described under ctime(3).  Neither `newline' nor NULL will be
     included.

LAST MODIFIACTION
     June 21, 1995, Istvan Cserny (cserny@atomki.hu)
*/

#include "f2c.h" 
#include <time.h>
#include <string.h>

void fdate_(char *cht, ftnlen cht_len)
{
    static time_t t;
    time(&t);
    s_copy(cht,ctime(&t),24L,24L);
    return;
}

