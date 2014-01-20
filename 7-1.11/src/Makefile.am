lib_LTLIBRARIES= libmopac7.la

libmopac7_la_SOURCES = \
		aababc.c addfck.c addhcr.c addnuc.c analyt.c \
		anavib.c axis.c block.c bonds.c brlzon.c \
		btoc.c calpar.c capcor.c cdiag.c chrge.c \
		cnvg.c compfg.c consts.c cqden.c datin.c \
		dcart.c delmol.c delri.c denrot.c densit.c \
		depvar.c deri0.c deri1.c deri2.c deri21.c \
		deri22.c deri23.c deritr.c deriv.c dernvo.c \
		ders.c dfock2.c dfpsav.c dgemm.c dgemv.c \
		dger.c dgetf2.c dgetrf.c dgetri.c diag.c \
		diat.c diat2.c diegrd.c dielen.c diis.c \
		dijkl1.c dijkl2.c dipind.c dipole.c dlaswp.c \
		dofs.c dot.c drc.c drcout.c dtrmm.c \
		dtrmv.c dtrsm.c dtrti2.c dtrtri.c dvfill.c \
		ef.c enpart.c esp.c etime.c exchng.c \
		fdate.c ffhpol.c flepo.c fmat.c fock1.c \
		fock2.c force.c formxy.c forsav.c frame.c \
		freqcy.c geout.c geoutg.c getgeg.c getgeo.c \
		getsym.c gettxt.c gmetry.c gover.c  greenf.c \
		grid.c h1elec.c haddon.c hcore.c helect.c \
		hqrii.c ijkl.c ilaenv.c initsv.c interp.c \
		iter.c jcarin.c linmin.c local.c locmin.c \
		lsame.c makpol.c mamult.c matou1.c matout.c \
		matpak.c meci.c mecid.c mecih.c mecip.c \
		moldat.c molval.c mullik.c mult.c nllsq.c \
		nuchar.c parsav.c partxy.c pathk.c paths.c \
		perm.c polar.c powsav.c powsq.c prtdrc.c \
		quadr.c react1.c reada.c readmo.c refer.c \
		repp.c rotat.c rotate.c rsp.c search.c \
		second.c setupg.c solrot.c swap.c sympro.c \
		symtry.c symtrz.c thermo.c timer.c timout.c \
		update.c upsurf.c vecprt.c writmo.c wrtkey.c \
		wrttxt.c xerbla.c xyzint.c \
		mopac7lib.c libmopac7.c

libmopac7includedir = $(includedir)/mopac7

libmopac7include_HEADERS = libmopac7.h

if HAVE_F2C
noinst_PROGRAMS = mopac7
mopac7_SOURCES = mopac7app.c
mopac7_LDFLAGS = -lmopac7 -lf2c -lm
else
# the executable is not built!
# so nothing here...
endif
