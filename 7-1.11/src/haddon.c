/* haddon.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int haddon_(doublereal *w, integer *l, integer *m, integer *
	loc, doublereal *a)
{
    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal pi;
    extern /* Subroutine */ int depvar_(doublereal *, integer *, doublereal *,
	     integer *);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, "(///10X,'UNDEFINED SYMMETRY FUNCTION "
	    "USED')", 0 };


/* ********************************************************************** */

/*   HADDON CALCULATES THE VALUE OF A SYMMETRY-DEPENDENT VARIABLE */

/*  ON INPUT: M   = NUMBER SPECIFYING THE SYMMETRY OPERATION */
/*            LOC = ADDRESS OF REFERENCE ATOM */
/*            A   = ARRAY OF INTERNAL COORDINATES */
/*  ON OUTPUT W   = VALUE OF DEPENDENT FUNCTION */
/*            L   = 1 (FOR BOND LENGTH), 2 (ANGLE), OR 3 (DIHEDRAL) */
/* ********************************************************************** */
    /* Parameter adjustments */
    a -= 4;

    /* Function Body */
    pi = 3.1415926536;
    if (*m > 18 || *m < 1) {
	s_wsfe(&io___2);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    i__ = *loc;
    switch (*m) {
	case 1:  goto L140;
	case 2:  goto L160;
	case 3:  goto L10;
	case 4:  goto L20;
	case 5:  goto L30;
	case 6:  goto L40;
	case 7:  goto L50;
	case 8:  goto L60;
	case 9:  goto L70;
	case 10:  goto L80;
	case 11:  goto L90;
	case 12:  goto L100;
	case 13:  goto L110;
	case 14:  goto L120;
	case 15:  goto L150;
	case 16:  goto L170;
	case 17:  goto L180;
	case 18:  goto L190;
    }
L10:
    *w = a[i__ * 3 + 3];
    goto L130;
L20:
    *w = pi / 2. - a[i__ * 3 + 3];
    goto L130;
L30:
    *w = pi / 2. + a[i__ * 3 + 3];
    goto L130;
L40:
    *w = pi * 2. / 3. - a[i__ * 3 + 3];
    goto L130;
L50:
    *w = pi * 2. / 3. + a[i__ * 3 + 3];
    goto L130;
L60:
    *w = pi - a[i__ * 3 + 3];
    goto L130;
L70:
    *w = pi + a[i__ * 3 + 3];
    goto L130;
L80:
    *w = pi * 4. / 3. - a[i__ * 3 + 3];
    goto L130;
L90:
    *w = pi * 4. / 3. + a[i__ * 3 + 3];
    goto L130;
L100:
    *w = pi * 3. / 2. - a[i__ * 3 + 3];
    goto L130;
L110:
    *w = pi * 3. / 2. + a[i__ * 3 + 3];
    goto L130;
L120:
    *w = -a[i__ * 3 + 3];
L130:
    *l = 3;
    return 0;
L140:
    *l = 1;
    *w = a[i__ * 3 + 1];
    return 0;
L150:
    *l = 1;
    *w = a[i__ * 3 + 1] / 2.;
    return 0;
L160:
    *l = 2;
    *w = a[i__ * 3 + 2];
    return 0;
L170:
    *l = 2;
    *w = a[i__ * 3 + 2] / 2.;
    return 0;
L180:
    *l = 2;
    *w = pi - a[i__ * 3 + 2];
    return 0;
L190:
    depvar_(&a[4], &i__, w, l);
    return 0;

} /* haddon_ */

