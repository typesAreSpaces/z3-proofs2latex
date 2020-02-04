#!/usr/bin/env python 

from z3 import *

set_param(proof=True)
set_option(max_args=10000000, max_lines=1000000, max_depth=10000000, max_visited=1000000)
set_pp_option("max_indent", 0)
set_pp_option("max_width", 100000)

s = Solver()
s.from_file("./smt2_files/a.smt2")
# s.from_file("./smt2_files/QF_UFLIA/mathsat/Hash/hash_uns_03_03.smt2")
if(s.check() == unsat):
    print s.proof()
