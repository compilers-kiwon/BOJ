use std::io;

fn get_pizza_info() -> Vec<f64> {
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

const INF: f64 = 1000000.0;

fn main() {
    let mut m = 1;

    loop
    {
        let n = get_number();

        if n == 0 {
            break;
        }

        let mut best_value = INF;
        let mut best_diameter = 0;

        for _ in 1..=n {
            let p: Vec<f64> = get_pizza_info();
            let cur_value = (p[1]*100.0)/((p[0]/2.0).powf(2.0)*3.14);

            if cur_value < best_value {
                best_value = cur_value;
                best_diameter = p[0] as i32;
            }
        }

        println!("Menu {}: {}",m,best_diameter);
        m += 1;
    }
}