#include <stdio.h>
#include <rt/rt_api.h>
#include <stdint.h>

int __rt_fpga_fc_frequency = 		10000000; // e.g. 20000000 for 20MHz;
int __rt_fpga_periph_frequency =	 5000000; // e.g. 10000000 for 10MHz;

#define BUFFER_SIZE 3

RT_L2_DATA uint8_t tx_buffer[BUFFER_SIZE];
RT_L2_DATA uint8_t rx_buffer[BUFFER_SIZE];


int main()
{
  printf("Entering test\r\n");

  rt_i2c_conf_t conf;

  rt_i2c_conf_init(&conf);

  // This will tell the driver to use the i2c 0 interface (in case there are several)
  conf.id = 0;
  conf.cs = 0x5B;	// CCS811
  conf.max_baudrate = 100000;

  rt_i2c_t *i2c = rt_i2c_open(NULL, &conf, NULL);
  if (i2c == NULL) return -1;

  for (int i=0; i<BUFFER_SIZE; i++)
  {
    tx_buffer[i] = i;
  }

  // No event is specified so we are doing a blocking call, which means
  // we are blocked on this call until the whole buffer is sent
  // rt_i2c_write(i2c, tx_buffer, BUFFER_SIZE, 0, NULL);
  rt_i2c_write(i2c, 0x20, 1, 0, NULL);		// Read reg 0x20 (HW_ID)

  rt_i2c_read(i2c, rx_buffer, 1, 0, NULL);	// Retrieve HW_ID
  
  printf("HW_ID: 0x%02x\r\n", rx_buffer[0]);

  //rt_i2c_control(i2c, RT_I2C_CTRL_SET_MAX_BAUDRATE, 2000000);

  // volatile int i;
  // for (i=0; i<10000; i++);
  
  // rt_i2c_write(i2c, tx_buffer, BUFFER_SIZE, 0, NULL);

  return 0;
}
