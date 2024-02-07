#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26; 
const int BTN_PIN_2 = 7; 


int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);


  gpio_init(BTN_PIN_2);
  gpio_set_dir(BTN_PIN_2, GPIO_IN);
  gpio_pull_up(BTN_PIN_2);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
        printf("1\n");
        while(!gpio_get(BTN_PIN)){};
    }

    if (!gpio_get(BTN_PIN_2)) {
        printf("2\n");
        while(!gpio_get(BTN_PIN_2)){};
    }
    
  }
}