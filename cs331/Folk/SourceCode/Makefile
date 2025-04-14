
include default.mk

DIRS = app_d app_e app_f app_g app_h app_i app_j

all: $(DIRS) 

setup: 
	-mkdir include
	-mkdir lib
	-mkdir object

$(DIRS): 
	-mkdir object/$@
	-$(COPY) src/$@/Makefile object/$@
	-$(COPY) src/$@/*.txt object/$@
	cd object/$@; make clean; make; make include

FORCE:
