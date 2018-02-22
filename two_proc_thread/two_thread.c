//
//  main.c
//  two_thread
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "charMap.h"

void *thread1(void *);
void *thread2(void *);
char *specified_char;

int main (void) {
    pthread_t t_a, t_b;
    
    specified_char = (char *) malloc(sizeof(char));
    
    pthread_create(&t_a, NULL, thread2, (void *)NULL);
    pthread_create(&t_b, NULL, thread1, (void *)NULL);
    pthread_join(t_b, NULL);
    free(specified_char);
    
    exit(0);
}

void *thread1(void *junk) {
    //printf("Memory location of specified_char in thread 1: %p\n", &specified_char);
    *specified_char = '*';
    print_string_by_char("ECE", *specified_char);
    sleep(10);
    print_string_by_char("JWN", *specified_char);
    return (void *) NULL;
}

void *thread2(void *junk) {
    //printf("Memory location of specified_char in thread 2: %p\n", &specified_char);
    sleep(3);
    *specified_char = '#';
    print_string_by_char("531", *specified_char);
    return (void *) NULL;
}

