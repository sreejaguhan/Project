/* SREEJA GUHAN - MINI PROJECT */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "reverse.c"
#include "fact.c"

typedef struct Node
{
	int val;
	struct Node *next;
}node;


/*------------FUNCTIONS USED-----------------*/
void add_ele(node **, int);
void disp_sll(node *);
int fibo(int);
int sum_dig(int);
void patterns(int);
void sll_rev(node**);
int prime(int ); 
void del_node(node**, node*);
void del_prime(node**); 

 
int r1,*r2;
	node *head = NULL;

/*-----------------------------------------------MAIN BEGINS----------------------------------------*/
int main()
{
	int n,x,fib,i,c=0,sum,j,sll_val[10]={2,5,1,3,4,6,7,8,9,2};
		printf("Enter a number:\n");
		scanf("%d",&n);
		r1=fact(n);
		printf("Factorial = %d\n",r1);
		r2 = reverse(r1);
		printf("Reverse is %d\n",*r2);
		x = *r2;
		printf("%d is x\n",x);
	 

	if(x<r1)
	{
		for (i = 1; i <= x; i++)
		{
			printf("%d\n", fibo(c));
			c++;
		}
	}
		else if(x>r1)
		{
		sum=sum_dig(r1);
		printf("%d is the sum of digits\n",sum);
		}
	 
	else if(x==r1)
	{
		for(j=0;j<10;j++)
		{
			add_ele(&head,sll_val[j]);
		}
		printf("Displaying the SLL..\n\n");
		disp_sll(head);
if(x%2==0)
{
printf("R2 is even. Hence, deleting prime numbers from the linked list..\n");
del_prime(&head);
}
else
{
printf("R2 is odd. Hence, reversing the linked list..\n");
sll_rev(&head);
}

	}

	float arr[2][5] ={ {1.6,2.8,8,-34,10} , {5,5,5,5,5}};
	int m,l;
	printf("Displaying the 2x5 matrix..\n\n");
	for(m=0;m<2;m++)
	{
		for(l=0;l<5;l++)
		{
			printf("%lf ",arr[m][l]);
		}
		printf("\n");
	}

	printf("*******MATRIX CALCULATIONS*******\n");
	for(m=0;m<2;m++)
	{
		for(l=0;l<5;l++)
		{
			if(m==0)
			{
				switch(l)
				{
					case 0: printf("\tFloor = %f\n",floor(arr[m][l]));

						break;
					case 1: printf("\tCeiling = %f\n",ceil(arr[m][l]));
						break;
					case 2: printf("\tPower = %f\n", pow(arr[m][l],3));
						break;
					case 3: printf("\tAbsolute = %f\n",abs(arr[m][l]));
						break;
					case 4: printf("\tLog = %f\n",log10(arr[m][l]));
						break;
				}
			}
		}
	}

	patterns(arr[1][0]);

}


/* -------------------------------------------END OF MAIN--------------------------------------------------*/


/*------------------FUNCTION DEFINITIONS--------------------------*/
int fibo(int a)
{
	if (a == 0 || a == 1)
		return a;
	else
		return (fibo(a-1) + fibo(a-2));
}


int sum_dig(int b)
{
	int sum=0,x;
	while(b)
	{
		x=b%10;
		sum=sum+x;
		b=b/10;
	}
	return sum;
}
void add_ele(node **head, int val)
{
	node*new = NULL;
	node*end = NULL;

	new = (node*)malloc(sizeof(node));

	if(new == NULL)
	{
		printf("Node not created!\n");
		return;
	}
	new->val = val;
	new->next = NULL;

	if(*head == NULL)
	{
		*head = new;
		return;
	}


	end = *head;
	while(end->next) 
		end = end->next;

	end->next = new;
}

void disp_sll(node *head)
{
	while(head)
	{
		printf("%d ",head->val);
		head = head->next;
	}
	printf("\n");
}

/*--------------------------------PATTERNS----------------------------------------*/
void patterns(int p)
{
	printf("*******PRINTING PATTERNS*******\n\n");
	int i,j,s,a;
	printf("Pattern 1:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<p;j++)
		{
			if(i==j)
				printf("0 ");
			else printf("%d ",i+1);
		}
		printf("\n");
	}
	printf("\n");
	printf("Pattern 2:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i==j || (i%2 && j%2)||(i%2==0 && j%2==0))
				printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
	printf("Pattern 3:\n");
	for (i=1;i<=p;i++) {
		for (j=1;j<=i;j++) {
			printf("%d ",i*j);
		}
		printf("\n");
	}
	printf("\n");
	printf("Pattern 4:\n");
	for(a=1;a<=p;a++)
	{
		for(i=p;i>a;i--)
		{
			printf(" ");
		}
		for(j=a;j>=1;j--)
		{
			printf("%d", j);
		}
		printf("\n");
	}
	printf("\n");
	printf("Pattern 5:\n");
	for(a=1;a<=p;a++)
	{
		for(i=p;i>a;i--)
		{
			printf(" ");
		}
		for(j=a;j>=1;j--)
		{
			printf("* ");
		}
		printf("\n");
	}
	s=1;
	for ( i=p-1;i>0;i--)  
	{  

		for (j=0;j<s;j++)  
			printf(" ");  

		for (j=0;j<i;j++)  
			printf("* ");

		printf("\n"); 
		s++;  
	}  
	printf("\n");
}

void sll_rev(node **head)
{

		printf("Reversed Linked List..\n");
		node*prev=NULL;
		node*now=*head;
		node*next=NULL;
		while(now!=NULL)
		{
			next=now->next;
			now->next=prev;

			prev=now;
			now=next;
		}
		*head=prev;
disp_sll(*head);
}

void del_prime(node** head) 
		{ 
			node* ptr = *head; 
			node* next; 

			while (ptr != NULL) 
			{ 
				next = ptr->next;  
				if (prime(ptr->val))
					del_node(head, ptr); 
				ptr = next; 
			}
disp_sll(*head);
		} 

int prime(int n) 
{ 
	if (n==1 || n==0)
		return 0;
	else
	{
		int i;
		for(i=2;i<=(n/2);i++)
		{
			if(n%i==0)
				return 0;
			else continue;
		} 
		if(i>(n/2))
			return 1;
		else return 0;
	}
}



void del_node(node** h, node* del) 
{  
    node* temp = *h; 
    if (*h == NULL) 
        return; 
     
    if (*h == del) 
{
        (*h) = (*h)->next; 
    temp->next = del->next; 
    free(del);  
    return;  
 }    
    while (temp->next != del) { 
        temp = temp->next; 
    } 
    temp->next = del->next; 
    free(del);  
    return;  
}

/*----------------------------------END OF FUNCTION DEFINITIONS---------------------`-----------*/
