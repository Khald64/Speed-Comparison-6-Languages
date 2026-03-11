const fs = require("fs");

const data = fs.readFileSync("numbers.txt", "utf8").trim().split("\n");
const a = new Array(data.length);
for (let i = 0; i < data.length; i++) a[i] = Number(data[i]);
console.log("Reading done.\nSorting...");
const start = process.hrtime.bigint();
a.sort((x, y) => x - y);
const ns = process.hrtime.bigint() - start;

console.log(ns.toString(),"nanoseconds");