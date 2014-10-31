   (define sum-numbers
        (lambda (ls)
            (cond ((number? ls) ls)
                  ((not (list? ls))  0)
                  ((null? ls) 0)
                  (else (+ (sum-numbers (car ls)) 
                           (sum-numbers (cdr ls))))
            )
        )
    )

(sum-numbers '((1) 2.0 ((3/4) 5)))
