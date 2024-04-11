#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut led(PWM_OUT);

int main()
{
    // specify period first
    led.period(0.05f);      // 4 second period
    led.write(0.50f);       // 50% duty cycle, relative to period
    //led = 0.5f;            // shorthand for led.write()
    //led.pulsewidth(2);     // alternative to led.write, set duty cycle time in seconds
    
    while (1) {
        // Send a very short pulse
        led.write(0.1f);   // 10% duty cycle
        ThisThread::sleep_for(10);  // Sleep for 10 milliseconds (short duration)
        
        // Send a short pulse
        led.write(0.2f);   // 90% duty cycle
        ThisThread::sleep_for(10);  // Sleep for 10 milliseconds (long duration)

        // Send a long pulse
        led.write(0.3f);   // 90% duty cycle
        ThisThread::sleep_for(10);  // Sleep for 10 milliseconds (long duration)

        // Send a very long pulse
        led.write(0.4f);   // 90% duty cycle
        ThisThread::sleep_for(10);  // Sleep for 10 milliseconds (long duration)
    };
}
