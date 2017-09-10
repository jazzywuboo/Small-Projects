#include "stm32l476xx.h"
#include "LED.h"
#include "SysTimer.h"

// function declarations
void print_array(int arr[]);
void side2side(int arr[]);
void array_to_GPIO(int arr[]);
void config_HSI();
void config_GPIOS();

int main(void){
	LED_Init();
	SysTick_Init();
	config_HSI();
	config_GPIOS();
		
	int arr[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	int cycle = 0;
	int num_cycles = 10;
	while (cycle < num_cycles){
	    side2side(arr);
	    cycle++;
	}
	array_to_GPIO(arr);
}

// function definitions

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

void side2side (int arr[]){
	int i = 0;
	int j = 9;
	while (i < 10) {
    	while (i < 6){
    	    array_to_GPIO(arr);
    		arr[i] = 0; // 
    		arr[i+4] = 1;
    		i++;
    	}
    	while (i < 12){
    	    array_to_GPIO(arr);
            arr[j] = 0;
            arr[j-4] = 1;
            i++;
            j--;
    	}
	}
}

void array_to_GPIO(int arr[]){
    for (int i = 0; i < 10; i++){
        if (i < 4 ){
            if (arr[i] == 0){
                GPIOA->BRR[i] = 1;
            }
            else {
                GPIOA->BSRR[i] = 1;
            }
        }
        if (i > 3) {
            int j = i+6;
            if (arr[i] == 0){
                GPIOE->BRR[j] = 1;
            }
            else {
                GPIOE->BSRR[j] = 1;
            }
        }
    }
}
