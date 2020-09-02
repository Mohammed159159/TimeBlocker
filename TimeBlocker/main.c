#include<stdio.h>
#include<string.h>
#include<Windows.h>

int main() {

    system("COLOR F0");
    FILE* fptr;

    fptr = fopen("Time Blocker.txt", "w");
    char ap[3], ap2[3];
    int daynight = 2, contr = 1, count = 0, startIs12 = 0, startIsSame = 0;
    int hrs, mins, t, hrs2, mins2;
    printf("Enter Initial Time(hrs:mins am/pm): ");
    scanf("%d:%d %s", &hrs, &mins, ap);
    printf("Enter intervals: ");
    scanf("%d", &t);
    printf("Enter Final Time(hrs:mins am/pm): ");
    scanf("%d:%d %s", &hrs2, &mins2, ap2);

    if (hrs == 12)
    {
        startIs12 = 1;
    }
    if (hrs == hrs2 && mins == mins2 && (strcmp(ap, ap2) == 0))
    {
        startIsSame = 1;
    }

    if (strcmp(ap, "am") == 0)
        daynight = 2;
    else if (strcmp(ap, "pm") == 0)
        daynight = 3;

    // logic
    int i = mins - t;

    while (1)
    {
        // terminating logic

        if (hrs == hrs2 && ((mins2 - i) < t || i == mins2) && (strcmp(ap, ap2) == 0) && startIsSame == 0)
            break;


        // adding logic

        else
        {
            i += t;

            if (i >= 60)
            {
                hrs++;
                i = i - 60;
            }
            if (hrs > 12)
                hrs = 1;

            if (hrs == 12 && contr == 1 && startIs12 == 0)
            {
                daynight++;

                if (daynight % 2 == 0)
                    strcpy(ap, "am");
                else strcpy(ap, "pm");

                contr = 0;
            }
            if (hrs == 1 && startIs12 == 0)
                contr = 1;
            // printing logic

            if (hrs < 10 && i < 10)
                fprintf(fptr, " 0%d:0%d %s", hrs, i, ap);
            else if (hrs < 10)
                fprintf(fptr, " 0%d:%d %s", hrs, i, ap);
            else if (i < 10)
                fprintf(fptr, " %d:0%d %s", hrs, i, ap);
            else
                fprintf(fptr, " %d:%d %s", hrs, i, ap);

            fprintf(fptr, "\n");
        }

        if (hrs != hrs2)
            startIsSame = 0;
        if (hrs != 12)
            startIs12 = 0;

    }



    fclose(fptr);




}

