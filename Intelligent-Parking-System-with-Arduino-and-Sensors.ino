// Include the necessary library to work with the OLED screen
#include "U8glib.h"

// Initialize the OLED screen
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST); // Fast I2C / TWI

// 'car_image', 40x20px
const unsigned char bitmap_car_image [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xfe, 0x00, 0x00, 0x60, 0x00, 0x03, 0x00, 0x0e, 
	0xdf, 0x80, 0xfd, 0xb8, 0x07, 0xbf, 0xff, 0xfe, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x60, 0x07, 0xff, 
	0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x0e, 0x00, 0x00, 0x00, 0x38, 0x0c, 0x00, 0x00, 
	0x00, 0x18, 0x18, 0x7f, 0xff, 0xff, 0x0c, 0x1f, 0xff, 0x80, 0xff, 0xfc, 0x1f, 0xff, 0x80, 0xff, 
	0xfc, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xfc, 
	0x1f, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0x80, 0x00, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0x00, 0xf8, 0x07, 
	0x00, 0x00, 0x00, 0x70
};
// 'sensor_01_a_off', 32x14px
const unsigned char bitmap_sensor_01_a_off [] PROGMEM = {
	0x00, 0x40, 0x00, 0x00, 0x02, 0xa8, 0x00, 0x00, 0x05, 0x55, 0x00, 0x00, 0x02, 0xaa, 0xa0, 0x00, 
	0x05, 0x55, 0x54, 0x00, 0x0a, 0xaa, 0xaa, 0xa0, 0x15, 0x55, 0x55, 0x50, 0x0a, 0xaa, 0xaa, 0xa0, 
	0x01, 0x55, 0x55, 0x40, 0x00, 0x2a, 0xaa, 0xa0, 0x00, 0x15, 0x55, 0x40, 0x00, 0x02, 0xaa, 0xa0, 
	0x00, 0x00, 0x15, 0x40, 0x00, 0x00, 0x02, 0x80
};
// 'sensor_01_a_on', 32x14px
const unsigned char bitmap_sensor_01_a_on [] PROGMEM = {
	0x00, 0x40, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 
	0x0f, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xe0, 
	0x03, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x03, 0xff, 0xe0, 
	0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x03, 0xc0
};
// 'sensor_01_b_off', 32x16px
const unsigned char bitmap_sensor_01_b_off [] PROGMEM = {
	0x02, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 0xa0, 0x00, 0x00, 0x05, 0x54, 0x00, 0x00, 
	0x0a, 0xaa, 0x80, 0x00, 0x15, 0x55, 0x50, 0x00, 0x0a, 0xaa, 0xaa, 0x80, 0x15, 0x55, 0x55, 0x50, 
	0x0a, 0xaa, 0xaa, 0xa8, 0x05, 0x55, 0x55, 0x50, 0x00, 0xaa, 0xaa, 0xa8, 0x00, 0x15, 0x55, 0x50, 
	0x00, 0x02, 0xaa, 0xa0, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x0a, 0xa0, 0x00, 0x00, 0x00, 0x50
};
// 'sensor_01_b_on', 32x16px
const unsigned char bitmap_sensor_01_b_on [] PROGMEM = {
	0x02, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 
	0x0f, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xf8, 
	0x1f, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xf8, 
	0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0xf0
};
// 'sensor_01_c_off', 32x17px
const unsigned char bitmap_sensor_01_c_off [] PROGMEM = {
	0x08, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0a, 0x80, 0x00, 0x00, 0x15, 0x50, 0x00, 0x00, 
	0x2a, 0xaa, 0x00, 0x00, 0x15, 0x55, 0x40, 0x00, 0x2a, 0xaa, 0xaa, 0x00, 0x55, 0x55, 0x55, 0x40, 
	0x2a, 0xaa, 0xaa, 0xaa, 0x15, 0x55, 0x55, 0x54, 0x02, 0xaa, 0xaa, 0xa8, 0x00, 0x55, 0x55, 0x54, 
	0x00, 0x0a, 0xaa, 0xa8, 0x00, 0x01, 0x55, 0x54, 0x00, 0x00, 0x2a, 0xa8, 0x00, 0x00, 0x01, 0x54, 
	0x00, 0x00, 0x00, 0x28
};
// 'sensor_01_c_on', 32x17px
const unsigned char bitmap_sensor_01_c_on [] PROGMEM = {
	0x08, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 
	0x3f, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xe0, 
	0x7f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xfc, 
	0x00, 0x1f, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x03, 0xfc, 
	0x00, 0x00, 0x00, 0x38
};
// 'sensor_01_d_off', 32x18px
const unsigned char bitmap_sensor_01_d_off [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x2a, 0x80, 0x00, 0x00, 
	0x55, 0x50, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x00, 0x55, 0x55, 0x40, 0x00, 0xaa, 0xaa, 0xaa, 0x00, 
	0x55, 0x55, 0x55, 0x50, 0x2a, 0xaa, 0xaa, 0xaa, 0x05, 0x55, 0x55, 0x54, 0x02, 0xaa, 0xaa, 0xaa, 
	0x00, 0x55, 0x55, 0x54, 0x00, 0x0a, 0xaa, 0xa8, 0x00, 0x01, 0x55, 0x54, 0x00, 0x00, 0x2a, 0xa8, 
	0x00, 0x00, 0x01, 0x54, 0x00, 0x00, 0x00, 0x08
};
// 'sensor_01_d_on', 32x18px
const unsigned char bitmap_sensor_01_d_on [] PROGMEM = {
	0x20, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 
	0xff, 0xf8, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xfe, 0x00, 
	0x7f, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xfe, 
	0x00, 0x7f, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 
	0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x1c
};
// 'sensor_02_a_off', 24x9px
const unsigned char bitmap_sensor_02_a_off [] PROGMEM = {
	0x2a, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x2a, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x2a, 0xaa, 0xaa, 0x55, 
	0x55, 0x55, 0x2a, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x2a, 0xaa, 0xaa
};
// 'sensor_02_a_on', 24x9px
const unsigned char bitmap_sensor_02_a_on [] PROGMEM = {
	0x3f, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 
	0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0xff, 0xff
};
// 'sensor_02_b_off', 32x9px
const unsigned char bitmap_sensor_02_b_off [] PROGMEM = {
	0x0a, 0xaa, 0xaa, 0xa8, 0x05, 0x55, 0x55, 0x50, 0x0a, 0xaa, 0xaa, 0xa8, 0x05, 0x55, 0x55, 0x50, 
	0x0a, 0xaa, 0xaa, 0xa8, 0x15, 0x55, 0x55, 0x54, 0x0a, 0xaa, 0xaa, 0xa8, 0x15, 0x55, 0x55, 0x54, 
	0x0a, 0xaa, 0xaa, 0xa8
};
// 'sensor_02_b_on', 32x9px
const unsigned char bitmap_sensor_02_b_on [] PROGMEM = {
	0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 
	0x0f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfc, 
	0x0f, 0xff, 0xff, 0xf8
};
// 'sensor_02_c_off', 32x10px
const unsigned char bitmap_sensor_02_c_off [] PROGMEM = {
	0x10, 0x00, 0x00, 0x04, 0x0a, 0xaa, 0xaa, 0xa8, 0x15, 0x55, 0x55, 0x54, 0x0a, 0xaa, 0xaa, 0xaa, 
	0x15, 0x55, 0x55, 0x54, 0x2a, 0xaa, 0xaa, 0xaa, 0x15, 0x55, 0x55, 0x54, 0x2a, 0xaa, 0xaa, 0xaa, 
	0x15, 0x55, 0x55, 0x54, 0x0a, 0xaa, 0xaa, 0xa8
};
// 'sensor_02_c_on', 32x10px
const unsigned char bitmap_sensor_02_c_on [] PROGMEM = {
	0x10, 0x00, 0x00, 0x04, 0x1f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xfe, 
	0x3f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xfe, 
	0x3f, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xf8
};
// 'sensor_02_d_off', 40x10px
const unsigned char bitmap_sensor_02_d_off [] PROGMEM = {
	0x01, 0x00, 0x00, 0x00, 0x40, 0x02, 0xaa, 0xaa, 0xaa, 0xa0, 0x05, 0x55, 0x55, 0x55, 0x50, 0x02, 
	0xaa, 0xaa, 0xaa, 0xa0, 0x05, 0x55, 0x55, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0xaa, 0xa0, 0x05, 0x55, 
	0x55, 0x55, 0x50, 0x02, 0xaa, 0xaa, 0xaa, 0xa0, 0x05, 0x55, 0x55, 0x55, 0x50, 0x00, 0xaa, 0xaa, 
	0xaa, 0x80
};
// 'sensor_02_d_on', 40x10px
const unsigned char bitmap_sensor_02_d_on [] PROGMEM = {
	0x03, 0x00, 0x00, 0x00, 0x60, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 
	0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 
	0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 
	0xff, 0xc0
};
// 'sensor_03_a_off', 32x14px
const unsigned char bitmap_sensor_03_a_off [] PROGMEM = {
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xaa, 0x00, 0x00, 0x05, 0x55, 0x00, 0x00, 0x2a, 0xaa, 0x00, 
	0x01, 0x55, 0x55, 0x00, 0x2a, 0xaa, 0xaa, 0x80, 0x55, 0x55, 0x55, 0x40, 0x2a, 0xaa, 0xaa, 0x80, 
	0x15, 0x55, 0x54, 0x00, 0x2a, 0xaa, 0xa0, 0x00, 0x15, 0x55, 0x40, 0x00, 0x2a, 0xaa, 0x00, 0x00, 
	0x15, 0x40, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00
};
// 'sensor_03_a_on', 32x14px
const unsigned char bitmap_sensor_03_a_on [] PROGMEM = {
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x3f, 0xff, 0x00, 
	0x03, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0x80, 
	0x3f, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x3f, 0xfe, 0x00, 0x00, 
	0x3f, 0xe0, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00
};
// 'sensor_03_b_off', 32x16px
const unsigned char bitmap_sensor_03_b_off [] PROGMEM = {
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0xaa, 0x80, 
	0x00, 0x05, 0x55, 0x40, 0x00, 0x2a, 0xaa, 0xa0, 0x05, 0x55, 0x55, 0x40, 0x2a, 0xaa, 0xaa, 0xa0, 
	0x55, 0x55, 0x55, 0x40, 0x2a, 0xaa, 0xaa, 0x80, 0x55, 0x55, 0x54, 0x00, 0x2a, 0xaa, 0xa0, 0x00, 
	0x15, 0x55, 0x00, 0x00, 0x2a, 0xa8, 0x00, 0x00, 0x15, 0x40, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00
};
// 'sensor_03_b_on', 32x16px
const unsigned char bitmap_sensor_03_b_on [] PROGMEM = {
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0xff, 0xc0, 
	0x00, 0x07, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xf0, 
	0x7f, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xf0, 0x00, 
	0x3f, 0xff, 0x80, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00
};
// 'sensor_03_c_off', 32x17px
const unsigned char bitmap_sensor_03_c_off [] PROGMEM = {
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x0a, 0xa8, 
	0x00, 0x00, 0x55, 0x54, 0x00, 0x02, 0xaa, 0xa8, 0x00, 0x55, 0x55, 0x54, 0x02, 0xaa, 0xaa, 0xaa, 
	0x55, 0x55, 0x55, 0x54, 0x2a, 0xaa, 0xaa, 0xa8, 0x15, 0x55, 0x55, 0x40, 0x2a, 0xaa, 0xaa, 0x00, 
	0x15, 0x55, 0x50, 0x00, 0x2a, 0xaa, 0x80, 0x00, 0x15, 0x54, 0x00, 0x00, 0x2a, 0x80, 0x00, 0x00, 
	0x14, 0x00, 0x00, 0x00
};
// 'sensor_03_c_on', 32x17px
const unsigned char bitmap_sensor_03_c_on [] PROGMEM = {
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 
	0x00, 0x00, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x7f, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0x00, 
	0x3f, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 
	0x1c, 0x00, 0x00, 0x00
};
// 'sensor_03_d_off', 32x18px
const unsigned char bitmap_sensor_03_d_off [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x01, 0x54, 0x00, 0x00, 0x02, 0xa8, 
	0x00, 0x00, 0x15, 0x54, 0x00, 0x00, 0xaa, 0xaa, 0x00, 0x05, 0x55, 0x54, 0x00, 0xaa, 0xaa, 0xaa, 
	0x15, 0x55, 0x55, 0x54, 0xaa, 0xaa, 0xaa, 0xa8, 0x55, 0x55, 0x55, 0x40, 0xaa, 0xaa, 0xaa, 0x80, 
	0x55, 0x55, 0x54, 0x00, 0x2a, 0xaa, 0xa0, 0x00, 0x55, 0x55, 0x00, 0x00, 0x2a, 0xa8, 0x00, 0x00, 
	0x55, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00
};
// 'sensor_03_d_on', 32x18px
const unsigned char bitmap_sensor_03_d_on [] PROGMEM = {
	0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x07, 0xfc, 
	0x00, 0x00, 0x3f, 0xfe, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xfe, 
	0x1f, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xfc, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 
	0x7f, 0x80, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00
};
// 'sound', 24x10px
const unsigned char bitmap_sound [] PROGMEM = {
	0x01, 0xc0, 0x07, 0x01, 0x04, 0x01, 0x01, 0x0c, 0x11, 0x01, 0x1c, 0x49, 0x01, 0x3d, 0x29, 0x01, 
	0x3d, 0x29, 0x01, 0x1c, 0x49, 0x01, 0x0c, 0x11, 0x01, 0x04, 0x01, 0x01, 0xc0, 0x07
};

// 'sound off', 24x10px
const unsigned char bitmap_sound_off [] PROGMEM = {
	0x01, 0xc0, 0x07, 0x01, 0x04, 0x01, 0x01, 0x0d, 0x09, 0x01, 0x1c, 0x91, 0x01, 0x3c, 0x41, 0x01, 
	0x3c, 0x21, 0x01, 0x1c, 0x91, 0x01, 0x0d, 0x09, 0x01, 0x04, 0x01, 0x01, 0xc0, 0x07
};

// 'unit_cm', 24x10px
const unsigned char bitmap_unit_cm [] PROGMEM = {
	0xe0, 0x01, 0xc0, 0x80, 0x00, 0x40, 0xbe, 0xff, 0x40, 0xb6, 0xdb, 0x40, 0xb0, 0xdb, 0x40, 0xb0, 
	0xdb, 0x40, 0xb6, 0xdb, 0x40, 0xbe, 0xdb, 0x40, 0x80, 0x00, 0x40, 0xe0, 0x01, 0xc0
};



/*
  Fontname: ProjectDigits
  Copyright: Created with Fony 1.4.7
  Capital A Height: 0, '1' Height: 6
  Calculated Max Values w= 6 h= 6 x= 2 y= 0 dx= 9 dy= 0 ascent= 0 len= 6
  Font Bounding box     w= 9 h= 5 x= 0 y=-6
  Calculated Min Values           x= 0 y=-6 dx= 0 dy= 0
  Pure Font   ascent = 6 descent= 0
  X Font      ascent = 6 descent= 0
  Max Font    ascent = 0 descent=-6
*/

const u8g_fntpgm_uint8_t ProjectDigits[137] U8G_FONT_SECTION("ProjectDigits") = {
  0,9,5,0,250,6,0,0,0,0,48,57,0,0,250,6,
  0,5,6,6,9,2,250,248,216,216,216,216,248,4,6,6,
  9,2,250,224,96,96,96,96,240,5,6,6,9,0,250,248,
  24,120,192,192,248,6,6,6,9,0,250,252,12,252,12,204,
  252,5,6,6,9,0,250,56,120,216,248,24,24,6,6,6,
  9,0,250,252,192,252,12,12,252,5,6,6,9,0,250,248,
  192,248,216,216,248,5,6,6,9,0,250,248,24,24,24,24,
  24,5,6,6,9,0,250,248,216,248,216,216,248,5,6,6,
  9,0,250,248,216,216,248,24,248};


// Define the pins for each sensor
#define sensor_01_ECHO_PIN 6
#define sensor_01_TRIG_PIN 7
#define sensor_02_ECHO_PIN 4
#define sensor_02_TRIG_PIN 5
#define sensor_03_ECHO_PIN 2
#define sensor_03_TRIG_PIN 3
#define BUZZER_PIN 8
#define BUTTON_PIN 9  

#define nrSensors 3  // Number of sensors

// Structure for storing data of each sensor
struct sensor_data{
    int echo_pin;
    int trig_pin;
    int measured_distance_cm;  // Measured distance in cm
    int label_posX;            // Label position on the X-axis
    int label_posY;            // Label position on the Y-axis
    int label_width;           // Label width
};

char buffer[10];  // Buffer for storing data

struct sensor_data sensor[nrSensors];  // Array of structures for storing sensor data

int min_dist = 10; 	// Minimum distance in cm
int max_dist = 100; // Maximum distance in cm

// Distances for each step (there are 4 steps for each sensor)
int dist_step_1;	
int dist_step_2;	
int dist_step_3;  
int dist_step_4;  

bool isSoundOn = true; // Declare isSoundOn and initialize it to true
int lastButtonState = HIGH; // Declare lastButtonState and initialize it to HIGH

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Set the distances for each step
  dist_step_1 = 10;
  dist_step_2 = 25;
  dist_step_3 = 50;
  dist_step_4 = 100;

  // Initialize the pins for sensors
  sensor[0].echo_pin = sensor_01_ECHO_PIN;
  sensor[0].trig_pin = sensor_01_TRIG_PIN;
  sensor[1].echo_pin = sensor_02_ECHO_PIN;
  sensor[1].trig_pin = sensor_02_TRIG_PIN;
  sensor[2].echo_pin = sensor_03_ECHO_PIN;
  sensor[2].trig_pin = sensor_03_TRIG_PIN;

  // Set the mode of the pins for each sensor
  pinMode(sensor[0].trig_pin, OUTPUT);
  pinMode(sensor[0].echo_pin, INPUT);
  pinMode(sensor[1].trig_pin, OUTPUT);
  pinMode(sensor[1].echo_pin, INPUT);
  pinMode(sensor[2].trig_pin, OUTPUT);
  pinMode(sensor[2].echo_pin, INPUT);

  // Set the position of the labels for each sensor
  sensor[0].label_posX = 30;
  sensor[0].label_posY = 58;
  sensor[1].label_posX = 67;
  sensor[1].label_posY = 58;
  sensor[2].label_posX = 100;
  sensor[2].label_posY = 58;

  // Set the font and color for the OLED screen
  u8g.setFont(ProjectDigits);
  u8g.setColorIndex(1);

  // Initialize the serial communication
  Serial.begin(115200);
}

void loop() {

    int buttonState = digitalRead(BUTTON_PIN);
    Serial.println(buttonState); // Print the state of the button
    if(buttonState == LOW && lastButtonState == HIGH) {    // Button is pressed if the reading is LOW and it was HIGH in the last iteration
        isSoundOn = !isSoundOn; // Toggle isSoundOn
        delay(100); // Wait for 100ms to debounce the button
    }
    lastButtonState = buttonState; // Update lastButtonState

    // Loop over each sensor
  for(int i = 0; i < nrSensors; i++){
    // Trigger the sensor
    digitalWrite(sensor[i].trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor[i].trig_pin, LOW);

    // Read the echo time and convert it to distance in cm
    sensor[i].measured_distance_cm = pulseIn(sensor[i].echo_pin, HIGH);
    sensor[i].measured_distance_cm = round(sensor[i].measured_distance_cm * 0.0343/2.0);

    // Convert the measured distance to string and calculate the label width
    itoa(sensor[i].measured_distance_cm, buffer, 10);
    sensor[i].label_width = u8g.getStrWidth(buffer);

  if(isSoundOn==true){
		// If the measured distance is less than 10 cm
    if(sensor[i].measured_distance_cm < 10) {
    // Sound the buzzer with a high frequency tone
      tone(BUZZER_PIN, 1000, 250);
      delay(150);  // Beep for 100ms
      noTone(BUZZER_PIN);  // Stop the sound
  }
    // Else if the measured distance is less than 25 cm
    else if(sensor[i].measured_distance_cm < 25) {
    // Sound the buzzer with a medium-high frequency tone
      tone(BUZZER_PIN, 800, 250);
      delay(150);  // Beep for 100ms
      noTone(BUZZER_PIN);  // Stop the sound
  }
    // Else if the measured distance is less than 50 cm
    else if(sensor[i].measured_distance_cm < 50) {
    // Sound the buzzer with a medium-low frequency tone
      tone(BUZZER_PIN, 600, 250);
      delay(150);  // Beep for 100ms
      noTone(BUZZER_PIN);  // Stop the sound
  }
    // Else if the measured distance is less than 100 cm
    else if(sensor[i].measured_distance_cm < 100) {
    // Sound the buzzer with a low frequency tone
      tone(BUZZER_PIN, 10, 250);
      delay(150);  // Beep for 100ms
      noTone(BUZZER_PIN);  // Stop the sound
  }
  }
}

  // Start drawing on the display
  u8g.firstPage();
  do {
    // Draw the car image, sound indicator, and unit indicator
    u8g.drawBitmapP(45, 0, 40/8, 20, bitmap_car_image);
    u8g.drawBitmapP(1, 2, 24/8, 10, bitmap_unit_cm);

    if(isSoundOn==true) {
    // Display the "sound on" image
    u8g.drawBitmapP(103, 2, 24/8, 10, bitmap_sound);
    } else {
    // Display the "sound off" image
    u8g.drawBitmapP(103, 2, 24/8, 10, bitmap_sound_off);
    }

    // For each sensor, draw four rectangles (one for each distance step)
    // The rectangles are colored based on the measured distance
    // Also draw the label with the measured distance
    u8g.drawBitmapP(26, 17, 32/8, 14, sensor[0].measured_distance_cm > dist_step_1 ? bitmap_sensor_01_a_on : bitmap_sensor_01_a_off);
    u8g.drawBitmapP(23, 25, 32/8, 16, sensor[0].measured_distance_cm > dist_step_2 ? bitmap_sensor_01_b_on : bitmap_sensor_01_b_off);
    u8g.drawBitmapP(20, 34, 32/8, 17, sensor[0].measured_distance_cm > dist_step_3 ? bitmap_sensor_01_c_on : bitmap_sensor_01_c_off);
    u8g.drawBitmapP(18, 43, 32/8, 18, sensor[0].measured_distance_cm > dist_step_4 ? bitmap_sensor_01_d_on : bitmap_sensor_01_d_off);

    u8g.drawBitmapP(53, 23, 24/8, 9, sensor[1].measured_distance_cm > dist_step_1 ? bitmap_sensor_02_a_on : bitmap_sensor_02_a_off);
    u8g.drawBitmapP(49, 33, 32/8, 9, sensor[1].measured_distance_cm > dist_step_2 ? bitmap_sensor_02_b_on : bitmap_sensor_02_b_off);
    u8g.drawBitmapP(49, 42, 32/8, 10, sensor[1].measured_distance_cm > dist_step_3 ? bitmap_sensor_02_c_on : bitmap_sensor_02_c_off);
    u8g.drawBitmapP(45, 52, 40/8, 10, sensor[1].measured_distance_cm > dist_step_4 ? bitmap_sensor_02_d_on : bitmap_sensor_02_d_off);

    u8g.drawBitmapP(76, 17, 32/8, 14, sensor[2].measured_distance_cm > dist_step_1 ? bitmap_sensor_03_a_on : bitmap_sensor_03_a_off);
    u8g.drawBitmapP(78, 25, 32/8, 16, sensor[2].measured_distance_cm > dist_step_2 ? bitmap_sensor_03_b_on : bitmap_sensor_03_b_off);
    u8g.drawBitmapP(79, 34, 32/8, 17, sensor[2].measured_distance_cm > dist_step_3 ? bitmap_sensor_03_c_on : bitmap_sensor_03_c_off);
    u8g.drawBitmapP(82, 43, 32/8, 18, sensor[2].measured_distance_cm > dist_step_4 ? bitmap_sensor_03_d_on : bitmap_sensor_03_d_off);

	for(int i=0; i<nrSensors; i++){
		// Draw a box around the label
      u8g.setColorIndex(0);
      u8g.drawBox((sensor[i].label_posX - sensor[i].label_width /2) - 2,sensor[i].label_posY - 4,sensor[i].label_width,8);
      // Convert the measured distance to string
      itoa(sensor[i].measured_distance_cm, buffer, 10);
      // Draw the label with the measured distance
      u8g.setColorIndex(1);
      u8g.drawStr(sensor[i].label_posX - sensor[i].label_width /2, sensor[i].label_posY - 3, buffer);
    }
  } while ( u8g.nextPage() );  // Continue drawing until all pages have been displayed
}
