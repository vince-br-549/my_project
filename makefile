all:		infinite add hello BSTWithClass AVLClass

AVLClass:	AVLclass.cpp  AVL.cpp  AVL.h
	c++ -o  AVLclass.exe  AVL.cpp AVLclass.cpp

BSTWithClass:	BSTWithClass.cpp
	c++ -o BSTWithClass.exe BSTWithClass.cpp

hello:		hello.cc
		c++ -o hello.exe hello.cc

infinite:	infinite.c
		c++ -o inifinite.exe infinite.c
add:		add.cc
		c++ -o add.exe add.cc

clean:
		rm -f *.o *.exe

