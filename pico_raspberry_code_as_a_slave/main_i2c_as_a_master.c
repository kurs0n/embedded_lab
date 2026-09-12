#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include "pico/i2c_slave.h"
#include <stdio.h>
#include <string.h>

#define I2C_SLAVE_ADDRESS 0x17
#define PIN_SDA 0
#define PIN_SCL 1

int main(){
    stdio_init_all();
    gpio_pull_up(PIN_SDA);
    gpio_pull_up(PIN_SCL);
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);

    i2c_init(i2c0, 100 * 1000); // normal mode 100kHz
    
    uint8_t data_to_send[] = {0x01, 0x02, 0x03};
    uint8_t data_received[5];
    
    while(1){
        int bytes_written = i2c_write_blocking(i2c0, I2C_SLAVE_ADDRESS, data_to_send, 3, false);
        if (bytes_written == PICO_ERROR_GENERIC) {
            printf("Slave is not responding \n");
        } else {
            printf("Sent data");
        }
        sleep_ms(100);

        int bytes_read = i2c_read_blocking(i2c0, I2C_SLAVE_ADDRESS, data_received, 5, false);
        
        if (bytes_read == PICO_ERROR_GENERIC) {
            printf("error of reading\n");
        } else {
            printf("get data: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", 
                   data_received[0], data_received[1], data_received[2], 
                   data_received[3], data_received[4]);
        }

        sleep_ms(2000);
    }
}