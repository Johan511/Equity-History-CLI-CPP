main.exe: main.o inputValidation.o utility.o
	g++ main.o inputValidation.o utility.o -o main.exe

inputValidation.o: ./0_headers/input_validation.h ./sources/inputValidation.cpp
	g++ -c ./sources/inputValidation.cpp

main.o: main.cpp
	g++ -c main.cpp

utility.o: ./0_headers/utility.h ./sources/utility.cpp
	g++ -c ./sources/utility.cpp
clean:
	rm *.o