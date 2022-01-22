def lucas_lehmer(p):
    s = 4
    m = 2 ** p - 1
    for _ in range(p - 2):
        s = ((s * s) - 2) % m
        print(s)
    return s == 0

print(lucas_lehmer(5))
"""
def is_prime(number):
    """
    #the efficiency of this doesn't matter much as we're
    #only using it to test the primeness of the exponents
    #not the mersenne primes themselves
"""

    if number % 2 == 0:
        return number == 2

    i = 3
    while i * i <= number:
        if number % i == 0:
            return False
        i += 2

    return True

print(3)  # to simplify code, treat first mersenne prime as a special case

for i in range(3, 64, 1):  # generate up to M20, found in 1961
    if is_prime(i) and lucas_lehmer(i):
        print(i,2 ** i - 1)
"""