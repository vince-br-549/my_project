all:
		c++    *.cc -o a.out

clean:	
	rm -f *.o a.out

cleanall:
	rm -f *.o *.exe

