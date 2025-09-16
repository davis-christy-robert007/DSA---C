#include<stdio.h>
int FRONT=-1,REAR=-1;

void enqueue(int Q[], int SIZE, int ITEM){
    if(REAR==SIZE-1){
        printf("Overflow!\n");
        return;
    }
    else{
        if(FRONT==-1){
           FRONT=0;
        }
        REAR++;
        Q[REAR]=ITEM;
        printf("Inserted %d\n",ITEM);
    }
}

void dequeue(int Q[],int ITEM){
    if(FRONT==-1 || FRONT>REAR){
        printf("Underflow!\n");
    }
    else{
        ITEM=Q[FRONT];
        FRONT++;
        printf("Deleted %d\n",ITEM);
        if(FRONT>REAR){
            FRONT=REAR=-1;
        }
    }
}

int main(){
    int i,SIZE,ITEM,ch;
    SIZE=100;   
    int Q[SIZE];

    while(1){
        printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if (ch==1){
            printf("Enter value to insert: ");
            scanf("%d",&ITEM);
            enqueue(Q,SIZE,ITEM);
        }
        else if (ch==2){
            dequeue(Q,ITEM);
        }
        else if(ch==3){
            if(FRONT==-1 || FRONT>REAR){
                printf("Empty queue!\n");
            }
            else{
                printf("Queue elements: ");
                for(i=FRONT;i<=REAR;i++){   
                    printf("%d\t",Q[i]);
                }
                printf("\n");
            }
        }
        else{ 
            if(ch==4){
                printf("Exiting..\n");
            }
            break;
        }    
    }
    return 0;
}
