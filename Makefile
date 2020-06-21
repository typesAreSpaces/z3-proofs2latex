Z3DIR = /home/jose/Documents/GithubProjects/z3/build/libz3.so
PARSER_DIR = ./parser
SEXPR_PARSER_DIR = ./parser-sexpr
PROOF_GEN_PY_DIR = ./proof_generator/python
PROOF_GEN_CPP_DIR = ./proof_generator/cpp

all: python_proof

.PHONY: z3-proof-parser
z3-proof-parser: 
	make -C $(PARSER_DIR)

.PHONY: z3-proof-parser-sexpr
z3-proof-parser-sexpr: 
	make -C $(SEXPR_PARSER_DIR)

python_proof: z3-proof-parser $(PROOF_GEN_PY_DIR)/gen_proof.py
	$(PROOF_GEN_PY_DIR)/proof_gen.py > $@.txt
	$(PARSER_DIR)/z3-proof-parser < $@.txt > $@.tex
	pdflatex $@.tex

cpp_proof: z3-proof-parser-sexpr $(PROOF_GEN_CPP_DIR)/bin/proof_gen
	$(PROOF_GEN_CPP_DIR)/bin/proof_gen > $@.txt
	$(SEXPR_PARSER_DIR)/z3-proof-parser-sexpr < $@.txt > $@.tex
	pdflatex $@.tex

.PHONY: clean
clean:
	make -C $(PARSER_DIR)        clean
	make -C $(SEXPR_PARSER_DIR)  clean
	make -C $(PROOF_GEN_CPP_DIR) clean
	rm -rf python_proof.aux python_proof.log python_proof.tex python_proof.txt python_proof.pdf \
	cpp_proof.aux cpp_proof.log cpp_proof.tex cpp_proof.txt cpp_proof.pdf \
	*\~
