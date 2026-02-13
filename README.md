# Dissecting Hello World: Removing printf, libc, and main.
This repository contains the source code for a deep dive into how C programs interact with the OS. It demonstrates the progression from a standard "Hello World" using the C Standard Library down to a raw system call using inline assembly, removing all dependencies on libc and main.
# File structure:  
- `1-1-simplePrintf.c`: classic printf example as the basis
- `2-writePrintf.c`: using the write function. This is also where I try to make it static using the `-static` flag.
- `3-BadAssemblyPrintf.c`: Attempting to use assembly without recognising executable requiements
- `4-GoodAssemblyPrintf.c`: Full standalone assembly with _start. This is truly independent
# Usage & Compilation
1. Standard printf
```bash
gcc 1-simplePrintf.c -o level1
./level1
```
2. The Low-Level C Function
```bash
gcc -static 2-writePrintf.c -o level2
./level2
```
3. The "Hybrid" Assembly
This file uses inline assembly for printing but still uses the standard main function.Note: If you try to compile this without the standard library (-nostdlib), it will crash because it lacks an entry point and exit handler.
```bash
#Standard compile works (but still links libc)
gcc 3-BadAssemblyPrintf.c -o level3
./level3
```
4. True independent printing
```bash
gcc -nostdlib -static 4-GoodAssemblyPrintf.c -o level4
./level4
```
# Results:
If you run ls -lh on the final binaries, you will observe the following sizes:
- Level 1 (Dynamic): ~16KB
- Level 2 (Static Write): ~700KB+ (Bloat from static libc)
- Level 4 (Nostdlib): ~4KB (Only your code + ELF headers)

🔗 Blog Post
For a full explanation of how this works, check out the accompanying blog post:
[Dissecting Hello World: Removing printf, libc, and main]()
