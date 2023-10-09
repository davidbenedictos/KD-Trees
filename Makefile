all: kdtree.o program 

program: kdtree.o main.cc
	g++ -o program main.cc kdtree.o

kdtree.o: 
	g++ -c  kdtree.cc

clean:
	rm -f *.o program


