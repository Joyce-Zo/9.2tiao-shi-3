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
	printf("�����εĸ߶�Ϊ%d\n",Height);
	printf("�����볤��\n");
	scanf("%d",&m_long);
	printf("��������\n"); scanf("%d", &m_width);
	result = calculate(m_long, m_width); printf("�����ε������:");
	printf("%d \n", result); 
	return 0;
}

int calculate(int m_long, int width)
{
	int result =m_long* width * Height;
	return result;
}

#include <stdio.h>              //����Ԥ����ָ�� 
int main(void)                 //main�����ǳ������� 
{
	int num;                    //����return��main����֮��Ķ������ 
	num = 1;

	printf("���Ǹ��򵥵�����");
	printf("��ӭ��ʼѧC���ԡ�\n");
	printf("���е�һ������ʼ�ɡ�\n");
	return 0;
}
#include<stdlib.h>

int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	printf("%p\n", arr);
	printf("%p\n", &i);	// Debugʱ����С�����
						 Releaseʱ���������С���Ѿ��Ż�
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
 arr2��ԭ��ַ��ֻΪ�����ݲ�ϣ���䱻�޸ģ����Լ�const��ֹ�޸�/, ���5�����������޷�ͨ��
char* my_strcpy(char* arr1, const char* arr2)	// strcpy��������������Ϊchar*
{												
	while (*arr2!='\0')
	{
		*arr1 = *arr2;			// 1
		arr1++; 
		arr2++;
	}
	*arr1 = *arr2;	// ѭ������\0ֹͣ�������ͣ������\0Ҳcpy��ȥ
	 
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
	assert(arr2 != NULL); //���� - ���������׳����������������λ��
	while (*arr1++ = *arr2++)
	{
		;						// 5
	}
 
	��arr2ָ����ַ���������arr1ָ��Ŀռ䣬����'\0\�ַ�
	char* ret = arr1;	//  ����մ�������arr1
 	assert(arr1 != NULL);
	assert(arr2 != NULL); //���� - ���������׳����������������λ��
	while (*arr1++ = *arr2++)
	{						//  �޸�arr1
		;						// 6
	}
	return ret;			//  �����޸ĺ��arr1
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
	printf("%s\n", my_strcpy(arr1, arr2));	// ��ʽ����
	return 0;
}

int main()
{
	int a = 30;
	const int* p = &a;	// const�� * ���ʱ������*p�����Բ���ͨ��p���ı�*p��ֵ
						  ���� *p=12; ����p=&b
	int* const p = &a;   const�� * �ұ�ʱ������ָ�����p������p���ܱ��ı�
						  ���� *p=12,����p=&b
	int b = 20;
	*p = 100;
	p = &b;
	printf("%d ", a);
	return 0;
}

				strlen������ʵ��

int my_strlen(const char* arr)	// +constʹ�ַ��������ı�
{
	int count = 0;
	assert(arr != NULL);		// ���ԣ���֤��ȡ���ַ�����Ϊ��
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

	   ��  ��  ��  ��
  1. �����ʹ��� - �﷨���� - ƽ���ļ򵥴����ٸ�;��( �ȵ��ô�
  2. �����ʹ��� - ʹ�õķ���δ���� / ������ʹ��ʱд���
  3. ����ʱ���� - �������ԣ��𲽶�λ�����Ų�