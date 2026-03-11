use std::fs::File;
use std::io::{BufRead, BufReader};
use std::time::Instant;

fn main() {
    let file = File::open("numbers.txt").unwrap();
    let reader = BufReader::new(file);

    let mut a: Vec<i32> = Vec::with_capacity(10_000_000);
    for line in reader.lines() {
        a.push(line.unwrap().parse().unwrap());
    }
	println!("Reading done.\nSorting...");
    let start = Instant::now();
    a.sort();
    let ns = start.elapsed().as_nanos();

    println!("{} nanoseconds", ns);
}