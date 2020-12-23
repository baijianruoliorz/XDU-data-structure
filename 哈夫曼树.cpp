#include<iostream>
#include<algorithm>
class huffuman
{
public:
	int isleaf;
	int sum;
	int data;
	huffuman(){
	    data=0;
	    sum=0;
	    isleaf=0;
	}
	~huffuman()
	{
	}
	void setData(int data){
	    this->data=data;
	}
	void setSum(int sum){
	    this->sum=sum;
	}
	huffuman operator+(const huffuman& hf1)
	{
		huffuman hfnew;
		hfnew.sum=hf1.sum+this->sum+hf1.data*hf1.isleaf+this->data*this->isleaf;
		hfnew.data=hf1.data+this->data;
		hfnew.isleaf=1;
		return hfnew;
	}
};
bool cmp(const huffuman& hf1,const huffuman& hf2)
{
	return hf1.data>hf2.data;
}
int main()
{
	int n;
	int data;
	std::cin>>n;
	huffuman* arr=new huffuman[n];
	for(int i=0;i<n;i++)
	{
		std::cin>>data;
		arr[i].setData(data);
		arr[i].setSum(data);
	}
	std::sort(arr,arr+n,cmp);
	for(int i=n-1;i>=1;i--)
	{
		arr[i-1]=arr[i]+arr[i-1];
		std::sort(arr,arr+i,cmp);
	}
	std::cout<<arr[0].sum;
	delete [] arr;
	return 0;
}
