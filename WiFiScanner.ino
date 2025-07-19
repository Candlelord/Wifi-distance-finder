#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

const int red = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  BLEDevice::init(""); //intializes BLE to start
  Serial.begin(115200);
  scan = BLEDevice::getScan(); //this will scan if we call it basically calls a method of a class without creating a object
  scan-> setActiveScan(true); //this will make it continously scan for bluetooth devices

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Scanning.......");
   //called scan and gave it a time of 1 sec to scan
  BLEAdvertisedDevice device = scan->start(1) //Creates a device object that stores the value of the targeted device which in the scase is my iphone

  if (device.getRSSI(0) > -30) { //check for distance (-dbm)
  digitalWrite(red, HIGH);
  Serial.println("ITS NEAR");
} else {
  digitalWrite(red, 0);
}
delay(30);
}
