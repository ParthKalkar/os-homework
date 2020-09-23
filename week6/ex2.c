#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
    	*a = *b;
    	*b = temp;
}


int main() {   
	
	// Pointers to arrays of arrival time (AT) and burst time (BT) of each process
	int *at, *bt;
	// Number of processes 
	int size;
	
	
	printf("Enter number of processes = ");
	scanf("%d", &size);
     
	at = malloc(size * sizeof(int));
	bt = malloc(size * sizeof(int));
     	
     	// Put arrival and burst time for each process
	for(int i = 0; i < size; i++) {
		printf("Enter arrival time of process P[%d] = ", i + 1);
		scanf("%d", &at[i]);
		
		printf("Enter burst time of process P[%d] = ", i + 1);
		scanf("%d", &bt[i]);
	}
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (at[j] > at[j + 1]) {
				swap (&at[j], &at[j + 1]);
				swap (&bt[j], &bt[j + 1]);
			}
			
			if (at[j] == at[j + 1]) {
				if (bt[j] > bt[j + 1]) {
					swap (&at[j], &at[j + 1]);
					swap (&bt[j], &bt[j + 1]);
				}
			}
		}
	}
	
	// Arrays for completion time (CT), turn around time (TAT) and Waiting time (WT)
	int ct[size], tat[size], wt[size];
	// Average turnaround time (ATT) and average waiting time (AWT)
	float att, awt;
	// Total turnaround time and total waiting time, whey will be used to find ATT and AWT respectively
	float total_tat = 0, total_wt = 0;
	
	
	// Completion time equals to its BT + CT of previous process
	ct[0] = at[0] + bt[0];
	for (int i = 1; i < size; i++) {
		ct[i] = ct[i - 1] + bt[i];
	}
	
	
	// For each process turnaround time equals to its CT minus its AT
	// total_tat is sum of TAT of each process
	for (int i = 0; i < size; i++) {
		tat[i] = ct[i] - at[i];
		total_tat += tat[i];
	}
	
	
	// For each process waiting time equals to its TAT minus its BT 
	// Waiting time for first process is 0
	// total_wt is sum of WT of each process
	wt[0] = 0;
	for (int i = 1; i < size; i++) {
		wt[i] = tat[i] - bt[i];
		total_wt += wt[i];
	}
	
	// Output result:	
	printf("#P\tAT\tBT\tCT\tTAT\tWT\n");
	for (int i = 0; i < size; i++) {
		// Number of process
		printf("%d\t", (i + 1));
		// Its AT
		printf("%d\t", at[i]);
		// Its BT
		printf("%d\t", bt[i]);
		// Its CT
		printf("%d\t", ct[i]);
		// Its TAT
		printf("%d\t", tat[i]);
		// Its WT
		printf("%d\n", wt[i]);
	}
	
	// Output average TAT and WT by dividing total_tat and total_wt by number of processes
	printf("Average Turnaround time = %f \n", total_tat / (float)size);
	printf("Average Waiting time = %f \n", total_wt / (float)size);
}
