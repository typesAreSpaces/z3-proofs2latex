Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so

all: z3-proof-parser-sexpr

z3-proof-parser-sexpr.tab.c z3-proof-parser-sexpr.tab.h:	z3-proof-parser-sexpr.y
	bison -d z3-proof-parser-sexpr.y

z3-proof-parser-sexpr.yy.c: z3-proof-parser-sexpr.l z3-proof-parser-sexpr.tab.h
	flex -o $@ z3-proof-parser-sexpr.l

z3-proof-parser-sexpr: z3-proof-parser-sexpr.yy.c z3-proof-parser-sexpr.tab.c z3-proof-parser-sexpr.tab.h
	gcc -o z3-proof-parser-sexpr z3-proof-parser-sexpr.tab.c z3-proof-parser-sexpr.yy.c

.PHONY: clean
clean:
	rm -rf z3-proof-parser-sexpr z3-proof-parser-sexpr.tab.c z3-proof-parser-sexpr.tab.h z3-proof-parser-sexpr.yy.c proof_unsat \
	*\~
