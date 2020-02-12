(TeX-add-style-hook
 "proof-sexpr"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("standalone" "varwidth=2000pt")))
   (TeX-run-style-hooks
    "latex2e"
    "standalone"
    "standalone10"
    "ebproof"
    "amssymb"
    "amsmath"))
 :latex)

