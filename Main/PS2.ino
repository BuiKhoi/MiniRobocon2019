SimpleKalmanFilter Ch0(10, 10, 5);
SimpleKalmanFilter Ch1(10, 10, 5);
SimpleKalmanFilter Ch2(10, 10, 5);

void PrintChannels() {
  Serial.print(Channels[0]);
  Serial.print("  ");
  Serial.print(Channels[1]);
  Serial.print("  ");
  Serial.print(Channels[2]);
  Serial.println("  ");
}

void GetControllerState() {
  Serial.println("Scanning");
  //Scan all button state for new events
  ps2x.read_gamepad(false, 0);
  if (true) {
    //Analog read
    Channels[0] = map(ps2x.Analog(PSS_LY), 256, 0, -255, 255);
    Channels[0] = Ch0.updateEstimate(Channels[0]);
    Channels[1] = map(ps2x.Analog(PSS_LX), 0, 256, -255, 255);
    Channels[1] = Ch1.updateEstimate(Channels[1]);
    Channels[2] = map(ps2x.Analog(PSS_RX), 0, 256, -255, 255);
    Channels[2] = Ch2.updateEstimate(Channels[2]);
    Channels[2] /= 1.5;

    for (int i=0; i<3; i++) {
      if (abs(Channels[i]) <= 100) {
        Channels[i] = 0;
      }
    }
    
//    PrintChannels();

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

    temp = ps2x.Button(PSB_PAD_LEFT);
    if (temp != Butt[7]) {
      Butt[7] = temp;
      ProcessRelay(7);
    }
  }
}
