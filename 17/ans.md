
# Free Space

## Simulation

1. First run with the flags ```-n 10 -H 0 -p BEST -s 0``` to generate a few random allocations and frees. Can you predict what alloc()/free() will return? Can you guess the state of the free list after each request? What do you notice about the free list over time?

Because coalesce is turned off, the list becomes fragmented as more allocations are called.

2. How are the results different when using a WORST fit policy to search the free list (-p WORST)? What changes?

More entries are added to the list overall. It doesn't use segments that the memory could fit in, so it continuously fragments the largest.

3. What about when using FIRST fit (-p FIRST)? What speeds up when you use first fit?

Similar to BEST, as the program is requesting allocations of similar size. The algorithm doesn't need to search the full list when it finds a match.

4.  For the above questions, how the list is kept ordered can affect the time it takes to find a free location for some of the policies. Use the different free list orderings (-l ADDRSORT, -l SIZESORT+, -l SIZESORT-) to see how the policies and the list orderings interact.

The orderings don't change much for this sample size and allocation requests. The size sorts flip the list opposite of eachother, which can make worst or first fit faster.

5. Coalescing of a free list can be quite important. Increase the number of random allocations (say to -n 1000). What happens to larger allocation requests over time? Run with and without coalescing (i.e., without and with the -C flag). What differences in outcome do you see? How big is the free list over time in each case? Does the ordering of the list matter in this case?

Ordering matters. Address ordering with best fit coalesces the list to length 2 by the final allocation, and keeps the list in single digits for the other allocation algorithms. Size sorting inflates the list massively.

6. What happens when you change the percent allocated fraction -P to higher than 50? What happens to allocations as it nears 100? What about as the percent nears 0?

As the percent increases, the system has a harder time finding suitable memory segments for the request. As it nears 100% it starts to always return null.

7.  What kind of specific requests can you make to generate a highlyfragmented free space? Use the -A flag to create fragmented free lists, and see how different policies and options change the organization of the free list.

Sizesort first fit and 50/50 alloc/dealloc with variable size memory requests.
