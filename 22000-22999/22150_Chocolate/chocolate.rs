use std::io;
use std::convert::TryInto;

fn get_numbers()->Vec<i32> {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");

    let ret:Vec<i32> = str.split_whitespace()
                            .map(|str| str.trim().parse().expect(""))
                            .collect::<Vec<_>>();
    return  ret;
}

fn simulate() {
    let numbers = get_numbers();
    let mut n:usize = 1;

    while n <= (numbers[0]*2).try_into().unwrap() {
        let left = numbers[n];
        let right = numbers[n+1];

        if left+right != numbers[0] {
            println!("yes");
            return;
        }

        n += 2;
    }

    println!("no");
    return;
}

fn main() {
    let mut t = (get_numbers())[0];
    
    while t > 0 {
        simulate();
        t -= 1;
    }
}