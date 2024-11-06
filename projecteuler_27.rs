fn is_prime(n: i32) -> bool {
    if n < 2 {
        return false;
    }
    let sqrt_n = (n.abs() as f64).sqrt() as i32;
    for i in 2..=sqrt_n {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn count_consecutive_primes(a: i32, b: i32) -> i32 {
    let mut n = 0;
    loop {
        let result = n * n + a * n + b;
        if !is_prime(result) {
            return n;
        }
        n += 1;
    }
}

fn main() {
    let mut max_primes = 0i32;
    let mut best_a = 0i32;
    let mut best_b = 0i32;
    
    // Create vector for prime b values
    let mut b_primes: Vec<i32> = Vec::new();
    
    // Find prime b values
    for b in -1000i32..=1000i32 {
        if is_prime(b.abs()) {
            b_primes.push(b);
        }
    }
    
    // Main calculation loop
    for a in -999i32..1000i32 {
        for &b in b_primes.iter() {
            // Check if second number is prime (when n=1)
            if !is_prime(1 + a + b) {
                continue;
            }
            
            let count = count_consecutive_primes(a, b);
            if count > max_primes {
                max_primes = count;
                best_a = a;
                best_b = b;
            }
        }
    }
    
    println!("a = {}, b = {}", best_a, best_b);
    println!("Number of primes = {}", max_primes);
    println!("Product = {}", best_a * best_b);
}
