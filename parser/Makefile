Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so

all: z3-parser

z3-parser.tab.c z3-parser.tab.h:	z3-parser.y
	bison -d z3-parser.y

z3-parser.yy.c: z3-parser.l z3-parser.tab.h
	flex -o $@ z3-parser.l

z3-parser: z3-parser.yy.c z3-parser.tab.c z3-parser.tab.h
	gcc -o z3-parser z3-parser.tab.c z3-parser.yy.c

.PHONY: clean
clean:
	rm -rf z3-parser z3-parser.tab.c z3-parser.tab.h z3-parser.yy.c \
	*\~
