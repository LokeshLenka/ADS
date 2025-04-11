#include <stdio.h>
#include <stdlib.h>

void max_adjust(int);
void swap(int* ,int*);
void create();
void printlist();

int a[20],n;

int main(){

    int ch,x,i;

    create();
    printlist();

    while(true){

        printf("\n --------------------MENU--------------------");
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit");
        
        printf("Enter Your Choice");
        scanf("%d",&ch);

        switch (ch){

            case 1: n++;
                    printf("\n Enter the elements to be insert:");
                    scanf("%d",&a[n]);

                    for (int i = n/2; i >= 1; i--){
                        max_adjust(i);
                    }
                    
                    printlist();
                    break;
                    
            case 2: swap(&a[1],&a[n]);
            		x = a[n];
            		n--;
            		max_adjust(1);
            		
					printf("\nDeleted number is : %d",x);
            		printlist();
            		break;
        	
			case 3: printlist();
        			break;
        	
			case 4: exit(0);		
		
			default:
        		    break;
        }
    }
}


void create(){

    int i;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);

    printf("\nEnter the elements:\n");

    for (int i = 1; i <= n; i++){
    	scanf("%d",&a[i]);
	}
	
	for(i = n/2;i >= 1;i--){
        max_adjust(i);
    }

//	printf("Elememts Inserted");
}

void max_adjust(int i){

    int child,temp;

    for(temp = a[i];(2*i) <= n; i = child){

        child = 2*i;

        if((child < n) && (a[child+1] > a[child]))
            child++;

       if(temp < a[child])
            a[i] = a[child];

        else
            break;
    }

    a[i] = temp;

}

void swap(int *p,int *q){

    int t;

    t = *p;
    *p = *q;
    *q = t;

}

void printlist(){

    int i;

    printf("\nElements in MAX-HEAP\n");
    for(int i = 1; i <= n; i++){
        printf("%d\t",a[i]);
    }
}
