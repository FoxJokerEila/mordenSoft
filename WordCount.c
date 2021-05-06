#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
void main(int argc, char *input[])
{
	char file[100] = "C:\\Users\\ASUS\\Desktop\\201931061043\\info.txt";
	char cup[MAX];

	int letter = 0;
	int word = 0;

	int l = 0;
	
	FILE *fp;

	// 打开文件
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
	}

	// 计数
	while (!feof(fp))
	{
		if (fgets(cup, MAX, fp) != NULL)
		{
			l = strlen(cup);
			letter += l;
			word++;
			for (int i = 0; i < l - 1; i++)
			{
				if (cup[i] == ' ')
				{
					word++;
				}
			}
		}
	}
	// 判断参数决定输出
	if (!strcmp(input[1], "-w"))
	{
		printf("单词数：%d\n", word);
	}
	if (!strcmp(input[1], "-c"))
	{
		printf("字符数：%d\n", letter);
	}
	// 关闭文件
	fclose(fp);
}
