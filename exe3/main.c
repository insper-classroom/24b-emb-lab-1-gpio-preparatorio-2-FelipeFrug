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
    int luz = gpio_get(LED_PIN_R);
    gpio_put(LED_PIN_R, !luz);
    sleep_ms(50);
    while (!gpio_get(BTN_PIN_R)) {
    };
    int luz2 = gpio_get(LED_PIN_G);
    gpio_put(LED_PIN_G, !luz2);
    sleep_ms(50);
    while (!gpio_get(BTN_PIN_G)) {
    }
  }
}
