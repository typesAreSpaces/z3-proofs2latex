(set-info :status unknown)
(declare-fun f (Int) Int)
(declare-fun a () Int)
(declare-fun x () Int)
(declare-fun b () Int)
(assert
 (let ((?x14 (f a)))
 (let (($x16 (= ?x14 4)))
 (let ((?x17 (f x)))
 (let (($x19 (= ?x17 3)))
 (let (($x21 (= a 1)))
 (let (($x22 (<= 1 x)))
 (let (($x23 (and $x22 $x21)))
 (let (($x24 (and $x23 $x19)))
 (and $x24 $x16))))))))))
(assert
 (let ((?x26 (f b)))
 (let (($x28 (= ?x26 5)))
 (and (and (<= x 2) (= b 2)) $x28))))
(check-sat)
