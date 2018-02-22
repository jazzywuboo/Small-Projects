//
//  two_proc.c
//  lab2
//
//  Created by jaz on 2/15/18.
//  Copyright © 2018 jaz. All rights reserved.
//
#include "charMap.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    
    char *specified_char = (char *) malloc(sizeof(char));
    
    if (fork() == 0) {  // indicates parents process
        printf("Memory location of specified_char in parent proc: %p\n", &specified_char);
        *specified_char = '*';
        print_string_by_char("ECE", *specified_char);
        sleep(10);
        print_string_by_char("JWN", *specified_char);
    }
    else { // death of child proc terminates the parent
        printf("Memory location of specified_char in child proc: %p\n", &specified_char);
        sleep(3);
        *specified_char = '#';
        print_string_by_char("531", *specified_char);
    }
    free(specified_char);
    return 0;
}
