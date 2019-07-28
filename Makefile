AutomatedMakefile = am
CC = g++

FILES = FalsePosition.o Heun.o SailboatMast.o Diffusion.o

PROJECT_PATH = $(PROJECT_PATH)

INC_DIRS = -I$(PROJECT_PATH)/include/
LIB_DIRS = -L$(PROJECT_PATH)/lib/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Sailboat

Sailboat: 		$(FILES)
			$(LINK) Sailboat.exe $(FILES) $(LIBS)

FalsePosition.o:	FalsePosition.h FalsePosition.cpp
			$(COMPILE) FalsePosition.cpp

Heun.o:			Heun.h Heun.cpp
			$(COMPILE) Heun.cpp
			
Diffusion.o:		Diffusion.h Diffusion.cpp
			$(COMPILE) Diffusion.cpp

SailboatMast.o:		SailboatMast.h SailboatMast.cpp
			$(COMPILE) SailboatMast.cpp








