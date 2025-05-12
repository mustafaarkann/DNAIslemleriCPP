all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/dna.cpp -o ./lib/dna.o
	g++ -c -I "./include" ./src/gen.cpp -o ./lib/gen.o
	g++ -c -I "./include" ./src/kromozom.cpp -o ./lib/kromozom.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/menu.cpp -o ./lib/menu.o

bagla:
	g++ ./lib/dna.o ./lib/gen.o ./lib/kromozom.o ./lib/main.o ./lib/menu.o -o ./bin/RASTGELE

calistir:
	./bin/RASTGELE
