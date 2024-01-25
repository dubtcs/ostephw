
# Threads: Intro

## Simulation

### Questions

1. Let’s examine a simple program, “loop.s”. First, just read and understand it. Then, run it with these arguments (```./x86.py -t 1 -p loop.s -i 100 -R dx```) This specifies a single thread, an interrupt every 100 instructions, and tracing of register %dx. What will %dx be during the run? Use the -c flag to check your answers; the answers, on the left, show the value of the register (or memory value) after the instruction on the right has run.

%dx register should be -1. Only one sub command is run

2. Same code, different flags: (```./x86.py -p loop.s -t 2 -i 100 -a dx=3,dx=3 -R dx```) This specifies two threads, and initializes each %dx to 3. What values will %dx see? Run with -c to check. Does the presence of multiple threads affect your calculations? Is there a race in this code?

%dx register should be -1, from 3

3. Run this: ```./x86.py -p loop.s -t 2 -i 3 -r -R dx -a dx=3,dx=3``` This makes the interrupt interval small/random; use different seeds (-s) to see different interleavings. Does the interrupt frequency change anything?

The decreased interrupt timer conflicts with jump commands as values are no longer what they were when tested.

4. Now, a different program, looping-race-nolock.s, which accesses a shared variable located at address 2000; we’ll call this variable value. Run it with a single thread to confirm your understanding: ```./x86.py -p looping-race-nolock.s -t 1 2000``` What is value (i.e., at memory address 2000) throughout the run? Use -c to check.

This will take the value at address 200, move it into %ax, subtract one, then push it back into address 2000

5.  Run with multiple iterations/threads: ```./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -M 2000``` Why does each thread loop three times? What is final value of value?

%ax will be 6 at the end. %bx is set to 3 at the start of the threads, and is subtracted each iteration.

6. Run with random interrupt intervals: ```./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 0``` with different seeds (-s 1, -s 2, etc.) Can you tell by looking at the thread interleaving what the final value of value will be? Does the timing of the interrupt matter? Where can it safely occur? Where not? In other words, where is the critical section exactly?

The interrupt doesn't matter in this case, as the move and store operations happen before the interrupts in each thread. The value is saved correctly.
