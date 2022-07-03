#include <HX711.h>

const int DOUT = 4;
const int CLK = 5;
HX711 scale;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  scale.begin(DOUT, CLK); 
}

void loop() {
  // Oversampling
  long adc = scale.read_average(25);
  //(2^24)-1
  // 24 bit ADC
  double voltage = 5.0*adc/16777215;
  Serial.print("Voltage:\t\t");
  Serial.println(voltage);
}
