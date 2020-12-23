//问题 B: Problem E
/*
题目描述
请写一个程序，判断给定表达式中的括号是否匹配，
表达式中的合法括号为”(“, “)”, “[", "]“, “{“, ”}”,
这三个括号可以按照任意的次序嵌套使用。 
*/
#include<cstdio>
#include<string>
#include<stack>
#include<iostream>
using namespace std;
const int maxn=100;
stack<char> s;

int main()
{
    int m=10000;

    char str[maxn];
    string s1[10000];
    int ss=0;
    while(m--)
    {
        string str;
        cin>>str;
        if(str=="**0000**") {

            for (int j = 0; j <= ss - 1; ++j) {
                cout<<s1[j]<<endl;
            }
            return 0;
        }
        //	cout<<str<<" : ";
        while(!s.empty())//清空栈
        {
            s.pop();
        }
        bool flag=true;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='('||str[i]=='['||str[i]=='{')
            {
                s.push(str[i]);//左括号入栈
            }
            else if(str[i]==')')
            {
                if(!s.empty() && s.top()=='(')
                {
                    s.pop();//匹配则弹出
                }
                else
                {
                    flag=false;
                    break;
                }

            }
            else if(str[i]==']')
            {
                if(!s.empty() && s.top()=='[')
                {
                    s.pop();//匹配则弹出
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            else if(str[i]=='}')
            {
                if(!s.empty() && s.top()=='{')
                {
                    s.pop();//匹配则弹出
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
        {
           s1[ss++]="Match";
        }
        else
        {
            s1[ss++]="DisMatch";
        }

    }

    return 0;
}