#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	char buf[2048]={0};
	FILE *fp=NULL;
	FILE *fpw=NULL;
	long length=0;

	if(argc!=3)
	{
		printf("argc error!");
		exit(1);
	}
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("file open error!");
		exit(1);
	}
	fpw=fopen(argv[2],"w");
	if(fpw==NULL)
	{
		printf("create file error!");
		exit(1);
	}
	fseek(fp,0,SEEK_END);
 	length=ftell(fp);
	fseek(fp,0,SEEK_SET);
	fread(buf,length,1,fp);
	fwrite(buf,length,1,fpw);
	fclose(fp);
	fclose(fpw);
	return 0;
} 	