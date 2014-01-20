      MODULE hmuf_I   
      INTERFACE
!...Generated by Pacific-Sierra Research 77to90  4.4G  21:23:38  03/14/06  
      SUBROUTINE hmuf (H1, ID, COORD, NFIRST, NLAST, NAT, NORBS, NUMAT) 
      USE vast_kind_param,ONLY: DOUBLE       
      integer, INTENT(IN) :: ID 
      integer, INTENT(IN) :: NORBS 
      integer, INTENT(IN) :: NUMAT 
      real(DOUBLE), DIMENSION(NORBS,NORBS), INTENT(INOUT) :: H1 
      real(DOUBLE), DIMENSION(3,*), INTENT(IN) :: COORD 
      integer, DIMENSION(NUMAT), INTENT(IN) :: NFIRST 
      integer, DIMENSION(NUMAT), INTENT(IN) :: NLAST 
      integer, DIMENSION(NUMAT), INTENT(IN) :: NAT 
      END SUBROUTINE  
      END INTERFACE 
      END MODULE 