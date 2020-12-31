//哈夫曼树
#include<stdio.h>
void fun(int *array,int len){
	int i,j,temp;
	for(i=1;i<len;i++){
		for(j=i;j>0&&array[j]>array[j-1];j--){
			temp=array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
		}
	}
} 
int main(){
	int n;
	int i,top,result;
	scanf("%d",&n);
	int stack[10000];
	top=n;
	for(i=0;i<n;i++){
		scanf("%d",&stack[i]);
	}
	fun(stack,top);
	result=0;
	while(top>1){
		result+=stack[top-1]+stack[top-2];//计算带权路径 
		stack[top-2]=stack[top-1]+stack[top-2];
		top--;
		fun(stack,top);
	}
	printf("%d",result);
	return 0;
}
 
