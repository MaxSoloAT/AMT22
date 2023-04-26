#define ENC_0 9
#define ENC_1 10
#define SPI_MOSI        11
#define SPI_MISO        12
#define SPI_SCLK        13


#include "AMT22.h"

uint16_t pos = 0;
float pos_angle;
AMT22 ENC0(ENC_0, SPI_MOSI, SPI_MISO, SPI_SCLK);
void setup() {
  Serial.begin(115200);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  SPI.begin();
}

void loop() {
  pos = ENC0.getPosition();
  if (pos == 0xFFFF) //position is bad or some issuse
    {
      Serial.println("Encoder 0 error");
    }
    else{  
      Serial.println(pos);
    }
  pos_angle = ENC0.angle;
  Serial.println(pos_angle);
}
