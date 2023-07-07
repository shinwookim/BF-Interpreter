
# A BrainfuCk Interpreter
A light-weight [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter written using C.


## What is Brainfuck?
**Brainfuck** is an [esoteric programming language](https://en.wikipedia.org/wiki/Esoteric_programming_language "Esoteric programming language") created in 1993 by Urban Müller.

Notable for its extreme minimalism, the language consists of only eight simple commands, a [data pointer](https://en.wikipedia.org/wiki/Data_pointer "Data pointer") and an [instruction pointer](https://en.wikipedia.org/wiki/Instruction_pointer "Instruction pointer"). While it is fully [Turing complete](https://en.wikipedia.org/wiki/Turing_completeness "Turing completeness"), it is not intended for practical use, but to challenge and amuse [programmers](https://en.wikipedia.org/wiki/Programmers "Programmers"). Brainfuck requires one to break commands into microscopic steps.

The language's name is a reference to the slang term *[brainfuck](https://en.wiktionary.org/wiki/brainfuck "wikt:brainfuck")*, which refers to things so complicated or unusual that they exceed the limits of one's understanding, as it was not meant or made for designing actual software but to challenge the boundaries of [computer programming](https://en.wikipedia.org/wiki/Computer_programming "Computer programming").


(From [Wikipedia](https://en.wikipedia.org/wiki/Brainfuck))

### Commands

| Token | Effect                                                                |
| ----- | --------------------------------------------------------------------- |
| `>`   | Increment the data pointer                                            |
| `<`   | Decrement the data pointer                                            |
| `+`   | Increment the byte at the data pointer                                |
| `-`   | Decrement the byte at the data pointer                                |
| `.`   | Output the byte at the data pointer                                   |
| `,`   | Accept one byte of input and store at data pointer                    |
| `[`   | If byte at data pointer is zero, jump to command after matching ]     |
| `]`   | If byte at data pointer is not zero, jump to command after matching [ |

At run-time, the interpreter may prompt user for input when it encounters a `,` command. In such case, the user can use their keyboard to provide a single-character input which will be written onto the data tape.

Because this may dirty the terminal output, the interpreter firsts redirects all output to a temporary buffer and prints the entire output to a cleaned terminal just before terminating.
## Usage
Run using the example "Hello, World!" program (`hello_world.bf`)
```sh
# Using GNU make
make run
# $ BF File: hello_world.bf
# Hello, World!
```

### Web Version (using WASM)
The interpreter has also been compiled using web assembly and presented ina pretty web format [here]().

To compile locally
```sh
# Requires emcc
make web
```

(Program expects Brainfuck programs(`*.bf`) to follow the specifications outlined on [Wikipedia](https://en.wikipedia.org/wiki/Brainfuck).)

### Other Notes
Although there are some variations among various Brainfuck specs found online, this interpreter follows the one on Wikipedia. This means:
1. The data tape consists of 30,000 cells, each of one byte.
2. Contents of each cell is unsigned (ranging 0 - 255).
3. Output interprets the unsigned value in each cell as a character using ASCII symbol table.
## License

[MIT](LICENSE)
