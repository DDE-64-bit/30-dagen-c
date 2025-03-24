#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void* printMessage(void* threadId)
{
    long tid = (long)threadId;
    printf("Thread %ld is gestart.\n", tid);
    for (int i = 0; i < 5; i++)
    {
        printf("Thread %ld doet werk %d.\n", tid, i);
    }
    printf("Thread %ld is klaar.\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Main: maakt thread %ld aan.\n", t);
        rc = pthread_create(&threads[t], NULL, printMessage, (void*)t);

        if (rc)
        {
            printf("Fout bij het aanmaken van thread %ld, foutcode: %d\n", t, rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    printf("Alle threads zijn klaar.\n");
    return 0;
}
