#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_G = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;
const int LED_PIN_R = 4;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  gpio_init(BTN_PIN_R);
  gpio_init(BTN_PIN_G);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);

  gpio_pull_up(BTN_PIN_R);
  gpio_pull_up(BTN_PIN_G);
  
  int led_r_status = 0;
  int led_g_status = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      led_r_status = !led_r_status;
      gpio_put(LED_PIN_R, led_r_status);
    }
    if (!gpio_get(BTN_PIN_G)) {
      led_g_status = !led_g_status;
      gpio_put(LED_PIN_G, led_g_status);
    }
  }
}
