PARSER_DIR=./parser

all: z3-proof-parser

.PHONY: z3-proof-parser
z3-proof-parser: 
	make -C $(PARSER_DIR)

.PHONY: clean
clean:
	make -C $(PARSER_DIR)        clean
	rm -rf ./output/*
