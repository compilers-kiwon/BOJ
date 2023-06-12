use std::io;

fn get_num() -> u64 {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let n:u64 = get_num();

    println!("{}\n{}",n*(n-1)/2,2);
}