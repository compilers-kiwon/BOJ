use std::io;

fn main()
{
    let mut input_str = String::new();

    io::stdin()
        .read_line(&mut input_str)
        .expect("Wrong input!!");

    let num:Vec<usize> = input_str.split_whitespace()
                            .map(|s| s.trim().parse().expect("Parsing error!!"))
                            .collect::<Vec<_>>();
    let sum = num[0]+num[1];

    println!("{sum}");
}