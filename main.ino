#include <HX711.h>

const int DOUT = 4; // Data Output to Digital Pin 4
const int CLK = 5; // Clock input Digital Pin 5
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
  Serial.print(voltage);
  Serial.println(" volts");
  double mass ; // Set equal to equation connecting voltage and mass
  Serial.print("Mass:\t\t");
  Serial.print(mass);
  Serial.println(" g");
  double force = mass *9.807;
  Serial.print("Force:\t\t");
  Serial.print(force);
  Serial.println(" N");
}