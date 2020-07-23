unsat
(interpolants
 (exists ((%0 Int))
  (! (forall ((%1 (Array Int Int)))
       (! (exists ((%2 (Array Int Int)))
            (! (forall ((%3 Int))
                 (! (exists ((%4 Int) (%5 Int))
                      (! (forall ((%6 Int))
                           (! (exists ((%7 (Array Int Int)))
                                (! (forall ((%8 (Array Int Int)))
                                     (! (exists ((%9 Int) (%10 (Array Int Int)))
                                          (! (forall ((%11 Int)
                                                      (%12 Int)
                                                      (%13 Int)
                                                      (%14 Int))
                                               (! (exists ((%15 Int))
                                                    (! (forall ((%16 Int))
                                                         (! (let ((a!1 (= %9
                                                                          (select (store %10
                                                                                         %6
                                                                                         %11)
                                                                                  ((_ array-ext
                                                                                      0)
                                                                                    %7
                                                                                    %8))))
                                                                  (a!3 (or (not (= ((_ array-ext
                                                                                       0)
                                                                                     %2
                                                                                     %1)
                                                                                   %16))
                                                                           (not (= (select |array_{t_{4}}|
                                                                                           %16)
                                                                                   %3))))
                                                                  (a!4 (and (= %15
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{4}}|
                                                                                            %15)
                                                                                    %3))
                                                                            (|q_{3}| %15)
                                                                            (|q_{2}| %15)
                                                                            (|q_{1}| %15)
                                                                            (|p_{4}| %15)))
                                                                  (a!5 (and (= %0
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{2}}|
                                                                                            %0)
                                                                                    %3))
                                                                            (|p_{2}| %0)
                                                                            (|q_{1}| %0)))
                                                                  (a!6 (and (= %4
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{3}}|
                                                                                            %4)
                                                                                    %3))
                                                                            (|q_{1}| %4)
                                                                            (|p_{3}| %4)
                                                                            (|q_{2}| %4)))
                                                                  (a!7 (and (= %5
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{1}}|
                                                                                            %5)
                                                                                    %3))
                                                                            (|p_{1}| %5)))
                                                                  (a!8 (not (and (= ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8)
                                                                                    %14)
                                                                                 (= %1
                                                                                    %8))))
                                                                  (a!13 (or (not (= ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %1)
                                                                                    %12))
                                                                            (not (= (select |array_{t_{2}}|
                                                                                            %12)
                                                                                    %3))
                                                                            (|p_{1}| %12)
                                                                            (|q_{2}| %12)
                                                                            (p %1)))
                                                                  (a!14 (or (not (= ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %1)
                                                                                    %13))
                                                                            (not (= (select |array_{t_{3}}|
                                                                                            %13)
                                                                                    %3))
                                                                            (|p_{2}| %13)
                                                                            (|q_{3}| %13)
                                                                            (|p_{1}| %13)
                                                                            (p %1)))
                                                                  (a!16 (or (not (= ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %1)
                                                                                    %16))
                                                                            (not (= (select |array_{s_{2}}|
                                                                                            %0)
                                                                                    %3)))))
                                                            (let ((a!2 (and a!1
                                                                            (= (select (store s
                                                                                              %6
                                                                                              %11)
                                                                                       ((_ array-ext
                                                                                           0)
                                                                                         %2
                                                                                         %8))
                                                                               %3)))
                                                                  (a!9 (or a!8
                                                                           (not (= (select |array_{t_{1}}|
                                                                                           %14)
                                                                                   %3))))
                                                                  (a!10 (or a!8
                                                                            (not (= (select |array_{s_{2}}|
                                                                                            %0)
                                                                                    %3))))
                                                                  (a!11 (or a!8
                                                                            (not (= (select |array_{s_{4}}|
                                                                                            %15)
                                                                                    %3)))))
                                                            (let ((a!12 (or (and (= ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8)
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %8))
                                                                                 a!9)
                                                                            (|q_{1}| %14)
                                                                            (and (= %0
                                                                                    %14)
                                                                                 (= ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8)
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %8))
                                                                                 a!10
                                                                                 (|p_{2}| %0)
                                                                                 (|q_{1}| %0))
                                                                            (p %1)
                                                                            (and (= %15
                                                                                    %14)
                                                                                 (= ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8)
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %2
                                                                                      %8))
                                                                                 a!11
                                                                                 (|q_{3}| %15)
                                                                                 (|q_{2}| %15)
                                                                                 (|q_{1}| %15)
                                                                                 (|p_{4}| %15))))
                                                                  (a!17 (and (not a!2)
                                                                             (or (and (= %0
                                                                                         %16)
                                                                                      a!16
                                                                                      (|p_{2}| %0)
                                                                                      (|q_{1}| %0))
                                                                                 (p %1)))))
                                                            (let ((a!15 (and (or (and (not a!2)
                                                                                      a!3)
                                                                                 a!4
                                                                                 (p %1)
                                                                                 a!5
                                                                                 a!6
                                                                                 a!7)
                                                                             a!12
                                                                             (or (= %6
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8))
                                                                                 a!1)
                                                                             a!13
                                                                             a!14))
                                                                  (a!18 (and (or a!17
                                                                                 a!4
                                                                                 (p %1)
                                                                                 a!5
                                                                                 a!6
                                                                                 a!7)
                                                                             a!12
                                                                             (or (= %6
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8))
                                                                                 a!1)
                                                                             a!13
                                                                             a!14)))
                                                            (let ((a!19 (or (and (not a!2)
                                                                                 (or a!15
                                                                                     (p %1)
                                                                                     (|q_{4}| %16)
                                                                                     (|p_{1}| %16)
                                                                                     a!18
                                                                                     (|p_{3}| %16)))
                                                                            a!4
                                                                            (p %1)
                                                                            a!5
                                                                            a!6
                                                                            a!7)))
                                                            (let ((a!20 (and a!19
                                                                             a!12
                                                                             (or (= %6
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %7
                                                                                      %8))
                                                                                 a!1)
                                                                             a!13
                                                                             a!14)))
                                                              (or a!20 (p %1))))))))
                                                            :qid itp))
                                                       :qid itp))
                                                  :qid itp))
                                             :qid itp))
                                        :qid itp))
                                   :qid itp))
                              :qid itp))
                         :qid itp))
                    :qid itp))
               :qid itp))
          :qid itp))
     :qid itp)))
