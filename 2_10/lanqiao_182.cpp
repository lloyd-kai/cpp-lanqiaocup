//��Ŀ���ӣ�https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182 
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N = 1e5+9;//����������

//n��ͼ�еĽڵ�����a[]�洢ÿ���ڵ�ָ�����һ���ڵ㣬��dfn�Ǽ�¼�ڵ㱻���ʵ�˳��
//idx�����ɵ�ʱ���(�ڵ㱻���ʵ�˳��)����ʾ��ǰ���ʵ��ڼ����ڵ�
//mindfn��¼��ǰ������Сʱ��� 
int n,a[N],dfn[N],idx,mindfn;

int dfs(int x)
{
	dfn[x] = ++idx;//��ǰ�ڵ㸳��ʱ��� 
	
	if(dfn[a[x]]) //����ڵ��ѱ����� 
	{
		if(dfn[a[x]]>=mindfn)// ʱ�����С�ڵ�ǰ������Сʱ��� mindfn,���ɻ� 
		{
			return dfn[x]-dfn[a[x]]+1;//���ػ��ĳ��� 
		}
	}
	
	return dfs(a[x]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
    	cin>>a[i];
	}
	
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		if(!dfn[i])//���ʱ���û�б����� 
		{
			mindfn = idx+1;
			ans = max(ans,dfs(i));
		} 
	}
    
    cout<<ans<<"\n";
    return 0;
} 
