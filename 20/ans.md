# Advanced Page Tables

## Simulation

1. One register. It leads directly to the page index.

2. 2 memory references for each lookup. One for the page directory, and another for the page table.

3. Page directory lookups will have some cache misses, but page table lookups will correspond to each page directory.