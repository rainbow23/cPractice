#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void* does_not(void *a)
{
	for(int i=0; i<10; i++)
	{
		//sleep(1);
		puts("Does not!");
	}
	return NULL;
}

void* does_too(void *a)
{
	for(int i=0; i<10; i++)
	{
		//sleep(1);
		puts("Does too!");
	}
	return NULL;
}

int main()
{
	pthread_t t0;
	pthread_t t1;

	if(pthread_create(&t0, NULL, does_not, NULL) == -1)
	{
		error("スレッドt0を作成できません");
	}

	if(pthread_create(&t1, NULL, does_too, NULL) == -1)
	{
		error("スレッドt1を作成できません");
	}

	void* result;
	if(pthread_join(t0, result) == -1)
	{
		error("スレッド0をジョインできません");
	}

	if(pthread_join(t1, result) == -1)
	{
		error("スレッド0をジョインできません");
	}
	
	fprintf(stderr, "%s: %s\n", "aaa", strerror(errno));
}





