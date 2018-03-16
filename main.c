#include<stdio.h>
#include<string.h>

int mian(void)
{
	char buf[128]={0};
	FILE *fp=fopen("foo.txt","r");
	if(fp==NULL)
	{
	    printf("file doesn't exist!");
		return 1;
	}
	while(fread(buf,1,128,fp))
	{
	    printf("%s",buf);
		memset(buf,0,128);
	}
	fclose(fp);
	return 0;
}