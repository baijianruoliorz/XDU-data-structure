#include<stdio.h>
#include<string.h>
int main(void){
	int n;
	int i,j,k; 
	char stack[1000]; //定义括号栈 
	int flag[1000];  //0表示不匹配 1表示匹配 
	char array[1000][128];
	for(i=0;;i++){
		scanf("%s",&array[i]);
		if(strcmp(array[i],"**0000**")==0){
			break;
		}
		flag[i]=1; //初始化标记数组 
	}
	n=i;
	//判断括号是否匹配
	for(i=0;i<n;i++){
		k=0;
		int length = strlen(array[i]);
		for(j=0;j<length;j++){
			if(array[i][j]=='(' || array[i][j]=='{' || array[i][j]=='['){ // ({ [ 入栈 
				stack[k++] = array[i][j];
				stack[k]='\0';
			}else if(array[i][j]==')' || array[i][j]=='}' || array[i][j]==']'){ //出栈 
				if(k==0){
					flag[i] = 0;
				 	break;
				} 
				char temp = stack[--k]; //出栈取出元素
			 	if((array[i][j]==')' && temp!='(') || (array[i][j]=='}'&&temp!='{') || (array[i][j]==']'&&temp!='[')){//栈空 或类型不匹配 
			 		flag[i] = 0;
				 	break; 
			 	}
			}
		}
		//遍历完后 栈不为空 则不匹配 
		if(k!=0){
			flag[i]=0;
		} 
	}
	for(i=0;i<n;i++){
		if(flag[i]==0){
			printf("Mismatch\n");
		}else{
			printf("Match\n");
		}
	} 
	return 0;
}

