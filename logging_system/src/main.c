#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

struct stu
{
    int num;
    char name[100];
    float mark;
};

int prime(int n)
{
    int i;

    LOG_DEBUG("Checking %d", n);

    if(n < 2)
    {
        LOG_WARN("%d is not prime", n);
        return 0;
    }

    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            LOG_DEBUG("%d is divisible by %d", n, i);
            return 0;
        }
    }

    LOG_DEBUG("%d is prime", n);
    return 1;
}

int main()
{
    int i;
    int count = 0;
    int n = 5;
    struct stu *p;

    LOG_INFO("Program started");

    p = malloc(n * sizeof(struct stu));

    if(p == NULL)
    {
        LOG_ERROR("Memory allocation failed");
        return 1;
    }

    LOG_DEBUG("Memory allocated");

    for(i = 0; i < n; i++)
    {
        p[i].num = i + 2;
        sprintf(p[i].name, "Student%d", i + 1);
        p[i].mark = 50 + i * 10;

        if(p[i].mark < 60)
            LOG_WARN("%s mark is %.2f", p[i].name, p[i].mark);
    }

    for(i = 0; i < n; i++)
    {
        if(prime(p[i].num))
            count++;
    }

    LOG_INFO("Prime count = %d", count);

    LOG_ASSERT(count <= n, "Prime count is greater than number of students");

    printf("\nResults\n");

    for(i = 0; i < n; i++)
        printf("%d %s %.2f\n", p[i].num, p[i].name, p[i].mark);

    printf("Prime count = %d\n", count);

    free(p);

    LOG_INFO("Program ended");

    return 0;
}
