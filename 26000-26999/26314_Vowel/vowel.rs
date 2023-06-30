use std::io;

fn get_number()->u32 {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str.trim().parse().expect("")
}

fn main() {
    let mut n = get_number();
    
    while n > 0 {
        let mut vowel = 0;
        let mut cons = 0;
        let mut str = String::new();

        io::stdin().read_line(&mut str).expect("");

        for c in str.chars() {
            if c<'a' || c>'z' {
                continue;
            }

            if c=='a' || c=='e' || c=='i' || c=='o' || c=='u' {
                vowel += 1;
            }
            else {
                cons += 1;
            }
        }

        print!("{}",str);

        if vowel > cons {
            println!("1");
        }
        else {
            println!("0");
        }

        n -= 1;
    }
}