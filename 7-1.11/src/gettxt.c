/* gettxt.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int gettxt_(void)
{
    /* System generated locals */
    integer i__1;
    char ch__1[80];
    olist o__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), f_rew(
	    alist *), s_wsfe(cilist *), e_wsfe(void), s_cmp(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static char ch[1];
    static integer is[3];
    static char ch2[1], filen[50];
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int upcase_(char *, ftnlen);
    static char oldkey[80];

    /* Fortran I/O blocks */
    static cilist io___2 = { 1, 5, 1, "(A)", 0 };
    static cilist io___7 = { 1, 4, 1, "(A)", 0 };
    static cilist io___8 = { 1, 4, 1, "(A)", 0 };
    static cilist io___9 = { 1, 5, 1, "(A)", 0 };
    static cilist io___10 = { 1, 5, 1, "(A)", 0 };
    static cilist io___11 = { 1, 4, 1, "(A)", 0 };
    static cilist io___12 = { 1, 5, 1, "(A)", 0 };
    static cilist io___13 = { 1, 5, 1, "(A)", 0 };
    static cilist io___14 = { 1, 5, 1, "(A)", 0 };
    static cilist io___15 = { 1, 4, 1, "(A)", 0 };
    static cilist io___16 = { 1, 5, 1, "(A)", 0 };
    static cilist io___17 = { 1, 5, 1, "(A)", 0 };
    static cilist io___18 = { 1, 5, 1, "(A)", 0 };
    static cilist io___19 = { 1, 5, 1, "(A)", 0 };
    static cilist io___20 = { 0, 6, 0, "(A)", 0 };
    static cilist io___23 = { 0, 6, 0, "(A,I2,A)", 0 };
    static cilist io___24 = { 0, 6, 0, "(A)", 0 };
    static cilist io___25 = { 0, 6, 0, "(A)", 0 };


    is[0] = 161;
    is[1] = 81;
    is[2] = 1;
    s_copy(keywrd_1.keywrd, " ", (ftnlen)241, (ftnlen)1);
    s_copy(titles_1.koment, "    NULL  ", (ftnlen)81, (ftnlen)10);
    s_copy(titles_1.title, "    NULL  ", (ftnlen)81, (ftnlen)10);
    i__1 = s_rsfe(&io___2);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, keywrd_1.keywrd, (ftnlen)80);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = e_rsfe();
L100001:
    if (i__1 < 0) {
	goto L100;
    }
    if (i__1 > 0) {
	goto L90;
    }
    s_copy(oldkey, keywrd_1.keywrd, (ftnlen)80, (ftnlen)241);
    upcase_(keywrd_1.keywrd, (ftnlen)80);
    if (i_indx(keywrd_1.keywrd, "SETUP", (ftnlen)241, (ftnlen)5) != 0) {
	i__ = i_indx(keywrd_1.keywrd, "SETUP=", (ftnlen)241, (ftnlen)6);
	if (i__ != 0) {
	    j = i_indx(keywrd_1.keywrd + (i__ - 1), " ", 241 - (i__ - 1), (
		    ftnlen)1);
	    i__1 = i__ + 5;
	    s_copy(filen, oldkey + i__1, (ftnlen)50, i__ + j - 1 - i__1);
	} else {
	    s_copy(filen, "SETUP", (ftnlen)50, (ftnlen)5);
	}
	o__1.oerr = 0;
	o__1.ounit = 4;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, filen, (ftnlen)50);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	f_open(&o__1);
	al__1.aerr = 0;
	al__1.aunit = 4;
	f_rew(&al__1);
	i__1 = s_rsfe(&io___7);
	if (i__1 != 0) {
	    goto L40;
	}
	i__1 = do_fio(&c__1, keywrd_1.keywrd + 80, (ftnlen)80);
	if (i__1 != 0) {
	    goto L40;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L40;
	}
	upcase_(keywrd_1.keywrd + 80, (ftnlen)80);
	i__1 = s_rsfe(&io___8);
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_fio(&c__1, keywrd_1.keywrd + 160, (ftnlen)80);
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L10;
	}
	upcase_(keywrd_1.keywrd + 160, (ftnlen)80);
L10:
	i__1 = s_rsfe(&io___9);
	if (i__1 != 0) {
	    goto L100002;
	}
	i__1 = do_fio(&c__1, titles_1.koment, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100002;
	}
	i__1 = do_fio(&c__1, titles_1.title, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100002;
	}
	i__1 = e_rsfe();
L100002:
	if (i__1 < 0) {
	    goto L100;
	}
	if (i__1 > 0) {
	    goto L90;
	}
    } else if (i_indx(keywrd_1.keywrd, " +", (ftnlen)80, (ftnlen)2) != 0) {

/*  READ SECOND KEYWORD LINE */

	i__1 = s_rsfe(&io___10);
	if (i__1 != 0) {
	    goto L100003;
	}
	i__1 = do_fio(&c__1, keywrd_1.keywrd + 80, (ftnlen)80);
	if (i__1 != 0) {
	    goto L100003;
	}
	i__1 = e_rsfe();
L100003:
	if (i__1 < 0) {
	    goto L100;
	}
	if (i__1 > 0) {
	    goto L90;
	}
	s_copy(oldkey, keywrd_1.keywrd + 80, (ftnlen)80, (ftnlen)80);
	upcase_(keywrd_1.keywrd + 80, (ftnlen)80);
	if (i_indx(keywrd_1.keywrd + 80, "SETUP", (ftnlen)80, (ftnlen)5) != 0)
		 {
	    i__ = i_indx(keywrd_1.keywrd, "SETUP=", (ftnlen)241, (ftnlen)6);
	    if (i__ != 0) {
		j = i_indx(keywrd_1.keywrd + (i__ - 1), " ", 241 - (i__ - 1), 
			(ftnlen)1);
		i__1 = i__ - 75;
		s_copy(filen, oldkey + i__1, (ftnlen)50, i__ + j - 80 - i__1);
	    } else {
		s_copy(filen, "SETUP", (ftnlen)50, (ftnlen)5);
	    }
	    o__1.oerr = 0;
	    o__1.ounit = 4;
	    o__1.ofnmlen = 80;
	    getnam_(ch__1, (ftnlen)80, filen, (ftnlen)50);
	    o__1.ofnm = ch__1;
	    o__1.orl = 0;
	    o__1.osta = "UNKNOWN";
	    o__1.oacc = 0;
	    o__1.ofm = "FORMATTED";
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    al__1.aerr = 0;
	    al__1.aunit = 4;
	    f_rew(&al__1);
	    i__1 = s_rsfe(&io___11);
	    if (i__1 != 0) {
		goto L20;
	    }
	    i__1 = do_fio(&c__1, keywrd_1.keywrd + 160, (ftnlen)80);
	    if (i__1 != 0) {
		goto L20;
	    }
	    i__1 = e_rsfe();
	    if (i__1 != 0) {
		goto L20;
	    }
	    upcase_(keywrd_1.keywrd + 160, (ftnlen)80);
L20:
	    ;
	} else if (i_indx(keywrd_1.keywrd + 80, " +", (ftnlen)80, (ftnlen)2) 
		!= 0) {

/*  READ THIRD KEYWORD LINE */

	    i__1 = s_rsfe(&io___12);
	    if (i__1 != 0) {
		goto L100004;
	    }
	    i__1 = do_fio(&c__1, keywrd_1.keywrd + 160, (ftnlen)80);
	    if (i__1 != 0) {
		goto L100004;
	    }
	    i__1 = e_rsfe();
L100004:
	    if (i__1 < 0) {
		goto L100;
	    }
	    if (i__1 > 0) {
		goto L90;
	    }
	    upcase_(keywrd_1.keywrd + 160, (ftnlen)80);
	}

/*  READ TITLE LINE */

	i__1 = s_rsfe(&io___13);
	if (i__1 != 0) {
	    goto L100005;
	}
	i__1 = do_fio(&c__1, titles_1.koment, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100005;
	}
	i__1 = do_fio(&c__1, titles_1.title, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100005;
	}
	i__1 = e_rsfe();
L100005:
	if (i__1 < 0) {
	    goto L100;
	}
	if (i__1 > 0) {
	    goto L90;
	}
    } else if (i_indx(keywrd_1.keywrd, "&", (ftnlen)80, (ftnlen)1) != 0) {
	i__1 = s_rsfe(&io___14);
	if (i__1 != 0) {
	    goto L100006;
	}
	i__1 = do_fio(&c__1, keywrd_1.keywrd + 80, (ftnlen)80);
	if (i__1 != 0) {
	    goto L100006;
	}
	i__1 = e_rsfe();
L100006:
	if (i__1 < 0) {
	    goto L100;
	}
	if (i__1 > 0) {
	    goto L90;
	}
	s_copy(oldkey, keywrd_1.keywrd + 80, (ftnlen)80, (ftnlen)80);
	upcase_(keywrd_1.keywrd + 80, (ftnlen)80);
	if (i_indx(keywrd_1.keywrd + 80, "SETUP", (ftnlen)80, (ftnlen)5) != 0)
		 {
	    i__ = i_indx(keywrd_1.keywrd, "SETUP=", (ftnlen)241, (ftnlen)6);
	    if (i__ != 0) {
		j = i_indx(keywrd_1.keywrd + (i__ - 1), " ", 241 - (i__ - 1), 
			(ftnlen)1);
		i__1 = i__ - 75;
		s_copy(filen, oldkey + i__1, (ftnlen)50, i__ + j - 80 - i__1);
/*               write(*,*)' <'//FILEN//'>' */
/*               stop */
	    } else {
		s_copy(filen, "SETUP", (ftnlen)50, (ftnlen)5);
	    }
	    o__1.oerr = 0;
	    o__1.ounit = 4;
	    o__1.ofnmlen = 80;
	    getnam_(ch__1, (ftnlen)80, filen, (ftnlen)50);
	    o__1.ofnm = ch__1;
	    o__1.orl = 0;
	    o__1.osta = "UNKNOWN";
	    o__1.oacc = 0;
	    o__1.ofm = "FORMATTED";
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    al__1.aerr = 0;
	    al__1.aunit = 4;
	    f_rew(&al__1);
	    i__1 = s_rsfe(&io___15);
	    if (i__1 != 0) {
		goto L30;
	    }
	    i__1 = do_fio(&c__1, keywrd_1.keywrd + 160, (ftnlen)80);
	    if (i__1 != 0) {
		goto L30;
	    }
	    i__1 = e_rsfe();
	    if (i__1 != 0) {
		goto L30;
	    }
	    upcase_(keywrd_1.keywrd + 160, (ftnlen)80);
	    i__1 = s_rsfe(&io___16);
	    if (i__1 != 0) {
		goto L100007;
	    }
	    i__1 = do_fio(&c__1, titles_1.title, (ftnlen)81);
	    if (i__1 != 0) {
		goto L100007;
	    }
	    i__1 = e_rsfe();
L100007:
	    if (i__1 < 0) {
		goto L100;
	    }
	    if (i__1 > 0) {
		goto L90;
	    }
L30:
	    ;
	} else if (i_indx(keywrd_1.keywrd + 80, "&", (ftnlen)80, (ftnlen)1) !=
		 0) {
	    i__1 = s_rsfe(&io___17);
	    if (i__1 != 0) {
		goto L100008;
	    }
	    i__1 = do_fio(&c__1, keywrd_1.keywrd + 160, (ftnlen)80);
	    if (i__1 != 0) {
		goto L100008;
	    }
	    i__1 = e_rsfe();
L100008:
	    if (i__1 < 0) {
		goto L100;
	    }
	    if (i__1 > 0) {
		goto L90;
	    }
	} else {
	    i__1 = s_rsfe(&io___18);
	    if (i__1 != 0) {
		goto L100009;
	    }
	    i__1 = do_fio(&c__1, titles_1.title, (ftnlen)81);
	    if (i__1 != 0) {
		goto L100009;
	    }
	    i__1 = e_rsfe();
L100009:
	    if (i__1 < 0) {
		goto L100;
	    }
	    if (i__1 > 0) {
		goto L90;
	    }
	}
    } else {
	i__1 = s_rsfe(&io___19);
	if (i__1 != 0) {
	    goto L100010;
	}
	i__1 = do_fio(&c__1, titles_1.koment, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100010;
	}
	i__1 = do_fio(&c__1, titles_1.title, (ftnlen)81);
	if (i__1 != 0) {
	    goto L100010;
	}
	i__1 = e_rsfe();
L100010:
	if (i__1 < 0) {
	    goto L100;
	}
	if (i__1 > 0) {
	    goto L90;
	}
    }
    goto L50;
L40:
    s_wsfe(&io___20);
    do_fio(&c__1, " SETUP FILE MISSING OR CORRUPT", (ftnlen)30);
    e_wsfe();
L50:
    for (j = 1; j <= 3; ++j) {
	i__1 = is[j - 1] - 1;
	if (s_cmp(keywrd_1.keywrd + i__1, " ", is[j - 1] - i__1, (ftnlen)1) !=
		 0) {
	    i__1 = is[j - 1] - 1;
	    s_copy(ch, keywrd_1.keywrd + i__1, (ftnlen)1, is[j - 1] - i__1);
	    i__1 = is[j - 1] - 1;
	    s_copy(keywrd_1.keywrd + i__1, " ", is[j - 1] - i__1, (ftnlen)1);
	    for (i__ = is[j - 1] + 1; i__ <= 239; ++i__) {
		*(unsigned char *)ch2 = *(unsigned char *)&keywrd_1.keywrd[
			i__ - 1];
		*(unsigned char *)&keywrd_1.keywrd[i__ - 1] = *(unsigned char 
			*)ch;
		*(unsigned char *)ch = *(unsigned char *)ch2;
		i__1 = i__;
		if (s_cmp(keywrd_1.keywrd + i__1, "  ", i__ + 2 - i__1, (
			ftnlen)2) == 0) {
		    i__1 = i__;
		    s_copy(keywrd_1.keywrd + i__1, ch, i__ + 1 - i__1, (
			    ftnlen)1);
		    goto L70;
		}
/* L60: */
	    }
	    s_wsfe(&io___23);
	    do_fio(&c__1, " LINE", (ftnlen)5);
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " OF KEYWORDS DOES NOT HAVE ENOUGH", (ftnlen)33);
	    e_wsfe();
	    s_wsfe(&io___24);
	    do_fio(&c__1, " SPACES FOR PARSING.  PLEASE CORRECT LINE.", (
		    ftnlen)42);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
L70:
	    ;
	}
/* L80: */
    }
    return 0;
L90:
    s_wsfe(&io___25);
    do_fio(&c__1, " ERROR IN READ OF FIRST THREE LINES", (ftnlen)35);
    e_wsfe();
L100:
    s_stop("", (ftnlen)0);
    return 0;
} /* gettxt_ */

/* Subroutine */ int upcase_(char *keywrd, ftnlen keywrd_len)
{
    static integer i__, icapa, iline, ilowa, ilowz;

    icapa = 'A';
    ilowa = 'a';
    ilowz = 'z';
    for (i__ = 1; i__ <= 80; ++i__) {
	iline = *(unsigned char *)&keywrd[i__ - 1];
	if (iline >= ilowa && iline <= ilowz) {
	    *(unsigned char *)&keywrd[i__ - 1] = (char) (iline + icapa - 
		    ilowa);
	}
/* L10: */
    }
    return 0;
} /* upcase_ */

