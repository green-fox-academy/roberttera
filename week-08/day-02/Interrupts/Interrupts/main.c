#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT0_vect){
    // Toggle the LED
    PORTB ^= 1 << PORTB5;
}

// This is an init function, which initializes the MCU for the rest of the program.
// It is common in embedded C programs to set port direction (input/output), pull-ups and pull-downs,
// and everything that is needed at the start of your program.

void init(){
    // The button is connected to PB7 pin, which is the PCINT7 pin (PinChangeINTerrupt7 pin)
    // If we enable this interrupt on every pin state changes the interrupt handler will be fired.
    // So when the button is pressed OR released the interrupt handler will run.

    // Set the PCINT7 bit of PCMSK0 register. This will enable the interrupts from the button (PB7=PCINT7)
    PCMSK0 |= 1 << PCINT7;
    // Enable pin interrupt on change 0 interrupts. This will enable PCINT0, PCINT1, PCINT2 ... PCINT7 interrupts.
    PCICR |= 1 << PCIE0;

    // Finally, enable the interrupts globally
    sei();
    // Set PB5 as output, this is the LED pin
    DDRB = 1 << 5;
}

int main(void)
{
    // Never forget to call the init function if you have it :)
    init();
    while (1) {

    }
}