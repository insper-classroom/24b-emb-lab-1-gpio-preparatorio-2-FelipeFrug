
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_1 = 4;
const int LED_PIN_2 = 6;
const int BTN_PIN_1 = 28;
const int BTN_PIN_2 = 26;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_1);
  gpio_init(LED_PIN_2);
  gpio_init(BTN_PIN_1);
  gpio_init(BTN_PIN_2);

  gpio_set_dir(LED_PIN_1, GPIO_OUT);
  gpio_set_dir(LED_PIN_2, GPIO_OUT);
  gpio_set_dir(BTN_PIN_1, GPIO_IN);
  gpio_set_dir(BTN_PIN_2, GPIO_IN);

  gpio_pull_up(BTN_PIN_1);
  gpio_pull_up(BTN_PIN_2);

  while (true) {
  if (!gpio_get(BTN_PIN_1)) {
    int luz = gpio_get(LED_PIN_1);
    gpio_put(LED_PIN_1, !luz);
    sleep_ms(50);
    while (!gpio_get(BTN_PIN_1)) {
    };
  };
  if (!gpio_get(BTN_PIN_2)) {
    int luz = gpio_get(LED_PIN_2);
    gpio_put(LED_PIN_2, !luz);
    sleep_ms(50);
    while (!gpio_get(BTN_PIN_2)) {
    }
  }
}
}
