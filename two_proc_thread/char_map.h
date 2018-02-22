//
//  charMap.h
//  two_thread
//
//  Created by jaz on 2/15/18.
//  Copyright © 2018 jaz. All rights reserved.
//

#ifndef charMap_h
#define charMap_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const int num_rows = 5;
const int chars_per_row = 8;

const int char_map[36][num_rows] = {
    /*  maps A-Z and 0-9 to ascii art shapes saved as hex values
        when translated to binary, a 0 represents a space and a 1 represents the specified character
     */
    {   // A
        0x08, 0x14, 0x2A, 0x41, 0x41
    },
    {   // B
        0xFF, 0x81, 0xFF, 0x81, 0xFF
    },
    {   // C
        0xFF, 0x80, 0x80, 0x80, 0xFF
    },
    {   // D
        0xFF, 0x81, 0x81, 0x81, 0xFF
    },
    {   // E
        0xFF, 0x80, 0xFC, 0x80, 0xFF
    },
    {   // F
        0xFF, 0x80, 0xF8, 0x80, 0x80
    },
    {   // G
        0xFF, 0x80, 0x87, 0x81, 0xFF
    },
    {   // H
        0x81, 0x81, 0xFF, 0x81, 0x81
    },
    {   // I
        0xFF, 0x08, 0x08, 0x08, 0xFF
    },
    {   // J
        0x1F, 0x1, 0x1, 0x81, 0xFF
    },
    {   // K
        0x82, 0x88, 0xA0, 0x84, 0x82
    },
    {   // L
        0x80, 0x80, 0x80, 0x80, 0xFF
    },
    {   // M
        0x81, 0xA5, 0x89, 0x81, 0x81
    },
    {   // N
        0x81, 0xA1, 0x89, 0x81, 0x81
    },
    {   // O
        0xFF, 0x81, 0x81, 0x81, 0xFF
    },
    {   // P
        0xFF, 0x81, 0xFF, 0x80, 0x80
    },
    {   // Q
        0xFF, 0x81, 0x81, 0x85, 0xFD
    },
    {   // R
        0xFF, 0x81, 0xFF, 0x81, 0x81
    },
    {   // S
        0xFF, 0x80, 0xFF, 0x01, 0xFF
    },
    {   // T
        0xFF, 0x08, 0x08, 0x08, 0x08
    },
    {   // U
        0x81, 0x81, 0x81, 0x81, 0xFF
    },
    {   // V
        0x81, 0x81, 0x42, 0x24, 0x18
    },
    {   // W
        0x81, 0x81, 0x81, 0x92, 0x44
    },
    {   // X
        0x82, 0x44, 0x10, 0x44, 0x82
    },
    {   // Y
        0x82, 0x44, 0x10, 0x10, 0x10
    },
    {   // Z
        0xFF, 0x04, 0x10, 0x40, 0xFF
    },
    {   // 0
        0xFF, 0x81, 0x81, 0x81, 0xFF
    },
    {   // 1
        0x04, 0x14, 0x04, 0x04, 0x3F
    },
    {   // 2
        0xFF, 0x01, 0xFF, 0x80, 0xFF
    },
    {   // 3
        0xFF, 0x01, 0x0F, 0x01, 0xFF
    },
    {   // 4
        0x81, 0x81, 0xFF, 0x01, 0x01
    },
    {   // 5
        0xFF, 0x80, 0xFF, 0x01, 0xFF
    },
    {   // 6
        0xFF, 0x80, 0xFF, 0x81, 0xFF
    },
    {   // 7
        0xFF, 0x01, 0x01, 0x01, 0x01
    },
    {   // 8
        0xFF, 0x81, 0xFF, 0x81, 0xFF
    },
    {   // 9
        0xFF, 0x81, 0xFF, 0x01, 0x01
    }
};

int * char_to_map_i(char *string_printed) {
    int num_chars = strlen(string_printed);
    int* char_indices = (int*) malloc(num_chars*sizeof(int));
    for (int i = 0; i < num_chars; i++) {
        int char_ascii = (int)(string_printed[i]);
        if (char_ascii >= 65 && char_ascii <= 90) {
            char_indices[i] = char_ascii - 65;
        }
        else if (char_ascii >= 48 && char_ascii <= 57) {
            char_indices[i] = char_ascii - 22;
        }
        else {
            printf("Error: program only accepts A-Z and 0-9.\n");   // formalize this
            exit(1);
        }
    }
    return char_indices;
}

void print_string_by_char(char *string_printed, char specified_char) {
    int num_chars = strlen(string_printed);
    int *char_map_keys = char_to_map_i(string_printed);
    for (int row_num = 0; row_num < num_rows; row_num++) {
        for (int j = 0; j < num_chars; j++) {
            int char_seg_hex_val = char_map[char_map_keys[j]][row_num];
            for (int char_i = chars_per_row; char_i >= 0; char_i--) {
                if (char_seg_hex_val & (0x1 << char_i)) {
                    printf("%c", specified_char);
                }
                else {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

#endif /* charMap_h */
