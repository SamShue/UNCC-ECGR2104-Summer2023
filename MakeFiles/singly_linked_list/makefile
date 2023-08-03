COMPILER_VERSION	= -std=c++11
TARGET				= test

$(TARGET): main.o singly_linked_list.o
	g++ -o test main.cpp singly_linked_list.cpp $(COMPILER_VERSION)
	
main.o: main.cpp singly_linked_list.h
	g++ -c main.cpp $(COMPILER_VERSION)
	
singly_linked_list.o: singly_linked_list.cpp singly_linked_list.h
	g++ -c singly_linked_list.cpp $(COMPILER_VERSION)
	
clean:  
	rm *.o test