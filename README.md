# 🪟 CLI Window Management

This project implements a **Command Line Interface (CLI)** application for managing windows and GUI elements in a grid layout.  
It allows creating windows, adding text, tables, and buttons, and organizing them hierarchically.

---

## 📑 Table of Contents
- [Overview](#overview)  
- [Files](#files)  
- [Requirements](#requirements)  
- [Usage](#usage)  
- [Example Commands](#example-commands)  
- [License](#license)  

---

## 📌 Overview
The application allows you to:
- Create windows with custom dimensions  
- Add text, tables, and buttons at specific positions  
- Manage parent-child relationships between windows  
- Display elements in a structured grid layout  

All operations are performed via simple CLI commands.

---

## 📂 Files
- `inc/` → Header files (`base.h`, `window.h`, `text.h`, `table.h`, `button.h`, `command.h`, `manage.h`)  
- `src/` → Source files (`main.cpp`, `window.cpp`, `text.cpp`, `table.cpp`, `button.cpp`,`command.cpp`, `manage.cpp`)  
- `obj/` → Object files (generated during compilation)  
- `bin/` → Compiled executable  
- `Makefile` → Build automation  

---

## ⚙️ Requirements
- A C++ compiler supporting C++17 or later (e.g., `g++`, `clang++`)  
- Compatible with Linux, macOS, and Windows  

---

## ▶️ Usage

### 🛠️ 1. Build and Run the Project 

You can build and run the project in two ways:

**Option 1: Build and run separately**
```bash
make                     # Compiles the project
./bin/main.exe # Runs the program
```
**Option 2: Build and run in a single step**
```bash
make run                  # Compiles (if needed) and runs the CLI
```
### 👀 2. Enter Commands
After launching the CLI, interact with the program by typing commands to:
- Create new windows
- Add text, tables, or buttons to existing windows
- Display the contents of windows
- Exit the application when done

---

## 📋 Example Commands

When you run the CLI, it will first ask you to create the **initial window** by entering its ID, row count, and column count:

```bash
Command Line Application (CLI)
------------------------------
First window: enter ID, rowCount and colCount
Type Exit to quit
< 1 10 10
```
After the first window is created, you can use the available commands:
```bash
add window <id> <rowCount> <colCount> <pId> <row> <col>
add text   <id> <text> <pId> <row> <col>
add table  <id> <rowCount> <colCount> <pId> <row> <col>
add button <id> <text> <pId> <row> <col>
Show
Exit
```
### 📖 Example Workflow

```bash
< 101 5 5           # First window with ID=101, 5 rows, 5 columns
add_text 201 "Hello" 101 0 0
add_table 301 3 3 101 1 1
add_button 401 "Click Me" 101 2 2
Show
 < 101        # Enter the window ID to display
Exit
```
> 📝 Notes:
> - `<pId>` refers to the **parent window ID** where the element will be added.
> - `Show` prompts for a **window ID** and displays that window’s content in a **grid (matrix) format**.
>   - Empty positions in the grid are shown as `[empty]`.
> - `Exit` quits the CLI.

After entering Show with the window ID, the CLI prints the window contents in a grid format:
```bash
[Text: Hello] [empty] [empty] ...
[empty]       [Table: 3x3] [empty] ...
[empty]       [empty]       [Button: Click Me] ...
```
---
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

MIT License

Copyright (c) 2025 Mane Azaryan

Permission is hereby granted, free of charge, to any person obtaining a copy  
of this software and associated documentation files (the "Software"), to deal  
in the Software without restriction, including without limitation the rights  
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
copies of the Software, and to permit persons to whom the Software is  
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all  
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL T
