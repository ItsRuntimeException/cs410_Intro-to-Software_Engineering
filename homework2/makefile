cc = g++
CPPFLAG = -std=c++11
appname = hw2

$(appname):		hw2.o
				$(cc) $(CPPFLAG) -o hw2.exe hw2.o

$(appname).o:	hw2.cpp functions.o
				$(cc) $(CPPFLAG) -c hw2.cpp

functions.o:	functions.h functions.cpp
				$(cc) $(CPPFLAG) -c functions.cpp

clean-all:		
				rm $(appname).exe
				rm *.o
clean:
				rm *.o