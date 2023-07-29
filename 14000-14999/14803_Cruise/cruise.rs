use std::io;

fn get_horse_info() -> Vec<f64> {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");

    let ret:Vec<f64> = str.split_whitespace()
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
    let t = get_number();

    for i in 1..=t {
        let annie = get_horse_info();
        let d = annie[0];
        let n = annie[1] as i32;

        let mut max_time: f64 = 0.0;

        for _ in 1..=n {
            let h = get_horse_info();
            let t = (d-h[0])/h[1];

            if t > max_time {
                max_time = t;
            }
        }

        println!("Case #{}: {:.6}", i, d/max_time);
    }
}