
# Segmentation

## Simulation

### Questions

1. First let’s use a tiny address space to translate some addresses. Here’s a simple set of parameters with a few different random seeds; can you translate the addresses?

```segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0```

```
ARG seed 0
ARG address space size 128
ARG phys mem size 512

Segment 0 base  (grows positive) : 0x00000000 (decimal 0)
Segment 0 limit                  : 20

Segment 1 base  (grows negative) : 0x00000200 (decimal 512)
Segment 1 limit                  : 20
```

VA 0: 108   - (492) -> 109 - 128 = -20; 512 + (-20) = 492
VA 1: 97    - Segfault
VA 2: 53    - Segfault
VA 3: 33    - Segfault
VA 4: 65    - Segfault

```segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1```

VA 0: 17    - (17)
VA 1: 108   - (492)
VA 2: 97    - Segfault
VA 3: 32    - Segfault
VA 4: 63    - Segfault

```segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2```

VA 0: 122   - (506)
VA 1: 121   - (505)
VA 2: 7     - (7)
VA 3: 10    - (10)
VA 4: 106   - Segfault

2. Now, let’s see if we understand this tiny address space we’ve constructed (using the parameters from the question above). What is the highest legal virtual address in segment 0? What about the lowest legal virtual address in segment 1? What are the lowest and highest illegal addresses in this entire address space? Finally, how would you run segmentation.py with the -A flag to test if you are right?

S0: [0, 19]

S1: [107, 127]

3.  Let’s say we have a tiny 16-byte address space in a 128-byte physical memory. What base and bounds would you set up so as to get the simulator to generate the following translation results for the specified address stream: valid, valid, violation, ..., violation, valid, valid? Assume the following parameters:

```segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 ? --l0 ? --b1 ? --l1 ?```

Solution: ```segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 0 --l0 2 --b1 127 --l1 2```

4.  Assume we want to generate a problem where roughly 90% of the randomly-generated virtual addresses are valid (not segmentation violations). How should you configure the simulator to do so? Which parameters are important to getting this outcome?

Make segment length 90% of address space size.

5. Can you run the simulator such that no virtual addresses are valid? How?

Make the memory segment length 0. ```--l0 0 --l1 0```
