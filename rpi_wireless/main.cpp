#include <cstdlib>
#include <iostream>
#include "lib/RF24/RF24.h"
#include "lib/RF24/compatibility.h"

using namespace std;

RF24 radio(8, 25);

uint64_t addresses[] = {
	0xF0F0F0F0E1LL,
	0xF0F0F0F0E2LL,
	0x0000000000LL
};

void setup(uint64_t address)
{
	radio.begin();
	radio.enableDynamicPayloads();
	radio.setRetries(15,15);
	radio.setDataRate(RF24_250KBPS);
	radio.setPALevel(RF24_PA_HIGH);
	radio.setChannel(120);
	radio.setCRCLength(RF24_CRC_16);
	
	radio.openWritingPipe( address );
}

int main(int argc, char** argv) 
{
	printf("Setup using address index from first argument: %s\n",argv[1]);
	setup( addresses[ atoi(argv[1]) ] );
	
	printf("Build command from second argument: %s\n",argv[2]);
	char command[32];
	sprintf(command, "%s", argv[2] );
	
	printf("Write command to radio...\n");
	radio.write( command, 32);
	
	return 0;
}
