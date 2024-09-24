fn merge_alternately(word1: &str, word2: &str) -> String {
    let mut result = String::with_capacity(word1.len() + word2.len());
    let mut iter1 = word1.chars();
    let mut iter2 = word2.chars();

    loop {
        match (iter1.next(), iter2.next()) {
            (Some(c1), Some(c2)) => {
                result.push(c1);
                result.push(c2);
            }
            (Some(c1), None) => {
                result.push(c1);
                result.extend(iter1);
                break;
            }
            (None, Some(c2)) => {
                result.push(c2);
                result.extend(iter2);
                break;
            }
            (None, None) => break,
        }
    }

    result
}

fn main() {
    let word1 = "abc";
    let word2 = "pqr";
    let result = merge_alternately(word1, word2);
    println!("Merged string: {}", result);
}
