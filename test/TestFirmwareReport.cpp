#include <Arduino.h>
#include <unity.h>
#include <FirmwareReport.h>

void test_constructor() {
  FirmwareReport report("my_firmware", "1.2.3");
  TEST_ASSERT_EQUAL_STRING("{"
          "\"firmware\":{"
            "\"type\":\"my_firmware\","
            "\"version\":\"1.2.3\","
          "}"
        "}", report.report().c_str());
}

void setup() {
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(test_constructor);
}

void loop() {
  UNITY_END();
}