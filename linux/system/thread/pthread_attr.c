#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//
// Created by bruce on 18-5-20.
//
void *myfunc(void* args)
{
    printf("child thread id:%lu\n",pthread_self());
    return NULL;
}
int main()
{
    //穿件一个子线程
    //线程ID变量
    pthread_t pthid;
    //初始化线程的属性
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    //设置分离
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    int ret = pthread_create(&pthid,&attr,myfunc,NULL);

    if(ret != 0)
    {
        printf("error number%d\n",ret);
        printf("%s\n",strerror(ret));
    }
    printf("parent thread id:%lu\n",pthread_self());

    for(int i=0;i<5;++i)
    {
        printf("i=%d\n",i);
    }
    sleep(2);
    pthread_attr_destroy(&attr);
    return 0;
}
