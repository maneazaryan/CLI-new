CC = g++
CFLAGS =-Iinc 

SRC = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

obj/%.o:src/%.cpp inc/%.h
	$(CC) $(CFLAGS) -c $< -o $@

bin/main.exe:src/main.cpp  $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean run

clean:
	rm -f obj/*.o bin/*.exe

run: bin/main.exe
	./bin/main.exe
