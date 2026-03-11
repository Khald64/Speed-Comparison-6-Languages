This are the code files used in the video "I sorted 10 million numbers in 6 languages to see which one is the fastest"

Default compilers were used for compiled langauges.
g++ was used for c++.

# Optimization flags used:
- C++:
rustc -C opt-level=3 rust-code.rs
- Rust:
g++ -Ofast cpp-code.cpp
- Go:
go build -ldflags="-s -w" go-code.go


All code in here was genearted by AI (OpenAI's ChatGPT)
