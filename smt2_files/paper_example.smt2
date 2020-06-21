(declare-fun x1 () Int)
(declare-fun x2 () Int)
(declare-fun x3 () Int)
(declare-fun y1 () Int)
(declare-fun y2 () Int)
(declare-fun y3 () Int)
(declare-fun a () Int)
(declare-fun b () Int)
(declare-fun f (Int) Int)
(declare-fun g (Int) Int)

;; Part A
(assert (= (+ (f x1) x2) x3))
(assert (= (+ (f y1) y2) y3))
(assert (<= y1 x1))

;; Part B
(assert (= x2 (g b)))
(assert (= y2 (g b)))
(assert (<= x1 y1))
(assert (< x3 y3))

(check-sat)
