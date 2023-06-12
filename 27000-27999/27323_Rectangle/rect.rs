use std::io;

fn get_number()->u32 {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let a = get_number();
    let b = get_number();

    println!("{}",a*b);
}