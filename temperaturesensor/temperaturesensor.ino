float lowTemp = 73.5;
float highTemp = 85;


#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}

void loop(void){ 
  sensors.requestTemperatures(); 
  Serial.print("Fahrenheit temperature: ");
  float tempF = sensors.getTempFByIndex(0);
  Serial.println(tempF);
  int mappedVal = map(tempF * 100, lowTemp * 100, highTemp * 100, 0, 255);
  //Serial.print("MappedVal: ");
  //Serial.println(mappedVal);
  if (tempF > highTemp ) {
    analogWrite(11, 0);
    analogWrite(9, 255);
  } else if (tempF < lowTemp) {
    analogWrite(11, 255);
    analogWrite(9, 0);
  } else {
    analogWrite(11, 255-((int) mappedVal));
    analogWrite(9, (int)mappedVal);
  }
}