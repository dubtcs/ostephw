
# Multi Level Feedback Queue

## Q1

> Run a few examples of mlfq.py and complete the execution trace for each.

```
./mlfq.py -j 2 -n 2 -M 0 -m 5

OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 0
OPTIONS ioTime 5
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime   4 - ioFreq   0
  Job  1: startTime   0 - runTime   2 - ioFreq   0
```

**Answer**

| Time |Job | Priority | Tick |
|:-:|:-:|:-:|:-:|
|0|0|0|0|
|1|0|0|1|
|2|0|0|2|
|3|0|0|3|
|4|1|0|0|
|5|1|0|1|

 - Job 0 Start
 - Job 0 Tick 1 P0
 - Job 0 Tick 2 P0
 - Job 0 Tick 3 P0
 - Job 0 Tick 4 P0
 - Job 0 Complete
 - Job 1 Tick 1 P0
 - Job 1 Tick 2 P0
 - Job 1 Complete

## Q2

> How would you run the scheduler to reproduce each example in the chapter?

**Answer**

 - (8.2) ```./mlfq.py -j 1 -n 3 -q 10 -l 0,200,0```
 - (8.3a) ```./mlfq.py -j 2 -n 3 -q 10 -l 0,200,0:100,50,0```
 - (8.3b) ```./mlfq.py -j 2 -n 3 -q 10 -i 5 -S -l 0,200,0:50,50,1```
 - (8.4a) ```./mlfq.py -j 3 -n 3 -q 10 -l 0:200,0:100,100,0:100,100,0```
 - (8.4b) ```./mlfq.py -j 3 -n 3 -q 10 -B 25 -l 0:200,0:100,100,0:100,100,0```

## Q3

> How would you configure the schedule parameters to perform like a round robin?

**Answer**

One queue, with 10 ms quantum ```./mlfq.py -n 1 -q 10```

## Q4

>  Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the -S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.

**Answer**

```./mlfq.py -j2 -n 3 -q 25 -i 1 -l 0,200,0:50,100,24```

## Q5

> Given a system with a quantum length of 10 ms in its highest queue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU?

**Answer**

200ms. 10 is 5% of 200.
