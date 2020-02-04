# z3-proofs2latex

A small script to produce a natural derivation using a z3 proof produced by the pretty printer of the Python API.

Edit the path file inside proof_unsat.py to parse the smt formula.

Obtain the pdf file proof.pdf using
```
    $ make
```

Currently, it supports the logic "QF_UFLIA".
