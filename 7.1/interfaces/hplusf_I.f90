      MODULE hplusf_I   
      INTERFACE
!...Generated by Pacific-Sierra Research 77to90  4.4G  21:23:38  03/14/06  
      SUBROUTINE hplusf (F, H, NORBS) 
      USE vast_kind_param,ONLY: DOUBLE
      integer, INTENT(IN) :: NORBS  
      real(DOUBLE), DIMENSION(NORBS,NORBS), INTENT(INOUT) :: F 
      real(DOUBLE), DIMENSION(NORBS,NORBS), INTENT(IN) :: H       
      END SUBROUTINE  
      END INTERFACE 
      END MODULE 
