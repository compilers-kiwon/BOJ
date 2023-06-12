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

    let mut x:i32 = 0;
    let mut y:i32 = 0;
    let mut found:bool = false;

    x = -999;

    while x <= 999 {
        found = false;

        y = -999;

        while y <= 999 {
            if numbers[0]*x+numbers[1]*y==numbers[2] {
                if numbers[3]*x+numbers[4]*y==numbers[5] {
                    found = true;
                    break;
                }
            }

            y = y+1;
        }

        if found == true {
            break;
        }

        x = x+1;
    }

    println!("{} {}",x,y);
}