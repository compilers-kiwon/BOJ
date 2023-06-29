use std::io;

fn get_numbers()->Vec<i32> {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");

    let ret:Vec<i32> = str.split_whitespace()
                            .map(|str| str.trim().parse().expect(""))
                            .collect::<Vec<_>>();
    return  ret;
}

fn main() {
    let numbers:Vec<i32> = get_numbers();
    let m = numbers[0]*12+numbers[1];

    let mut cur = 1;
    let mut h = 0;

    while cur <= m {
        if cur <= 12 {
            h += 15;
        }
        else if cur <= 24 {
            h += 9;
        }
        else {
            h += 4;
        }

        cur += 1;
    }

    println!("{} {}",h/12,h%12);
}