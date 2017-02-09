#include <iostream>

unsigned char data1[22] = { 0x02,0x7A,0x4E,0x30,0x30,0x20,0x47,0x30,0x30,0x20,0x58,0x31,0x30,0x2E,0x30,0x20,0x59,0x31,0x30,0x2E,0x30,0x0D };
unsigned char* data = &data[0];
unsigned char length = 22;

unsigned int crc_chk(unsigned char* data, unsigned char length)
{
	int j;
	unsigned int reg_crc = 0Xffff;
	while(length--)
	{
		reg_crc ^= *data++;
		for (j = 0; j<8; j++)
		{
			if (reg_crc & 0x01) 
				reg_crc = (reg_crc >> 1) ^ 0Xa001; /* LSB£¨b0£©=1 */
			else 
				reg_crc = reg_crc >> 1;
		}
	}
	return reg_crc; // the value that sent back to the CRC register finally
}


int main()
{
	unsigned int a = crc_chk(data1, length);
	std::cout << std::hex << a << std::endl;
	system("pause");
}


