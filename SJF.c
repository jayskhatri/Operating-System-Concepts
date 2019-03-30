#include<stdio.h>
#define N 15
int main(){
    int i,j,k,t,t1,bt[N]={0},at[N]={0},tat[N]={0},wt[N]={0},ct[N]={0};
	int totalProcess,tBT=0,time=0, temp;
	float tTAT=0,tWT=0;

    printf("\n\t\t\tSJF\n\n");
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

    k=1;
    //sort using burst time
    for(j=0;j<totalProcess;j++){
        time = time + bt[j];
        t = bt[k];
        for(i=k;i<totalProcess;i++){
            if(time>=at[i] && bt[i]<t){
                temp = at[k];
                at[k] = at[i];
                at[i] = temp;
                temp = bt[k];
                bt[k] = bt[i];
                bt[i] = temp;
            }
        }
        k++;
    }

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
	printf("\n\n\t\t\t\t\tANSWER\n\n\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurn Around Time\t\tWaiting Time\t\n\n");

	for(i=0;i<totalProcess;i++){
		printf("P%d\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------");
	printf("\nTotal\t\t\t\t\t\t\t\t\t\t%.2f\t\t\t\t%.2f\n",tTAT,tWT);

	printf("\n\nAverage Turnaround Time = %f\n",tTAT/totalProcess);
	printf("Average WT = %f\n\n",tWT/totalProcess);


}
