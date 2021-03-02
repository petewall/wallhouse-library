#include <Arduino.h>
#include <unity.h>
#include <Blinker.h>

#define INTERVAL 100
#define HALF_INTERVAL INTERVAL / 2
Blinker blinker(INTERVAL);

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void) {
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
    TEST_ASSERT_EQUAL(true, blinker.state);
}

void test_led_state_low(void) {
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
    TEST_ASSERT_EQUAL(false, blinker.state);
}

void setup() {
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(test_led_builtin_pin_number);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
  unsigned long now = millis();

  if (i < max_blinks) {

    delay(HALF_INTERVAL);

    blinker.check(now);
    RUN_TEST(test_led_state_low);

    delay(INTERVAL);

    blinker.check(now);
    RUN_TEST(test_led_state_high);

    delay(HALF_INTERVAL);

    i++;
  } else {
    UNITY_END();
  }
}
