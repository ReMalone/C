program4: G_00_P4_main.o G_00_P4_functions.o
	g++ -o prog4 G_00_P4_main.o G_00_P4_functions.o	

G_00_P4_main.o: G_00_P4_main.cpp G_00_P4_class_header.h
	g++ -c G_00_P4_main.cpp

G_00_P4_functions.o: G_00_P4_functions.cpp G_00_P4_class_header.h
	g++ -c G_00_P4_functions.cpp

run: prog4
	./prog4