use std::io;
use std::cmp::max;

fn get_numbers()->Vec<i32> {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");

    let ret:Vec<i32> = str.split_whitespace()
                            .map(|str| str.trim().parse().expect(""))
                            .collect::<Vec<_>>();
    return  ret;
}

fn get_number() -> i32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    return  s.trim().parse().expect("");
}

fn main() {
    let n = get_number();
    let mut max_area: i32 = 0;

    for _ in 1..=n {
        let numbers:Vec<i32> = get_numbers();
        let cur_area = numbers[0]*numbers[1];

        max_area = max(max_area,cur_area);
    }

    println!("{}", max_area);
}