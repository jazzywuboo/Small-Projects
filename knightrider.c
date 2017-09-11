#include <stdio.h>
//#include "stm32l476xx.h"
//#include "LED.h"
//#include "SysTimer.h"

// function declarations
void print_array(int arr[]);
void side2side(int arr[]);
//void System_Clock_Init(void);
//void config_GPIOS ();
//void config_HSI ();

int main () {
	/*
	LED_Init();
	SysTick_Init();
	config_HSI();
	config_GPIOS();
	*/
	int arr[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	/* set pins PA0-PA3 on
	GPIOA->BSRR[0] = 1;
	GPIOA->BSRR[1] = 1;
	GPIOA->BSRR[2] = 1;
	GPIOA->BSRR[3] = 1;
	*/
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
    		/*
			if (i < 4) {
				GPIOA->BRR[i] = 1;
				GPIOA->BSRR[i+4] = 1;
			}
			else {	turn PE10-15 on/off
				i += 6;
				GPIOE->BRR[i] = 1;
				GPIOE->BSRR[i+4] = 1;
			}
    		*/
    		i++;
    	}
    	while (i < 12){
    	    print_array(arr);
            arr[j] = 0;
            arr[j-4] = 1;
    		/*
			if (i < 4) {
				GPIOA->BRR[j] = 1;
				GPIOA->BSRR[j-4] = 1;
			}
			else {
				j += 6;
				GPIOE->BRR[j] = 1;
				GPIOE->BSRR[j-4] = 1;
			}
    		*/
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
/*
void config_HSI () {
	// Enable High Speed Internal Clock (HSI = 16 MHz)
	RCC->CR |= ((uint32_t)RCC_CR_HSION);

	// wait until HSI is ready
	while ( (RCC->CR & (uint32_t) RCC_CR_HSIRDY) == 0 ) {;}

	// Select HSI as system clock source 
	RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
	RCC->CFGR |= (uint32_t)RCC_CFGR_SW_HSI;  //01: HSI16 oscillator used as system clock

	// Wait till HSI is used as system clock source 
	while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) == 0 ) {;}
}

void config_GPIOS () {
	// Enable GPIO Clock to ports A and E
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOEEN;

	// configure GPIOA and GPIOE ports
	GPIOE -> MODER &= ~0XFFF00000;
	GPIOE -> MODER |= 0X555000000;

	GPIOE -> OTYPER &= ~0XFC000000;
	GPIOE -> OTYPER |= 0X00000000;

	GPIOE -> PUPDR &= ~0XFFF00000;
	GPIOE -> PUPDR |= 0X00000000;

	GPIOA -> MODER &= ~ 0X000000FF;
	GPIOA -> MODER |= 0X00000055;

	GPIOA -> OTYPER &= ~ 0X000F0000;
	GPIOA -> OTYPER |=  0X00000000;

	GPIOA -> PUPDR &= ~ 0X00000011;
	GPIOA -> PUPDR |= 0X00000000;
}

void System_Clock_Init(void){
	
	RCC->CR |= RCC_CR_MSION; 
	
	// Select MSI as the clock source of System Clock
	RCC->CFGR &= ~RCC_CFGR_SW; 
	
	// Wait until MSI is ready
	while ((RCC->CR & RCC_CR_MSIRDY) == 0); 	
	
	// MSIRANGE can be modified when MSI is OFF (MSION=0) or when MSI is ready (MSIRDY=1). 
	RCC->CR &= ~RCC_CR_MSIRANGE; 
	RCC->CR |= RCC_CR_MSIRANGE_7;  // Select MSI 8 MHz	
 
	// The MSIRGSEL bit in RCC-CR select which MSIRANGE is used. 
	// If MSIRGSEL is 0, the MSIRANGE in RCC_CSR is used to select the MSI clock range.  (This is the default)
	// If MSIRGSEL is 1, the MSIRANGE in RCC_CR is used. 
	RCC->CR |= RCC_CR_MSIRGSEL; 
	
	// Enable MSI and wait until it's ready	
	while ((RCC->CR & RCC_CR_MSIRDY) == 0); 		
}
*/
