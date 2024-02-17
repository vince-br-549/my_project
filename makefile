all:		infinite add

infinite:	infinite.c
	c++ -o inifinite.exe infinite.c
add:	add.cc
	c++ -o add.exe add.cc

clean:
	rm -f *.o *.exe

