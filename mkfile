</$objtype/mkfile
LIB=/$objtype/lib
HDR=/$objtype/include

all: stack.c queue.c list.c
	$CC -c $prereq
	ar vu libds.a *.$O

nuke: 
	rm *.$O
	rm libds.a

install: libds.a
	cp libds.a $LIB
	cp ds.h $HDR

uninstall: nuke
	rm $LIB/libds.a
	rm $HDR/ds.h

rebuild: uninstall all install

tests: install tests/stacktest.c tests/queuetest.c tests/listtest.c
	$CC $prereq

man: 
	cp ./man/ds.2 /sys/man/2/ds
