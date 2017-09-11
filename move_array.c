#include <stdio.h>

// function declarations
void print_array(int arr[]);
void side2side(int arr[]);

int main () {
	int arr[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	int i = 0;
	while (i < 3){
	    side2side(arr);
	    i++;
	}
}

// function definitions

void side2side (int arr[]){
	int i = 0;
	int j = 9;
	while (i < 10) {
    	while (i < 6){
    	    print_array(arr);
    		arr[i] = 0;
    		arr[i+4] = 1;
    		i++;
    	}
    	while (i < 12){
    	    print_array(arr);
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
