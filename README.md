# 🚀 Minishell - 42 School Project

> Dive into the world of shells with Minishell, a playful yet powerful bash-inspired interpreter crafted for the 42 School curriculum. We’ve reimagined the classic shell experience—mandatory features meet exciting bonuses, all wrapped in a sleek, minimalist package.

## ✍️ Authors

- **Cao Tan** – Parsing handler ([GitHub](https://github.com/Siuol7))
- **Triet Pham** – Execution handler([GitHub](https://github.com/hihi-louis))

## 🎯 Overview

Minishell is your pocket-sized command-line companion. Type, parse, and execute with flair. From built-in magic tricks to complex operator acrobatics, this shell handles:

- **Pipes that flow**: chain commands like rivers of data
- **Redirections that bend reality**: `<`, `>`, `>>`, `<<`
- **Variable illusions**: `$VAR` expansion

Plus, robust error detecting keeps ambiguous redirections and syntax mishaps at bay.

## 🌟 Core Features

- 🎩 **Built-in spells**: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, `unset`
- 🔄 **Unlimited pipelines**: No cap on pipes or file descriptors—chain to your heart’s content
- 📜 **Here-doc adventures**: `<<` blocks with expansions and wildcards
- 🕵️ **Edge-case mastery**:
  - Nested shells track depth like a pro
  - `cd ..` survives ghost directories
  - Ambiguous redirections get tamed
  - Final `env` commands bow to correctness

### Parsing Flowchart

~~~text
Input Command -> Validate -> Lexer -> Tokenize and Classify -> Expand -> Split after Expanding -> Parse to Command Group
~~~

### Execution Flowchart

~~~text
AST create -> Execute from Leftnode -> Handle Signal and Exitcode -> Clean Up
~~~
## 🔍 Behind the Scenes

1. **Tokenize** your input: commands, operators, redirects, and parentheses become neat tokens.
2. **Validate** syntax: unmatched parentheses? sneaky operators? We catch them.
3. **Expand** variables and wildcards—watch stars align before execution.
4. **Build** an Abstract Syntax Tree (AST) as your execution roadmap.
5. **Execute**:
   - Traverse left subtree first, then right based on `|` outcomes.
   - Internally handle built-ins; summon external programs with `execve` when needed.

##  Lessons learn:
1. Process Management
2. Signals Handling
3. Bash Behaviours
4. Strings manipulation

## 📦 Installation & Launch

```bash
# Clone your new best friend
git clone https://github.com/Siuol7/42-minishell.git minishell
cd minishell
make         # build the magic

# Fire it up
./minishell
```

| ***Execute & Makefile tutorial*** |
|-----------|
| <img src="https://github.com/Siuol7/Project-Overview/blob/main/assets/philo.gif" width="600"/> |
