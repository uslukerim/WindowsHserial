#include <stdio.h>
#include <conio.h>
#include "tserial.h"
#include "bot_control.h"
#include <stdlib.h>
#include <stdint.h>
serial comm; //serial is a class type defined in these files, used for referring to the communication device
uint8_t asdf;
//unsigned char BootBinString[5712];

int main() {
static const int  BufferSize = 5792;
    int i;
    FILE *ptr;
    unsigned char buffer[BufferSize];
    ptr = fopen("Ledex.bin","rb");
    const size_t fileSize = fread(buffer, sizeof(unsigned char), BufferSize, ptr);
    fclose(ptr);

	
//char data; //To store the character to send
//printf("Enter character to be sent"); //User prompt
//scanf("%c",&data); //User input
comm.startDevice("COM6", 9600);
/* “COM 2” refers to the com port in which the USB to SERIAL port is attached. It is shown by right clicking on my computer, then going to properties and then device manager
9600 is the baud-rate in bits per second */
for(i = 0; i < (fileSize / sizeof(unsigned char)); i++)
    {
        //printf("0x%x ", (int)buffer2[i]);
        comm.send_data(buffer[i]); //The data is sent through the port

    }
//comm.send_data(data); //The data is sent through the port
comm.stopDevice(); //The device is closed down
printf("BootCode transmitted\n");
getch();
} 
