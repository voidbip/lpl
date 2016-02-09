#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "parser.h"
#include "debug.h"

int main() {
    FILE *fp;
    char commandLine[1024];
    node *result;
    clock_t start, diff;
    time_t wstart;
    double wtime;
    int msec;


    struct timespec now, tmstart;


    while (fgets(commandLine,1024,stdin)) {
#ifdef DEBUG
      /* fp = fopen("errors.log","w");
      ParseTrace(fp,"err: "); */
#endif

      clock_gettime(CLOCK_REALTIME, &tmstart);

        start = clock();
          result=parse(commandLine);
          printNode(result);
          printf("\n");
        diff = clock()-start;

      clock_gettime(CLOCK_REALTIME, &now);

      wtime = 1000*((double)((now.tv_sec+now.tv_nsec*1e-9) - (double)(tmstart.tv_sec+tmstart.tv_nsec*1e-9)));


      msec = diff*1000 / CLOCKS_PER_SEC;

      printf("%s, walltime: %f, cputime: %d ms\n",commandLine,wtime,msec);
#ifdef DEBUG
      /* fclose(fp); */
#endif
    }

    return 0;
}
