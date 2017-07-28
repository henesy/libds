CC=gcc
CFLAGS=-ggdb -Wall -c
AR=ar
ARFLAGS=cvq
MAKE=make
HOME=/home/seh

all: 
	$(CC) $(CFLAGS) *.c
	$(AR) $(ARFLAGS) libdumb.a *.o

clean: 
	rm *.o
	rm *.a

homeinstall: libdumb.a
	cp libdumb.a $(HOME)/lib/libdumb.a
	cp dumb.h $(HOME)/include/dumb.h

homeuninstall:
	rm $(HOME)/lib/libdumb.a
	rm $(HOME)/include/dumb.h

homerebuild: clean homeuninstall all homeinstall

install: libdumb.a
	cp libdumb.a /usr/lib/libdumb.a
	cp dumb.h /usr/include/dumb.h

uninstall: 
	rm /usr/lib/libdumb.a
	rm /usr/include/dumb.h

wininstall:
	cp libdumb.a 'C:/mingw/lib/libdumb.a'
	cp dumb.h 'C:/mingw/include/dumb.h'

winuninstall:
	rm 'C:/mingw/lib/libdumb.a'
	rm 'C:/mingw/include/dumb.h'

cyginstall:
	cp libdumb.a 'C:/cygwin64/usr/x86_64-pc-cygwin/lib/libdumb.a'
	cp dumb.h 'C:/cygwin64/usr/include/dumb.h'

cyguninstall:
	rm 'C:/cygwin64/usr/x86_64-pc-cygwin/lib/libdumb.a'
	rm 'C:/cygwin64/usr/include/dumb.h'

rebuild: clean uninstall all install

winrebuild: clean winuninstall all wininstall

cygrebuild: clean cyguninstall all cyginstall

man:
	gzip -c ./man/dumb.3 > /usr/man/man3/dumb.3.gz

