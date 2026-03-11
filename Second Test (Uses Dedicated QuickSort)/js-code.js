const fs = require("fs");

const data = fs.readFileSync("numbers.txt", "utf8").trim().split("\n");
const a = new Array(data.length);
for (let i = 0; i < data.length; i++) a[i] = Number(data[i]);

function quicksort(arr, left = 0, right = arr.length - 1) {
    if (left >= right) return;
    let pivot = arr[right];
    let i = left;
    for (let j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            [arr[i], arr[j]] = [arr[j], arr[i]];
            i++;
        }
    }
    [arr[i], arr[right]] = [arr[right], arr[i]];
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}
console.log("Reading done.\nSorting...");
const start = process.hrtime.bigint();
quicksort(a);
const ns = process.hrtime.bigint() - start;

console.log(ns.toString(),"nanoseconds");
