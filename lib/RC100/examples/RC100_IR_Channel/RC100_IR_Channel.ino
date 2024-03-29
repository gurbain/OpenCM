/*
  IR Remote control using RC-100 and IR receiver
 
 Demonstrates communication the OpenCM9.04 and RC100 with IR Receiver
 RC100 is a remote controller with built-in IR module
 IR Receiver can be connected to 4 pin communication port and controlled by RC-100
 You can buy it the link below.(Korea only)
 [RC-100] Controller like joystick
 http://www.robotis-shop-kr.com/goods_detail.php?goodsIdx=817
 
 You can connect the below products to RC-100 in CM-900
 [BT-110A] or [BT-110A Set]
 http://www.robotis-shop-kr.com/goods_detail.php?goodsIdx=875
 [ZIG-110A Set]
 http://www.robotis-shop-kr.com/goods_detail.php?goodsIdx=405
 [LN-101] download tool in CM-100
 http://www.robotis-shop-kr.com/goods_detail.php?goodsIdx=348
 
 You can also find all information about ROBOTIS products
 http://support.robotis.com/
 
 created 19 Dec 2012
 by ROBOTIS CO,.LTD.
 */

#include <RC100.h>

RC100 Controller;

void setup() {
  pinMode(BOARD_LED_PIN, OUTPUT);
  Controller.begin(2); // RC100 init as IR mode
  Controller.setChannel(2);
}
int RcvData =0;

void loop() {

  if(Controller.available()){
    RcvData = Controller.readData();
    SerialUSB.print("RcvData = ");
    SerialUSB.println(RcvData);

    if(RcvData & RC100_BTN_1)
      digitalWrite(BOARD_LED_PIN,LOW);


    delay(100);
  }
  digitalWrite(BOARD_LED_PIN,HIGH);

}
/* defines for RC100 in the RC100.h
 Controller.begin(1);  ----> Bluetooth/Zigbee Mode
 Controller.begin(2);  ----> IR Mode
 
 #define RC100_BTN_U		(1)
 #define RC100_BTN_D		(2)
 #define RC100_BTN_L		(4)
 #define RC100_BTN_R		(8)
 #define RC100_BTN_1		(16)
 #define RC100_BTN_2		(32)
 #define RC100_BTN_3		(64)
 #define RC100_BTN_4		(128)
 #define RC100_BTN_5		(256)
 #define RC100_BTN_6		(512)
 */


