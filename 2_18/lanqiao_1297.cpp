//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1297/learning/?page=1&first_category_id=1&problem_id=1297 
//�������������ģ����
//������:
//��a,b�ǲ�ȫΪ0������,���������x,yʹ��ax+by=gcd(a,b)
//��չ������:
//a,bΪ��С��0������,nΪ����,�Ƿ���ڲ�С��0��x��yʹ��ax+by=n�н�?
//1����n>ab-a-b,�н�
//2����n=0,�н�(x=y=0)
//3����n<0,�޽�(a,b,x,y����С��0,�޷����Ա任������)
//4����ax+by=n�н�,��ax+by=ab-a-b-n�޽�

//������Ҫ�����С��ax+by=n,ʹ��n>0
//��a��b�����Լ��Ϊgcd(a,b),��Ϊa,b,x,y��Ϊ����,���������ͬ����gcd(a,b)�ı���
//��ax+by=k*gcd(a,b) 
//��k=1,�ɵ���С��ax+by=gcd(a,b) 
//�ʱ���ֱ�����gcd(a,b)����
//ע�⵱ab���ʱgcd(a,b)���ظ���,��Ҫȡ����ֵ 
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)//���a��b�����Լ��(��ֱ��ʹ��C++�Դ��⺯��__gcd(int,int)) 
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
        cout<<abs(gcd(a,b))<<endl;//ab��Ž����ظ���,��Ҫȡ����ֵ 
    }
    return 0;
}
