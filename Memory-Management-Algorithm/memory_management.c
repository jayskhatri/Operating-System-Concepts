#include<stdio.h>
void bestfit(int *bSize,int tBlock, int*pSize, int tProcess){
    int i,j,allocation[tProcess], fit,flag[tBlock],ext=0,ext1=0,external_frag=0,internal_frag=0,total_internal=0;
    for(i=0;i<tProcess;i++){
        allocation[i]=-1;
    }
    for(i=0;i<tBlock;i++){
        flag[i]=0;
    }
    for(i=0; i<tProcess; i++){
        fit=-1;
        for(j=0; j<tBlock; j++){
            if(bSize[j]-pSize[i]>=0){
                   if(flag[j] == 0){
                       if(fit==-1){
                            fit = j;
                            //printf("\nif:: %d  will be allocated in :%d",pSize[i],bSize[fit]);
                            flag[fit]=1;
                       }
                        else if(bSize[fit]>bSize[j]){
                            flag[fit]=0;
                            //printf("\nif:: %d  will be allocated in :%d rather then %d",pSize[i],bSize[j],bSize[fit]);
                            fit = j;
                            flag[j]=1;
                        }
                   }
            }
        }
        if(fit!=-1){
            allocation[i] = fit;
            internal_frag=bSize[fit]-pSize[i];
            printf("\nRemaining Space : after allocating %d - %d = %5d", bSize[fit],pSize[i],internal_frag);
            bSize[fit] = internal_frag;
            total_internal +=internal_frag;
        }
    }
    //To check any process unallocated
    for(i=0;i<tProcess;i++){
        if(allocation[i]==-1){
                //printf("\nUnallocated Process: i %d",i);
            ext1+=pSize[i];
        }
    }
    //To check unallocated block
    for(i=0;i<tBlock;i++){
        if(flag[i]==0){
                //printf("\nUnallocated Block: i %d",i);
            ext += bSize[i];
        }
    }
    if(ext<=ext1){
        external_frag=ext;
    }
    else{
        external_frag = 0;
    }
    printf("\nProcess \tProcess Size\tBlock no.\n");
    for (i = 0; i < tProcess; i++)
    {
        printf("\n   %d\t\t%d\t\t", (i+1),pSize[i]);
        if (allocation[i] != -1)
            printf("%d",(allocation[i] + 1));
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("\n\tTotal Internal fragmentation: %d", total_internal);
    printf("\n\tTotal External fragmentation: %d", external_frag);
}

void firstfit(int *bSize,int tBlock, int*pSize, int tProcess){
    int i,j,allocation[tProcess],flag[tBlock],ext=0,ext1=0,external_frag=0,internal_frag=0,total_internal=0;;
    for(i=0;i<tProcess;i++){
        allocation[i]=-1;
    }
    for(i=0;i<tBlock;i++){
        flag[i]=0;
    }
    for(i=0; i<tProcess; i++){
        for(j=0; j<tBlock; j++){
            if(pSize[i]<= bSize[j]){
                if(flag[j]==0){
                    allocation[i] = j;
                    internal_frag=bSize[j]-pSize[i];
                    bSize[j]=internal_frag;
                    total_internal+=internal_frag;
                    flag[j]=1;
                    break;
                }

            }
        }
    }
    //To check any process unallocated
    for(i=0;i<tProcess;i++){
        if(allocation[i]==-1){
                //printf("\nUnallocated Process: i %d",i);
            ext1+=pSize[i];
        }
    }
    //To check unallocated block
    for(i=0;i<tBlock;i++){
        if(flag[i]==0){
                //printf("\nUnallocated Block: i %d",i);
            ext += bSize[i];
        }
    }
    if(ext<=ext1){
        external_frag=ext;
    }
    else{
        external_frag = 0;
    }
    printf("\nProcess \tProcess Size\tBlock no.\n");
    for (i = 0; i < tProcess; i++)
    {
        printf("\n   %d\t\t%d\t\t", (i+1),pSize[i]);
        if (allocation[i] != -1)
            printf("%d",(allocation[i] + 1));
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("\n\tTotal Internal fragmentation: %d", total_internal);
    printf("\n\tTotal External fragmentation: %d", external_frag);
}

void worstfit(int *bSize,int tBlock, int*pSize, int tProcess){
    int i,j,allocation[tProcess], fit,flag[tBlock],ext=0,ext1=0,external_frag=0,internal_frag=0,total_internal=0;
    for(i=0;i<tProcess;i++){
        allocation[i]=-1;
    }
    for(i=0;i<tBlock;i++){
        flag[i]=0;
    }
    for(i=0; i<tProcess; i++){
        fit=-1;
        for(j=0; j<tBlock; j++){
            if(bSize[j]-pSize[i]>=0){
                if(flag[j]==0){
                    if(fit==-1){
                        fit = j;
                        flag[fit]=1;
                    }
                    else if(bSize[fit]<bSize[j]){
                        flag[fit] = 0;
                        fit = j;
                        flag[j] = 1;
                    }
                }
            }
        }
        if(fit!=-1){
            allocation[i] = fit;
            internal_frag=bSize[fit]-pSize[i];
            //printf("\nRemaining Space : after allocating %d - %d = %5d", bSize[fit],pSize[i],internal_frag);
            bSize[fit] = internal_frag;
            total_internal +=internal_frag;
        }
    }
        //To check any process unallocated
    for(i=0;i<tProcess;i++){
        if(allocation[i]==-1){
                ext1+=pSize[i];
              //  printf("\nUnallocated process size: %d, ext1: %d",pSize[i],ext1);
        }
    }
    //To check unallocated block
    for(i=0;i<tBlock;i++){
        if(flag[i]==0){
            ext += bSize[i];
            //printf("\nUnallocated block size: %d, ext: %d",bSize[i],ext);
        }
    }
    if(ext>=ext1){
        external_frag=ext;
    }
    else{
        external_frag = 0;
    }
    printf("\nProcess \tProcess Size\tBlock no.\n");
    for (i = 0; i < tProcess; i++)
    {
        printf("\n   %d\t\t%d\t\t", (i+1),pSize[i]);
        if (allocation[i] != -1)
            printf("%d",(allocation[i] + 1));
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("\n\tTotal Internal fragmentation: %d", total_internal);
    printf("\n\tTotal External fragmentation: %d", external_frag);
}

int main(){
    int i,numBlock, numProcess, *bSize, *pSize,option;
    char c;
    do{
        printf("1. BestFit Algorithm\n2. FirstFit Algorithm\n3. WorstFit Algorithm\n4. Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\n\n\t\t\tBEST FIT\n\n");
                printf("\nEnter total blocks: ");
                scanf("%d", &numBlock);
                bSize = (int *) malloc(numBlock*sizeof(int));
                for(i=0;i<numBlock;i++){
                    printf("\nEnter %d's Block Size : ",(i+1));
                    scanf("%d", &bSize[i]);
                    //printf("\n%d's Block Size : %d",(i+1),bSize[i]); //
                }

                printf("\nEnter total blocks of process: ");
                scanf("%d", &numProcess);
                pSize = (int *) malloc(numProcess*sizeof(int));
                for(i=0;i<numProcess;i++){
                    printf("\nEnter %d's Process Size : ",(i+1));
                    scanf("%d", &pSize[i]);
                }
                printf("\n********************\n*BEST FIT ALGORITHM*\n********************");
                bestfit(bSize,numBlock,pSize,numProcess);
                break;
            case 2:
                printf("\n\n\t\t\tFIRST FIT\n\n");
                printf("\nEnter total blocks: ");
                scanf("%d", &numBlock);
                bSize = (int *) malloc(numBlock*sizeof(int));
                for(i=0;i<numBlock;i++){
                    printf("\nEnter %d's Block Size : ",(i+1));
                    scanf("%d", &bSize[i]);
                    //printf("\n%d's Block Size : %d",(i+1),bSize[i]); //
                }

                printf("\nEnter total blocks of process: ");
                scanf("%d", &numProcess);
                pSize = (int *) malloc(numProcess*sizeof(int));
                for(i=0;i<numProcess;i++){
                    printf("\nEnter %d's Process Size : ",(i+1));
                    scanf("%d", &pSize[i]);
                }
                printf("\n********************\n*FIRST FIT ALGORITHM*\n********************");
                firstfit(bSize,numBlock,pSize,numProcess);
                break;

            case 3:
                printf("\n\n\t\t\tWORST FIT\n\n");
                printf("\nEnter total blocks: ");
                scanf("%d", &numBlock);
                bSize = (int *) malloc(numBlock*sizeof(int));
                for(i=0;i<numBlock;i++){
                    printf("\nEnter %d's Block Size : ",(i+1));
                    scanf("%d", &bSize[i]);
                    //printf("\n%d's Block Size : %d",(i+1),bSize[i]); //
                }

                printf("\nEnter total blocks of process: ");
                scanf("%d", &numProcess);
                pSize = (int *) malloc(numProcess*sizeof(int));
                for(i=0;i<numProcess;i++){
                    printf("\nEnter %d's Process Size : ",(i+1));
                    scanf("%d", &pSize[i]);
                }
                printf("\n********************\n*WORST FIT ALGORITHM*\n********************");
                worstfit(bSize,numBlock,pSize,numProcess);
                break;

            case 4:
                exit(0);
            default:
                printf("Enter valid Choice.. Sorry\n");
                break;

        }
        printf("\nDo you want to continue?(Y/N): ");
        scanf("%c",&c);
    }while(c=='y' || c=='Y');
}
