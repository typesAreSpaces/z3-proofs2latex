unsat
(interpolants
 (forall ((%0 (Array Int Int)))
  (! (exists ((%1 (Array Int Int)))
       (! (forall ((%2 Int) (%3 Int))
            (! (exists ((%4 (Array Int Int)))
                 (! (forall ((%5 (Array Int Int)))
                      (! (exists ((%6 (Array Int Int)))
                           (! (forall ((%7 Int))
                                (! (exists ((%8 Int))
                                     (! (forall ((%9 Int))
                                          (! (exists ((%10 Int) (%11 Int))
                                               (! (forall ((%12 Int))
                                                    (! (exists ((%13 Int))
                                                         (! (forall ((%14 Int))
                                                              (! (let ((a!1 (or (not (= ((_ array-ext
                                                                                            0)
                                                                                          %1
                                                                                          %5)
                                                                                        ((_ array-ext
                                                                                            0)
                                                                                          %4
                                                                                          %5)))
                                                                                (= %2
                                                                                   (select (store s
                                                                                                  %3
                                                                                                  %7)
                                                                                           ((_ array-ext
                                                                                               0)
                                                                                             %4
                                                                                             %5)))))
                                                                       (a!2 (= (select (store %6
                                                                                              %3
                                                                                              %7)
                                                                                       ((_ array-ext
                                                                                           0)
                                                                                         %4
                                                                                         %5))
                                                                               %8))
                                                                       (a!3 (or (not (= ((_ array-ext
                                                                                            0)
                                                                                          %1
                                                                                          %0)
                                                                                        %14))
                                                                                (not (= (select |array_{t_{2}}|
                                                                                                %14)
                                                                                        %2))))
                                                                       (a!4 (or (not (= ((_ array-ext
                                                                                            0)
                                                                                          %1
                                                                                          %0)
                                                                                        %12))
                                                                                (not (= (select |array_{t_{3}}|
                                                                                                %12)
                                                                                        %2))
                                                                                (|q_{3}| %12)
                                                                                (|p_{1}| %12)
                                                                                (|p_{2}| %12)
                                                                                (p %0)))
                                                                       (a!5 (not (and (= ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5)
                                                                                         %9)
                                                                                      (= %0
                                                                                         %5))))
                                                                       (a!8 (and (= %13
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %1
                                                                                      %0))
                                                                                 (not (= (select |array_{s_{1}}|
                                                                                                 %13)
                                                                                         %2))
                                                                                 (|p_{1}| %13)))
                                                                       (a!9 (and (= %10
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %1
                                                                                      %0))
                                                                                 (not (= (select |array_{s_{2}}|
                                                                                                 %10)
                                                                                         %2))
                                                                                 (|p_{2}| %10)
                                                                                 (|q_{1}| %10)))
                                                                       (a!10 (and (= %11
                                                                                     ((_ array-ext
                                                                                         0)
                                                                                       %1
                                                                                       %0))
                                                                                  (not (= (select |array_{s_{3}}|
                                                                                                  %11)
                                                                                          %2))
                                                                                  (|q_{1}| %11)
                                                                                  (|q_{2}| %11)
                                                                                  (|p_{3}| %11))))
                                                                 (let ((a!6 (or a!5
                                                                                (not (= (select |array_{t_{1}}|
                                                                                                %9)
                                                                                        %2))))
                                                                       (a!11 (or a!5
                                                                                 (not (= (select |array_{s_{2}}|
                                                                                                 %10)
                                                                                         %2))))
                                                                       (a!14 (or a!5
                                                                                 (not (= (select |array_{s_{3}}|
                                                                                                 %11)
                                                                                         %2)))))
                                                                 (let ((a!7 (and (not (and a!1
                                                                                           a!2))
                                                                                 a!3
                                                                                 a!4
                                                                                 (= ((_ array-ext
                                                                                        0)
                                                                                      %4
                                                                                      %5)
                                                                                    ((_ array-ext
                                                                                        0)
                                                                                      %1
                                                                                      %5))
                                                                                 a!6
                                                                                 (or (= %3
                                                                                        ((_ array-ext
                                                                                            0)
                                                                                          %4
                                                                                          %5))
                                                                                     a!2)))
                                                                       (a!12 (or (and (= %10
                                                                                         %9)
                                                                                      (= ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5)
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %1
                                                                                           %5))
                                                                                      a!11
                                                                                      (|p_{2}| %10)
                                                                                      (|q_{1}| %10))
                                                                                 (p %0)))
                                                                       (a!15 (or (and (= %11
                                                                                         %9)
                                                                                      (= ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5)
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %1
                                                                                           %5))
                                                                                      a!14
                                                                                      (|q_{1}| %11)
                                                                                      (|q_{2}| %11)
                                                                                      (|p_{3}| %11))
                                                                                 (p %0))))
                                                                 (let ((a!13 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!3
                                                                                  a!4
                                                                                  a!12
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2)))
                                                                       (a!16 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!3
                                                                                  a!4
                                                                                  a!15
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2))))
                                                                 (let ((a!17 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!3
                                                                                  a!4
                                                                                  (or a!7
                                                                                      (p %0)
                                                                                      a!8
                                                                                      a!9
                                                                                      a!10
                                                                                      (|q_{1}| %9)
                                                                                      a!13
                                                                                      a!16)
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2))))
                                                                 (let ((a!18 (or a!17
                                                                                 (p %0)
                                                                                 a!8
                                                                                 a!9
                                                                                 a!10
                                                                                 (|q_{2}| %14)
                                                                                 (|p_{1}| %14))))
                                                                 (let ((a!19 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!18
                                                                                  a!4
                                                                                  (= ((_ array-ext
                                                                                         0)
                                                                                       %4
                                                                                       %5)
                                                                                     ((_ array-ext
                                                                                         0)
                                                                                       %1
                                                                                       %5))
                                                                                  a!6
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2)))
                                                                       (a!20 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!18
                                                                                  a!4
                                                                                  a!12
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2)))
                                                                       (a!21 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!18
                                                                                  a!4
                                                                                  a!15
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2))))
                                                                 (let ((a!22 (and (not (and a!1
                                                                                            a!2))
                                                                                  a!18
                                                                                  a!4
                                                                                  (or a!19
                                                                                      (p %0)
                                                                                      a!8
                                                                                      a!9
                                                                                      a!10
                                                                                      (|q_{1}| %9)
                                                                                      a!20
                                                                                      a!21)
                                                                                  (or (= %3
                                                                                         ((_ array-ext
                                                                                             0)
                                                                                           %4
                                                                                           %5))
                                                                                      a!2))))
                                                                   (or a!22
                                                                       (p %0)
                                                                       a!8
                                                                       a!9
                                                                       a!10)))))))))
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
          :qid itp))
     :qid itp)))
