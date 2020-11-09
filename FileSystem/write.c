//gcc -Wall -Wextra -o write write.c


#define _GNU_SOURCE
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static double diff           (struct timespec start, struct timespec end);


int main (int argc, char *argv[])
{
	int      ret;
	int      cpu;
	cpu_set_t set;
	struct sched_param sp = {.sched_priority = 50, };
	struct timespec    tStart, tEnd;

    // cpu and task priority
    if (argc == 2)
    {
        cpu    = atoi(argv[1]);
    }
    else
    {
        cpu = 0;
    }

    
    CPU_ZERO (&set);
    CPU_SET (cpu, &set);
    ret=sched_setaffinity (0, sizeof(set), &set);
    printf ("setaffinity=%d\n", ret);

    ret=sched_setscheduler (0, SCHED_FIFO, &sp);
    printf ("setscheduler=%d\n", ret);
    

    
    clock_gettime(CLOCK_REALTIME, &tStart);	
    //writeSmallFiles();
    clock_gettime(CLOCK_REALTIME, &tEnd);
    printf ("Write small files, time[s]: %f\n", diff(tStart, tEnd));

    clock_gettime(CLOCK_REALTIME, &tStart);	
    //writeBigFile();
    clock_gettime(CLOCK_REALTIME, &tEnd);
    printf ("Write big files, time[s]: %f\n", diff(tStart, tEnd));

    return (0);
}

/*
static int writeSmallFiles()
{
    return 0;
}


static int writeBigFile()
{
    return 0;
}

*/


static double diff(struct timespec start, struct timespec end)
{
double t1, t2;

    t1 = (double)start.tv_sec;
    t1 = t1 + ((double)start.tv_nsec)/1000000000.0;
    t2 = (double)end.tv_sec;
    t2 = t2 + ((double)end.tv_nsec)/1000000000.0;

    return (t2-t1);
}
