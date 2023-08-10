fn get_number() -> i64 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    return  s.trim().parse().expect("");
}

fn main() {
    let n = get_number();
    let mut used: i64 = 0;
    let mut h: i64 = 1;

    loop {
        used += (2*h-1)*(2*h-1);

        if used > n {
            h -= 1;
            break;
        }

        h += 1;
    }

    println!("{}", h);
}