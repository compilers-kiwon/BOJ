use std::io;

fn get_number()->u32 {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let mut n = get_number();
    
    while n%2 != 0 {
        n = (n+1)/2;
    }

    println!("{}",n);
}