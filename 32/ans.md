# Concurrency Bugs

## Code

1. Output does not change

2. There isn't always a deadlock

3. Only 1 thread will never deadlock.

4. The special case allows for a list to be duplicated into itself and only hold one lock

5. 0.01 seconds on 2 threads. Increasing threads and loops slows the program down.

6. ```-p``` Allows much faster times, t/n

7. Number of retries increases as thread count increases, and the program slows down.

8. One single lock is required for any specific lock acquisition. Even if two threads are working on completely different vectors, they still have to wait for the global lock.

9. It uses a compare and swap asm instruction set.

10. No lock takes longer than the others