#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

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

//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//strstr -- �ַ����������ҵ�ʵ��

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* S1 = NULL;
//	char* S2 = NULL;
//	char* mark = (char*)p1;
//	if (!*p2)
//	{
//		return (char*)p1;
//	}
//	while (*mark)
//	{
//		S1 = mark;
//		S2 = (char*)p2;
//		while (*S1 && *S2 && (*S1 == *S2))
//		{
//			S1++, S2++;
//		}
//		if (!*S2)
//		{
//			return mark;
//		}
//		else
//			mark++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	const char* p1 = "abbcdef";
//	const char* p2 = "bcd";
//	//strstr �����ķ���ֵΪ char* ����
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�ַ���������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("Open file successfully\n");
//	return 0;
//}


//int main()
//{
//	char arr = 'a';
//	int ret = islower(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//�ַ����ຯ�����ַ�ת��������ʹ�á�
//int main()
//{
//	char arr[] = "I am a SB.";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//			arr[i] = tolower(arr[i]);
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//typedef struct Student
//{
//	char name[20];
//	int age;
//}S;
//
//void* my_memcpy(void* str, const void* src, size_t sz)
//{
//	void* ret = str;
//	assert(str && src);
//	while (sz--)
//	{
//		*(char*)str = *(char*)src;
//		++(char*)str;
//		++(char*)src;
//	}
//	return ret;
//}
//
//int main()
//{
//	S S1[] = {{"����",20},{"����",30}};
//	S S2[2] = { 0 };
//	my_memcpy(S2, S1, sizeof(S1));
//	printf("%s\n", S2[0].name);
//	printf("%d\n", S2[0].age);
//	printf("%s\n", S2[1].name);
//	printf("%d\n", S2[1].age);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memcpy(arr + 2, arr, 20);
//
//	//C���Ա�׼��memcpyֻҪ��ʵ�ֲ��ص��������С�
//	//�ֵ���2022VSҲ������memcpyʵ���ص�������
//	//���������еı�������֧��
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = src;
	//��һ��д��
	if (dest < src)
	{
		//��ǰ���󿽱�
		//ʹ��my_memcpy�ķ����Ϳ���
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//�Ӻ���ǰ����
		//ע��Խ��
		while (count--)
		{
			//��Ϊ��ʱ������Ҫsrc�ڴ������һ���ֽڵĴ洢������Ӧ��ʹ��count-1������count�Ѿ�--�ˣ���˴�ʱcount�Ѿ��൱�����һλ�ˡ�
			*((char*)dest + count) = *((char*)src + count);

		}
	}
	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}