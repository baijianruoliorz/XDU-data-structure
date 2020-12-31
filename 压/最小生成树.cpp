//最小生成树
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
#define MaxEdgeNum 100
typedef int VertexType;//顶点的数据类型
typedef int EdgeType;//权的数据类型
int fat[MaxVertexNum];
typedef struct{
	VertexType Vex[MaxVertexNum];//顶点表 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵,边表
	int vexnum,edgenum;//图的顶点数,边数 
}MGraph;
typedef struct{
	int vex1,vex2;
	int w;
}kedge;
void create_Graph(MGraph *G,int n,int m){
	int v1,v2,w;
	G->vexnum=n;
	G->edgenum=m;
	//初始化邻接矩阵
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			G->Edge[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v1,&v2,&w);
		G->Edge[v1-1][v2-1]=w;
		G->Edge[v2-1][v1-1]=w;
	}
}
void kruskal(MGraph *G){	/*克鲁斯卡尔算法-邻接矩阵*/
	int tag[MaxVertexNum];
	kedge Ke[MaxEdgeNum];	/*用来存放读取到的所有边*/ 
	int i,j;
	int length=0;
	int n=0;	//n表示ke[]中的边数 
	for(i=0;i<G->vexnum;i++)	
		tag[i]=i;	/*初始化tag标签数组*/
	for(i=0;i<G->vexnum;i++)
		for(j=i+1;j<G->vexnum;j++)
		if(G->Edge[i][j]!=0){		/*导入边表*/
			Ke[n].vex1=i;
			Ke[n].vex2=j;
			Ke[n++].w=G->Edge[i][j];
		}
		kedge temp;
		for(i=0;i<n-1;i++)		/*冒泡将边的集合按权值递增排序*/
			for(j=0;j<n-i-1;j++)
				if(Ke[j].w>Ke[j+1].w){
					temp=Ke[j+1];
					Ke[j+1]=Ke[j];
					Ke[j]=temp;
					}
		for(i=0;i<n;i++){	/*选则最短边*/ 
			int first,second;
			first = tag[Ke[i].vex1];	/*first表示当前边的第一个结点的标记集合*/ 
			second = tag[Ke[i].vex2];	/*second表示当前边的第二个结点的标记集合*/
			if(first!=second){
				length+=Ke[i].w;		/*计算最小生成树的总权值*/ 
				printf("%d %d %d\n",Ke[i].vex1+1,Ke[i].vex2+1,Ke[i].w); 
				tag[Ke[i].vex2]=first;		/*将该边纳入集合*/
				for(j=0;j<G->vexnum;j++){			/*两个集合统一编号*/
					if(second==tag[j])
					tag[j]=first;
				}
			}
		}
}
void Print(MGraph *G){
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			printf("%d ",G->Edge[i][j]);
		}
	//	printf("\n");
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	MGraph *G;
	G=(MGraph*)malloc(sizeof(MGraph));
	create_Graph(G,n,m);
//	sort(G);
//	Print(G);
	kruskal(G);
	return 0; 
} 
