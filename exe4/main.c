#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


const int LED_PIN1 = 7;
const int LED_PIN2 = 11;
const int LED_PIN3 = 15;
const int LED_PIN4 = 19;
const int BTN_PIN1 = 34;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN1);
  gpio_set_dir(BTN_PIN1, GPIO_IN);
  gpio_pull_up(BTN_PIN1);

  gpio_init(LED_PIN1);
  gpio_init(LED_PIN2);
  gpio_init(LED_PIN3);
  gpio_init(LED_PIN4);
  gpio_set_dir(LED_PIN1, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);
  gpio_set_dir(LED_PIN3, GPIO_OUT);
  gpio_set_dir(LED_PIN4, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN1)) {
      gpio_put(LED_PIN1, 1);
      sleep_ms (300);
      
      gpio_put(LED_PIN1, 0);
      gpio_put(LED_PIN2, 1);
      sleep_ms (300);
      
      gpio_put(LED_PIN2, 0);
      gpio_put(LED_PIN3, 1);
      sleep_ms (300);
      
      gpio_put(LED_PIN3, 0);
      gpio_put(LED_PIN4, 1);
      sleep_ms (300);
      
      gpio_put(LED_PIN4, 0);
    }
  }
}
