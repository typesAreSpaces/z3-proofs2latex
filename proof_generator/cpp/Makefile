Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so
CC = g++
FLAGS = -I$(./include)-std=c++11 -Wall
DEPS = $(wildcard ./include/*.h)

all: bin/proof_gen

./obj/%.o: ./src/%.cpp $(DEPS)
	$(CC) -g -c -o $@ $(FLAGS) $<

bin/proof_gen: ./obj/proof_gen.o $(Z3DIR)
	$(CC) -o $@ $^ $(FLAGS) -lpthread 

.PHONY: clean
clean:
	rm -rf obj/*.o bin/* \
	*\~
