#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void* test_malloc(size_t size){
        void *p = malloc(size);
        if(p)
        {
                printf("Malloc success\n");
        }
        else
        {
                printf("Malloc Failed\n");
        }
	return p;
}

void test_calloc(size_t nmem, size_t size){
        void *p = calloc(nmem, size);
        if(p)
        {
                printf("calloc success\n");
        }
        else
        {
                printf("calloc Failed\n");
        }
}

void test_realloc(void *ptr, size_t size){
        void *p = realloc(ptr, size);
        if(p)
        {
                printf("realloc success\n");
        }
        else
        {
                printf("realloc Failed\n");
        }
}

void test_brk(void *ptr){
        int p = brk(ptr);
        if(p != -1)
        {
                printf("brk success\n");
        }
        else
        {
                printf("brk Failed\n");
        }
}

void test_sbrk(intptr_t inc){
        void * p = sbrk(inc);
        if(p != NULL)
        {
                printf("sbrk success\n");
        }
        else
        {
                printf("sbrk Failed\n");
        }
}

int test_open(char *filename, int flags){
        int fd = open(filename, flags);
        if(fd != -1)
        {
                printf("Open success\n");
        }
        else
        {
                printf("Open Failed\n");
        }
	return fd;
}

void test_read(int fd,void *buf, size_t count){
        ssize_t byte_count = read(fd, buf, count);
        if(byte_count != -1)
        {
                printf("read success\n");
        }
        else
        {
                printf("read Failed\n");
        }
}

void test_write(int fd,void *buf, size_t count){
        ssize_t byte_count = write(fd, buf, count);
        if(byte_count != -1)
        {
                printf("write success\n");
        }
        else
        {
                printf("write Failed\n");
        }
}

void test_lseek(int fd, off_t offset, int whence){
        off_t set = lseek(fd, offset, whence);
        if(set != -1)
        {
                printf("lseek success\n");
        }
        else
        {
                printf("lseek failed\n");
        }
}

void test_dup2(int oldfd, int newfd){
        int fd  = dup2(oldfd, newfd);
        if(fd != -1)
        {
                printf("dup2 success\n");
        }
        else
        {
                printf("dup2 failed\n");
        }
}

void test_fork(){
        pid_t fd  = fork();
        if(fd == getpid())
        {
                printf("In parent process\n");
        }
        else if(fd == -1)
        {
                printf("Fork failed\n");
        }
	else{
		printf("In child process\n");
		exit(0);
	}
}


int main(){
        size_t size = 3;
	off_t set = 3;
	size_t nmem_size = 4;
	intptr_t inc = 3;
        printf("calling main\n");
        void *p =  test_malloc(size);
	test_calloc(nmem_size, size);
	test_realloc(p, size);
	test_brk(p);
	test_sbrk(inc);
	int fd = test_open("abc.txt", O_CREAT);
	char * buf;
	test_read(fd,buf, size );
	buf = "sripradha";
	test_write(fd, buf, size);
	test_lseek(fd, set, SEEK_SET);
	test_dup2(fd, 4);
	test_fork();
        return 0;
}

