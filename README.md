# ansi-c

Exercises and small programs implemented while working through “The C Programming Language” (Kernighan & Ritchie, a.k.a. K&R). This repo is a hands‑on companion: each subfolder under `exercises/` is a focused program or exercise that explores a concept from the book (I/O, control flow, functions, arrays, pointers, etc.).

The goal is clarity and correctness over cleverness, using a conservative C dialect close to the book (C90/C89), with simple build/run commands so you can compile and execute each program on its own.

## Repository Structure

- `exercises/`
  - Topical subfolders like `hello`, `temp-convert`, `control-flow`, `lexical-analysis`, etc.
  - Each subfolder typically contains one or more `.c` files and (in some cases) a compiled binary produced locally (you can rebuild these; see below).
  - A minimal `CMakeLists.txt` and `main.c` exist for a tiny demo target; most examples are built per‑folder via the compiler directly.
- `untitled/`
  - Scratch or sandbox area (not guaranteed to be stable).
- `LICENSE`
  - GPLv3 license for this repository.
- `README.md`
  - This file.

Example subfolders you can explore right away:

- `exercises/hello` – prints a decorative “hello world”.
- `exercises/temp-convert` – Fahrenheit/Celsius conversion tables (several variants).
- `exercises/control-flow` – functions like `itoa`/`itob`, plus control‑flow exercises.
- `exercises/word-counter`, `exercises/longest-line`, etc. – text processing utilities.

## Prerequisites

- A C compiler: `clang` or `gcc`.
- A POSIX‑like shell (Linux/macOS). On Windows, use WSL or a MinGW/Clang setup.
- Optional: `cmake` (if you want to build the small demo target in `exercises/`).

Recommended compiler flags when experimenting:

```
-std=c90 -Wall -Wextra -Wpedantic -O2
```

## Build and Run (per example)

Most examples are single‑file or small multi‑file programs you can build directly from their folder. For example:

```
cd exercises/hello
cc hello.c -o hello
./hello
```

Another example (temperature conversion):

```
cd exercises/temp-convert
cc f2c.c -o f2c
./f2c
```

Some programs read from standard input. You can pipe a file into them, e.g. for word/line counters:

```
cd exercises/word-counter
cc word-counter.c -o word-counter
./word-counter < ../test_text.txt
```

Note: Some subfolders may contain previously compiled binaries from local runs. You can safely ignore or overwrite them by rebuilding from source.

## Optional: CMake Demo

There’s a minimal CMake target that builds `exercises/main.c` as a simple “Hello, World!” executable. This is not intended to build all examples—use per‑folder builds for that.

```
cd exercises
cmake -S . -B build
cmake --build build
./build/exercises
```

## Conventions and Notes

- Standard: C90/C89 (to stay close to K&R).
- Focus: correctness, readable code, and incremental exploration of concepts.
- Organization: one exercise per subfolder, minimal dependencies between them.
- Warnings: compile with warnings enabled; treat them seriously to catch issues early.

## Roadmap (Informal)

- Chapter 1: Basics and I/O (hello world, temperature tables, counters).
- Chapter 2: Types, operators, expressions (`ranges`, `expressions`).
- Chapter 3: Control flow (`control-flow`, `longest-line`).
- Chapter 4: Functions and program structure (`funcs-and-prog-structure`).
- Later chapters continue similarly, each with small, focused programs.

This is a working set; folders may be added/refined as I progress.

## License

This repository is licensed under the GNU General Public License v3.0. See `LICENSE` for details.

## Acknowledgements

- Brian W. Kernighan and Dennis M. Ritchie — “The C Programming Language”.
- The broader C community for idioms, tips, and test texts used to exercise the programs.
