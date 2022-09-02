#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdio.h>
#define Height 10
int calculate(int m_long, int width); 

int main()
{
	int m_long; 
	int m_width; 
	int result;
	printf("长方形的高度为%d\n",Height);
	printf("请输入长度\n");
	scanf("%d",&m_long);
	printf("请输入宽度\n"); scanf("%d", &m_width);
	result = calculate(m_long, m_width); printf("长方形的体积是:");
	printf("%d \n", result); 
	return 0;
}

int calculate(int m_long, int width)
{
	int result =m_long* width * Height;
	return result;
}

#include <stdio.h>              //这是预处理指令 
int main(void)                 //main函数是程序的入口 
{
	int num;                    //介于return与main函数之间的都是语句 
	num = 1;

	printf("我是个简单的人呢");
	printf("欢迎开始学C语言。\n");
	printf("就有第一个程序开始吧。\n");
	return 0;
}
#include<stdlib.h>

int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	printf("%p\n", arr);
	printf("%p\n", &i);	// Debug时上面小下面大
						 Release时上面大下面小，已经优化
	system("pause");
	for (i = 0; i <= 12; i++)
	{
		printf("hello!\n");
		arr[i] = 0;
	}
	return 0;
}
#include <string.h>
#include<assert.h>
void my_strcpy(char* arr1, char* arr2)
void my_strcpy(char* arr1, const char* arr2)
 arr2是原地址，只为传内容不希望其被修改，所以加const防止修改/, 结合5，有问题则无法通过
char* my_strcpy(char* arr1, const char* arr2)	// strcpy函数本身返回类型为char*
{												
	while (*arr2!='\0')
	{
		*arr1 = *arr2;			// 1
		arr1++; 
		arr2++;
	}
	*arr1 = *arr2;	// 循环遇到\0停止，这里把停下来的\0也cpy过去
	 
	 	//if(*arr2!='\0')
	{ 
		*arr1 = *arr2;			// 2
		my_strcpy(arr1 + 1, arr2 + 1);
	}
	*arr1 = *arr2;

	while (*arr1++ = *arr2++)
	{
		;						// 3 
	}

	if(arr1!=NULL && arr2!=NULL)
		while (*arr1++ = *arr2++)
		{						
			;					// 4
		}

	assert(arr1 != NULL);
	assert(arr2 != NULL); //断言 - 遇到问题抛出，告诉我们问题的位置
	while (*arr1++ = *arr2++)
	{
		;						// 5
	}
 
	把arr2指向的字符串拷贝到arr1指向的空间，包含'\0\字符
	char* ret = arr1;	//  保存刚传过来的arr1
 	assert(arr1 != NULL);
	assert(arr2 != NULL); //断言 - 遇到问题抛出，告诉我们问题的位置
	while (*arr1++ = *arr2++)
	{						//  修改arr1
		;						// 6
	}
	return ret;			//  返回修改后的arr1
}
}

int main()
{
	char arr1[] = "#################";
	char arr2[] = "Hello";
	strcpy(arr1, arr2);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", my_strcpy(arr1, arr2));	// 链式访问
	return 0;
}

int main()
{
	int a = 30;
	const int* p = &a;	// const在 * 左边时，修饰*p，所以不能通过p来改变*p的值
						  不能 *p=12; 可以p=&b
	int* const p = &a;   const在 * 右边时，修饰指针变量p本身，则p不能被改变
						  可以 *p=12,不能p=&b
	int b = 20;
	*p = 100;
	p = &b;
	printf("%d ", a);
	return 0;
}

				strlen的完美实现

int my_strlen(const char* arr)	// +const使字符串不被改变
{
	int count = 0;
	assert(arr != NULL);		// 断言，保证获取的字符串不为空
	while (*arr++ != '\0')
	{
		count++;
		  arr++;
	}
	return count;
}
int main()
{
	char arr[] = "Do you love me?+";
	int len = my_strlen(arr);
	printf("%d ", len);
	return 0;
}

	   错  误  类  型
  1. 编译型错误 - 语法错误 - 平常的简单错误：少个;，( 等的用错
  2. 链接型错误 - 使用的符号未定义 / 定义了使用时写错等
  3. 运行时错误 - 借助调试，逐步定位错误并排查