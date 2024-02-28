# Memory Policies

## Simulation

1.  Generate random addresses with the following arguments: -s 0 -n 10, -s 1 -n 10, and -s 2 -n 10. Change the policy from FIFO, to LRU, to OPT. Compute whether each access in said address traces are hits or misses.

```-s 0 -n 10 -p RAND``` -- Random 

Assuming miss for all as it's random and the cache size is less than the page total.

```-s 1 -n 10 -p LRU``` -- Least recently used

Miss, miss, miss, miss, miss, hit, miss, miss, hit, miss

```-s 2 -n 10 -p OPT``` -- Optimal

Miss, miss, miss, miss, miss, Hit, Hit, miss, Hit, Hit

2. Worst cases: FIFO; Have all references just outside the cache window. LRU; Have page references just after the page capacity in calls, that way, if the page is only referenced once, it is replaced and immediately paged.

3.  ```6,9,3,4,5,8,10,2,1,7``` All page policies would behave similar as no pages are reused.

4. ```1,2,3,8,8,1,2,8``` 1,2,3 are spatial locality. 1,2,8 are temporal.
