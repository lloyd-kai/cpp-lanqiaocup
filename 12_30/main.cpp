//这里主要用于导入其他的头文件，函数的实现主要在头文件中 
#include "Character.h"
#include "BiSearch.h"
#include "Sort.h"
#include "OtherFun.h"


//这里主要负责测试头文件定义的测试函数 
//请参考其他的头文件
int main()
{
	//测试大小写转化 
	//Test_Character();
	
	//测试二分法
	//Test_BiSearch() ;
	
	//测试bound
	//Test_bound(); 
	
	//测试排序函数
	//Test_Sort(); 
	
	//测试内存块初始化函数
	//Test_Memset(); 
	
	//测试反转
	//Test_Reverse(); 
	
	//测试去重函数
	//Test_Unique(); 
	
	//测试全排列函数 
	//Test_permutation();
	
	//测试最值函数
	//Test_TheValue(); 
	Test_nth();
	
	return 0;
}
