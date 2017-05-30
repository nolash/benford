INCLUDE = ../include/
BUILDDIR = ../../.build

test: 
	$(CC) -Wall -g -I$(INCLUDE) -o $(BUILDDIR)/benford_test.o -c benford_test.c
	$(CC) -Wall -o $(BUILDDIR)/benford_test $(BUILDDIR)/benford.o $(BUILDDIR)/benford_test.o -lm
	
#shared:

#	$(CC) -Wall -I$(INCLUDE) -o lash_tree_lib.o -fPIC -c lash_tree3.c
#	$(CC) -Wall -I$(INCLUDE) -o lash_tree_dump_lib.o -fPIC -c lash_tree3_dump.c
#	$(CC) -shared -Wl,-soname,liblash.so.0 -o $(SHAREDOBJECTDIR)liblash.so lash_tree_lib.o lash_tree_dump_lib.o
	
