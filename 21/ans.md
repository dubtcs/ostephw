# Phsyical Memory: Mechanisms

## Measurement

### Questions

1. ```gcc mem.c -o mem``` ```./mem 1``` No noticeable changes happen in vmstat. User time increases per mem instance.

2. The "free" column decreases by the amount allocated.

3. Swap increases as the allocated memory does not fit into physical memory.

4. Both increase.

5. 1GB on my 32GB system takes 400ms on loop 0, then 180ms on the follwing loops.
