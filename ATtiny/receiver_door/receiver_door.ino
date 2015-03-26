#include <nRF24L01.h>
#include <RF24rec.h>
#include <RF24rec_config.h>
#include <SPI85.h>

RF24rec radio(PB4);

const uint64_t myAddress = 3;

const int payload_size = 32;
char receive_payload[payload_size+1]; // +1 to allow room for a terminating NULL char

void setup(void)
{
  pinMode(PB3,OUTPUT);
  pinMode(PB5,OUTPUT);
  
  digitalWrite(PB3,LOW);
  digitalWrite(PB5,LOW);
  
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
      
      if ( receive_payload[0] == '1' ) {
        
        // Lock
        digitalWrite(PB3,HIGH);
        delay(100);
        digitalWrite(PB3,LOW);
        
      } else {
        
        // Unlock
        for ( int i = 0, i < 4, i++ ) {

          digitalWrite(PB5,HIGH);
          delay(100);
          digitalWrite(PB5,LOW);
          delay(100);
        
        }

      }
      
    }
}


