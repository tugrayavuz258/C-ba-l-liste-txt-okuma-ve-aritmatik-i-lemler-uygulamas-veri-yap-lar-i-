calistir: bagKurMake
	./bin/program.exe
	
derleMake:
	g++ -o ./lib/Basamak.o -I ./include -c ./src/Basamak.cpp
	g++  -o ./lib/Dugum.o -I ./include -c ./src/Dugum.cpp
	g++  -o ./lib\Sayi.o -I ./include -c ./src\Sayi.cpp
	g++  -o ./lib/SayilarListesi.o -I ./include -c ./src\SayilarListesi.cpp
	g++  -o ./lib\main.o -I ./include -c ./src\main.cpp


bagKurMake: derleMake
	g++  ./lib/Basamak.o ./lib/Dugum.o ./lib/main.o ./lib/Sayi.o .\lib/SayilarListesi.o -o ./bin/program.exe

