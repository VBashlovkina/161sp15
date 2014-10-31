(define fahrenheit 72)
(define celsius 
  (lambda (fahrenheit) 
    (* (- fahrenheit 32.0) 5.0 1/9)))
(display fahrenheit)
(display " degrees fahrenheit = ")
(display (celsius fahrenheit))
(display " degrees celsius")
(newline)
       
