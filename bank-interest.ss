(define payment
  (lambda (amount monthlyRate n)
    (/ (* amount monthlyRate)
       (- 1 - (expt (+ 1 monthlyRate) (- (* 12 n)))))))

