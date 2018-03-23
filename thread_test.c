//
//  thread_test.c
//  P1
//
//  Created by Nicholas Debeurre on 9/20/17.
//  Copyright © 2017 Debeurre. All rights reserved.
//

#include <stdio.h>
#include "threads.h"

int globalVariable = 0;

void addOne()
{
    int x = 1;
    while(1)
    {
        printf("Add one: %d\n", x);
        printf("Global value: %d\n", globalVariable);
        globalVariable++;
        x++;
        yield();
    }
}

void addTwo()
{
    int x = 1;
    while(1)
    {
        printf("Add Two: %d\n", x);
        printf("Global value: %d\n", globalVariable);
        globalVariable++;
        x += 2;
        yield();
    }
}

void addTen()
{
    int x = 1;
    while(1)
    {
        printf("Add Ten: %d\n", x);
        printf("Global value: %d\n", globalVariable);
        globalVariable++;
        x += 10;
        yield();
    }
}

void testy()
{
    while(1)
    {
        printf("Get schwifty\n");
	printf("Global value: %d\n", globalVariable);
	globalVariable++;
	yield();
    }
}

void testy2()
{
    while(1)
    {
	printf("Pickle RIIIIIIIIICK\n");
	printf("Global value: %d\n", globalVariable);
	globalVariable++;
	yield();
    }
}

int main(int argc, const char * argv[])
{
    InitQueue(&RunQ);
    start_thread(addTen);
    start_thread(addTwo);
    start_thread(addOne);
    start_thread(testy);
    start_thread(testy2);
    run();
    return 0;
}
