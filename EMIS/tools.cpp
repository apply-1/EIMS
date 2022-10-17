#include "tools.h"

//	从键盘获取字符串
char* get_str(char* str,size_t len)
{
	if(NULL == str || len == 0)	return NULL;
	
	size_t index = 0;

	stdin->_IO_read_ptr = stdin->_IO_read_end;
	while(index < len-1)
	{
		char key_val = getch();
		if(key_val == 10)	break;
		if(key_val == 127)
		{
			if(index > 0)
			{
				index--;
				printf("\b \b");	//	显示退格效果
			}
			continue;
		}
		printf("%c",key_val);
		str[index++] = key_val;
	}
	str[index] = '\0';
	printf("\n");

	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	return str;
}


//	从键盘输入密码
char* get_pass(char* pass,size_t len,bool is_show)
{
	
	if(NULL == pass || len == 0)	return NULL;
	
	size_t index = 0;

	while(index < len-1)
	{
		char key_val = getch();
		if(key_val == 10)	break;
		if(key_val == 127)
		{
			if(index > 0)
			{
				index--;
				if(is_show)	printf("\b \b");	//	显示退格效果
			}
			continue;
		}
		if(is_show)	printf("*");
		pass[index++] = key_val;
	}
	pass[index] = '\0';
	printf("\n");

	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	return pass;
}

int get_cmd(char start,char end)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("请输入指令：");
	for(;;)
	{
		int cmd = getch();
		if(start <= cmd && end >= cmd)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	cout << "按任意键继续..." << endl;
	getch();
}

//	初始化id.dat文件
void init_id(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r");
	if(fp != NULL)	return;
	
	fp = fopen(DATA_ID_PATH,"w");
	int ids[3] = {1000,2000,3000};
	fwrite(ids,sizeof(ids),1,fp);
	fclose(fp);
}

//生成唯一的管理员id函数
int get_mgrid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		cout << "未调用init_id函数" << endl;
		return -1;
	}
	int id = 0;
	fseek(fp,0,SEEK_CUR);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}

//生成唯一的货架id函数
int get_shelfid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		cout << "未调用init_id函数" << endl;
		return -1;
	}
	int id = 0;
	fseek(fp,4,SEEK_CUR);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}

//生成唯一的快递id函数
int get_goodid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		cout << "未调用init_id函数" << endl;
		return -1;
	}
	int id = 0;
	fseek(fp,8,SEEK_CUR);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}
