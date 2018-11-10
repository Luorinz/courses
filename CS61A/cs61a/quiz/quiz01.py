def multiple(a, b):
    """Return the smallest number n that is a multiple of both a and b.

    >>> multiple(3, 4)
    12
    >>> multiple(14, 21)
    42
    """
    "*** YOUR CODE HERE ***"
    for i in range(max(a,b) , a*b +1):
        if i % a ==0 and i % b ==0:
            return i 
print(multiple(14,21)	)
		

def unique_digits(n):
    """Return the number of unique digits in positive integer n

    >>> unique_digits(8675309) # All are unique
    7
    >>> unique_digits(1313131) # 1 and 3
    2
    >>> unique_digits(13173131) # 1, 3, and 7
    3
    >>> unique_digits(10000) # 0 and 1
    2
    >>> unique_digits(101) # 0 and 1
    2
    >>> unique_digits(10) # 0 and 1
    2
    """
    "*** YOUR CODE HERE ***"
    def has_digit (n,k):
        """ determines whether a number n has digit k. """
        
        if str(k) in str(n):
            return True
        else:
            return False
    
    k = 0
    
    for i in range(10):
        if has_digit(n,i):
            k += 1
        
    return k    
        
        
