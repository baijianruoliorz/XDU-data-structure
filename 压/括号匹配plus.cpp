#include<stdio.h>
#include<string.h>
int main(void){
	int n;
	int i,j,k; 
	char stack[1000]; //��������ջ 
	int flag[1000];  //0��ʾ��ƥ�� 1��ʾƥ�� 
	char array[1000][128];
	for(i=0;;i++){
		scanf("%s",&array[i]);
		if(strcmp(array[i],"**0000**")==0){
			break;
		}
		flag[i]=1; //��ʼ��������� 
	}
	n=i;
	//�ж������Ƿ�ƥ��
	for(i=0;i<n;i++){
		k=0;
		int length = strlen(array[i]);
		for(j=0;j<length;j++){
			if(array[i][j]=='(' || array[i][j]=='{' || array[i][j]=='['){ // ({ [ ��ջ 
				stack[k++] = array[i][j];
				stack[k]='\0';
			}else if(array[i][j]==')' || array[i][j]=='}' || array[i][j]==']'){ //��ջ 
				if(k==0){
					flag[i] = 0;
				 	break;
				} 
				char temp = stack[--k]; //��ջȡ��Ԫ��
			 	if((array[i][j]==')' && temp!='(') || (array[i][j]=='}'&&temp!='{') || (array[i][j]==']'&&temp!='[')){//ջ�� �����Ͳ�ƥ�� 
			 		flag[i] = 0;
				 	break; 
			 	}
			}
		}
		//������� ջ��Ϊ�� ��ƥ�� 
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

