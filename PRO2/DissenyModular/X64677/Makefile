#	Gestión de una lavadora
#	24.04.2024
#	
#	Entregar program.tar
#	
#	https://github.com/fyodormeteor

OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.tar: program.cc Lavadora.cc Cubeta.cc Prenda.cc Makefile
	tar -cvf program.tar program.cc Lavadora.cc Cubeta.cc Prenda.cc Makefile

program.exe: program.o Prenda.o Lavadora.o Cubeta.o
	g++ -o program.exe program.o Prenda.o Lavadora.o Cubeta.o

Prenda.o: Prenda.cc
	g++ -c Prenda.cc $(OPCIONS)

Cubeta.o: Cubeta.cc
	g++ -c Cubeta.cc $(OPCIONS)

Lavadora.o: Lavadora.cc
	g++ -c Lavadora.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
