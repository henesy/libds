</$objtype/mkfile
LIB=/$objtype/lib
HDR=/$objtype/include

all: stack.c queue.c list.c
	$CC -c $prereq
	ar vu libdumb.a *.$O

nuke: 
	rm *.$O
	rm libdumb.a

install: libdumb.a
	cp libdumb.a $LIB
	cp dumb.h $HDR

uninstall: nuke
	rm $LIB/libdumb.a
	rm $HDR/dumb.h

rebuild: uninstall all install

tests: install tests/stacktest.c tests/queuetest.c tests/listtest.c
	$CC $prereq

man: 
	cp ./man/dumb.3 /sys/man/dumb

lf:
	ssam ',s/\r//g' *.[h c md]
