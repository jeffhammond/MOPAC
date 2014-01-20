      SUBROUTINE GETDAT
      CHARACTER*80 LINE, GETNAM
************************************************************************
*
*   GETDAT READS ALL THE DATA IN ON CHANNEL 2, AND WRITES IT TO SCRATCH
*   CHANNEL 5.  THIS WAY THE ORIGINAL DATA-SET IS FREED UP AS SOON AS
*   THE JOB STARTS.
*
************************************************************************
      DATA I/0/
      SAVE I
C#      WRITE(6,*)GETNAM('FOR005')
      OPEN(UNIT=2,FILE=GETNAM('FOR005'),STATUS='UNKNOWN')
C
C  CLOSE UNIT 5 IN CASE IT WAS ALREADY PRE-ASSIGNED.
C
      CLOSE (5)
      OPEN(UNIT=5,STATUS='SCRATCH')
      REWIND 5
      REWIND 2
   10 READ(2,'(A80)',END=20,ERR=20)LINE
      I=I+1
      WRITE(5,'(A80)')LINE
      GOTO 10
   20 REWIND 5
      IF(I.LT.3)THEN
         WRITE(6,'(A)')' INPUT FILE MISSING OR EMPTY'
         STOP
      ENDIF
      CLOSE (2)
      END
