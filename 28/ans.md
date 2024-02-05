
# Thread Locks

## Simulation

1. yes

2. ```./x86.py -p flag.s -t 1``` It does. It increments count by one and halts.

3. ```./x86.py -p flag.s -t 1 -a bx=10 -M flag,count -R ax -c``` This sets %bx to 10 causing it to loop 10 times. It increments count by one each time. Count increases with %bx.

4. Setting the interval to 16 results in desired outcome.

5. Atomic operation to swap variables. Because it is atomic, it will always be set and not interrupt can bother it while checking.

6. It can lead to inefficient cpu usage at interval period 14. A thread will be stuck checking while the other holds the lock.

8. The thread sets it's array index to true and sets the current turn to the opposite thread. As long as the opposite thread index in false, it will continue.

9. Using intervals above 2 will yield the desired result.
