#include "mcc_generated_files/mcc.h"

//#define speed 5 // Speed Range 10 to 1  10 = lowest , 1 = highest
#define steps 4000 // how much step it will take
#define clockwise 0 // clockwise direction macro
#define anti_clockwise 1 // anti clockwise direction macro

int step=24;
uint8_t dir=1;

//void full_drive (char direction); // This function will drive the motor in full drive mode
void ms_delay(unsigned int val)
{
    while(val>0)
    {
        val--;
        __delay_ms(1);
    }
}

// -- SYSTEM INITILIZATION -----------------------------------------------------

void system_init (void)
{
    //TRISB = 0x00;     // PORT B as output port
    //PORTB = 0x0F;
    EN_SetLow();
    __delay_ms(1);
    
    IN_1A_SetLow();
    IN_2A_SetLow();
    IN_1B_SetLow();
    IN_2B_SetLow();
    __delay_ms(1000);
}

// -- FULL STEP FUNCTIONS ------------------------------------------------------

void full_step_CW (step)
    {
    EN_SetHigh();
    
    for(int i=0; i<step; i++)
    {
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();

        __delay_ms(1);

        IN_1A_SetHigh();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_ms(1);

        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetHigh();

        __delay_ms(1);
    }
    
    EN_SetLow();
}


void full_step_CCW (step){

    EN_SetHigh();
    
    for(int i=0; i<step; i++)
    {
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();

        __delay_ms(10);

        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetHigh();

        __delay_ms(10);
             
        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_ms(10);
        
        IN_1A_SetHigh();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_ms(10);
        
        EN_SetLow();
    }
}

// -- HALF STEP FUNCTIONS ------------------------------------------------------

void half_step_CW_wrong (step)
    {
    EN_SetHigh();
    
    for(int i=0; i<step; i++)
    {
        
        IN_1A_SetHigh();
        IN_1B_SetLow();
        IN_2A_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);

        IN_1A_SetHigh();
        IN_1B_SetHigh();
        IN_2A_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_1B_SetHigh();
        IN_2A_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);

        IN_1A_SetLow();
        IN_1B_SetHigh();
        IN_2A_SetHigh();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_1B_SetLow();
        IN_2A_SetHigh();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_1B_SetLow();
        IN_2A_SetHigh();
        IN_2B_SetHigh();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_1B_SetLow();
        IN_2A_SetLow();
        IN_2B_SetHigh();

        __delay_ms(1);
        
        IN_1A_SetHigh();
        IN_1B_SetLow();
        IN_2A_SetLow();
        IN_2B_SetHigh();
        
        __delay_ms(1);
    }
    
    EN_SetLow();
}

void half_step_CW (step) //BUILD OFF THIS ONE
    {
    EN_SetHigh();
    
    for(int i=0; i<step; i++)
    {
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_us(1000);

        IN_1A_SetHigh();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_us(1000);
        
        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_us(1000);

        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_us(1000);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_us(1000);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetHigh();

        __delay_us(1000);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();

        __delay_us(1000);
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();
        
        __delay_us(1000);
    }
    
    EN_SetLow();
}

void half_step_CCW (step)
    {
    EN_SetHigh();
    
    for(int i=0; i<step; i++)
    {
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetHigh();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetLow();
        IN_2B_SetHigh();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetHigh();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetLow();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetHigh();
        IN_2B_SetLow();

        __delay_ms(1);
        
        IN_1A_SetLow();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);

        IN_1A_SetHigh();
        IN_2A_SetHigh();
        IN_1B_SetLow();
        IN_2B_SetLow();

        __delay_ms(1);        
        
    }
    
    EN_SetLow();
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    while (1)
    {
        // Add your application code
        /* Drive the motor in full drive mode clockwise */
        for(int i=0;i<step;i++)
        {
            half_step_CW(step);
            
            if (dir == 1)
            {
                half_step_CW(step);
            }
            else
            {
                half_step_CCW(step);
            }
        }
        
        __delay_ms(1000);
 
        /* Drive the motor in wave drive mode anti-clockwise */
        //for(int i=0;i<step;i++)
        //{
            //full_step_CCW(step);
            //full_drive(anti_clockwise);
        //}
        //__delay_ms(1000);
        
    }
}



/**
 End of File
*/