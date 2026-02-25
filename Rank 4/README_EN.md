# 🧠 42cursus - Exam Rank 04

This repository contains my solutions for the 42cursus **Exam Rank 04**, which is composed of three levels of increasingly difficult coding exercises.

---

## ⚙️ Level 1

### ✅ `ft_popen`
- **Goal**: Implement a simplified version of `popen()` to execute shell commands via `fork`, `pipe`, and `execvp`.
- **Focus**: Pipe setup, file descriptor management, and process control.

### ✅ `picoshell`
- **Goal**: Build a tiny shell that parses a string of piped commands (e.g., `ls | grep a | wc -l`) and executes them correctly.
- **Key Concepts**: `fork`, `execvp`, `pipe`, `dup2`, command parsing.

### ✅ `sandbox`
- **Goal**: Detect whether a function crashes, hangs (timeout), or exits normally.
- **Techniques Used**:
  - `fork()`, `alarm()`, `sigaction()`
  - Detecting segmentation faults or timeouts
  - Analyzing `waitpid` exit statuses

---

## 🌲 Level 2

### ✅ `argo`
- **Goal**: Parse a simplified JSON-like input string into an Abstract Syntax Tree (AST).
- **Parser Type**: Recursive Descent
- **Output**: Structured tree representing objects, arrays, strings, and numbers.

### ✅ `vbc` (Very Basic Compiler)
- **Goal**: Implement a compiler that converts arithmetic expressions (`+`, `*`, parentheses) into stack-based assembly-like instructions.
- **Key Concepts**:
  - Tokenization
  - AST construction
  - Recursive code generation

---

## 📌 Notes

- All projects are implemented in **C**, without using external libraries unless explicitly allowed.
- Each level had a strict time constraint during the exam.
- The repository is organized into folders by level, each containing source code and test cases.
- I skipped `tsp` due to time constraints but plan to complete it later for practice.

---

## 📚 Learnings

- Mastery of recursion, backtracking, and tree structures.
- Deep understanding of Unix process control (`fork`, `exec`, `pipe`, `wait`).
- Writing parsers and compilers from scratch without libraries.
- Low-level error handling and debugging using signals and system calls.

---

## 🏁 Final Thoughts

Exam Rank 04 was a significant step in mastering complex algorithmic thinking and system-level C programming. These exercises helped sharpen my skills in recursion, parsing, memory management, and inter-process communication.

