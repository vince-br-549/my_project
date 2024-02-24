main:	BSTWithClass.exe add.exe hello.exe infinite.exe myCodeschoolDoubleLinkedList.exe

add.exe:	add.cc
	g++ -o add.exe add.cc

BSTWithClass.exe:	BSTWithClass.cpp
	g++ -o BSTWithClass.exe BSTWithClass.cpp

hello.exe:	hello.cc
	g++ -o hello.exe hello.cc

infinite.exe:	infinite.c
	g++ -o infinite.exe infinite.c

myCodeschoolDoubleLinkedList.exe:	myCodeschoolDoubleLinkedList.cpp
	g++ -o myCodeschoolDoubleLinkedList.exe myCodeschoolDoubleLinkedList.cpp

clean:
	rm -rf *.o *.exe a.out  
