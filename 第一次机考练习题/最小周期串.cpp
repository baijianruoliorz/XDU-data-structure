#include<stdio.h>
#include<string.h>
#define shu 80
int main()
{char a[shu];
    int n,j;
    scanf("%s",&a);
    n=strlen(a);
    for(int i=1;i<=n;i++)
    {if(n%i==0)
        {for(j=i;j<n;++j)
                if(a[j]!=a[j%i])
                    break;
            if(j==n)
            {printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}