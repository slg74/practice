fn merge_alternately(word1: &str, word2: &str) -> String {
    let mut result = String::with_capacity(word1.len() + word2.len());
    let mut chars1 = word1.chars();
    let mut chars2 = word2.chars();

    while let (Some(c1), Some(c2)) = (chars1.next(), chars2.next()) {
        result.push(c1);
        result.push(c2);
    }

    result.extend(chars1);
    result.extend(chars2);

    result
}

fn main() {
    let word1 = "abc";
    let word2 = "pqr";
    let result = merge_alternately(word1, word2);
    println!("Merged string: {}", result);
}