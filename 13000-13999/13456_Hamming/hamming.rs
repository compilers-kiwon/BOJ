use std::io;

fn get_numbers()->Vec<i32> {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");

    let ret:Vec<i32> = str.split_whitespace()
                            .map(|str| str.trim().parse().expect(""))
                            .collect::<Vec<_>>();
    return  ret;
}

fn get_number() -> i32 {
    let numbers:Vec<i32> = get_numbers();
    numbers[0]
}

fn main() {
    let t = get_number();

    for _ in 1..=t {
        let n = get_number();
        let v:Vec<i32> = get_numbers();
        let u:Vec<i32> = get_numbers();
        let mut cnt = 0;

        for i in 0..n {
            let idx = i as usize;
            if v[idx] != u[idx] { cnt+=1; }
        }

        println!("{}", cnt);
    }
}