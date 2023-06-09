use std::io;

fn get_num() -> u32 {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let y:u32 = get_num();
    let m:u32 = get_num();

    println!("{}",m+(m-y));
}