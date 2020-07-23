unsat
(interpolants
 (exists ((%0 Int))
  (! (forall ((%1 (Array Int Int)))
       (! (exists ((%2 (Array Int Int)))
            (! (forall ((%3 Int))
                 (! (exists ((%4 Int))
                      (! (forall ((%5 Int))
                           (! (exists ((%6 (Array Int Int)))
                                (! (forall ((%7 (Array Int Int)))
                                     (! (exists ((%8 (Array Int Int)))
                                          (! (forall ((%9 Int))
                                               (! (exists ((%10 Int))
                                                    (! (forall ((%11 Int)
                                                                (%12 Int))
                                                         (! (let ((a!1 (and (= %10
                                                                               (select (store %8
                                                                                              %5
                                                                                              %9)
                                                                                       ((_ array-ext
                                                                                           0)
                                                                                         %6
                                                                                         %7)))
                                                                            (= (select (store s
                                                                                              %5
                                                                                              %9)
                                                                                       ((_ array-ext
                                                                                           0)
                                                                                         %2
                                                                                         %7))
                                                                               %3)))
                                                                  (a!2 (and (= %0
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{2}}|
                                                                                            %0)
                                                                                    %3))
                                                                            (|p_{2}| %0)))
                                                                  (a!3 (and (= %4
                                                                               ((_ array-ext
                                                                                   0)
                                                                                 %2
                                                                                 %1))
                                                                            (not (= (select |array_{s_{1}}|
                                                                                            %4)
                                                                                    %3))
                                                                            (|p_{1}| %4)))
                                                                  (a!5 (not (and (= ((_ array-ext
                                                                                        0)
                                                                                      %6
                                                                                      %7)
                                                                                    %11)
                                                                                 (= %1
                                                                                    %7))))
                                                                  (a!8 (or (= %5
                                                                              ((_ array-ext
                                                                                  0)
                                                                                %6
                                                                                %7))
                                                                           (= (select (store %8
                                                                                             %5
                                                                                             %9)
                                                                                      ((_ array-ext
                                                                                          0)
                                                                                        %6
                                                                                        %7))
                                                                              %10)))
                                                                  (a!9 (or (not (= ((_ array-ext
                                                                                       0)
                                                                                     %2
                                                                                     %1)
                                                                                   %12))
                                                                           (not (= (select |array_{t_{2}}|
                                                                                           %12)
                                                                                   %3))
                                                                           (|p_{1}| %12)
                                                                           (|q_{2}| %12)
                                                                           (p %1))))
                                                            (let ((a!4 (or (not a!1)
                                                                           (and (or a!2
                                                                                    (p %1))
                                                                                (|q_{1}| %0))
                                                                           a!3
                                                                           (p %1)))
                                                                  (a!6 (or a!5
                                                                           (not (= (select |array_{t_{1}}|
                                                                                           %11)
                                                                                   %3)))))
                                                            (let ((a!7 (or (and (= ((_ array-ext
                                                                                       0)
                                                                                     %6
                                                                                     %7)
                                                                                   ((_ array-ext
                                                                                       0)
                                                                                     %2
                                                                                     %7))
                                                                                a!6)
                                                                           (|q_{1}| %11)
                                                                           (p %1))))
                                                              (or (and (or (not a!1)
                                                                           (and a!4
                                                                                a!7
                                                                                a!8
                                                                                a!9)
                                                                           (p %1)
                                                                           a!3)
                                                                       a!7
                                                                       a!8
                                                                       a!9)
                                                                  (p %1)))))
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
