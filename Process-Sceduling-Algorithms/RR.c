    #include<stdio.h>
    #include<conio.h>
    int main()
    {    int i,j,totalProcess,time,temp,t=0,TQ,c,c1;
         int sum_wait=0,sum_turnaround=0,at[10],bt[10],rt[10];
         printf( "\n---------------- Process Scheduling Algorithm ----------------") ;
        printf( "\n----------------- Round Robin Scheduling ----------------") ;
         printf("Enter total Processes : ");
         scanf("%d",&totalProcess);
         temp=totalProcess;
         for(i=0;i<totalProcess;i++){
            printf("\nEnter Arrival time and Burst Time for process %d (Comma Separated): ",i+1);
            scanf("%d,%d",&at[i],&bt[i]);
         }

         //Swapping if user has not entered arrival time in ascending order
        for(i=0;i<totalProcess;i++){
            for(j=i+1; j<totalProcess; j++){
                if(at[i] > at[j]){
                    c = at[i];
                    c1 = bt[i];
                    at[i] = at[j];
                    bt[i] = bt[j];
                    at[j] = c;
                    bt[j] = c1;
                }
            }
        }
        for(i=0;i<totalProcess;i++){
            rt[i]=bt[i];
        }
        sum_wait = at[0];
        printf("Enter time quantum: ");
       scanf("%d",&TQ);
       printf("\n\n\n\t\t\tAnswers\n\n");
       printf("\n\nProcess\t\t\tArrival Time\t\t\tBurst Time\t\tCompletion time\t\tTurnaround time\t\tWaiting time\n\n");
       for(time=0,i=0;temp!=0;){
            if(rt[i]<=TQ && rt[i]>0){
                time+=rt[i];
                rt[i]=0;
                t=1;
            }
            else if(rt[i]>0){
                rt[i]-=TQ;
                time+=TQ;
            }
            if(rt[i]==0 && t==1)
            {
                temp--;
                printf("P[%d]\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i+1,at[i],bt[i],time,time-at[i],time-at[i]-bt[i]);
                sum_wait+=time-at[i]-bt[i];
                sum_turnaround+=time-at[i];
                t=0;
            }
            if(i==totalProcess-1)
            i=0;
            else if(at[i+1]<=time)
            i++;
            else
                i=0;
        }
    printf("\nAvg Waiting Time = %f\n",sum_wait*1.0/totalProcess);
    printf("Avg Turn Around Time = %f",sum_turnaround*1.0/totalProcess);
    return 0;

}
