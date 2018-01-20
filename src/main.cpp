#include <mbed.h>

#include <stdbool.h>

bool ispressed(DigitalIn button)
{
  if (!button.read())
  {
    return false;
  }
  else
  {
    return true;
  }
}

int main() {
    bool flashing = false;

    DigitalOut red(PTB22);
    DigitalIn  btn(PTC6);
    DigitalOut topRed(D5);

    DigitalIn up(A2);
/*
    while(1) {
        if( btn.read() ) flashing = true;
            else         flashing = false;
*/

// If up on joystick is pressed, light will turn off.
while(1)
{
  flashing = ispressed(up);

  if(!flashing) {
    topRed.write(0);
    wait(0.75);
    topRed.write(1);
    wait(0.75);
  }
  else {
    topRed.write(1);
  }
}

/* If the button is pressed, both Red LEDS will turn off
  while(1)
  {
    flashing = ispressed(btn);

        printf("button %d\n", btn.read() );
        if(flashing){
            topRed.write(0);
            red.write(0);
            wait(0.5);
            topRed.write(1);
            red.write(1);
            wait(0.5);
        }else{
            red.write(1);
            topRed.write(1);
            wait(1);
        }
    }

  */
}
