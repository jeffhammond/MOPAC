LIBS    = -framework Accelerate

FC      = gfortran
FFLAGS  = -g -O2 -Wall

LD      = $(FC)
LDFLAGS = $(FFLAGS) $(LIBS)

OBJ1 = $(patsubst %.f90,%.o,$(wildcard implementation/*.f90))
OBJ2 = $(patsubst %.F90,%.o,$(wildcard implementation/*.F90))
MOD1 = $(patsubst %.f90,%.mod,$(wildcard modules/*.f90))
MOD2 = $(patsubst %.F90,%.mod,$(wildcard modules/*.F90))
INT1 = $(patsubst %.f90,%.mod,$(wildcard interfaces/*.f90))
INT2 = $(patsubst %.F90,%.mod,$(wildcard interfaces/*.F90))

OBJECTS = $(OBJ1) $(OBJ2)
MODULES = $(MOD1) $(MOD2)
INTERFS = $(INT1) $(INT2)

.PHONY: all modules objects interfaces clean

all: mopac.x

interfaces: $(INTERFS)

modules: $(MODULES)

objects: $(OBJECTS)

mopac.x: $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.f90 $(MODULES)
	$(FC) $(FFLAGS) -c $<

%.o: %.F90 $(MODULES)
	$(FC) $(FFLAGS) -c $<

%.mod: %.f90
	$(FC) $(FFLAGS) -c $<

%.mod: %.F90
	$(FC) $(FFLAGS) -c $<

clean:
	-rm -f *.o *.mod
