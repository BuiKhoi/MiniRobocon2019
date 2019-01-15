#include <PS2X_lib.h>

PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;

int PS2_DAT      = 14;  //14
int PS2_CMD      = 15;  //15
int PS2_SEL      = 17;  //16
int PS2_CLK      = 16;  //17

void setup() {
  Serial.begin(9600);
  Serial.println("Serial started");
  delay(300);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  while (error != 0);
  type = ps2x.readType();
  while (type != 1);
}

void loop() {
  GetControllerState();
}

void GetControllerState() {
  //Scan all button state for new events
  ps2x.read_gamepad(false, 0);
  if (true) {
    //Analog read
    Serial.print("Channel 0: ");
    Serial.println(ps2x.Analog(PSS_LY));

    //Moving buttons
    bool temp = ps2x.Button(PSB_L1);
    if (temp) {
      Serial.println("Button 0");
    }

    temp = ps2x.Button(PSB_L2);
    if (temp) {
      Serial.println("Button 1");
    }

    temp = ps2x.Button(PSB_CIRCLE);
    if (temp) {
      Serial.println("Button 2");
    }

    temp = ps2x.Button(PSB_CROSS);
    if (temp) {
      Serial.println("Button 3");
    }
  }
}
