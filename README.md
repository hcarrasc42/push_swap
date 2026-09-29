This project was built as part of the 42 cursus by hcarrasc42.

# push_swap

> _Sort a stack. Now do it in as few moves as you can._

A sorting program that orders a stack of integers using only a small, fixed set
of stack operations — and tries to do so in as few instructions as possible.
Written in C, the large cases are solved with a **binary radix sort**.

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Topic](https://img.shields.io/badge/topic-algorithms-green?style=flat-square)
![Norm](https://img.shields.io/badge/norm-42-black?style=flat-square)

## 📖 About

`push_swap` receives a list of integers and must output the sequence of
operations that sorts them, using two stacks (`a` and `b`) and only these moves:

| Group | Ops | Effect |
|-------|-----|--------|
| swap | `sa` `sb` `ss` | swap the top two elements of a / b / both |
| push | `pa` `pb` | move the top element from one stack to the other |
| rotate | `ra` `rb` `rr` | shift a / b / both up by one (top goes to bottom) |
| reverse rotate | `rra` `rrb` `rrr` | shift a / b / both down by one (bottom goes to top) |

The score of a solution is the **number of operations** — the fewer, the better.

## ✨ Key Features

- **Strict input validation:** rejects non-numeric arguments, duplicates, and
  values outside `int` range before doing any work.
- **Index normalization:** each value is replaced by its rank (`index`), so the
  algorithm works on a contiguous `0..n-1` range regardless of the raw numbers.
- **Size-specialized sorting:**
  - hand-tuned routines for **3** and **5** elements (`sort_3`, `sort_5`),
  - a **binary radix sort** (`sort_unlimit`) for larger stacks.
- **Linked-list stacks** with the full operation set implemented as list surgery.

## 🧠 The Algorithm

For large stacks, `sort_unlimit` runs a **radix sort on the elements' indices**:

1. Compute how many bits are needed to represent the largest index (`getbits`).
2. For each bit position, from least to most significant:
   - if the top element's bit is `1`, `ra` (keep it in `a`),
   - if it's `0`, `pb` (push it to `b`).
   - once the pass is done, bring everything back from `b` to `a` with `pa`.
3. After processing every bit, the stack is sorted.

This gives roughly `bits × n` operations — well within the project's move
budget — without ever comparing full values, only individual bits of their ranks.

## 🛠 Technologies

| Component | Detail |
|-----------|--------|
| Language | C (`-Wall -Werror -Wextra`) |
| Data structure | singly linked list (`t_list`: value, index, next) |
| Build system | GNU Make |
| External libraries | none (a trimmed `libft` is bundled) |

## 🚀 How to Run

```sh
make
./push_swap 3 2 1 5 4        # prints the operations that sort the stack
./push_swap "4 67 3 87 23"   # arguments may also come as one string
```

Verify a solution with the `checker` (from the 42 subject):

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG   # -> OK
```

Count the operations:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

## 📂 Project Structure

```
push_swap/
├── Makefile
├── push_swap.h
└── srcs/
    ├── push_swap.c          # entry point + dispatch by stack size
    ├── list_init.c          # parsing, validation, list building
    ├── push_swap_utils.c    # indexing, length, sorted check
    ├── sort_3.c  sort_5.c   # specialized small-stack sorts
    ├── sort_unlimit.c       # binary radix sort
    ├── ft_swap.c  ft_push.c  ft_rotate.c  ft_reverse_rotate.c   # operations
    ├── ft_exit.c
    └── libft/               # ft_atoi, ft_split, ft_calloc, ...
```

## 💡 What This Project Demonstrates

- **Algorithm design under a hard cost metric** (minimize operation count).
- **Radix sort** applied to a stack machine with a restricted instruction set.
- **Linked-list manipulation** in C for every stack operation.
- **Robust input parsing and validation** with clean error handling.
