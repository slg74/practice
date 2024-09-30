
def is_prime(n):
    # sieve of eratosthenes 
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def primes_to(n):
    return [x for x in range(2, n+1) if is_prime(x)]

print(primes_to(2024))