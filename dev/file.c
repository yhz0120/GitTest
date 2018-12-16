#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(){
	int fd=open("../readme.txt",O_RDWR);
	if(fd==-1){
		perror("open");
		return -1;
	}
	if(-1==write(fd,"多用户操作！！！",20)){
		perror("write");
		return -1;
	}

	char buf[512]={0};	
	if(-1==read(fd,buf,sizeof(buf))){
		perror("read");
		return -1;
	}
	close(fd);
	return 0;
}
