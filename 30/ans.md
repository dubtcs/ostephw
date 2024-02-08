
# Conditional Variables

## Code

2. The producer keeps using the next available buffer and warpping back to start if at the end. The outcome doesn't change with 1 producer and consumer. Longer sleep cycles increase num fill.

4. It should take 10 seconds with 10 products. It has one buffer, so only one thread can hold the lock at a time.

5. It reduces the time by around 1 second.

6. It reduces the time in half. It sleeps after releasing the lock, not while holding.

7. No changes when increasing amount of buffers.

8. No...

9. ```-P 0,0,0,0,0,0,1``` makes the producer sleep while the others are sleeping and they all start waiting.
