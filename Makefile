PARSER_DIR        = ./parser
SEXPR_PARSER_DIR  = ./parser-sexpr
PROOF_GEN_PY_DIR  = ./proof_generator/python
PROOF_GEN_CPP_DIR = ./proof_generator/cpp

all: python_proof

.PHONY: z3-proof-parser
z3-proof-parser: 
	make -C $(PARSER_DIR)

.PHONY: z3-proof-parser-sexpr
z3-proof-parser-sexpr: 
	make -C $(SEXPR_PARSER_DIR)

python_proof: z3-proof-parser 
	$(PROOF_GEN_PY_DIR)/proof_gen.py > ./output/$@.txt
	$(PARSER_DIR)/z3-proof-parser < ./output/$@.txt > ./output/$@.tex
	cd ./output && pdflatex $@.tex

.PHONY: $(PROOF_GEN_CPP_DIR)/bin/proof_gen
$(PROOF_GEN_CPP_DIR)/bin/proof_gen:
	make -C $(PROOF_GEN_CPP_DIR)

cpp_proof: z3-proof-parser-sexpr $(PROOF_GEN_CPP_DIR)/bin/proof_gen
	$(PROOF_GEN_CPP_DIR)/bin/proof_gen > ./output/$@.txt
	$(SEXPR_PARSER_DIR)/z3-proof-parser-sexpr < ./output/$@.txt > ./output/$@.tex
	cd ./output && pdflatex $@.tex

.PHONY: clean
clean:
	make -C $(PARSER_DIR)        clean
	make -C $(SEXPR_PARSER_DIR)  clean
	make -C $(PROOF_GEN_CPP_DIR) clean
	rm -rf ./output/*
