#include<stdio.h>
#define N 15
int main(){

	int i,j,k,t,t1,bt[N]={0},at[N]={0},tat[N]={0},wt[N]={0},ct[N]={0};
	int totalProcess,tBT=0;
	float tTAT=0,tWT=0;

	printf("Enter total process: ");
	scanf("%d",&totalProcess);

	for(i=0;i<totalProcess;i++){
		printf("\nEnter Arrival time and Burst Time for process %d (Comma Seperated): ",i+1);
		scanf("%d,%d",&at[i],&bt[i]);
	}

    //Swapping if user has not entered arrival time in ascending order
	for(i=0;i<totalProcess;i++){
        for(j=i+1; j<totalProcess; j++){
            if(at[i] > at[j]){
                t = at[i];
                t1 = bt[i];
                at[i] = at[j];
                bt[i] = bt[j];
                at[j] = t;
                bt[j] = t1;
            }
        }
    }

	//calculate completion time of processes
    tBT = at[0];
	for( j=0;j<totalProcess;j++){
		tBT+=bt[j];
		ct[j]+=tBT;
	}

	//calculate turnaround time and waiting times
	for(k=0;k<totalProcess;k++){
		tat[k]=ct[k]-at[k];
		wt[k]=tat[k]-bt[k];
		tTAT+=tat[k];
        tWT+=wt[k];
	}
    //Printing Table
	printf("P#\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\n\n");

	for(i=0;i<totalProcess;i++){
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t\t\t%.2f\t\t%.2f\n",tTAT,tWT);

	printf("\n\nAverage Turnaround Time = %f\n",tTAT/totalProcess);
	printf("Average WT = %f\n\n",tWT/totalProcess);

	return 0;
}

