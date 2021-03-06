      real(kind(0.0d0)) function helect (n, p, h, f) 
!-----------------------------------------------
!   M o d u l e s 
!-----------------------------------------------
      USE vast_kind_param, ONLY:  double 
!...Translated by Pacific-Sierra Research 77to90  4.4G  08:34:42  03/09/06  
!...Switches: -rl INDDO=2 INDIF=2 
      implicit none
!-----------------------------------------------
!   D u m m y   A r g u m e n t s
!-----------------------------------------------
      integer , intent(in) :: n 
      real(double) , intent(in) :: p(*) 
      real(double) , intent(in) :: h(*) 
      real(double) , intent(in) :: f(*) 
!-----------------------------------------------
!   L o c a l   V a r i a b l e s
!-----------------------------------------------
      integer :: k, nn, i, jj
      real(double) :: ed, ee 
!-----------------------------------------------
!***********************************************************************
!
!    SUBROUTINE CALCULATES THE ELECTRONIC ENERGY OF THE SYSTEM IN EV.
!
!    ON ENTRY N = NUMBER OF ATOMIC ORBITALS.
!             P = DENSITY MATRIX, PACKED, LOWER TRIANGLE.
!             H = ONE-ELECTRON MATRIX, PACKED, LOWER TRIANGLE.
!             F = TWO-ELECTRON MATRIX, PACKED, LOWER TRIANGLE.
!    ON EXIT
!        HELECT = ELECTRONIC ENERGY.
!
!    NO ARGUMENTS ARE CHANGED.
!
!***********************************************************************
      ed = 0.0D00 
      ee = 0.0D00 
      k = 0 
      nn = n + 1 
      do i = 2, nn 
        k = k + 1 
        jj = i - 1 
        ed = ed + p(k)*(h(k)+f(k)) 
        if (i == nn) cycle  
        if (jj > 0) then 
          ee = ee + sum(p(k+1:jj+k)*(h(k+1:jj+k)+f(k+1:jj+k))) 
          k = jj + k 
        endif 
      end do 
      ee = ee + .5D00*ed 
      helect = ee 
      return  
!
      end function helect 
