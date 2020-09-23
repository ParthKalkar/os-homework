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
	int N, arrive[20], burst[20]; //storing data
	int index[20];
	printf("Enter the total amount of processes (up to 20): "); //getting data
	scanf_s("%d", &N);

	N = 14;

	printf("\nEnter Process Arrival Time\n"); //getting data
	for (int i = 0; i < N; i++) {
		index[i] = i + 1;
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &arrive[i]);
	}

	printf("\nEnter Process Burst Time\n"); //getting data
	for (int i = 0; i < N; i++) {
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &burst[i]);
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

	int wait[20]; //counting waiting time from the very beginning
	wait[0] = arrive[0]; 
	int turnAround[20];
	turnAround[0] = wait[0] + arrive[0];

	/*
		int the next loop, i'm sorting processes by their bursts,
		but they are still sorted according their arrival time
	*/

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arrive[j] != arrive[i]) {
				for (int k = i; k < j - 1; k++) {
					if (burst[k] > burst[k + 1]) {
						swap(&arrive[k], &arrive[k + 1]);
						swap(&burst[k], &burst[k + 1]);
						swap(&index[k], &index[k + 1]);
					}
				}
				break;
			}
		}
	}

	bool waiting[20]; //if processes are waiting or not
	bool executed[20]; //if processes have been executed or not

	for (int i = 0; i < N; i++) { //non of them have waited or been executed yet
		waiting[i] = false;
		executed[i] = false;
	}

	int time = 0; //time is zero yet
	int numOfEx = 0; 

	while (true) { //the loop where i run processes
		for (int i = 0; i < N; i++) { //here i select the processes that are waiting
			if (!executed[i]) {
				if (time >= arrive[i] && !executed[i]) {
					waiting[i] = true;
				}
			}
		}

		int a, b; //finding borders of selected processes in the loop
		for (int i = 0; i < N; i++) {
			if (waiting[i]) {
				a = i;
				break;
			}
		}
		for (int i = N - 1 ; i >= 0; i--) {
			if (waiting[i]) {
				b = i;
				break;
			}
		}

		for (int i = a; i < b; i++) { //sorting by their bursts to execute in the right order
			if (burst[i] > burst[i + 1]) {
				swap(&arrive[i], &arrive[i + 1]);
				swap(&burst[i], &burst[i + 1]);
				swap(&index[i], &index[i + 1]);
			}
		}

		bool stop = false; //need this to stop the loop if needed

		for (int i = a; i <= b && !stop; i++) {
			executed[i] = true; //the next lines until "if" consdition represent setting a process as executed
			numOfEx++;
			wait[i] = time;
			time += burst[i];
			waiting[i] = false;
			turnAround[i] = time;

			if (b != N - 1) { //if a process has been executed but it's time for a futher process to be executed, we need to consider it too
				for (int i = b + 1; i < N && !stop; i++) { //so we do our selection again
					if (time >= arrive[i] && !executed[i]) {
						stop = true;
					}
				}
			}
		}

		if (numOfEx == N) break; //if all the processes have been executed, stop
	}

	double avWait = 0;
	
	for (int i = 0; i < N; i++){
		avWait = avWait + wait[i] - arrive[i];
	}
	avWait = avWait / N;

	double avTurnAround = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		turnAround = turnAround[i] - arrive[i];
		avTurnAround = avTurnAround + turnAround[i];
	}
	avTurnAround = avTurnAround / N;

	printf("\nProcess\t\tArrival Time\tWaiting Time\tBurst Time\tTurnaroudTime"); //printing everythin
	for (int i = 0; i < N; i++) {
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", index[i], arrive[i], wait[i] - arrive[i], burst[i], turnAround[i]); //the time of waiting here starts from arriving point
	}

	printf("\nCompletion Time: %d", time);
	printf("\nAverage Waiting Time: %f", avWait);
	printf("\nAverage Turnaround Time: %f", avTurnAround);

	system("Pause");

	return 0;
}
