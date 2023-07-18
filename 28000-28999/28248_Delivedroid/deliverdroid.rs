const DELIVERED_POINTS: i64 = 50;
const COLLISION_POINTS: i64 = -10;
const BONUS_POINTS: i64 = 500;

fn input() -> i64 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("");
    return s.trim().parse().expect("");
}

fn main() {
    let delivered = input();
    let collision = input();

    let mut score: i64;

    score = delivered*DELIVERED_POINTS+collision*COLLISION_POINTS;
    if delivered > collision { score += BONUS_POINTS; }

    println!("{}",score);
}