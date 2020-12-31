////统计二叉树中叶子结点个数
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}bitree;
bitree *root;
int creat(bitree *root)
{
	char ch;
	bitree *q[100],*s;
	int f=1,r=0,n,i;
	root=NULL;
	while((ch=getchar())!='#')
	{
		s=NULL;
		if(ch!='@')
		{
			s=(bitree*)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		r++;
		q[r]=s;
		if(r==1) root=s;
		else
		{
			if(s&&q[f])
			{
				if(r%2==0) q[f]->lchild=s;
				else q[f]->rchild=s;
			}
			if(r%2==1) f++;
		}
	}
	n=0;
	for(i=1;i<=r;i++)
	{
		if(q[i]!=NULL&&q[i]->lchild==NULL&&q[i]->rchild==NULL&&q[i]->data!='@')
		{
			printf("%c",q[i]->data);
			if(i!=r) printf(" ");
			n++;
		}
	}
	printf("\n");
	return n;
}
int main()
{
	int n;
	root=(bitree*)malloc(sizeof(bitree));
	n=creat(root);
	printf("%d",n);
	return 0;
}

