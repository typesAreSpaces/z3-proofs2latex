Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so

all: ok

ok: 
	make -C ./z3-proof-parser

proof_python: z3-proof-parser proof_unsat.py
	./proof_unsat.py > $@.txt
	./z3-proof-parser < $@.txt > $@.tex
	pdflatex $@.tex

proof_unsat: proof_unsat.cpp $(Z3DIR)
	g++ -o $@ $^ -lpthread -Wall

proof_cpp: z3-proof-parser-sexpr proof_unsat
	./proof_unsat > $@.txt
	./z3-proof-parser-sexpr < $@.txt > $@.tex
	pdflatex $@.tex

.PHONY: clean
clean:
	rm -rf proof_python.aux proof_python.log proof_python.tex proof_python.txt proof_python.pdf \
	proof_cpp.aux proof_cpp.log proof_cpp.tex proof_cpp.txt proof_cpp.pdf \
	*\~
