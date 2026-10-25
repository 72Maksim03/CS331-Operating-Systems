#include <stdio.h>
#include <stdlib.h>

struct Process {
	int pid;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int response_time;
};

void fcfs(struct Process p[], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - 1; j++){
			if (p[j].arrival_time > p[j+1].arrival_time){
				struct Process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	int current_time = 0;
	double waiting = 0;
	double turnaround = 0;	
	double response = 0;

	printf("\n=== First Come First Served (FCFS) ===\n");
	printf("Gantt Chart:\n");

	for (int i = 0; i < n; i++){
		if(current_time < p[i].arrival_time){
			current_time = p[i].arrival_time;
		}

		p[i].response_time = current_time - p[i].arrival_time;
		p[i].waiting_time = current_time - p[i].arrival_time;
		current_time += p[i].burst_time;

		p[i].turnaround_time = current_time - p[i].arrival_time;

		waiting += p[i].waiting_time;
		turnaround += p[i].turnaround_time;
		response += p[i].response_time;
	
		printf("| P%d ", p[i].pid);
	}

	printf("|\n\n");
	printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "PID", "AT", "BT", "WT", "TAT", "RT");

	for (int i = 0; i < n; i++) {
		printf("%-8d %-8d %-8d %-8d %-8d %-8d\n",
				p[i].pid, p[i].arrival_time, p[i].burst_time,
				p[i].waiting_time, p[i].turnaround_time,
				p[i].response_time);
	}
	
	printf("\nAverage Waiting Time: %.2f\n", waiting / n);
	printf("Average Turnaround Time: %.2f\n", turnaround / n);
	printf("Average Response Time: %.2f\n", response / n);
}

void sjf(struct Process p[], int n){
	int current_time = 0;
	int completedCount = 0;
	int completed[n];

	for(int i = 0; i < n; i++){
		completed[i] = 0;
	}

	double waiting = 0;
	double turnaround = 0;
	double response = 0;
	
	printf("\n=== Shortest Job First (SJF) ===\n");
	printf("Gantt Chart:\n");

	while (completedCount < n){
		int selected = -1;

		for (int i = 0; i < n; i++){
			if (completed[i] != 0 || current_time < p[i].arrival_time){
				continue;
			}

			if (selected == -1 ||
					p[i].burst_time < p[selected].burst_time || 
					(p[i].burst_time == p[selected].burst_time && p[i].arrival_time < p[selected].arrival_time) ||
					(p[i].burst_time == p[selected].burst_time && p[i].arrival_time == p[selected].arrival_time && p[i].pid < p[selected].pid)){
				selected = i;
			}
		}

		if (selected == -1){
			int next_arrival = 0;

			for (int i = 0; i < n; i++){
				if (completed[i] == 0 && (next_arrival == 0 || p[i].arrival_time < next_arrival)){
					next_arrival = p[i].arrival_time;
				}
			}
			current_time = next_arrival;
			continue;
		}

		p[selected].response_time = current_time - p[selected].arrival_time;
		p[selected].waiting_time = current_time - p[selected].arrival_time;

		current_time += p[selected].burst_time;

		p[selected].turnaround_time = current_time - p[selected].arrival_time;

		waiting += p[selected].waiting_time;
		response += p[selected].response_time;
		turnaround += p[selected].turnaround_time;

		completed[selected] = 1;
		completedCount++;

		printf("| P%d ", p[selected].pid);
	}

	printf("|\n\n");
        printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "PID", "AT", "BT", "WT", "TAT", "RT");

        for (int i = 0; i < n; i++) {
                printf("%-8d %-8d %-8d %-8d %-8d %-8d\n",
                                p[i].pid, p[i].arrival_time, p[i].burst_time,
                                p[i].waiting_time, p[i].turnaround_time,
                                p[i].response_time);
        }

        printf("\nAverage Waiting Time: %.2f\n", waiting / n);
        printf("Average Turnaround Time: %.2f\n", turnaround / n);
        printf("Average Response Time: %.2f\n", response / n);
}

int main(){
	int procNum;

	printf("Enter the number of processes: ");

	scanf("%d", &procNum);
	if(procNum < 0){
		printf("The number of processes can not be negative\n");
		exit(1);
	}

	struct Process fcfsProc[procNum];
	struct Process sjfProc[procNum];
	for (int i = 0; i < procNum; i++){
		fcfsProc[i].pid = i+1;
		sjfProc[i].pid = i+1;

		int arrival;
		int burst;

		printf("Enter the arrival time and burst time for process %d: ", i+1);
		scanf("%d %d", &arrival, &burst);

		if (arrival < 0){
			printf("The arrival time must be non-negative");
			exit(1);
		}
		if (burst < 0){
			printf("The burst time must be non-negative");
			exit(1);
		}

		fcfsProc[i].arrival_time = arrival;
		sjfProc[i].arrival_time = arrival;

		fcfsProc[i].burst_time = burst;
		sjfProc[i].burst_time = burst;
	}

	fcfs(fcfsProc, procNum);
	sjf(sjfProc, procNum);
}
