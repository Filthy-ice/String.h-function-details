#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//����Ŀ���ַ�����destָ��Ŀռ䡣
//	while (*dest++ = *src++)//����ԡ�ִ��ͬʱ���ý����Ϊѭ������ж���
//	{
//		;
//	}
//	//����ָ��ռ����ʼ��ַ��
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "ghi";
//	//��һ�δ���д��strcpy�����С�
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}