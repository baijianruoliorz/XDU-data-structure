#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
struct edge{
int u,v; //系数和指数
};

int main(){
int m,n,t;
edge e1[9999],e2[9999],e3[9999],e4[9999];
int max1=0,max2=0,max=0;
cin>>n>>m>>t;
for(int i=0;i<n;i++)
{
cin>>e1[i].u>>e1[i].v;
if(max1<e1[i].v)
{
max1=e1[i].v;
}
}
for(int i=0;i<m;i++)
{
cin>>e2[i].u>>e2[i].v;
if(max2<e1[i].v)
{
max2=e1[i].v;
}
}
if(max1>max2) max=max1;
else max=max2;
//e3,e4初始化
for(int i=0;i<=max;i++){
e3[i].u=0;
e3[i].v=i;
e4[i].u=0;
e4[i].v=i;
}
for(int i=0;i<n;i++){
e3[e1[i].v].u=e1[i].u;

}
for(int i=0;i<m;i++){
e4[e2[i].v].u=e2[i].u;
}
if(t==0){
for(int i=0;i<=max;i++){
e1[i].u=e3[i].u+e4[i].u;
e1[i].v=e3[i].v;
}

}
if(t==1){
for(int i=0;i<=max;i++){
e1[i].u=e3[i].u-e4[i].u;
e1[i].v=e3[i].v;
}
}
int flag=1;

//输出时 细节的考虑
for(int i=0;i<=max;i++){
if(flag==1){
if(e1[i].u>0){

if(e1[i].u>=1&&e1[i].v!=0){
if(e1[i].v==1){
cout<<"x";
}
else
cout<<"x^"<<e1[i].v;

}
if(e1[i].u>=1&&e1[i].v==0){
cout<<e1[i].u;
}
flag=0;
}

}
else{

if(e1[i].u>0){
if(e1[i].u==1&&e1[i].v!=0){
if(e1[i].v==1){
cout<<"+x";
}
else
cout<<"+"<<"x^"<<e1[i].v;
}
if(e1[i].u==1&&e1[i].v==0){
cout<<"+"<<e1[i].u;
}
if(e1[i].u>1&&e1[i].v!=0){
if(e1[i].v==1){
cout<<"+"<<e1[i].u<<"x";
}
else
cout<<"+"<<e1[i].u<<"x^"<<e1[i].v;
}
if(e1[i].u>1&&e1[i].v==0){
cout<<"+"<<e1[i].u;
}
}

}

if(e1[i].u<0&&e1[i].v!=0)
{

if(e1[i].u!=-1)
{
if(e1[i].v==1){
cout<<e1[i].u<<"x";
}
else
cout<<e1[i].u<<"x^"<<e1[i].v;
}
if(e1[i].u==-1)
{
if(e1[i].v==1){
cout<<"-"<<"x";
}
else
cout<<"-"<<"x^"<<e1[i].v;
}
flag=0;
}
if(e1[i].u<0&&e1[i].v==0)
{
cout<<e1[i].u;
flag=0;
}
}
return 0;
}  