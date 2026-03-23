# The Standard C++ Template

Every millisecond counts in CP, both in execution time and typing time. We use a standard template to handle common imports, speed up input/output, and provide useful shortcuts.

## Understanding the Template

1. The Magic Header: **<bits/stdc++.h>**
Instead of manually including <iostream>, <vector>, <algorithm>, etc., this GCC-specific header includes the entire standard library at once. It saves time during contests so you don't have to remember which header belongs to which data structure.

2. Fast I/O
```
C++

ios_base::sync_with_stdio(false);
cin.tie(NULL);
```
Standard cin and cout are famously slow because they synchronize with C's stdio library (printf/scanf). These two lines disable that synchronization, making cin/cout just as fast. Without this, you will get Time Limit Exceeded (TLE) on problems with large inputs.

3. using vs. #define
You will notice we use both using and #define.

Use using for Types: using ll = long long; is handled by the C++ compiler. It is type-safe, respects scope, and prevents weird pointer bugs.

Use #define for Syntax: #define pb push_back is handled by the preprocessor. It does a blind "Find and Replace" on your text before compilation. We use it to shorten typing for repetitive syntax.

4. Hiding Debug Prints (#ifndef ONLINE_JUDGE)
Automated judges (like Codeforces or LeetCode) strictly compare your exact output text to the answer key. If you print "Time elapsed: 15 ms", the judge will mark your answer as Wrong Answer (WA).
Most CP platforms automatically define a macro called ONLINE_JUDGE. By wrapping our timing/debug code in #ifndef ONLINE_JUDGE ("If Not Defined"), that code will run on your laptop, but will become completely invisible to the official grader!

5. Why no inline keywords?
You might see older templates use inline functions to try and speed up execution time by reducing "function call overhead." In modern C++, the compiler is smarter than us. When compiling with optimization flags, the compiler automatically inlines small, frequently used functions. Focus on your Big O time complexity, not micro-optimizations!

## How to Compile and Run Your Code

To save time and simulate the online judge environment, we use an automated compilation script. 

### 1. Using the Automated Script (Recommended)
Inside each problem folder, you will find a script (e.g., `comp` or `comp.sh`). This script automatically removes old executables, compiles your `main.cpp` with the correct optimization flags, and runs it against every `.txt` file in the `tests/` directory.

To run it, simply open your terminal in the problem's directory and type:
```bash
./comp

**Note: If you get a "Permission denied" error the first time, run chmod +x comp to make it executable.**
```

### 2. Manual Compilation (The Standard Command)

If you want to compile and run a specific test case manually, use this command:

Bash
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -o main.exe main.cpp && ./main.exe < tests/01.txt

- -std=c++17: Uses the C++17 standard, which is the baseline for most modern CP platforms.

- -O2: Applies level 2 optimizations. This makes your code run significantly faster, mimicking the official judge.

- -Wall -Wextra: Turns on warnings. The compiler will tap you on the shoulder if you do something suspicious, like declaring a variable you never use.

- -Wshadow: Warns you if you accidentally declare a local variable with the exact same name as a global variable (a very common bug!).

- < tests/01.txt: This is called input redirection. It feeds the text file directly into your program's cin stream, saving you from typing out the test cases manually.

- cat input_test.txt | ./main.exe: The cat command reads your test file, and the pipe (|) sends that text directly into your program's cin stream, saving you from typing out the test cases manually.


