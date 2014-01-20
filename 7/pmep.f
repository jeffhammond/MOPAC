       SUBROUTINE PMEP
************************************************************************
*  This is a driving routine for computations of PMEP - Parametric
*  Molecular Electrostatic Potential as well as  MEP charges.
*
*  Ref.  B. Wang and G.P.Ford J.Compt.Chem. in press.
*        G.P.Ford and B. Wang J.Compt.Chem. 14(1993)1101.
*
*                               written by Bingze Wang, August 1993
************************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      INCLUDE 'SIZES'
      parameter (mxmep=numatm*50+1000)
      COMMON /MOLKST/ numat,nat(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      COMMON /KEYWRD/ KEYWRD
      common /geom/ geo(3,numatm)
      CHARACTER*241 KEYWRD
      dimension potpt(3,mxmep),coord(3,numatm),alpw(107)
c                                    AM1 parameters (for H,C,N,O,F,Cl)
      data alpw/2.92d0,4*0.0d0,4.36d0,6.95d0,9.22d0,5.53d0,0.0d0,
     1         6*0.0d0,3.32d0,90*0.0d0/
      data nmep/0/
*                                                 check for saving time
      IF(INDEX(KEYWRD,' AM1') .eq. 0) goto 999
      do 10 i=1,numat
         if (alpw(nat(i)).lt.0.1d0) goto 999
10    continue
c
      T1=SECOND()
C
      CALL GMETRY(GEO,COORD)
*                                              ***** calculate MEP only 
      IF(INDEX(KEYWRD,' PMEP') .NE. 0) THEN
         call mepmap(coord)
         goto 1000
      endif
*                         ***** choose surface where points are sampled
*
      IF (INDEX(KEYWRD,'WILLIAMS').NE.0) THEN
*                                                  The Williams surface
             CALL GRIDS(coord,potpt,nmep)
      ELSE
*                                                  The Connolly surface
             CALL SURFA(coord,potpt,nmep)
      ENDIF
C                                           ***** calculate mep charges
      CALL mepchg(coord,potpt,nmep)
C
1000  T1=SECOND()-T1
      WRITE(6,'(/1X,A,F9.2,A)') 'TIME TO CALCULATE MEP',T1,' SECONDS'
      RETURN
999   write(6,*) ' AM1 PARAMETERS FOR H,C,N,F AND CL ARE AVAILABLE.',
     1  '  PMEP WAS NOT EXECUTED'
      return
      END
c
      SUBROUTINE GRIDS(co,potpt,nmep)
*********************************************************************
*   This subroutine calculates the Williams surface or grids. It is
*   lifted from <ESP> by B.H.Besler and K.M.Merz.
*********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      INCLUDE 'SIZES'
      COMMON /MOLKST/ natom,ian(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      DIMENSION VDERW(53),DIST(100),XMIN(3),XMAX(3)
      dimension POTPT(3,*),CO(3,*)
C
      DATA VDERW/53*0.0D0/
      VDERW(1)=2.4D0
      VDERW(5)=3.0D0
      VDERW(6)=2.9D0
      VDERW(7)=2.7D0
      VDERW(8)=2.6D0
      VDERW(9)=2.55D0
      VDERW(15)=3.1D0
      VDERW(16)=3.05D0
      VDERW(17)=3.0D0
      VDERW(35)=3.15D0
      VDERW(53)=3.35D0
      SHELL=1.2D0
      GRID=0.8D0
      CLOSER=0.D0
C     CHECK IF VDERW IS DEFINED FOR ALL ATOMS
C
      DO 30 I=1,NATOM
         IF (VDERW(ian(i)).EQ.0.0D0) GO TO 40
   30 CONTINUE
      GO TO 50
   40 CONTINUE
      WRITE(6,*) 'VAN DER WAALS'' RADIUS NOT DEFINED FOR ATOM',I
      WRITE(6,*) 'IN WILLIAMS SURFACE ROUTINE PDGRID!'
      STOP
C     NOW CREATE LIMITS FOR A BOX
   50 DO 100 IX = 1,3
         XMIN(IX)= 100000.0D0
         XMAX(IX)=-100000.0D0
         DO 90 IA = 1,NATOM
            IF (CO(IX,IA)-XMIN(IX))60,70,70
   60       XMIN(IX)=CO(IX,IA)
   70       IF (CO(IX,IA)-XMAX(IX))90,90,80
   80       XMAX(IX)=CO(IX,IA)
   90    CONTINUE
  100 CONTINUE
C     ADD (OR SUBTRACT) THE MAXIMUM VDERW PLUS SHELL
      VDMAX=0.0D0
      DO 110 I=1,53
         IF (VDERW(I).GT.VDMAX) VDMAX=VDERW(I)
  110 CONTINUE
      DO 120 I=1,3
         XMIN(I)=XMIN(I)-VDMAX-SHELL
  120 XMAX(I)=XMAX(I)+VDMAX+SHELL
C STEP GRID BACK FROM ZERO TO FIND STARTING POINTS
      XSTART=0.0D0
  130 XSTART=XSTART-GRID
      IF (XSTART.GT.XMIN(1)) GO TO 130
      YSTART=0.0D0
  140 YSTART=YSTART-GRID
      IF (YSTART.GT.XMIN(2)) GO TO 140
      ZSTART=0.0D0
  150 ZSTART=ZSTART-GRID
      IF (ZSTART.GT.XMIN(3)) GO TO 150
      NPNT=0
      ZGRID=ZSTART
  160 YGRID=YSTART
  170 XGRID=XSTART
  180 DO 190 L=1,NATOM
         JZ=IAN(L)
         DIST(L)=SQRT((CO(1,L)-XGRID)**2+(CO(2,L)-YGRID)**2+
     1 (CO(3,L)-ZGRID)**2)
C     REJECT GRID POINT IF ANY ATOM IS TOO CLOSE
         IF(DIST(L).LT.(VDERW(JZ)-CLOSER)) GO TO 220
  190 CONTINUE
C BUT AT LEAST ONE ATOM MUST BE CLOSE ENOUGH
      DO 200 L=1,NATOM
         JZ=IAN(L)
         IF(DIST(L).GT.(VDERW(JZ)+SHELL)) GO TO 200
         GO TO 210
  200 CONTINUE
      GO TO 220
  210 NPNT=NPNT+1
      NMEP=NMEP+1
      POTPT(1,NMEP)=XGRID
      POTPT(2,NMEP)=YGRID
      POTPT(3,NMEP)=ZGRID
  220 XGRID=XGRID+GRID
      IF (XGRID.LE.XMAX(1)) GO TO 180
      YGRID=YGRID+GRID
      IF (YGRID.LE.XMAX(2)) GO TO 170
      ZGRID=ZGRID+GRID
      IF (ZGRID.LE.XMAX(3)) GO TO 160
      RETURN
      END
C
      SUBROUTINE SURFA(co,potpt,nmep)
************************************************************************
*   This subroutine calculated the molecular surface and was lifted
*   from M. Connolly's program by U.C.Singh and P.A.Kollman.
*   In this modified version it generates the sample points on four 
*   layers of Van der Waal's surfaces.
*                                     by Bingze Wang on 19 August 1993
************************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      INCLUDE 'SIZES'
      parameter (mxmep=numatm*50+1000)
      COMMON /MOLKST/ natom,ian(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      COMMON /KEYWRD/ KEYWRD
      CHARACTER*241 KEYWRD
      DIMENSION VANDER(100),CON(3,1000),ias(mxmep),RAD(MXMEP),
     1          co(3,*),POTPT(3,*)
      data scale/1.4d0/,dens/1.0d0/,scincr/0.20d0/,layer/4/
C
C     NEIGHBOR ARRAYS
C
C     THIS SAME DIMENSION FOR THE MAXIMUM NUMBER OF NEIGHBORS
C     IS USED TO DIMENSION ARRAYS IN THE LOGICAL FUNCTION COLLID
C
      DIMENSION INBR(200),CNBR(3,200),RNBR(200)
      LOGICAL SNBR(200),MNBR(200)
C
C              ARRAYS FOR ALL ATOMS, IATOM, JATOM AND KATOM COORDINATES
      DIMENSION CI(3), IELDAT(56), TEMP0(3)
C                                        GEOMETRIC CONSTRUCTION VECTORS
      DIMENSION CW(3,2)
C                                                     LOGICAL VARIABLES
      LOGICAL SI
C                                                     LOGICAL FUNCTIONS
      LOGICAL COLLIS
C                                            DATA FOR VANDER VALL RADII
      CHARACTER MARKER*3, MARKSS*3, MYNAM*3, IELDAT*4, NAMATM*4
      DATA VANDER/1.20D0,1.20D0,1.37D0,1.45D0,1.45D0,1.50D0,1.50D0,
     1            1.40D0,1.35D0,1.30D0,1.57D0,1.36D0,1.24D0,1.17D0,
     2            1.80D0,1.75D0,1.70D0,17*0.0D0,2.3D0,65*0.0D0/
      DATA MARKER/'A  '/,MARKSS/'SS0'/,MYNAM/'UC '/
C
      DATA IELDAT/'  BQ','  H ','  HE','  LI','  BE','  B ',
     1            '  C ','  N ','  O ','  F ','  NE','  NA',
     2            '  MG','  AL','  SI','  P ','  S ','  CL',
     3            '  AR','  K ','  CA','  SC','  TI','  V ',
     4            '  CR','  MN','  FE','  CO','  NI','  CU',
     5            '  ZN','  GA','  GE','  AS','  SE','  BR',
     6            '  KR','  RB','  SR','   Y','  ZR','  NB',
     7            '  MO','  TC','  RU','  RH','  PD','  AG',
     8            '  CD','  IN','  SN','  SB','  TE','   I',
     9            '   X','  CS'/
c
      PI=4.D0*ATAN(1.D0)
C                                    INSERT VAN DER WAAL RADII FOR ZINC
      VANDER(30)=1.00D0
c
         IF(INDEX(KEYWRD,'SCALE=') .NE. 0)
     1          SCALE = READA(KEYWRD,INDEX(KEYWRD,'SCALE='))
         IF(INDEX(KEYWRD,'DEN=') .NE. 0)
     1          DENS = READA(KEYWRD,INDEX(KEYWRD,'DEN='))
         IF(INDEX(KEYWRD,'SCINCR=') .NE. 0)
     1          SCINCR = READA(KEYWRD,INDEX(KEYWRD,'SCINCR='))
         IF(INDEX(KEYWRD,'NSURF=') .NE. 0)
     1      layer = READA(KEYWRD,INDEX(KEYWRD,'NSURF='))
c
      do 1000 ishel=1,layer
C                         ONLY VAN DER WAALS' TYPE SURFACE IS GENERATED
      RW =0.0D0
      DEN = DENS
      DO 30 I=1,NATOM
         IPOINT = IAN(I)
         RAD(I) = VANDER(IPOINT)*SCALE
         IF (RAD(I) .LT. 0.01D0) 
     1      WRITE(6,'(T2,''VAN DER WAALS'''' RADIUS FOR ATOM '',I3,
     1      '' IS ZERO, SUPPLY A VALUE IN SUBROUTINE SURFAC)'' )')
         IAS(I) = 2
   30 CONTINUE
C
C     BIG LOOP FOR EACH ATOM
C
      DO 110 IATOM = 1, NATOM
         IF (IAS(IATOM) .EQ. 0) GO TO 110
C
C     TRANSFER VALUES FROM LARGE ARRAYS TO IATOM VARIABLES
C
         NAMATM =IELDAT(IAN(IATOM)+1)
         RI = RAD(IATOM)
         SI = IAS(IATOM) .EQ. 2
         DO 40 K = 1,3
            CI(K) = CO(K,IATOM)
   40    CONTINUE
C                                GATHER THE NEIGHBORING ATOMS OF IATOM
         NNBR = 0
         DO 60 JATOM = 1, NATOM
            IF (IATOM .EQ. JATOM .OR. IAS(JATOM) .EQ. 0) GO TO 60
            d2=(ci(1)-co(1,jatom))**2+(ci(2)-co(2,jatom))**2
     1         +(ci(3)-co(3,jatom))**2
            IF (D2 .GE. (2*RW+RI+RAD(JATOM)) ** 2) GO TO 60
C
C     WE HAVE A NEW NEIGHBOR
C     TRANSFER ATOM COORDINATES, RADIUS AND SURFACE REQUEST NUMBER
C
           NNBR = NNBR + 1
           IF (NNBR .GT. 200)THEN
              WRITE (6,'(''ERROR'',2X,''TOO MANY NEIGHBORS:'',I5)')NNBR
              STOP
           ENDIF
           INBR(NNBR) = JATOM
           DO 50 K = 1,3
              CNBR(K,NNBR) = CO(K,JATOM)
   50      CONTINUE
           RNBR(NNBR) = RAD(JATOM)
           SNBR(NNBR) = IAS(JATOM) .EQ. 2
   60    CONTINUE
C
C     CONTACT SURFACE
C
         IF (.NOT. SI) GO TO 110
         NCON = (4 * PI * RI ** 2) * DEN
         IF (NCON .GT. 1000) NCON = 1000
C
C     THIS CALL MAY DECREASE NCON SOMEWHAT
C
         IF ( NCON .EQ. 0) THEN
            WRITE(6,'(T2,''VECTOR LENGTH OF ZERO IN SURFAC'')')
            STOP
         ENDIF
         CALL GENVEC(CON,NCON)
         AREA = (4 * PI * RI ** 2) / NCON
C
C     CONTACT PROBE PLACEMENT LOOP
C
         DO 100 I = 1,NCON
            DO 70 K = 1,3
               CW(K,1) = CI(K) + (RI + RW) * CON(K,I)
   70       CONTINUE
C
C     CHECK FOR COLLISION WITH NEIGHBORING ATOMS
C
            IF (COLLIS(CW(1,1),RW,CNBR,RNBR,MNBR,NNBR,1,
     1      JNBR,KNBR)) GO TO 100
            DO 80 KK=1,3
               TEMP0(KK) =CI(KK)+RI*CON(KK,I)
   80       CONTINUE
C
C     STORE POINT IN POTPT AND INCREMENT NMEP
C
            NMEP = NMEP + 1
            IF (NMEP .GT. MXMEP) GOTO 1001
            POTPT(1,NMEP) = TEMP0(1)
            POTPT(2,NMEP) = TEMP0(2)
            POTPT(3,NMEP) = TEMP0(3)
  100    CONTINUE
  110 CONTINUE
            SCALE = SCALE + SCINCR
1000  continue
      RETURN
1001  WRITE(6,90)
      STOP
   90 FORMAT(/'ERROR - TO MANY POINTS GENERATED IN SURFAC'/,
     1        '    REDUCE NSURF, SCALE, DEN, OR SCINCR')
      END
C
      LOGICAL FUNCTION COLLIS(CW,RW,CNBR,RNBR,MNBR,NNBR,ISHAPE,
     1JNBR,KNBR)
C****************************************************************
C     COLLISION CHECK OF PROBE WITH NEIGHBORING ATOMS
C     FOR CONNOLLY SURFACE ONLY.
C****************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      DIMENSION CW(3), CNBR(3,200), RNBR(200)
      LOGICAL MNBR(200)
c
      COLLIS = .FALSE.
      IF (NNBR .LE. 0) RETURN
C                 CHECK WHETHER PROBE IS TOO CLOSE TO ANY NEIGHBOR
      DO 10 I = 1, NNBR
         IF (ISHAPE .GT. 1 .AND. I .EQ. JNBR) GO TO 10
         IF (ISHAPE .EQ. 3 .AND. (I .EQ. KNBR .OR. .NOT. MNBR(I)))
     1   GO TO 10
         SUMRAD = RW + RNBR(I)
         VECT1 = DABS(CW(1) - CNBR(1,I))
         IF (VECT1 .GE. SUMRAD) GO TO 10
         VECT2 = DABS(CW(2) - CNBR(2,I))
         IF (VECT2 .GE. SUMRAD) GO TO 10
         VECT3 = DABS(CW(3) - CNBR(3,I))
         IF (VECT3 .GE. SUMRAD) GO TO 10
         SR2 = SUMRAD ** 2
         DD2 = VECT1 ** 2 + VECT2 ** 2 + VECT3 ** 2
         IF (DD2 .LT. SR2) GO TO 30
   10 CONTINUE
      RETURN
   30 COLLIS = .TRUE.
      RETURN
      END
C
      SUBROUTINE GENVEC(U,N)
C*******************************************************************
C  GENERATE UNIT VECTORS OVER SPHERE. FOR CONNOLLY SURFACE ONLY
C*******************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      DIMENSION U(3,N)
      PI=4.D0*ATAN(1.D0)
      NEQUAT = SQRT(N * PI)
      NVERT = NEQUAT/2
      NU = 0
      DO 20 I = 1,NVERT+1
         FI = (PI * (I-1)) / NVERT
         Z = COS(FI)
         XY = SIN(FI)
         NHOR = NEQUAT * XY
         IF (NHOR .LT. 1) NHOR = 1
         DO 10 J = 1,NHOR
            FJ = (2.D0 * PI * (J-1)) / NHOR
            X = DCOS(FJ) * XY
            Y = DSIN(FJ) * XY
            IF (NU .GE. N) GO TO 30
            NU = NU + 1
            U(1,NU) = X
            U(2,NU) = Y
            U(3,NU) = Z
   10    CONTINUE
   20 CONTINUE
   30 CONTINUE
      N = NU
      RETURN
      END
C
      subroutine mepchg(co,potpt,nmep)
***********************************************************************
*  MEPCHG calculates the mep charges by fitting the quantum potential 
*  to the coulomb potential. 
*  Ref.  B. Wang and G.P.Ford J.Compt.Chem. in press.
*        G.P.Ford and B. Wang J.Compt.Chem. 14(1993)1101.
*                                       Bingze Wang on 19 August 1993
***********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      INCLUDE 'SIZES'
      parameter (mxmep=numatm*50+1000, nonzox=10*maxhev+maxlit+50)
      COMMON /DENSTY/ P(MPACK),PA(MPACK),PB(MPACK)
      COMMON /MOLKST/ natom,ian(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      COMMON /DIPSTO/ UX,UY,UZ,CH(NUMATM)
      COMMON /ELEMTS/ ELEMNT(107)
      COMMON /KEYWRD/ KEYWRD
      CHARACTER KEYWRD*241, ELEMNT*2
      dimension AL((NUMATM+4)**2),A(NUMATM+4,NUMATM+4),Q(NUMATM),
     1          POTPT(3,*),EP(mxmep),co(3,*),b(numatm+4),pp(nonzox),
     1          QSC(NUMATM),d(numatm,mxmep),d1(numatm,mxmep),qq(numatm)
      LOGICAL CEQUIV(NUMATM,NUMATM),idip
c
      DATA AU/627.506d0/,BOHR/0.529167D0/,iz/0/,RMS/0.0d0/,RRMS/0.0d0/, 
     1   DIPX/0.0d0/, DIPY/0.0d0/, DIPZ/0.0d0/,idip/.false./
      BOHR1=1.0d0/BOHR
      AU1=1.0d0/AU
      CF=5.2917715D0*1.601917D0/3.33564D0
      natom0=natom+1
c
      WRITE(6,11)
11    format(//1X,'ATOMIC CHARGES DERIVED FROM MOLECULAR',
     1  ' ELECTROSTATIC POTENTIAL')
      IF(INDEX(KEYWRD,' WILLIAMS').NE.0) then
          write(6,'(8x,"(WILLIAMS SURFACES)"/)')
      else
          write(6,'(8x,"(CONNOLLY SURFACES)"/)')
      endif
C
      IF(INDEX(KEYWRD,' CHARGE=') .NE. 0) 
     1      IZ=READA(KEYWRD,INDEX(KEYWRD,' CHARGE='))
C                                                  DIPOLAR CONSTRAINTS
      IF(INDEX(KEYWRD,'DIPOLE').NE.0) THEN
        if (iz.eq.0) then
           idip = .true.
           natom0=natom+4
           WRITE(6,'(/12X,''DIPOLE CONSTRAINTS WILL BE USED'',/)')
           DX = UX
           DY = UY
           DZ = UZ
           IF(INDEX(KEYWRD,'DIPX=') .NE. 0) 
     1       DX = READA(KEYWRD,INDEX(KEYWRD,'DIPX='))
           IF(INDEX(KEYWRD,'DIPY=') .NE. 0) 
     1       DY = READA(KEYWRD,INDEX(KEYWRD,'DIPY='))
           IF(INDEX(KEYWRD,'DIPZ=') .NE. 0)
     1       DZ = READA(KEYWRD,INDEX(KEYWRD,'DIPZ='))
        else
           WRITE(6,*)' DIPOLE CONSTRAINTS NOT USED FOR CHARGED MOLECULE'
        endif
      ENDIF
      DO 10  K=1,natom
            xk=CO(1,K)
            yk=CO(2,K)
            zk=CO(3,K)
         DO 10  I=1,NMEP
            xp=POTPT(1,I)-xk
            yp=POTPT(2,I)-yk
            zp=POTPT(3,I)-zk
            dki=SQRT(xp*xp+yp*yp+zp*zp)
            d(k,i)=dki
            d1(k,i)=BOHR/dki
10    CONTINUE
c
*******  SET UP THE LINEAR EQUATION A*Q=B  *******
c                                       MEP at sample points & b matrix
      call packp(p,pp,nonzo)
        do 20 i=1,natom
20      b(i)=0.0d0
      DO 100 Ip=1,NMEP
        call pmepco(pp,d(1,ip),potpt(1,ip),ui,co,nonzo,1)
        ep(ip)=ui*au1
        DO 40 i=1,natom
40      B(i)=B(i)+EP(Ip)*d1(i,ip)
100   continue
        B(NATOM+1)=FLOAT(IZ)
      IF(IDIP) THEN
        B(NATOM+2)=DX/CF
        B(NATOM+3)=DY/CF
        B(NATOM+4)=DZ/CF
      ENDIF
C                                                      THE A(J,K) ARRAY
      DO 120  K=1,NATOM
        DO 118  J=1,k
            ajk=0.0d0
          DO 115  IP=1,NMEP
            AJK=AJK+d1(k,ip)*d1(j,ip)
  115     CONTINUE
            a(k,j)=ajk
            A(J,K)=AJK
  118    continue
            A(NATOM+1,K)= 1.D0
            A(K,NATOM+1)= 1.D0
         IF(IDIP) THEN
            A(NATOM+2,K)= CO(1,K)*BOHR1
            A(NATOM+3,K)= CO(2,K)*BOHR1
            A(NATOM+4,K)= CO(3,K)*BOHR1
            A(K,NATOM+2)= A(NATOM+2,K)
            A(K,NATOM+3)= A(NATOM+3,K)
            A(K,NATOM+4)= A(NATOM+4,K)
         ENDIF
  120 CONTINUE
            A(NATOM+1,NATOM+1)=0.D0
         IF(IDIP) THEN
            A(NATOM+2,NATOM+2)=0.D0
            A(NATOM+3,NATOM+3)=0.D0
            A(NATOM+4,NATOM+4)=0.D0
         ENDIF
C                                                            solve AQ=B            
         L=0
         DO 130 I=1,NATOM0 
            DO 130 J=1,NATOM0
               L=L+1
  130    AL(L)=A(I,J)
      CALL OSINV(AL,NATOM0,DET)
         L=0
         DO 150 I=1,NATOM
             qi=0.0d0
            DO 140 J=1,NATOM0
               L=L+1
               QI=QI+AL(L)*B(J)
  140       CONTINUE
            q(i)=qi
  150    CONTINUE
C                               AVERAGE CHARGES EQUIVALENT BY SYMMETRY
        DO 70 I=1,NATOM
           DO 70 J=1,NATOM
             CEQUIV(I,J)=.FALSE.
             IF(ABS(ABS(CH(I))-ABS(CH(J))).LT.1.D-5) CEQUIV(I,J)=.TRUE.
   70   CONTINUE
        DO 90 I=1,NATOM
          IEQ=0
          QSC(I)=0.D0
          DO 80 J=1,NATOM
             IF(CEQUIV(I,J)) THEN
                QSC(I)=QSC(I)+ABS(Q(J))
                IEQ=IEQ+1
             ENDIF
   80     CONTINUE
          QQ(I)=Q(I)/ABS(Q(I))*QSC(I)/IEQ
   90   CONTINUE
        DO 95 I=1,NATOM
95        Q(I)=QQ(I)
C                              ROOT MEAN SQUARE (RMS) AND RELATIVE RMS 
      DO 160 I=1,NMEP
         EPC=0.D0
         EPI=EP(I)
         DO 155 J=1,NATOM
  155    EPC=EPC+Q(J)*d1(j,i)
         EPC=EPC-EPI
         RMS=RMS+EPC*EPC
  160 RRMS=RRMS+EPI*EPI
      RMS=SQRT(RMS/NMEP)
      RRMS=RMS/SQRT(RRMS/NMEP)
      RMS=RMS*AU
C     
      WRITE(6,'(3X,''ATOM NO.    TYPE    CHARGE'')')
      DO 170 I=1,NATOM
  170 WRITE(6,'(5X,I2,9X,A2,1X,F10.4)') I,ELEMNT(IAN(I)),Q(I)
C
      WRITE(6,'(/2X,A,4X,I6)')  'NUMBER OF POINTS ',NMEP
      WRITE(6,'(2X,A,4X,F9.4)') 'RMS DEVIATION ',RMS
      WRITE(6,'(2X,A,3X,F9.4)') 'RRMS DEVIATION ',RRMS
C
      IF (IZ.NE.0) RETURN
C                                    DIPOLE MOMENT FOR NEUTRAL MOLECULE
         DO 50 I=1,NATOM
            DIPX=DIPX+CO(1,I)*Q(I)
            DIPY=DIPY+CO(2,I)*Q(I)
            DIPZ=DIPZ+CO(3,I)*Q(I)
   50    CONTINUE
            DIPX=DIPX*BOHR1
            DIPY=DIPY*BOHR1
            DIPZ=DIPZ*BOHR1
            DIP =SQRT(DIPX*DIPX+DIPY*DIPY+DIPZ*DIPZ)
      WRITE(6,'(//1X,"DIPOLE MOMENT EVALUATED FROM THE MEP CHARGES")')
      WRITE(6,'(7X,''D(X)     D(Y)     D(Z)     TOTAL'')')
      WRITE(6,'(3X,4F9.4)')DIPX*CF,DIPY*CF,DIPZ*CF,DIP*CF
c
      RETURN
      END
c
      subroutine packp(p,pp,mn)                                      
**********************************************************************
*  Subroutine packp re-writes the density matrix. 
*  Written by Bingze Wang, 20 October 1991.
**********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                               
      INCLUDE 'SIZES'                                                   
      COMMON /MOLKST/ NUMAT,NAT(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      dimension p(*), pp(*)                                             
      mn=0                                                              
      do 100 i=1,numat                                                  
             ia=nfirst(i)                                               
             ib=nlast(i)                                                
           do 80 j=ia,ib                                                
                j1st=j*(j-1)/2                                          
           do 80 k=ia,j                                                 
                mn=mn+1                                                 
                pp(mn)=p(j1st+k)                                        
   80      continue                                                     
  100   continue                                                        
      return                                                            
      end                                                               
c                                                                       
      SUBROUTINE DREPP2(NI,NJ,RIJ,RI,CORE)
**********************************************************************
* DREPP2 calculates the integral for PMEP.
* Reference G.P.Ford and B.Wang, J.Comput.Chem. 14 (1993)1101.
*                            Written by Bingze Wang, 10 October 1991.
**********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                               
      COMMON /MULTIP/ DD(107),QQ(107),ADD(107,3)                        
      COMMON /CORE/ TORE(107)                                           
      COMMON /NATORB/ NATORB(107)                                       
      DIMENSION RI(22),CORE(4,2),ARG(72),SQR(72) 
      DATA A0/0.529167D0/ ,EV/27.21D0/, EV1/13.605D0/, EV2/6.8025D0/
      DATA PP/0.5D00/          
      R=RIJ/A0                                                          
      IF (NATORB(NI).lt.3) then 
c                                           HYDROGEN - HYDROGEN (SS/SS)
         AEE = PP/ADD(NI,1) 
         AEE = AEE * AEE                                                
         RI(1) = EV/DSQRT(R*R+AEE)                                      
         CORE(1,1 )= RI(1)                                     
         CORE(1,2) = TORE(NI)*RI(1)                                     
      ELSE 
c                                                 HEAVY ATOM - HYDROGEN
         AEE = PP/ADD(NI,1) 
         AEE = AEE * AEE                                                
         DA=DD(NI)                                                      
         QA=QQ(NI) * 2.0d0
         ADE = PP/ADD(NI,2) 
         ADE = ADE * ADE                                                
         AQE = PP/ADD(NI,3) 
         AQE = AQE * AQE                                                
         RSQ = R*R                                                      
         ARG(1) = RSQ + AEE                                             
         XXX = R+DA                                                     
         ARG(2) = XXX*XXX + ADE                                         
         XXX = R-DA                                                     
         ARG(3) = XXX*XXX + ADE                                         
         XXX = R+QA                                                     
         ARG(4) = XXX*XXX + AQE                                         
         XXX = R-QA                                                     
         ARG(5) = XXX*XXX + AQE                                         
         ARG(6) = RSQ + AQE                                             
         ARG(7) = ARG(6) + QA*QA                                        
         DO 10 I = 1,7                                                  
            SQR(I) = DSQRT(ARG(I))                                     
   10    CONTINUE                                                       
         EE = EV/SQR(1)                                                 
         RI(1) = EE                                                     
         RI(2) = EV1/SQR(2) - EV1/SQR(3)                                
         RI(3) = EE + EV2/SQR(4) + EV2/SQR(5) - EV1/SQR(6)              
         RI(4) = EE + EV1/SQR(7) - EV1/SQR(6)                           
         CORE(1,1) = RI(1)                                     
         CORE(2,1) = RI(2)                                     
         CORE(3,1) = RI(3)                                     
         CORE(4,1) = RI(4)                                     
         CORE(1,2) = TORE(NI)*RI(1)                                     
      endif                    
      RETURN                                                            
      END                                                               
C                                                                       
      SUBROUTINE DROTAT(NI,NJ,XI,XJ,E1B,ENUC,rij)
***********************************************************************
*  Subroutine DROTAT transforms the integrals from local coordinates
*  into molecular coordinates for PMEP computations. 
*                                  written by Bingze Wang, Nov. 1991
***********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                               
      COMMON /NATORB/ NATORB(107)                                       
      COMMON /CORE  / TORE(107)                                         
      COMMON /ROTDUM/ CSS1,CSP1,CPPS1,CPPP1,CSS2,CSP2,CPPS2,CPPP2       
      dimension  X(3),Y(3),Z(3)                                    
      DIMENSION XI(3),XJ(3),E1B(10)
      DIMENSION RI(22),CCORE(4,2)
      EQUIVALENCE (CCORE(1,1),CSS1)                                     
C                                                                       
      X(1)=XI(1)-XJ(1)                                                  
      X(2)=XI(2)-XJ(2)                                                  
      X(3)=XI(3)-XJ(3)                                                  
         RIJX= RIJ                                                      
c                                   COMPUTE INTEGRALS IN DIATOMIC FRAME 
         CALL dREPP2(NI,NJ,RIJ,RI,CCORE)
C                                                                       
         GAM = RI(1)                                                    
         A=1.D0/RIJX                                                    
         X(1) = X(1)*A                                                  
         X(2) = X(2)*A                                                  
         X(3) = X(3)*A                                                  
         IF (dABS(X(3)).GT.0.99999D0) THEN                         
            X(3) = dSIGN(1.D0,X(3))                             
            Y(1) = 0.D0                                                 
            Y(2) = 1.D0                                                 
            Y(3) = 0.D0                                                 
            Z(1) = 1.D0                                                 
            Z(2) = 0.D0                                                 
            Z(3) = 0.D0                                                 
         ELSE                                                           
            Z(3)=DSQRT(1.D0-X(3)*X(3))                                  
            A=1.D0/Z(3)                                                 
            Y(1)=-A*X(2)*DSIGN(1.D0,X(1))                       
            Y(2)=dABS(A*X(1))                                     
            Y(3)=0.D0                                                   
            Z(1)=-A*X(1)*X(3)                                           
            Z(2)=-A*X(2)*X(3)                                           
         ENDIF                                                          
         IF ( NATORB(NI).GT.1) THEN 
            XX11 = X(1)*X(1)                                            
            XX21 = X(2)*X(1)                                            
            XX22 = X(2)*X(2)                                            
            XX31 = X(3)*X(1)                                            
            XX32 = X(3)*X(2)                                            
            XX33 = X(3)*X(3)                                            
            YY11 = Y(1)*Y(1)                                            
            YY21 = Y(2)*Y(1)                                            
            YY22 = Y(2)*Y(2)                                            
            ZZ11 = Z(1)*Z(1)                                            
            ZZ21 = Z(2)*Z(1)                                            
            ZZ22 = Z(2)*Z(2)                                            
            ZZ31 = Z(3)*Z(1)                                            
            ZZ32 = Z(3)*Z(2)                                            
            ZZ33 = Z(3)*Z(3)                                            
            YYZZ11 = YY11+ZZ11                                          
            YYZZ21 = YY21+ZZ21                                          
            YYZZ22 = YY22+ZZ22                                          
         ENDIF                                                          
C                               ROTATE THE NUCLEAR ATTRACTION INTEGRALS 
         E1B(1)=-CSS1                                                   
         IF(NATORB(NI).EQ.4) THEN                                       
            E1B(2) = -CSP1 *X(1)                                        
            E1B(3) = -CPPS1*XX11-CPPP1*YYZZ11                           
            E1B(4) = -CSP1 *X(2)                                        
            E1B(5) = -CPPS1*XX21-CPPP1*YYZZ21                           
            E1B(6) = -CPPS1*XX22-CPPP1*YYZZ22                           
            E1B(7) = -CSP1 *X(3)                                        
            E1B(8) = -CPPS1*XX31-CPPP1*ZZ31                             
            E1B(9) = -CPPS1*XX32-CPPP1*ZZ32                             
            E1B(10)= -CPPS1*XX33-CPPP1*ZZ33                             
         ENDIF                                                         
         ENUC = TORE(NI)*GAM                                   
      RETURN                                                            
      END                                                               
c
      subroutine mepmap(c1)
**********************************************************************
*  Subroutine MEPMAP calculates the MEP minima and generates the 
*  conrour data in a defined plane.
*  Ref.  G.P.Ford and B. Wang J.Compt.Chem. 14(1993)1101.
*                                    written by Bingze Wang, Dec 1992
**********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                               
      INCLUDE 'SIZES'                                                   
      parameter (nonzox=10*maxhev+maxlit+50)
      COMMON /DENSTY/ P(MPACK),PA(MPACK),PB(MPACK)
      COMMON /MOLKST/ NUMAT,NAT(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      common /keywrd/ keywrd                                            
      common /elemts/ elemnt(107)
      character keywrd*241,elemnt*2
      dimension pp(nonzox),w(3),c1(3,*),
     1          r0(3),t(3,3),ria(numatm),mx(numatm),my(numatm),
     1          vmin(numatm),cw(3,numatm),uu(200),rk(3),cmep(3,numatm)
      data t/1.0d0,3*0.0d0,1.0d0,3*0.0d0,1.0d0/
      data step/0.1d0/,need1/0/,natm/0/,r0/3*0.0d0/,iw/7/,cut/999.0d0/
      data icase/0/,z0/0.0d0/,iback/0/
      logical prtmep,minmep
      write(6,15)
15    format(///13x,'MOLCULAR ELECTROSTATIC POTENTIAL',
     1 //1x,'REFERENCES  B.WANG AND G.P.FORD J.COMPT.CHEM. IN PRESS',
     1  /13x,'G.P.FORD AND B.WANG J.COMPT.CHEM. 14(1993)1101')
      call meprot(c1,r0,t,xm,ym,icase,step,cmep,z0,iback)
      if (iback.gt.0) return
      prtmep=INDEX(KEYWRD,' PRTMEP').ne.0
      minmep=INDEX(KEYWRD,' MINMEP').ne.0
      do 20 i=1,numat
        cw(1,i)=cut
        cw(2,i)=cut
        cw(3,i)=cut
 20     vmin(i)=cut
c                             
      call packp(p,pp,nonzo)
c        
         npx=int(xm/step)*2+1
      if (icase.eq.2.or.icase.eq.3) then
         ym=ym+3.0d0
         npy=int(ym/step)+1
      else
         npy=int(ym/step)*2+1
      endif
      if (prtmep) then
        write(iw,25) numat,npx,npy,-xm,-ym,step
25      format(1x,3i5,3f8.2/)
        write(iw,35) npx,npy,npx*npy,z0,-xm,step,-ym,step
        write(7,45)
        write(7,55) (i,nat(i),(cmep(k,i),k=1,2),i=1,numat)
        write (7,*)
      endif
c                                   create the points and calculate mep
         do 30 i=1,3
30        rk(i)=r0(i)
c
         ip=0
          t11=t(1,1)
          t12=t(1,2)
          t13=t(1,3)
          t21=t(2,1)
          t22=t(2,2)
          t23=t(2,3)
          t31=t(3,1)
          t32=t(3,2)
          t33=t(3,3)
         xx0=z0*t31
         yy0=z0*t32
         zz0=z0*t33
         xxw=xx0+r0(1)
         yyw=yy0+r0(2)
         zzw=zz0+r0(3)
         step1=step
888      xx1=xx0+r0(1)
         yy1=yy0+r0(2)
         zz1=zz0+r0(3)
c     
         do 3000 m=1,npx
            stepm=(m-1)*step1
            xx2=xx1+stepm*t11
            yy2=yy1+stepm*t12
            zz2=zz1+stepm*t13
         do 2000 n=1,npy
            uu(n)=cut
            stepn=(n-1)*step1
            w(1)=xx2+stepn*t21
            w(2)=yy2+stepn*t22
            w(3)=zz2+stepn*t23
         if (need1.eq.0) then 
c                                          check if too close to nuclei
               rmin=81.0d0
            do 60 i=1,numat
               rr=(w(1)-c1(1,i))**2+(w(2)-c1(2,i))**2+(w(3)-c1(3,i))**2
               if (rr.lt.0.25d0) goto 2000
               if (nat(i).gt.1.and.rr.lt.0.36d0) goto 2000
               ria(i)=sqrt(rr)
               if (rmin.gt.rr) then
                  rmin=rr
                  imin=i
               endif
60          continue
            call pmepco(pp,ria,w,ui,c1,nonzo,1)
            uu(n)=ui
            if (ui.lt.vmin(imin)) then
               vmin(imin)=ui
               cw(1,imin)=w(1)
               cw(2,imin)=w(2)
               cw(3,imin)=w(3)
               mx(imin)=m 
               my(imin)=n
            endif
         else
            call pmepco(pp,ria,w,ui,c1,nonzo,0)
            if (ui.lt.vmin(natm)) then
               vmin(natm)=ui
               cw(1,natm)=w(1)
               cw(2,natm)=w(2)
               cw(3,natm)=w(3)
            endif
         endif
            ip=ip+1
2000   continue
       if (need1.eq.0.and.prtmep)  write(iw,99) (uu(ny),ny=1,npy)
3000   continue
c
       if (need1.eq.0)  write(6,401) npx,npy
       if (prtmep.and.need1.eq.0) 
     1             write(6,*) '=> CONTOUR FILE IS PRINTED ON CHANNEL 7'
       if (need1.gt.0) goto 777
c                                               remove the false minima
      minima=0
      do 80 i=1,numat
         if (vmin(i).gt.0.0d0) goto 80
         do 70 m=mx(i)-1,mx(i)+1
            stepm=(m-1)*step 
            xx2=xxw+stepm*t11
            yy2=yyw+stepm*t12
            zz2=zzw+stepm*t13
         do 70 n=my(i)-1,my(i)+1
            stepn=(n-1)*step
            w(1)=xx2+stepn*t21
            w(2)=yy2+stepn*t22
            w(3)=zz2+stepn*t23
            ip=ip+1
          call pmepco(pp,ria,w,ui,c1,nonzo,0)
          if (ui.lt.vmin(i)-0.001) then
              vmin(i)=99.0
              goto 80 
          endif
70     continue
          minima=minima+1
80     continue
        if (minima.eq.0) then
           write(6,*)' NO MEP MINIMUM FOUND IN THIS PLANE'
           return
        endif
        if (.not.minmep) goto 999
              need1=1
              step1=step*0.2d0
              npx=11
              npy=11
777     natm=natm+1
          if (natm.gt.numat) goto 999
          if (vmin(natm).gt.0.0d0) goto 777
              r0(1)=cw(1,natm)-step*(t11+t21)
              r0(2)=cw(2,natm)-step*(t12+t22)
              r0(3)=cw(3,natm)-step*(t13+t23)
              goto 888
999   if (need1.gt.0)  write(6,402) ip
      write(6,403)
      do 600 i=1,numat
         if (vmin(i).lt.0.0d0) 
     1   write(6,405) i,elemnt(nat(i)),vmin(i),
     1      dsqrt((c1(1,i)-cw(1,i))**2+(c1(2,i)-cw(2,i))**2
     1           +(c1(3,i)-cw(3,i))**2),
     1      (cw(j,i),j=1,3)
600   continue
      return
35    format(22x,'INSTRUCTION', 
     1  /1x,'1) NX*NY = ',I3,'*',I3,' =',I6,' GRIDS;',
     1  /1x,'2) NY VALUES IN EACH OF THE NX BLOCKS;',
     1  /1x,'3) X,Y COORDINATES (Z=',F6.2,' ) OF THE GRIDS:',
     1  /9X,'X(I)=',F8.2,'+',F6.2,'*(I-1)    I=1,2,...,NX',
     1  /9x,'Y(J)=',F8.2,'+',F6.2,'*(J-1)    I=1,2,...,NY')
45    format(1x,'4) THE MOLECULAR COORDINATES (X,Y)',
     1         ' ON THE 2D-MEP CONTOUR MAP')
55    format(9x,2i4,2f12.5)
99    format(6f11.5)
401   format(/1x,'GRIDS NX*NY=', I3,' *',I3)
402   format(1x,'TOTAL NUMBER OF THE POINTS CALCULATED ',I8)
403   format(/1x,'MINIMA IN THE SPECIFIED PLANE',
     1      /5x,'ATOM       UMIN      DISTANCE',10X,'XYZ COORDINATE',
     1 /15X,'KCAL/MOL     ANG',14X,'IN MOL COORD')
405   format(3x,i3,2x,a2,2x,f9.1,4x,f6.2,4x,3f9.3)
      end
c
      subroutine pmepco(pp,ria,w,ui,co,nonzo,id)
***********************************************************************
* pmepco is the core subroutine of this program <PMEP>. It calculates
* the MEP at an arbitralry position w(3). 
* Ref.  B. Wang and G.P.Ford J.Compt.Chem. in press
*       G.P.Ford and B. Wang J.Compt.Chem. 14(1993)1101 
*                                      Written by Bingze Wang Feb 1993
***********************************************************************
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                               
      INCLUDE 'SIZES'                                                   
      parameter (nonzox=10*maxhev+maxlit+50)
      COMMON /MOLKST/ NUMAT,NAT(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
      dimension e1b(10),pp(*),w(3),vp(nonzox),co(3,*),ria(*)
      dimension alpw(107),aw(107)
c                                    AM1 parameters (for H,C,N,O,F,Cl)
      data alpw/2.92d0,4*0.0d0,4.36d0,6.95d0,9.22d0,5.53d0,0.0d0,
     1         6*0.0d0,3.32d0,90*0.0d0/
      data  aw /0.05d0,4*0.0d0,0.63d0,0.64d0,0.67d0,0.29d0,0.0d0,
     1         6*0.0d0,0.31d0,90*0.0d0/
      data ev/23.061d0/
c
      do 10 j=1,nonzo                                                   
   10 vp(j)=0.0d0                                                       
             mn=0                                                       
             ENUCLR=0.D0                                                
      DO 200 I=1,NUMAT                                                  
         IA=NFIRST(I)                                                   
         IB=NLAST(I)                                                    
         NI=NAT(I)                                                      
            if (id.eq.1) then
                 rr=ria(i)
            else
                 xx=w(1)-co(1,i)
                 yy=w(2)-co(2,i)
                 zz=w(3)-co(3,i)
                 rr=sqrt(xx*xx+yy*yy+zz*zz)
            endif
            fnear=1.0d0+exp(-alpw(ni)*(rr-aw(ni)) )
c                                                                       
            CALL DROTAT(NI,1,CO(1,I),w,E1B,ENUC,rr) 
            ENUCLR = ENUCLR + ENUC *fnear
            I2=0                                                        
            DO 60 I1=IA,IB
            DO 60 J1=IA,I1                                           
                  I2=I2+1                                               
                  mn=mn+1                                               
                  vp(mn)=E1B(I2)
   60       continue
  200    CONTINUE                                                       
           mn=0                                                         
           ui=0.0d0   
        do 50 i=1,numat                                                 
             ia=nfirst(i)                                               
             ib=nlast(i)                                                
           do 51 j=ia,ib                                                
           do 51 k=ia,j                                                 
                 mn=mn+1                                                
                 if (k.eq.j) then                                       
                     ui=ui+pp(mn)*vp(mn)                             
                 else                                                   
                     ui=ui+2.0d0*pp(mn)*vp(mn)                         
                 endif                                                  
   51      continue                                                     
  50    continue                                                        
        ui=(enuclr+ui)*ev
c                                                       ui  in kcal/mol
      return
      end
c
      subroutine meprot(c,r0,t,xm,ym,icase,step,c1,z0,iback)
**********************************************************************
* MEPROT rotates the molecule to choose the plane in which MEP is 
* to be computed. 
*                                     by Bingze Wang  28 Oct 1992
**********************************************************************
      implicit double precision (a-h,o-z)                               
      INCLUDE 'SIZES'                                                   
      COMMON /MOLKST/ NUMAT,NAT(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM),  
     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA,        
     2                NCLOSE,NOPEN,NDUMY,FRACT                          
     3      /KEYWRD/ KEYWRD
      CHARACTER KEYWRD*241
      dimension  c(3,*),c1(3,*),t(3,3),r0(3),c0(3)
      data c0/3*0.0d0/
c
11    FORMAT(/1X,'INPUT CARD FOR PMEPR: ICASE,I,J,K,Z0 =',4I4,F8.2)
15    FORMAT(1X,'ICASE SHOULD BE 1,2, OR 3 AS PMEPR IS SPECIFIED',
     1      /1x, 'PMEPR WAS NOT EXECUTED')
16    format(1x,'THE THREE REFERENTIAL ATOMS ARE UNREASONABLE, ',
     1      /1x, 'PMEPR WAS NOT EXECUTED')
c
      if (INDEX(KEYWRD,' PMEPR').eq.0) goto 111
        read(5,*) icase,n1,n2,n3,z0
      write(6,11) icase,n1,n2,n3,z0 
      if (icase.lt.1.or.icase.gt.3) then
                 write(6,15)    
                 iback=1
                 return
      endif
      if (n1.eq.n2.or.n1.eq.n3.or.n2.eq.n3.or.
     1     n1.gt.numat.or.n2.gt.numat.or.n3.gt.numat) then
                 write(6,16)    
                 iback=1
                 return
      endif
      if (icase.eq.1) then
           if (abs(z0).lt.0.0001d0) then
                 write(6,21) n1,n2,n3
           else
                 write(6,22) z0,n1,n2,n3
           endif
      endif
21    format(1x,'MEPS ARE IN THE PLANE DEFINED BY ATOMS',
     1      3i4)
22    format(1x,'MEPS ARE IN THE PLANE',F6.2,
     1       ' ABOVE THAT DEFINED BY ATOMS',3I4)
      if (icase.eq.2) then
           if (abs(z0).lt.0.0001d0) then
                 write(6,31) n1,n2,n3,n1,n2
           else
                 write(6,32) n1,n2,n3,n1,n2,z0
           endif
      endif
31    format(1x,'MEPS ARE IN THE PLANE PERPENDICULAR TO THAT DEFINED ',
     1      /5x   'BY (',3I3,') AND THROUGH (',2i3,')')
32    format(1x,'MEPS ARE IN THE PLANE PERPENDICULAR TO THAT DEFINED',
     1 /5X,'BY (',3I3,') AND PARALLEL TO (',2I3,') WITH DISTANCE',F6.2)
      if (icase.eq.3) then
           if (abs(z0).lt.0.0001d0) then
                 write(6,41) n2,n1,n3
           else
                 write(6,42) n2,n1,n3,z0
           endif
       endif
41    format(1x,'MEPS ARE IN THE PLANE BISECTING THE ANGLE (',3I3,')')
42    format(1x,'MEPS ARE IN THE PLANE BISECTING THE ANGLE (',3I3,')',
     1      /5X,'BUT NON-ZERO VALUE Z0=',F6.2,' MAKES NO SENSE',
     1          ' AND IS IGNORED')
111   if (icase.le.1) then                             
             do 24 i=1,numat
                  c1(1,i)=c(1,i)
                  c1(2,i)=c(2,i)
24                c1(3,i)=c(3,i)
             goto 999
       endif
c                                            move the origin to atom n1
         do 20 i=1,numat
            c1(1,i)=c(1,i)-c(1,n1)
            c1(2,i)=c(2,i)-c(2,n1)
            c1(3,i)=c(3,i)-c(3,n1)
20       continue
c                                                                       
         x2=c1(1,n2)
         y2=c1(2,n2)
         z2=c1(3,n2)
         rr2=x2*x2+y2*y2+z2*z2                                   
         r2 =dsqrt(rr2)                              
         r21=1.0d0/r2
         x3= c1(1,n3)
         y3= c1(2,n3)
         z3= c1(3,n3)
         rr3= x3*x3+y3*y3+z3*z3                                  
         r3=dsqrt(rr3)                                                 
         r31=1.0d0/r3
         cos1=(rr3+rr2-(x3-x2)**2-(y3-y2)**2-(z3-z2)**2)*(0.5d0*r31*r21)
         if (1.0d0-dabs(cos1).lt.0.01d0) then
              write (6,25) dacos(cos1)             
              stop
         endif
c 
      if (icase.eq.1.or.icase.eq.2) then                                
c                                            choose x-axis for case 1,2
           t(1,1)=x2*r21                                                
           t(1,2)=y2*r21                                                
           t(1,3)=z2*r21                                                
c                                           y-axis for case 1, z case 2
             p41=r3*cos1*r21
             x34=x3-p41*x2                   
             y34=y3-p41*y2                   
             z34=z3-p41*z2                   
             r341=1.0d0/dsqrt(x34*x34+y34*y34+z34*z34)
                 if (icase.eq.1) then          
           t(2,1)= x34*r341
           t(2,2)= y34*r341                                       
           t(2,3)= z34*r341                                       
                 else                                                   
           t(3,1)=-x34*r341
           t(3,2)=-y34*r341                                       
           t(3,3)=-z34*r341                                       
                 endif                                                  
       endif                                                            
c                                           choose x, z-axes for case 3 
       if (icase.eq.3) then
           if (r3.gt.r2) then              
               x6= r2*r31                                
               y6= x6*y3                                 
               z6= x6*z3                                 
               x6= x6*x3                                 
               x62= x6-x2
               y62= y6-y2
               z62= z6-z2
               r621=1.0d0/dsqrt(x62*x62+y62*y62+z62*z62)   
              t(3,1)=-x62*r621     
              t(3,2)=-y62*r621    
              t(3,3)=-z62*r621   
               x4=(x2+x6)*0.5d0
               y4=(y2+y6)*0.5d0
               z4=(z2+z6)*0.5d0
            else     
               x6= r3*r21
               y6= x6*y2                                 
               z6= x6*z3                                 
               x6= x6*x2                                 
               x63= x6-x3
               y63= y6-y3
               z63= z6-z3
               r631=1.0d0/dsqrt(x63*x63+y63*y63+z63*z63)   
              t(3,1)= x63*r631
              t(3,2)= y63*r631  
              t(3,3)= z63*r631 
               x4=(x3+x6)*0.5d0
               y4=(y3+y6)*0.5d0
               z4=(z3+z6)*0.5d0
           endif                                    
         r41=1.0d0/dsqrt(x4*x4+y4*y4+z4*z4)
         t(1,1)=x4*r41                                                 
         t(1,2)=y4*r41                                                 
         t(1,3)=z4*r41                                                 
       endif                                                            
c                                      z for icase=1, y for icase=2 & 3 
         z5=1.0d0  
           if (dabs(x2).gt.0.1d0) then
               y5=-(x2*z3-x3*z2)/(x2*y3-x3*y2)
               x5=-(y5*y2+z2)/x2
               goto 55
           endif
           if (dabs(x3).gt.0.1d0) then
               y5=-(x3*z2-x2*z3)/(x3*y2-x2*y3)   
               x5=-(y3*y5+z3)/x3                         
               goto 55
           endif
           if (dabs(y3).gt.0.1d0) then
               x5=-(y3*z2-y2*z3)/(x2*y3-x3*y2)
               y5=-(x5*x3+z3)/y3
               goto 55
           endif
           if (dabs(y2).gt.0.1d0) then
               x5=-(y2*z3-y3*z2)/(x3*y2-x2*y3)
               y5=-(x5*x2+z2)/y2
               goto 55
             else
               write(6,35) x2,y2,x3,y3
               stop
           endif
55       r51=1.0d0/dsqrt(x5*x5+y5*y5+1.0d0)
                    k=3                                                 
                 if (icase.ne.1) k=2                                    
         t(k,1)=x5*r51                                   
         t(k,2)=y5*r51                                   
         t(k,3)=z5*r51                                  
c                            rotate the molecule to new xyz coordinates 
      do 300 k=1,numat                                                  
                xi=t(1,1)*c1(1,k)+t(1,2)*c1(2,k)+t(1,3)*c1(3,k)
                yi=t(2,1)*c1(1,k)+t(2,2)*c1(2,k)+t(2,3)*c1(3,k)
           c1(3,k)=t(3,1)*c1(1,k)+t(3,2)*c1(2,k)+t(3,3)*c1(3,k)
           c1(1,k)=xi
           c1(2,k)=yi
300   continue                                                          
c                                check if it is right-handed xyz system 
      dett=  t(1,1)*t(2,2)*t(3,3) + t(1,2)*t(2,3)*t(3,1)  
     2     + t(1,3)*t(2,1)*t(3,2) - t(1,3)*t(2,2)*t(3,1)
     3     - t(1,2)*t(2,1)*t(3,3) - t(1,1)*t(2,3)*t(3,2)
c                                                   non-weighted center
999      do 131 j=1,2
         CS=1.D6
         CL=-1.D6
               do 130 i=1,numat         
                  if (c1(j,i).lt.cs) then
                     cs=c1(j,i)
                     is=i
                  endif
                  if (c1(j,i).gt.cl) then
                     cl=c1(j,i)
                     il=i
                  endif 
130             continue
            c0(j)=(cs+cl)/2.0d0 
            r0(j)=cl-c0(j)+2.0d0
            if (nat(is).gt.1.or.nat(il).gt.1) r0(j)=r0(j)+0.4d0
131       continue
c                                                move to the new center
         do 40 i=1,numat
            c1(1,i)=c1(1,i)-c0(1)
            c1(2,i)=c1(2,i)-c0(2)
40       continue
            xm=int(r0(1)/step)*step
            ym=int(r0(2)/step)*step
         if (icase.lt.1.or.icase.gt.3) then
            r0(1)=(-xm+c0(1))*t(1,1)+(-ym+c0(2))*t(2,1)
            r0(2)=(-xm+c0(1))*t(1,2)+(-ym+c0(2))*t(2,2)
            r0(3)=(-xm+c0(1))*t(1,3)+(-ym+c0(2))*t(2,3)
         else
            if (icase.eq.1) then
               r0(1)=(-xm+c0(1))*t(1,1)+(-ym+c0(2))*t(2,1)+c(1,n1)
               r0(2)=(-xm+c0(1))*t(1,2)+(-ym+c0(2))*t(2,2)+c(2,n1)
               r0(3)=(-xm+c0(1))*t(1,3)+(-ym+c0(2))*t(2,3)+c(3,n1)
            else
               r0(1)=(-xm+c0(1))*t(1,1)+c0(2)*t(2,1)+c(1,n1)
               r0(2)=(-xm+c0(1))*t(1,2)+c0(2)*t(2,2)+c(2,n1)
               r0(3)=(-xm+c0(1))*t(1,3)+c0(2)*t(2,3)+c(3,n1)
            endif
         endif
      return
25    format(1x,'N2-N1-N3=',F9.3,' DEGREES, ALMOST LINEAR!')
35    format('X21,Y21,X31,Y31=',4F8.4,' WHY THEY ARE SO SMALL?') 
      end                                                               
