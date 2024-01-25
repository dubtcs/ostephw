
# Thread API

## Code

6. Let’s next look at main-signal.c. This code uses a variable (done) to signal that the child is done and that the parent can now continue. Why is this code inefficient? (what does the parent end up spending its time doing, particularly if the child thread takes a long time to complete?)

The main thread is stuck running constantly until done is set to 1, and the child thread must wait until the parent thread is done to make the change.

7. Now look at a slightly modified version of the code, which is found in main-signal-cv.c. This version uses a condition variable to do the signaling (and associated lock). Why is this code preferred to the previous version? Is it correctness, or performance, or both?

Both. The waiting thread doesn't do any work while it waits to be woken up after receiving the signal.
