      MODULE dnrm2_I   
      INTERFACE
!...Generated by Pacific-Sierra Research 77to90  4.4G  22:48:56  03/08/06  
      REAL(KIND(0.0D0)) FUNCTION dnrm2 (N, DX, INCX) 
      USE vast_kind_param,ONLY: DOUBLE 
      integer, INTENT(IN) :: N 
      real(DOUBLE), DIMENSION(N), INTENT(IN) :: DX 
      integer, INTENT(IN) :: INCX 
      END FUNCTION  
      END INTERFACE 
      END MODULE 