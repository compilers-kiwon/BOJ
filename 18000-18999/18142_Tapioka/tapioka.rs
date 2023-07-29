use std::io;

fn get_words() -> String {
    let mut str = String::new();
    io::stdin().read_line(&mut str).expect("");
    str = str.trim().to_string();
    return  str;
}

fn main() {
    let s: String = get_words();
    let mut w: String = "".to_string();
    let mut _v: Vec<String> = vec![];

    for c in s.chars() {
        if c==' ' || c=='\n' {
            _v.push(w);
            w = "".to_string();
        } else {
            w.push(c);
        }
    }
    _v.push(w);

    let mut cnt = 0;

    for n in _v {
        if n!="bubble".to_string() && n!="tapioka".to_string() {
            cnt += 1;
            print!("{} ", n);
        }
    }

    if cnt == 0 {
        print!("nothing");
    }

    println!("");
}