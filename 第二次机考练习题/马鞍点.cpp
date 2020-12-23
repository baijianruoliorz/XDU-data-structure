//若矩阵中的某个元素是第i行中的最小值，同时又是第j列中的最大值，
//则称此元素为该矩阵中的一个马鞍点。编写程序求出矩阵中的所有马鞍点。
//首先输入两个整数n和m，为矩阵维数，然后输入矩阵的值。
//输出矩阵中的所有马鞍点，输出顺序：行序优先，按行、列序号递增顺序输出。
//    ，若有多个马鞍点，每个马鞍点一行。也可能没有马鞍点，则输出NO。
#include<stdio.h>

typedef struct{
	int r;
	int c;
	int data;
}MaAnPoint;
MaAnPoint Ma[1000];
int b;		//名字起得不太规范，作用是为了记录 马鞍点的个数
int a[1000][1000];
int row,col;	//行，列
//分析:马鞍点最多有max(m,n)个 ，一个马鞍点有三个信息，第一 行，第二 序，第三值
//这样，由于题目要求若有多个马鞍点，则要按照行来。
//第一行，找到该行中最小的，然后看这个值在其所在列是不是最大的。如果也是，就存到一个数组里。
void Input();
void Search();
void Output();
int main()
{
	Input();
	Search();
	Output();
}
void Input()
{
	scanf("%d%d",&row,&col);
	for(int i = 1; i <= row ; i++)
	{
		for(int j = 1 ; j <= col ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void Search(){
	int min,flag=1;
	b=1;
	int t1,t2;
	for(int i=1 ;i<=row ;i++)	//行
	{
		min = a[i][1];t1 = i;t2=1;			//找每行的最小的 ，储存行，列，值信息
		for(int j=1 ;j<=col ;j++){
			if(min >a[i][j])
			{
				t1 = i;t2 = j; min = a[i][j];
			}
		}
		//找到行里最小的之后，判断它是不是列里最大的
		for(int k = 1; k<=row ;k++)
		{
			if( min <a[k][t2] ) 	//不是列里最大的 ,那就标记这个点不存入Ma数组里面，并且跳出
			{
				flag = 0;break;
			}
		}
		if(flag == 0){
			flag =1;
		}else{
			Ma[b].r = t1;Ma[b].c = t2,Ma[b].data = min;	b++;
		}

	 }
}
void Output()
{
	if(b==1) printf("NO\n");
	else{
		for(int i=1;i<b;i++)
		{
			printf("%d %d %d\n",Ma[i].r,Ma[i].c,Ma[i].data);
		}
	}

}




