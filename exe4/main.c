
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_1 = 5;
const int LED_PIN_2 = 8;
const int LED_PIN_3 = 11;
const int LED_PIN_4 = 15;
const int BTN_PIN = 28;


int main() {
  stdio_init_all();


  gpio_init(LED_PIN_1);
  gpio_init(LED_PIN_2);
  gpio_init(LED_PIN_3);
  gpio_init(LED_PIN_4);
  gpio_init(BTN_PIN);

  gpio_set_dir(LED_PIN_1, GPIO_OUT);
  gpio_set_dir(LED_PIN_2, GPIO_OUT);
  gpio_set_dir(LED_PIN_3, GPIO_OUT);
  gpio_set_dir(LED_PIN_4, GPIO_OUT);
  gpio_set_dir(BTN_PIN, GPIO_IN);

  gpio_pull_up(BTN_PIN_1);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_PIN_1, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_1, 0);
      gpio_put(LED_PIN_2, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_2, 0);
      gpio_put(LED_PIN_3, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_3, 0);
      gpio_put(LED_PIN_4, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_4, 0);

      while (!gpio_get(BTN_PIN)) {
      };
    };
  }
}
