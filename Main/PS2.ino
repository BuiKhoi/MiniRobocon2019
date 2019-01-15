void GetControllerState() {
  Serial.println("Scanning");
  //Scan all button state for new events
  ps2x.read_gamepad(false, 0);
  if (true) {
    //Analog read
    Channels[0] = map(ps2x.Analog(PSS_LY), 256, 0, MIN_SPEED, MAX_SPEED);
    Channels[1] = map(ps2x.Analog(PSS_LX), 0, 256, MIN_SPEED, MAX_SPEED);
    Channels[2] = map(ps2x.Analog(PSS_RX), 0, 256, MIN_SPEED, MAX_SPEED);
    Channels[2] /= 1.5;

    //Moving buttons
    bool temp = ps2x.Button(PSB_TRIANGLE);
    if (temp != Butt[0]) {
      Butt[0] = temp;
      ProcessRelay(0);
    }

    temp = ps2x.Button(PSB_CROSS);
    if (temp != Butt[1]) {
      Butt[1] = temp;
      ProcessRelay(1);
    }

    temp = ps2x.Button(PSB_CIRCLE);
    if (temp != Butt[2]) {
      Butt[2] = temp;
      ProcessRelay(2);
    }

    temp = ps2x.Button(PSB_L1);
    if (temp != Butt[3]) {
      Butt[3] = temp;
      ProcessRelay(3);
    }
    
    temp = ps2x.Button(PSB_PAD_UP);
    if (temp != Butt[4]) {
      Butt[4] = temp;
      ProcessRelay(4);
    }

    temp = ps2x.Button(PSB_PAD_DOWN);
    if (temp != Butt[5]) {
      Butt[5] = temp;
      ProcessRelay(5);
    }

    temp = ps2x.Button(PSB_PAD_RIGHT);
    if (temp != Butt[6]) {
      Butt[6] = temp;
      ProcessRelay(6);
    }
  }
}
