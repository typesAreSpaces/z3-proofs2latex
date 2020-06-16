#!/usr/bin/env python 

from z3 import *

set_option(max_args=10000000,
           max_lines=1000000,
           max_depth=10000000,
           max_visited=1000000,
           proof=True)
set_pp_option("max_indent", 0)
set_pp_option("max_width", 100000)
# set_pp_option("spacer.arith_solver", 0)

# s = Solver();
# s = SolverFor("QF_IDL")
s = SolverFor("QF_LIA")
s.set(fp.spacer.arith.solver, 0)

# s.from_file("./tests/a.smt2")
# s.from_file("./tests/paper_example.smt2")
s.from_file("./tests/diff_int_logic.smt2")
if(s.check() == unsat):
    print(s.proof())
