# Process Scheduling Simulation: FCFS & SJF

A C program that simulates two non-preemptive CPU scheduling algorithms:
- First Come First Served (FCFS)
- Shortest Job First (SJF)

## Compilation

```bash
gcc scheduler.c -o scheduler
```

## Execution

```bash
./scheduler
```

Enter the number of processes, followed by each process's
arrival time and burst time.

The program displays a Gantt chart, per-process waiting,
turnaround, and response times, and the averages for each
algorithm.

## Input Constraints
- Arrival time: non-negative integer
- Burst time: positive integer

