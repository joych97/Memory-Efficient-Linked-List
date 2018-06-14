#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdint.h>

struct node
{
	int data;
	struct node *npx;
}*start=NULL,*current=NULL;

struct node* XOR(struct node*a,struct node*b)
{
	return (struct node*)((uintptr_t)a ^ (uintptr_t)b);   // uintptr_t is the datatype used for XORing the two nodes 
}

void insert(struct node**head,struct node**cur)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));


	printf("Enter the data");
	scanf("%d",&new->data);
	new->npx=XOR(*head,NULL);
	if(*head==NULL)
	{
		*head=new;
		*cur=new;
	}
	else
	{
		struct node*prev=XOR(NULL,(*cur)->npx);
		(*cur)->npx=XOR(new,prev);
		new->npx=XOR(NULL,*cur);
		*cur=new;
	
	}
	

}

void traverse(struct node*head)
{
	struct node*curr=head;
	struct node*pre=NULL;
	struct node*next;
	while(curr!=NULL)
	{
		printf("%d ->",curr->data);
		next=XOR(pre,curr->npx);
		pre=curr;
		curr=next;
	}
	printf("End");
}


int main()
{
	char ch;
	int d;
	do{
		printf("Enter the choice \n");
		printf("1.want to enter\n");
		printf("2.want to traverse\n");
		scanf("%d",&d);
		if(d==1)
			insert(&start,&current);
		else if(d==2)
			{
				printf("Printing in forward direction \n");
				traverse(start);
				printf("\n");
				printf("Printing in backward direction \n");
				traverse(current);
				printf("\n");
				
			}
		printf("wanna do more Press y/n ...\n");
		scanf("\n%c",&ch);
	}while(ch!='n');
	
	
	

}
