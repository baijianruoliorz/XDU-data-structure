#include<stdio.h>

#include<string.h>

int main()

{
char a[1000],*p,*q,i;//定以变量及指针

gets(a);//输入字符串

i=strlen（a）-1;//字符串尾都有字符串结束符需要减去作为字符串a最后一个元素

p=&a[0];//指针p指向字符串元素的第一个

q=&a[i];//指针q指向字符串元素的最后一个

while（1）

{
if（*p！=*q）//取a[0]和a[i]的元素，若不相同直接跳出

break；

else//否则，若是相同在进行下一个元素的比较

{
p++;//后一个元素

q--;//前一个元素

}

}

if（p>=q）//如果进行了上面的操作后p的地址在q的地址前面的或相同的

printf("YES\n");//说明是对称字符串

else

printf("NO\n");//否则不是对称字符串

}