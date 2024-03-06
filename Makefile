#
# this make file seems to work properly.
#
main:	BSTWithClass.exe add.exe hello.exe infinite.exe DoubleLinkedList.exe HashTable.exe

HashTable.exe:	HashTable.cpp
	g++ -o HashTable.exe HashTable.cpp


add.exe:	add.cc
	g++ -o add.exe add.cc

BSTWithClass.exe:	BSTWithClass.cpp
	g++ -o BSTWithClass.exe BSTWithClass.cpp

hello.exe:	hello.cc
	g++ -o hello.exe hello.cc

infinite.exe:	infinite.c
	g++ -o infinite.exe infinite.c

DoubleLinkedList.exe:	DoubleLinkedList.cpp
	g++ -o DoubleLinkedList.exe DoubleLinkedList.cpp

clean:
	rm -rf *.o *.exe a.out  
