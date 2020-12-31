//—∞’“next÷µ
#include<stdio.h>
int main(){
	int n,i=0,j;
	scanf("%d",&n);
	int next[10000];
	char T[10000],ch;
	while(i<n){
		scanf("%c",&ch);
		if(ch!=' '&&ch!='\n')
		{
			T[i]=ch;
			i++;
		}
	}
	T[i]='\0';
	i=0,j=-1;
	next[i]=j;
	while(i<n){
		if(j==-1||T[i]==T[j]){
			i++;
			j++;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",next[i]);
	}
	return 0;
} 
