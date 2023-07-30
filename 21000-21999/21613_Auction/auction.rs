fn get_number() -> i32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    return  s.trim().parse().expect("");
}

fn get_name() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    return  s;
}

fn main() {
    let mut winner_name: String = "".to_string();
    let mut winner_amount: i32 = 0;
    let num_of_persons = get_number();

    for _ in 1..=num_of_persons {
        let name: String = get_name();
        let price: i32 = get_number();

        if price > winner_amount {
            winner_name = name;
            winner_amount = price;
        }
    }

    println!("{}", winner_name);
}