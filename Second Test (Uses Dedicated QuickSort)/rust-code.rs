use std::fs::File;
use std::io::{BufRead, BufReader};
use std::time::Instant;

fn quicksort(a: &mut [i32]) {
    if a.len() <= 1 { return; }
    let pivot = a[a.len() - 1];
    let mut i = 0;
    for j in 0..a.len() - 1 {
        if a[j] <= pivot {
            a.swap(i, j);
            i += 1;
        }
    }
    a.swap(i, a.len() - 1);
    quicksort(&mut a[0..i]);
    quicksort(&mut a[i + 1..]);
}

fn main() {
    let file = File::open("numbers.txt").unwrap();
    let reader = BufReader::new(file);

    let mut a: Vec<i32> = Vec::with_capacity(10_000_000);
    for line in reader.lines() {
        a.push(line.unwrap().parse().unwrap());
    }
println!("Reading done.\nSorting...");
    let start = Instant::now();
    quicksort(&mut a);
    let ns = start.elapsed().as_nanos();

    println!("{} nanoseconds", ns);
}
