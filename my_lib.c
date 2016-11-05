#define _GNU_SOURCE
#include <stdio.h>
#include<stdint.h>
#include<dlfcn.h>


void *malloc(size_t size){

	static void * (*real_malloc)(size_t) = NULL;
	if(!real_malloc){
		real_malloc = dlsym(RTLD_NEXT, "malloc");
	}
	return real_malloc(size);
}

void *calloc(size_t nmem, size_t size){

        static void * (*real_calloc)(size_t, size_t) = NULL;
        if(!real_calloc){
                real_calloc = dlsym(RTLD_NEXT, "calloc");
        }
        return real_calloc(nmem, size);
}

void *realloc(void *ptr, size_t size){

        static void * (*real_realloc)(void*, size_t) = NULL;
        if(!real_realloc){
                real_realloc = dlsym(RTLD_NEXT, "realloc");
        }
        return real_realloc(ptr, size);
}

int brk(void *ptr){

        static int (*real_brk)(void*) = NULL;
        if(!real_brk){
                real_brk = dlsym(RTLD_NEXT, "brk");
        }
        return real_brk(ptr);
}

void * sbrk(intptr_t increment){

        static void* (*real_sbrk)(intptr_t) = NULL;
        if(!real_sbrk){
                real_sbrk = dlsym(RTLD_NEXT, "sbrk");
        }
        return real_sbrk(increment);
}

int open(const char *pathname, int flags){
	static int (*real_open)(const char*,int) = NULL;
	if(!real_open){
		real_open = dlsym(RTLD_NEXT, "open");	
	}
	return real_open(pathname, flags);
}

ssize_t read(int fd,void * buf, size_t count){
        static ssize_t (*real_read)(int, void*, size_t) = NULL;
        if(!real_read){
                real_read = dlsym(RTLD_NEXT, "read");
        }
        return real_read(fd, buf,count);
}

ssize_t write(int fd,void * buf, size_t count){
        static ssize_t (*real_write)(int, void*, size_t) = NULL;
        if(!real_write){
                real_write = dlsym(RTLD_NEXT, "write");
        }
        return  real_write(fd, buf,count);
}

off_t lseek(int fd,off_t offset, int whence){
        static off_t (*real_lseek)(int, off_t, int) = NULL;
        if(!real_lseek){
                real_lseek = dlsym(RTLD_NEXT, "lseek");
        }
        return real_lseek(fd, offset, whence);
}

int dup2(int oldfd, int newfd){
        static int (*real_dup2)(int, int) = NULL;
        if(!real_dup2){
                real_dup2 = dlsym(RTLD_NEXT, "dup2");
        }
        return real_dup2(oldfd, newfd);
}


