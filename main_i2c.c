#include "header.h"

int main()
{
// 	unsigned char temp;
// 	i2c_init();
// 	uart1_init(9600);
// 	uart1_tx_string("I2C\r\n");
// 	i2c_byte_write_frame(0xD0,0x0,0x45);
// 	temp=i2c_byte_read_frame(0xD0,0x0);
	
	u8 h,m,s;
	i2c_init();
	uart1_init(9600);
	uart1_tx_string("DS1307 RTC\r\n");
	
	//set rtc time to 11:59:50 PM
	i2c_byte_write_frame(0xD0,0x2,0x23);	//set hrs
	i2c_byte_write_frame(0xD0,0x1,0x59);	//set min
	i2c_byte_write_frame(0xD0,0x0,0x50);	//set sec

	//set rtc time & dump on serial terminal
	while(1)
	{
		h=i2c_byte_read_frame(0xD0,0x2);
		m=i2c_byte_read_frame(0xD0,0x1);
		s=i2c_byte_read_frame(0xD0,0x0);
		
		uart1_tx_char((h/0x10)+48);
		uart1_tx_char((h%0x10)+48);
		uart1_tx_char(':');
	
		uart1_tx_char((m/0x10)+48);
		uart1_tx_char((m%0x10)+48);
		uart1_tx_char(':');
		
		uart1_tx_char((s/0x10)+48);
		uart1_tx_char((s%0x10)+48);
		uart1_tx_char('\r');
	}
}






