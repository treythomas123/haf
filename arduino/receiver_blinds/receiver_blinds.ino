#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include <Servo.h>

RF24 radio(9,10);
Servo servo;

const uint64_t myAddress = 5;

const int payload_size = 32;
char receive_payload[payload_size+1]; // +1 to allow room for a terminating NULL char

void setup(void)
{
  servo.attach(7);
  servo.write(30);
  
  radio.begin();
  radio.setRetries(15,15);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(120);
  radio.openReadingPipe(1,myAddress);
  radio.startListening();
}

void loop(void)
{
    if ( radio.available() )
    {
      // Dump the payloads until we've gotten everything
      bool done = false;
      while (!done)
      {
        done = radio.read( receive_payload, payload_size );
        
        receive_payload[payload_size] = 0;
      }
      
      if ( receive_payload[0] == '1' )
        servo.write(30);
      else
        servo.write(150);
    }
}


