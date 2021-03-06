#!/usr/bin/env python 

from z3 import *

set_option(auto_config=False,
        max_args=10000000,
        max_lines=1000000,
        max_depth=10000000,
        max_visited=1000000,
        proof=True)
set_pp_option("max_indent", 0)
set_pp_option("max_width", 100000)

# s = Solver();
# s = SolverFor("QF_LIA")
s = SolverFor("QF_FD")
# s.set("smt.arith.solver", 4)

# s.from_file("./smt2_files/a.smt2")
# s.from_file("./smt2_files/paper_example.smt2")
# s.from_file("./smt2_files/diff_int_logic.smt2")
# s.from_file("./smt2_files/boolean_cdcl_example.smt2")
s.from_file("./smt2_files/boolean_cdcl_example2.smt2")
if(s.check() == unsat):
    print(s.proof())
