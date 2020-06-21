Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so

all: z3-proof-parser

z3-proof-parser.tab.c z3-proof-parser.tab.h:	z3-proof-parser.y
	bison -d z3-proof-parser.y

z3-proof-parser.yy.c: z3-proof-parser.l z3-proof-parser.tab.h
	flex -o $@ z3-proof-parser.l

z3-proof-parser: z3-proof-parser.yy.c z3-proof-parser.tab.c z3-proof-parser.tab.h
	gcc -o z3-proof-parser z3-proof-parser.tab.c z3-proof-parser.yy.c

.PHONY: clean
clean:
	rm -rf z3-proof-parser z3-proof-parser.tab.c z3-proof-parser.tab.h z3-proof-parser.yy.c \
	*\~
