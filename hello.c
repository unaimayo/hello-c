/*
 * Sample code for basic C app which prints the current system date and time 10 sec delay
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*
 * Display the current system date and time
 */
void display_date_time()
{
    time_t tvar;
    /* Returns the current time of the system as a time_t object
     * which is usually time since an epoch, typically the Unix epoch
     */
    time(&tvar);
    /* Print the date and time after converting a time_t object
     * to a textual representation using ctime()
     */
    printf("Hi, today's date and time: %s",ctime(&tvar));
}

/*
 * Print the current system date and time
 */
void main()
{
    /*
     * Print the current system date and time for 10 times with 1 sec delay
     */
    setbuf(stdout, NULL);
    while(1)
    {
        /* Call the function to display the date and time */
        display_date_time();
        /* Sleep for 10 seconds for each iteration */
        sleep(10);
    }
}

