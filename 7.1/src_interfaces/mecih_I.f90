      MODULE mecih_I   
      INTERFACE
!...Generated by Pacific-Sierra Research 77to90  4.4G  10:47:25  03/09/06  
      SUBROUTINE mecih (DIAG, CIMAT, NMOS, LAB, XY) 
      USE vast_kind_param,ONLY: DOUBLE  
      REAL(DOUBLE), DIMENSION(*), INTENT(IN) :: DIAG 
      REAL(DOUBLE), DIMENSION(*), INTENT(out) :: cimat
      REAL(DOUBLE), DIMENSION(*), INTENT(in) :: xy 
      INTEGER, INTENT(IN) :: LAB 
      END SUBROUTINE  
      END INTERFACE 
      END MODULE 