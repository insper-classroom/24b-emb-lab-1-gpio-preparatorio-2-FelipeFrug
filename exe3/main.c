#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


const int LED_PIN1 = 4;
const int LED_PIN2 = 6;
const int BTN_PIN1 = 28;
const int BTN_PIN2 = 26;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN1);
  gpio_set_dir(BTN_PIN1, GPIO_IN);
  gpio_pull_up(BTN_PIN1);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  gpio_init(LED_PIN1);
  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN1, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN1)) {
      gpio_put(LED_PIN1, 1);
    }
    if (!gpio_get(BTN_PIN2)) {
      gpio_put(LED_PIN2, 1);
    }
  }
}
