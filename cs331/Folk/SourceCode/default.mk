# default.mk
#
# included in all make files. This file has rules for compilation and loading
#   It also has root directory location and subdirectory rules
#
# This file is set up to handle Unix files, using / in path names
# The paths that make uses must always use /, e.g. $(SRCDIR)
# The paths used by commands like copy use the operating system-specific paths

# individual Makefiles should set DIR to the name of the directory (app_d, etc.)

ROOTDIR = ../..
OS_ROOTDIR = ../..

# rules depend on Makefile setting variables OBJECTS, LIB, LIBS, and EXECS

all: $(EXECS) $(LIB)

# make directory variables
SRCDIR = $(ROOTDIR)/src/$(DIR)
INCDIR = $(ROOTDIR)/include
LIBDIR = $(ROOTDIR)/lib
OBJDIR = $(ROOTDIR)/object/$(DIR)

# make paths
vpath  %.h $(SRCDIR)
vpath  %.h $(INCDIR)
vpath  %.cc $(SRCDIR)
vpath  %.cpp $(SRCDIR)
vpath  %.c $(SRCDIR)
vpath  %.tc $(SRCDIR)
vpath  %.tc $(INCDIR)

# OS variables 
# use backslash for DOS, slash for Unix

#name of the delete and copy commands (del,copy in DOS; rm,cp in Unix)
DEL = rm
COPY = cp

OS_LIBDIR = $(OS_ROOTDIR)/lib
OS_INCDIR = $(OS_ROOTDIR)/include
BACKDIR = backup

CCFLAGS = -g -I$(SRCDIR) -I$(INCDIR) -L$(LIBDIR)

# compiler tools, CC is C++ compiler, CCLD is C++ loader, AR is archive
# OS and compiler specific definitions
CC=gcc
CCLD=g++
AR=ar

%.o: %.cpp 
	$(CC) $(CCFLAGS) -c $<

%.o: %.cc 
	$(CC) $(CCFLAGS) -c $<

%.o: %.c 
	$(CC) $(CCFLAGS) -c $<

$(LIB): $(OBJECTS)
	$(AR) r $(LIB) $(OBJECTS)
	$(COPY) $(LIB) $(OS_LIBDIR)

%: %.o $(OBJECTS)
	$(CCLD) -o $@ $< $(CCFLAGS) $(OBJECTS)  $(LIBS)

%.cpp: %.cc
	$(COPY) $<.cc $>.cpp
clean:
	-$(DEL) $(EXECS)
	-$(DEL) *.o
	-$(DEL) $(LIB)
	-$(DEL) *.dat

backup: FORCE
	mkdir backup
	-$(COPY) *.cc $(BACKDIR)
	-$(COPY) *.h $(BACKDIR)
	-$(COPY) Makefile $(BACKDIR)
	-$(COPY) *.dat $(BACKDIR)

include:
	-$(COPY) $(OS_ROOTDIR)/src/$(DIR)/*.h $(OS_INCDIR)
	-$(COPY) $(OS_ROOTDIR)/src/$(DIR)/*.tc $(OS_INCDIR)

FORCE:
