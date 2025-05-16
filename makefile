main: funkcijos.o klase.o
	g++ -O3 -o main main.cpp funkcijos.o klase.o

testai: funkcijos.o klase.o
	g++ -O3 -o testai testai.cpp funkcijos.o klase.o
	./testai.exe

vektorius:
	g++ -O3 -o vektorius vectorTestai.cpp
	./vektorius.exe

perskirstymai:
	g++ -O3 -o perskirstymai perskirstymuTestai.cpp
	./perskirstymai.exe

funkcijos: 
	g++ funkcijos.cpp

klase:
	g++ klase.cpp

run: main
	./main.exe

clean: 
	del *.o main.exe testai.exe perskirstymai.exe vektorius.exe