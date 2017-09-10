#include <stdio.h>

// function declarations
void print_array(int arr[]);
void side2side(int arr[]);
void array_to_GPIO(int arr[]);

int main () {
	int arr[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};	// initialize first four pins as on
	int num_cycles = 0;
	while (num_cycles < 2){
	    side2side(arr);
	    num_cycles++;
	}
	print_array(arr);
	array_to_GPIO(arr);
}

void side2side (int arr[]){
	int i = 0;
	int j = 9;
	while (i < 10) {
    	while (i < 6){
    	    print_array(arr);
    	    array_to_GPIO(arr);
    		arr[i] = 0; // 
    		arr[i+4] = 1;
    		i++;
    	}
    	while (i < 12){
    	    print_array(arr);
    	    array_to_GPIO(arr);
            arr[j] = 0;
            arr[j-4] = 1;
            i++;
            j--;
    	}
	}
}

void print_array(int arr[]) {
	for (int i = 0; i < 10; i++){
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}

void array_to_GPIO(int arr[]){
    for (int i = 0; i < 10; i++){
        if (i < 4 ){
            if (arr[i] == 0){
                //GPIOA->BRR[i] = 1;
            }
            else {
                //GPIOA->BSRR[i] = 1;
                printf("PA%d ", i);
            }
        }
        if (i > 3) {
            int j = i+6;
            if (arr[i] == 0){
                //GPIOE->BRR[j] = 1;
            }
            else {
                //GPIOE->BSRR[j] = 1;
                printf("PE%d ", j);
            }
        }
    }
    printf("- on\n");
}
