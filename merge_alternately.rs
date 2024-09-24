use std::time::Instant;

fn merge_alternately(word1: &str, word2: &str) -> String {
    let mut result = String::with_capacity(word1.len() + word2.len());
    let mut chars1 = word1.chars();
    let mut chars2 = word2.chars();
    let mut i = 0;
    let mut j = 0;

    while i < word1.len() || j < word2.len() {
        if i < word1.len() {
            if let Some(c) = chars1.next() {
                result.push(c);
            }
            i += 1;
        }
        if j < word2.len() {
            if let Some(c) = chars2.next() {
                result.push(c);
            }
            j += 1;
        }
    }

    result
}

fn main() {
    let word1 = "abc";
    let word2 = "pqrs";
    
    let start = Instant::now();
    
    for _ in 0..10000 {
        let _ = merge_alternately(word1, word2);
    }
    
    let duration = start.elapsed();
    let microseconds = duration.as_micros();
    
    println!("Time taken to run merge_alternately 10000 times: {} microseconds", microseconds);
    
    // Print the result once for verification
    let result = merge_alternately(word1, word2);
    println!("Merged string: {}", result);
}
