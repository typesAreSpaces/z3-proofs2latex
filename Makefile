all: z3-proof-parser

z3-proof-parser.tab.c z3-proof-parser.tab.h:	z3-proof-parser.y
	bison -d z3-proof-parser.y

lex.yy.c: z3-proof-parser.l z3-proof-parser.tab.h
	flex z3-proof-parser.l

z3-proof-parser: lex.yy.c z3-proof-parser.tab.c z3-proof-parser.tab.h
	gcc -o z3-proof-parser z3-proof-parser.tab.c lex.yy.c

run: z3-proof-parser proof_unsat.py
	./proof_unsat.py > proof.txt
	./z3-proof-parser < proof.txt > proof.tex
	pdflatex proof.tex

clean:
	rm -rf z3-proof-parser z3-proof-parser.tab.c lex.yy.c z3-proof-parser.tab.h *\~ proof.aux proof.log proof.tex proof.txt proof.pdf
