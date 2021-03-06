/*
 * MIT License
Copyright (c) 2017 DeeplyEmbedded
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 * cc3200_ds18b20.h
 *
 * Created on  : Jan 21, 2018
 *
 * Author      : Vinay Divakar
 *
 * Website     : www.deeplyembedded.org
 */

#ifndef CC3200_DS18B20_H_
#define CC3200_DS18B20_H_

typedef enum{
    DQ_SWITCH_TO_OUTPUT,
    DQ_SWITCH_TO_INPUT,
    DQ_INVALID_STATE
}DQ_PIN_STATE;

typedef enum{
    EXTERNAL_POWERED,
    PARASITIC_POWERED,
    ERROR
}DS18B20_POWER_STATE;

typedef struct{
  unsigned char temp_LSB;
  unsigned char temp_MSB;
  unsigned char TH_alarm;
  unsigned char TL_alarm;
  unsigned char config_reg;
}ds18b20_sram_T, *ds18b20_sram_Ptr;

typedef struct{
    float celsius;
    float fahrenheit;
}ds18b20_temp_T, *ds18b20_temp_Ptr;

extern void ds18b20_Init();
extern void dq_switch_state(DQ_PIN_STATE dq_state);
extern void ds18b20_send_reset_pulse(int level_rst_us);
extern int ds18b20_detect_presence();
extern int ds18b20_initialization_proc();
extern void ds182b0_write_bit(unsigned char ds182b0_wbit);
extern void ds182b0_write_byte(unsigned char ds182b0_wbyte, unsigned char flag);
extern void ds18b20_write_bytes(const unsigned char *buff_wptr, int num);
extern unsigned char ds18b20_read_bit();
extern unsigned char ds18b20_read_byte();
extern void ds18b20_read_bytes(unsigned char *buff_rptr, int count);
extern int ds18b20_single_read_ROM_addr(unsigned char *buff_rom_addr_ptr);
extern unsigned char crc8( unsigned char *addr, unsigned char len);
extern int ds18b20_read_temperature(const unsigned char *ds182b0_addr,
                             ds18b20_temp_Ptr ds18b20_temp_ptr);
extern int ds18b20_load_eeprom(const unsigned char *ds182b0_addr,
                        unsigned char parasite);
extern int ds18b20_write_scratchpad(unsigned char temp_TH,
                             unsigned char temp_TL,
                             unsigned char config,
                             const unsigned char *ds182b0_addr);
extern int ds18b20_read_scratchpad(const unsigned char *ds182b0_addr,
                                   ds18b20_sram_Ptr ds18b20_sram_ptr);
extern DS18B20_POWER_STATE check_power_supply(const unsigned char *ds182b0_addr);

#endif /* CC3200_DS18B20_H_ */
