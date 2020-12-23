#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node{
int id;
int token;
Node* next;
}Node,*pointer;
void RemoveNextNode(Node* p)
{	Node* q=p->next;
p->next=p->next->next;		
	free(q);
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	pointer head=(pointer)malloc(sizeof(Node));
	head->id=1;
	head->next=NULL;
	cin>>head->token; 
	pointer rear=head;
	for(int i=0;i<n-1;i++)
	{
		pointer p=(pointer)malloc(sizeof(Node));
		p->id=i+2;
		cin>>p->token;
		rear->next=p;
		rear=p;
	}
	rear->next=head;
	pointer ptr=rear;
	while(ptr->next!=ptr)
	{ 
		for(int i=0;i<m-1;i++)
		{
			ptr=ptr->next;	
		}
		cout<<ptr->next->id<<" ";
		m=ptr->next->token;
		RemoveNextNode(ptr);
	} 
	cout<<ptr->id;
	return 0;
}
