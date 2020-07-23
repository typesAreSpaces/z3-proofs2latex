PARSER_DIR=./parser
#FILE=ex5_n2.smt2
#FILE=ex5_n3.smt2
FILE=ex5_n4.smt2

all: z3-parser
	sed 's/|//g' ./smt2_files/$(FILE) > ./smt2_files/temp2.smt2
	sed 's/%\(\w*\)/x_{\1}/g' ./smt2_files/temp2.smt2 > ./smt2_files/temp3.smt2
	valgrind $(PARSER_DIR)/z3-parser < ./smt2_files/temp3.smt2 > out.tex
	mv out.tex output/out.tex
	cd ./output && pdflatex out.tex && mv out.pdf $(FILE).pdf
	rm -rf ./smt2_files/temp*

.PHONY: z3-parser
z3-parser: 
	make -C $(PARSER_DIR)

.PHONY: clean
clean:
	make -C $(PARSER_DIR) clean
	rm -rf ./output/*
