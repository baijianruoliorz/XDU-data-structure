#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
struct base{
    int x,y,dir;
};

    int d[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};    //���������Ⱥ��������ĸ������ң��£����� 
    deque<base> s;
    int a[102][102]={0};
    int m,n;  //��main�����ⶨ��a[100][100]��Ȼ�ڴ治�� 
    int startx,starty,endx,endy;
    base now;
    int flag=0; //flag=1��ʾ�Ѿ��ҵ��յ㣬����Ҫ����������֦�뷨 
    
void search(){
	if(now.x==endx&&now.y==endy){
		flag=1; return;
	}
	else{
		for(int i=1;i<=4;i++){
			if(a[now.x+d[i][0]][now.y+d[i][1]]==0){
				now.dir=i;
				s.push_back(now);					//���浱ǰλ�� 
				a[now.x+d[i][0]][now.y+d[i][1]]=1;
				now.x+=d[i][0];
				now.y+=d[i][1];
				search();							//������һ���� 
				if(flag==1)return;
				else{								//�����ϰ�����һ��
					 now=s.at(s.size()-1);
					 s.pop_back();					 
				}
			}
		}
	}
}

void print(base i){
	cout<<"("<<i.x<<","<<i.y<<","<<i.dir<<")"<<",";
}

int main(){
    cin>>m>>n;
    cin>>startx>>starty>>endx>>endy;
    for(int i=0;i<m+2;i++){					//���Թ���ΧΧ�ϱ߽� 
        for(int j=0;j<n+2;j++){
            if(i==0||i==m+1||j==0||j==n+1)a[i][j]=1;
        }
    }
    for(int i=1;i<=m;i++){					//��ȡ�Թ�Ԫ�� 
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    now={startx,starty,1}; 					//��ʼλ�� 
    search();

    if(s.empty()){
        cout<<"no";   //û���ѵ��������no 
    }else{
    	for_each(s.begin(),s.end(),print); 		//������� 
    	cout<<"("<<endx<<","<<endy<<","<<1<<")";
	}

}

