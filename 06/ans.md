
> Compute the solutions for simulations with 3 jobs and random seeds of 1, 2, and 3.

**Q1**

<details>
Here is the job list, with the run time of each job: 
  Job 0 ( length = 1, tickets = 84 )
  Job 1 ( length = 7, tickets = 25 )
  Job 2 ( length = 4, tickets = 44 )


Here is the set of random numbers you will need (at most):
Random 651593
Random 788724
Random 93859
Random 28347
Random 835765
Random 432767
Random 762280
Random 2106
Random 445387
Random 721540
Random 228762
Random 945271
</details>

 - (119)    J2, length = 3
 - (9)      J0, length = 0
 - Ticket total 69
 - (19)     J1, length = 6
 - (57)     J2, length = 2
 - (37)     J2, length = 1
 - (68)     J2, length = 0
 - Ticket total 44
 - Run J1 to completion


<details>
Here is the job list, with the run time of each job: 
  Job 0 ( length = 9, tickets = 94 )
  Job 1 ( length = 8, tickets = 73 )
  Job 2 ( length = 6, tickets = 30 )


Here is the set of random numbers you will need (at most):
Random 605944
Random 606802
Random 581204
Random 158383
Random 430670
Random 393532
Random 723012
Random 994820
Random 949396
Random 544177
Random 444854
Random 268241
Random 35924
Random 27444
Random 464894
Random 318465
Random 380015
Random 891790
Random 525753
Random 560510
Random 236123
Random 23858
Random 325143
</details>

 - 197 tickets
 - (169)    J2, length = 5
 - (42)     J0, length = 8
 - (54)     J0, length = 7
 - (192)    J2, length = 5
 - (28)     J0, length = 6
 - (123)    J1, length = 7
 - (157)    J1, length = 6

**Q2**

> Now run with two specific jobs: each of length 10, but one (job 0) with 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100). What happens when the number of tickets is so imbalanced? Will job 0 ever run before job 1 completes? How often? In general, what does such a ticket imbalance do to the behavior of lottery scheduling?

The job with more tickets monopolises the CPU. The job with less tickets has a near zero chance of finishing before the larger. 0.01^(10) chance. Such a ticket imbalance basically turns it into fifo.

**Q3**

> When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100,100:100), how unfair is the scheduler? Run with some different random seeds to determine the (probabilistic) answer; let unfairness be determined by how much earlier one job finishes than the other.

The scheduler is pretty fair. Most simulations fall within 10 cycles of one job finishing before the other. As quantum increases, the jobs finish closer and closer together.
