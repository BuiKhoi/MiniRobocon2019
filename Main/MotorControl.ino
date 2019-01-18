void ProcessMotor() {
  int Motors[4] = {0};

  Motors[0] = -Channels[0];
  Motors[1] = Channels[0];
  Motors[2] = -Channels[0];
  Motors[3] = Channels[0];

  Motors[0] += -Channels[1];
  Motors[1] += -Channels[1];
  Motors[2] += Channels[1];
  Motors[3] += Channels[1];

  Motors[0] += -Channels[2];
  Motors[1] += -Channels[2];
  Motors[2] += -Channels[2];
  Motors[3] += -Channels[2];

  SetSpeed(Motors);
}

void PrintMotorSpeed(int *motors) {
  for (int i=0; i<4; i++) {
    Serial.print(motors[i]);
    Serial.print("  ");
  }
  Serial.println();
}

int SetSpeed(int* motors) {
  Constrains(motors);
//  PrintMotorSpeed(motors);
  for (int i=0; i<4; i++) {
    if (motors[i]>=0) {
      analogWrite(MotorInput[i], motors[i]);
      digitalWrite(MotorOutput[i], LOW);
    } else {
      analogWrite(MotorInput[i], 255+motors[i]);
      digitalWrite(MotorOutput[i], HIGH);
    }
  }
}

void StopAllMotors() {
  int m[4] = {0, 0, 0, 0};
  SetSpeed(m);
}

void Constrains(int *motors) {
  /*Gotta make sure every value is vaild*/
  int temp = MIN_SPEED;
  for (int i=0; i<4; i++) {
    if (motors[i]>temp) {
      temp = motors[i];
    }
  }

  if (temp>MAX_SPEED) {
    float ratio = (float)MAX_SPEED/temp;
    for (int i=0; i<4; i++) {
      motors[i]*=ratio;
    }
  }

  temp = MAX_SPEED;
  for (int i=0; i<4; i++) {
    if (motors[i]<temp) {
      temp = motors[i];
    }
  }

  if (temp<MIN_SPEED) {
    float ratio = (float)MIN_SPEED/temp;
    for (int i=0; i<4; i++) {
      motors[i]*=ratio;
    }
  }
}
