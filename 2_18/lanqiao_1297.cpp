//题目链接：https://www.lanqiao.cn/problems/1297/learning/?page=1&first_category_id=1&problem_id=1297 
//本题是裴蜀定理的模板题
//裴蜀定理:
//设a,b是不全为0的整数,则存在整数x,y使得ax+by=gcd(a,b)
//扩展裴蜀定理:
//a,b为不小于0的整数,n为整数,是否存在不小于0的x和y使得ax+by=n有解?
//1、若n>ab-a-b,有解
//2、若n=0,有解(x=y=0)
//3、若n<0,无解(a,b,x,y均不小于0,无法线性变换出负数)
//4、若ax+by=n有解,则ax+by=ab-a-b-n无解

//本题需要求解最小的ax+by=n,使得n>0
//设a和b的最大公约数为gcd(a,b),因为a,b,x,y均为整数,其线性组合同样是gcd(a,b)的倍数
//故ax+by=k*gcd(a,b) 
//令k=1,可得最小的ax+by=gcd(a,b) 
//故本题直接求解gcd(a,b)即可
//注意当ab异号时gcd(a,b)返回负数,需要取绝对值 
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)//求解a和b的最大公约数(可直接使用C++自带库函数__gcd(int,int)) 
{
    if(b==0)return a;
    return gcd(b,a%b);    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        cout<<abs(gcd(a,b))<<endl;//ab异号将返回负数,需要取绝对值 
    }
    return 0;
}
