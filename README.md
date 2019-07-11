# Lark
Mixed-Signal Design Automation Tool.
## Introduction
**Lark** is a C/C++ based simulator. **Lark** supports basic simulation task and reduction algorithm. It can also plot MNA matrix and simulation result. In the part of parser, we use flex & bison to parse netlist. This project is for EDA research purpose and we will improve it for a long time.
## Parser
flex & bison
## Plot library
## Reduction algorithm
## Solver
## Environment
Platform: MacOS 10.14 </br>
Compiler: clang++ 11.0.0 </br>
Bison version: 3.2+ </br>
## How to use
### Compile & Run
`cd ./Lark` </br>
`./Make.sh` </br>
`./lark netlist`
### Clean
`./Make.sh clean`
## Rules
1. variable name: _xxx_yyy </br>
2. function name: XxxYyy </br>
3. C++ file: Xxx.cpp </br>
4. directory name: xxx </br>
5. class name: XxxYyy </br>
6. formal parameter name: _xxx_yyy </br>
## How to contribute
1. fork `msda-lab/Lark`
2. `git clone git@github.com:yourname/Lark.git`
3. `git checkout -b origin/dev`
4. do your work
5. `git add xxx`
6. `git commit -m "comment"`
7. `git remote -v`
8. `git remote add upstream git@github.com:msda-lab/Lark.git`
9. `git fetch upstream`
10. `git merge upstream/dev`
11. `git push`
12. Open page of `msda-lab/Lark`, click 'Pull request'
13. After verification, admin click `Merge pull request`
## Useful commands
1. `git status`
2. `git branch -a`
3. `git checkout branch`
4. other `merge` operations.
## Commit tags
`add`, `delete`, `update`, `fix`
