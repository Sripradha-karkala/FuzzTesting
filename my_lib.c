#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<dlfcn.h>
#include<sys/types.h>
#include<math.h>
#include<time.h>
#include"lib_types.h"

#ifndef RAND_MAX
#define RAND_MAX (2147483647)
#endif
#define SUCCESS_RATE 0.5 // equal to 50% of the functions overridden

static int init = 0;

static void initialize(){
 if(init)
	return;
 srandom(time(NULL));
 init = 1;
 return ;
}
static float chance(){
	float random = rand()/ (float) RAND_MAX;
	return random;
}

static void logInfo(const char * funcname,  float chance_fail){
     printf("Function  %s,  with random number : %f \n", funcname,  chance_fail);
}

/*void *malloc(size_t size){
	initialize();
	static void * (*real_malloc)(size_t) = NULL;
        if(!real_malloc){
                real_malloc = dlsym(RTLD_NEXT, "malloc");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
	{
		logInfo(__func__,  chance_fail);
		return  NULL;
	}
	logInfo(__func__, chance_fail);
	return real_malloc(size);
}

void *calloc(size_t nmem, size_t size){
	initialize();
	static void * (*real_calloc)(size_t, size_t) = NULL;
        if(!real_calloc){
                real_calloc = dlsym(RTLD_NEXT, "calloc");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
	{
		logInfo(__func__, chance_fail);
		return NULL;
	}
	logInfo(__func__, chance_fail);
        return real_calloc(nmem, size);
}

void *realloc(void *ptr, size_t size){
	initialize();
	static void * (*real_realloc)(void*, size_t) = NULL;
        if(!real_realloc){
                real_realloc = dlsym(RTLD_NEXT, "realloc");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
	{
		logInfo(__func__, chance_fail);
		return NULL;
	}
	logInfo(__func__, chance_fail);
        return real_realloc(ptr, size);
}

int brk(void *ptr){
	initialize();
	static int (*real_brk)(void*) = NULL;
        if(!real_brk){
                real_brk = dlsym(RTLD_NEXT, "brk");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
        return real_brk(ptr);
}

void * sbrk(intptr_t increment){
	
 	if(chance() > success_rate)
        {
		logInfo(__func__);
                success_rate=success_rate+1;
                return NULL;
        }
        static void* (*real_sbrk)(intptr_t) = NULL;
        if(!real_sbrk){
                real_sbrk = dlsym(RTLD_NEXT, "sbrk");
        }
	setRate();
        return real_sbrk(increment);
}*/

//File management functions

/*int open(const char *pathname, int flags){
	initialize();
	static int (*real_open)(const char*,int) = NULL;
        if(!real_open){
                real_open = dlsym(RTLD_NEXT, "open");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
	return real_open(pathname, flags);
}


ssize_t read(int fd,void * buf, size_t count){
	initialize();
	static ssize_t (*real_read)(int, void*, size_t) = NULL;
        if(!real_read){
                real_read = dlsym(RTLD_NEXT, "read");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
        return real_read(fd, buf,count);
}

ssize_t write(int fd,void * buf, size_t count){
	initialize();
	static ssize_t (*real_write)(int, void*, size_t) = NULL;
        if(!real_write){
                real_write = dlsym(RTLD_NEXT, "write");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
        return  real_write(fd, buf,count);
}

off_t lseek(int fd,off_t offset, int whence){
	initialize();
	static off_t (*real_lseek)(int, off_t, int) = NULL;
        if(!real_lseek){
                real_lseek = dlsym(RTLD_NEXT, "lseek");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return (off_t) -1;
        }
	logInfo(__func__, chance_fail);
        return real_lseek(fd, offset, whence);
}

int dup2(int oldfd, int newfd){
	initialize();
	static int (*real_dup2)(int, int) = NULL;
        if(!real_dup2){
                real_dup2 = dlsym(RTLD_NEXT, "dup2");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
        return real_dup2(oldfd, newfd);
}
*/
// Process Management functions
/*
pid_t fork(){
	if(chance() > success_rate)
        {
		logInfo(__func__);
                success_rate=success_rate+1;
                return -1;
        }

	static pid_t (*real_fork)() = NULL;
	if(!real_fork){
		real_fork = dlsym(RTLD_NEXT, "fork");
	}
	setRate();
	return real_fork();
}

// Network Operations 

int socket(int domain, int type, int protocol){
	initialize();
	static int (*real_socket)(int, int, int) = NULL;
        if(!real_socket){
                real_socket = dlsym(RTLD_NEXT, "socket");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
	return real_socket(domain, type, protocol);
}
*/
int accept(int socketfd, struct sockaddr* addr, socklen_t addrlen){
	initialize();
	static int (*real_accept)(int, struct sockaddr, socklen_t) = NULL;
        if(!real_accept){
                real_accept = dlsym(RTLD_NEXT, "accept");
        }
	float chance_fail = chance();
	if(chance_fail > SUCCESS_RATE)
        {
		logInfo(__func__, chance_fail);
                return -1;
        }
	logInfo(__func__, chance_fail);
        return real_accept(socketfd, *addr, addrlen);
}
/*
int bind(int socketfd, const struct sockaddr* addr, socklen_t addrlen){
	if(chance() > success_rate)
        {
		logInfo(__func__);
                success_rate=success_rate+1;
                return -1;
        }

        static int (*real_bind)(int, const struct sockaddr, socklen_t) = NULL;
        if(!real_bind){
                real_bind = dlsym(RTLD_NEXT, "bind");
        }
	setRate();
        return real_bind(socketfd, *addr, addrlen);
}

int connect(int socketfd, const struct sockaddr* addr, socklen_t addrlen){
	if(chance() > success_rate)
        {
		logInfo(__func__);
                success_rate=success_rate+1;
                return -1;
        }

        static int (*real_connect)(int, const struct sockaddr, socklen_t) = NULL;
        if(!real_connect){
                real_connect = dlsym(RTLD_NEXT, "connect");
        }
	setRate();
        return real_connect(socketfd, *addr, addrlen);
}


*/
