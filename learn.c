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
//	//拷贝目标字符串到dest指向的空间。
//	while (*dest++ = *src++)//妙不可言。执行同时利用结果作为循环体的判定。
//	{
//		;
//	}
//	//返回指向空间的起始地址。
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "ghi";
//	//用一段代码写出strcpy的运行。
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


//strstr -- 字符串函数查找的实现

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
//	//strstr 函数的返回值为 char* 类型
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("字符串不存在\n");
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

//字符分类函数和字符转换函数的使用。
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
//	S S1[] = {{"张三",20},{"李四",30}};
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
//	//C语言标准：memcpy只要能实现不重叠拷贝就行。
//	//怪的是2022VS也可以用memcpy实现重叠拷贝。
//	//但不是所有的编译器都支持
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
	//第一种写法
	if (dest < src)
	{
		//从前往后拷贝
		//使用my_memcpy的方法就可以
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//从后往前拷贝
		//注意越界
		while (count--)
		{
			//因为此时我们需要src内存中最后一个字节的存储，所以应该使用count-1，但是count已经--了，因此此时count已经相当于最后一位了。
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