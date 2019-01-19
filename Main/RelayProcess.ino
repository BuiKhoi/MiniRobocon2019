void ProcessRelay(int index) {
  switch (index) {
    case 0: { // Move arm up
        if (Butt[0]) {
          Serial.println("Arm up");
          digitalWrite(ArmUp, LOW);
          digitalWrite(ArmDown, LOW);
        } else {
          digitalWrite(ArmUp, HIGH);
          digitalWrite(ArmDown, LOW);
        }
        break;
      }
    case 1: { //Move arm down
        if (Butt[1]) {
          Serial.println("Arm down");
          digitalWrite(ArmUp, HIGH);
          digitalWrite(ArmDown, HIGH);
        } else {
          digitalWrite(ArmUp, HIGH);
          digitalWrite(ArmDown, LOW);
        }
        break;
      }
    case 2: { //Hand grab
        static bool count = false;
        if (Butt[2]) {
          count = !count;
        }
        if (count) {
          Serial.println("Hand grab");
          digitalWrite(Hand, LOW);
        } else {
          digitalWrite(Hand, HIGH);
        }
        break;
      }
    case 3: { //Pull the arm out
        if (Butt[3]) {
          Serial.println("Arm out");
          digitalWrite(Pullout, LOW);
        } else {
          digitalWrite(Pullout, HIGH);
        }
        break;
      }
    case 4: { //Stretch the arm
        if (Butt[4]) {
          Serial.println("Arm stretched");
          digitalWrite(Handout, LOW);
          digitalWrite(Handin, LOW);
        } else {
          digitalWrite(Handout, HIGH);
          digitalWrite(Handin, LOW);
        }
        break;
      }
      case 5: {
        if (Butt[5]) {
          Serial.println("Arm destretched");
          digitalWrite(Handout, HIGH);
          digitalWrite(Handin, HIGH);
        } else {
          digitalWrite(Handout, LOW);
          digitalWrite(Handin, HIGH);
        }
        break;
      }
      case 6: {
        static bool count = false;
        if (Butt[6]) {
          count = !count;
        }
        if (count) {
          MAX_SPEED = 50;
          MIN_SPEED = -MAX_SPEED;
        } else {
          MAX_SPEED = MAX_DEFINE_SPEED;
          MIN_SPEED = -MAX_SPEED;
        }
      }

      case 7: {
        static bool count = false;
        if (Butt[7]) {
          count = !count;
        }
        if (count) {
          MAX_SPEED = 120;
          MIN_SPEED = -MAX_SPEED;
        } else {
          MAX_SPEED = MAX_DEFINE_SPEED;
          MIN_SPEED = -MAX_SPEED;
        }
      }
      case 8: {
        static bool count = false;
        if (Butt[8]) {
          count = !count;
        }
        if (count) {
          BLDC.writeMicroseconds(2000);
        } else {
          BLDC.writeMicroseconds(1000);
        } 
      }
  }
}
