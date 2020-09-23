#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* first, int* second) { //swapping
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

int main() {
	int Q;
	int N, arrive[20], burst[20]; //storing data
	int burst1[20]; //will need this later
	int index[20];
	printf("Enter the total amount of processes (up to 20): "); //getting data
	scanf_s("%d", &N);

	printf("Enter the value of quantum: ");
	scanf_s("%d", &Q);

	printf("\nEnter Process Arrival Time\n");
	for (int i = 0; i < N; i++) {
		index[i] = i + 1;
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &arrive[i]);
	}

	printf("\nEnter Process Burst Time\n");
	for (int i = 0; i < N; i++) {
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &burst[i]);
		burst1[i] = burst[i];
	}

	for (int i = 0; i < N; i++) { //arrange according to the arrival time
		for (int j = 0; j < N - 1; j++) {
			if (arrive[j] > arrive[j + 1]) {
				swap(&arrive[j], &arrive[j + 1]);
				swap(&burst[j], &burst[j + 1]);
				swap(&index[j], &index[j + 1]);
			}
		}
	}

	int time = 0; //time
	int turnAround[20];

	int wait[20]; //counting waiting from the very beginning
	wait[0] = arrive[0];

	int numOfEx = 0;

	while (numOfEx != N) { //here i divide the precesses and execute them
		for (int i = 0; i < N; i++) { 
			if (time >= arrive[i]) { //execute when it is the time
				if (burst[i] > 0) {
					if (burst[i] <= Q) { 
						numOfEx++;
						wait[i] = time;
						time = time + burst[i];
						turnAround[i] = time;
						burst[i] = burst[i] - Q;
					}
					else {
						burst[i] = burst[i] - Q;
						time = time + Q;
					}
				}
			}
		}
	}
	double avWait = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		avWait = avWait + wait[i];
	}
	avWait = avWait / N;

	double avTurnAround = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		turnAround[i] = turnAround[i] - arrive[i];
		avTurnAround = avTurnAround + turnAround[i];
	}
	avTurnAround = avTurnAround / N;

	printf("\nProcess\t\tArrival Time\tWaiting Time\tBurst Time\tTurnaroudTime"); //printing everything
	for (int i = 0; i < N; i++) {
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", index[i], arrive[i], wait[i] - arrive[i], burst1[i], turnAround[i]); //the time of waiting here starts from arriving point
	}

	printf("\nCompletion Time: %d", time);
	printf("\nAverage Waiting Time: %f", avWait);
	printf("\nAverage Turnaround Time: %f", avTurnAround);

	system("Pause");

	return 0;
}