#include<stdio.h>
#include<math.h>
int yuanma(int *a);
void PriArray(int array[],int x);
int main()
{
    int i,m,CF=1,Compare,sign;
    int a[32];
    int b[32];
    int c[32];
    int d[32];
    printf("input a int :\n");
    scanf("%d",&m);
    a[0]=0;
    for(i=1;i<32;i++)
        a[i]=pow(2,31-i);
    //把2的xx次方都存入a
    if(m>=0)
    {
        sign=0;
    }
    else
    {
        sign=1;
        m=-m;
    }
    b[0]=sign;
    for(i=1;i<32;i++)
    {
        if(m && m>=a[i])
        {
            b[i]=1;
            m-=a[i];
        }
        else
            b[i]=0;
    }
    //数组b为原码，MSB为符号
    c[0]=sign;
    for(i=1;i<32;i++)
        c[i]=1-b[i];
    //c为反码
    d[0]=sign;
    for(i=31;i>0;i--)
    {
        Compare=CF^c[i];
        CF=1-Compare;
        //进位符号和比特不一样下一个进位符号一定是0
        d[i]=Compare;
    }
    PriArray(b,32);
    PriArray(c,32);
    PriArray(d,32);
    return 0;
}
void PriArray(int array[],int x)
{
    int i;
    for(i=0;i<32;i++)
    {
        printf("%d",array[i]);
        if((i+1)%4==0)
            putchar(' ');
    }
    putchar('\n');
}
