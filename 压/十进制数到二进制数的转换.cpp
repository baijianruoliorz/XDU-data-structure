#include<stdio.h>
void conversion(int m){
	if(m==0){
	}else{
		conversion(m/2);
		printf("%d",m%2);
	}
}
int main(){
	int m,n,q;
	scanf("%d%d%d",&m,&n,&q);
	if(m){
		conversion(m);
		printf(" ");
	}else{
		printf("%d ",m);
	}if(n){
		conversion(n);
		printf(" ");
	}else{
		printf("%d ",n);
	}if(q){
		conversion(q);
	}else{
		printf("%d ",q);
	}
	
	return 0;
}
