
# Scheduling Intro Excersises

Scheduling policy simulations using the supplied scheduler.py script

## Q1

<details>

> Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

```
./scheduler.py -p FIFO -j 3 -l 200,200,200

ARG policy FIFO
ARG jlist 200,200,200

Here is the job list, with the run time of each job: 
  Job 0 ( length = 200.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 200.0 )
```

### Answer

| Job | Response Time | Turnaround |
|:---:|---------------|------------|
|0|0|200|
|1|200|400|
|2|400|600|

### Solution Output

```
Final statistics:
  Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```
</details>

## Q2

<details>

> Now do the same but with jobs of different lengths: 100, 200, and 300.

```
./scheduler.py -p FIFO -j 3 -l 100,200,300

ARG policy FIFO
ARG jlist 100,200,300

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )
```

### Answer

| Job | Response Time | Turnaround |
|:---:|---------------|------------|
|0|0|100|
|1|100|300|
|2|300|600|

### Solution Output

```
Final statistics:
  Job   0 -- Response: 0.00  Turnaround 100.00  Wait 0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33
```

</details>

## Q3

<details>

> Now do the same, but also with the RR scheduler and a time-slice of 1.

```
./scheduler.py -p FIFO -j 3 -l 200,200,200 -q 1

ARG policy RR
ARG jlist 100,200,300

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )
```

### Answer

| Job | Response Time | Turnaround |
|:---:|---------------|------------|
|0|0|300|
|1|1|500|
|2|2|600|

I was off by 2 ticks for job 0. Because each "chunk" of execution is split 3 ways in the beginning, Job 0 completes at the start of the 100th chunk, which is 298. Tick 300 is the completetion of that entire chunk of execution.

Same with Job 1 being off by 1 tick. There's only 2 jobs in each chunk, so the actual completion tick is offset by 1.

### Solution Output

```
Final statistics:
  Job   0 -- Response: 0.00  Turnaround 298.00  Wait 198.00
  Job   1 -- Response: 1.00  Turnaround 499.00  Wait 299.00
  Job   2 -- Response: 2.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 1.00  Turnaround 465.67  Wait 265.67
```

</details>

## Q4

<details>

>  For what types of workloads does SJF deliver the same turnaround times as FIFO?

### Answer

Jobs with very close time of completion make both policies perform very similarly.

</details>

## Q5

<details>

>  For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

### Answer

Jobs with very close time of completion and very low quantum timing.

</details>

## Q6

<details>

>  What happens to response time with SJF as job lengths increase?

### Answer

Response time gets worse, as each job must complete before the next is started. As all jobs queued take longer, the response time gets worse.

</details>

## Q7

<details>

>  What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

### Answer

Response time gets linearly worse for each job. Equation: ```r(j) = q * (N - 1)```

</details>
