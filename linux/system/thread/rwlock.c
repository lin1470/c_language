//
// Created by bruce on 18-5-20.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

int number=0;
pthread_rwlock_t lock;
void* write_func(void*arg)
{
    while(1)
    {
        pthread_rwlock_wrlock(&lock);
        number++;
        printf("===write:%lu,%d\n",pthread_self(),number);
        pthread_rwlock_unlock(&lock);
        usleep(500);
    }
    return NULL;
}
void* read_func(void*arg)
{
    while(1)
    {
        //加读锁
        pthread_rwlock_rdlock(&lock);
        printf("===read:%lu,%d\n",pthread_self(),number);
        pthread_rwlock_unlock(&lock);
        usleep(500);
    }
    return NULL;
}
int main()
{
    pthread_t p[8];
    pthread_rwlock_init(&lock,NULL);
    for(int i=0;i<3;++i)
    {
        pthread_create(&p[i],NULL,write_func,NULL);
    }
    for(int i=3;i<8;++i)
    {
        pthread_create(&p[i],NULL,read_func,NULL);
    }
    //阻塞回收
    for(int i=0;i<8;++i)
    {
        pthread_join(p[i],NULL);
    }
    pthread_rwlock_destroy(&lock);
    return 0;
}