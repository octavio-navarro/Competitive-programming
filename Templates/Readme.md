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

Do not just use standard g++ main.cpp. To accurately simulate the online judge and catch beginner bugs, use these specific compilation commands in your terminal.

The Standard Command (Use everyday)
```
Bash
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -o main.exe main.cpp && cat input_test.txt | ./main.exe
```

- -std=c++17: Uses the C++17 standard, which is the baseline for most modern CP platforms.

- -O2: Applies level 2 optimizations. This is how the online judge will compile your code, making it run significantly faster.

- -Wall -Wextra: Turns on warnings. The compiler will tap you on the shoulder if you do something suspicious, like declaring a variable you never use.

- -Wshadow: Warns you if you accidentally declare a local variable with the exact same name as a global variable (a very common bug!).

- cat input_test.txt | ./main.exe: The cat command reads your test file, and the pipe (|) sends that text directly into your program's cin stream, saving you from typing out the test cases manually.
