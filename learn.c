#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

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

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* S1 = NULL;
	char* S2 = NULL;
	char* mark = (char*)p1;
	if (!*p2)
	{
		return (char*)p1;
	}
	while (*mark)
	{
		S1 = mark;
		S2 = (char*)p2;
		while (*S1 && *S2 && (*S1 == *S2))
		{
			S1++, S2++;
		}
		if (!*S2)
		{
			return mark;
		}
		else
			mark++;
	}
	return NULL;
}

int main()
{
	const char* p1 = "abbcdef";
	const char* p2 = "bcd";
	//strstr 函数的返回值为 char* 类型
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("字符串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

