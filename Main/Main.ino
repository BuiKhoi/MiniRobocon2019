#include <PS2X_lib.h>
#include <SimpleKalmanFilter.h>

const byte MotorInput[4] = {12, 3, 8, 5};
const byte MotorOutput[4] = {13, 2, 9, 6};

const byte ArmUp = 39;
const byte ArmDown = 41;
const byte Hand = 35;
const byte Pullout = 37;
const byte Handout = 25;
const byte Handin = 23;

#define MAX_DEFINE_SPEED 90

int MAX_SPEED = MAX_DEFINE_SPEED;
int MIN_SPEED = -MAX_SPEED;

int Channels[3] = {0, 0, 0};
bool Butt[8] = {false};

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
  for (int i=0; i<4; i++) {
    pinMode(MotorInput[i], OUTPUT);
    pinMode(MotorOutput[i], OUTPUT);
  }

  pinMode(ArmUp, OUTPUT);
  pinMode(ArmDown, OUTPUT);
  pinMode(Hand, OUTPUT);
  pinMode(Pullout, OUTPUT);
  pinMode(Handout, OUTPUT);
  pinMode(Handin, OUTPUT);
  Serial.println("Configuring controller");
  delay(500);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  while (error != 0) {
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
    delay(200);
  }
  type = ps2x.readType();
  while (type != 1);
  SystemInit();
  Serial.println("System started");
}

void loop() {
  GetControllerState();
  ProcessMotor();
}

void SystemInit() {
  StopAllMotors();
  digitalWrite(ArmUp, LOW);
  digitalWrite(ArmDown, HIGH);
  digitalWrite(Hand, HIGH);
  digitalWrite(Pullout, HIGH);
  digitalWrite(Handout, LOW);
  digitalWrite(Handin, HIGH);
}
