use std::io;

fn get_str() -> String {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    return  str;
}

fn get_num() -> usize {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let s:String = get_str();
    let i:usize = get_num();

    println!("{}",&s[i-1..i]);
}