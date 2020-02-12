(TeX-add-style-hook
 "proof-sexpr"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("standalone" "varwidth=1000pt")))
   (TeX-run-style-hooks
    "latex2e"
    "standalone"
    "standalone10"
    "ebproof"))
 :latex)

