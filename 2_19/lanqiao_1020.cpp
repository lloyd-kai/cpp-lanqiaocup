//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1020/learning/?page=1&first_category_id=1 
#include <stdio.h>
#include <stdlib.h>
//����Լ����������1��100ÿ���������ҳ����ǵ�������
//��ͳ������1-100����������Ϊ���ӳ��ֵĴ�����ÿ����һ����˼��ɵó�Լ������
int main()
{
  // ���ڴ��������Ĵ���
 int prime[25] ={ 2,3, 5,7, 11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
 int num[25] = {0};
 int i,j,temp;
 long long count = 1;
 for(i = 2;i<=100;i++){
   temp = i;
   j = 0;//����100��������ͳ��100���ڵ�������Ϊ���ӳ��ֵĴ���
   while(temp > 1 && temp>=prime[j]){
   if(temp%prime[j]==0){
   temp/=prime[j];
   num[j]++;
   }
   else j++;
   }
 }
 for(i = 0;i<25;i++)
 if(num[i]>0) count*=(num[i]+1);
 printf("%lld",count);
 return 0;
}
