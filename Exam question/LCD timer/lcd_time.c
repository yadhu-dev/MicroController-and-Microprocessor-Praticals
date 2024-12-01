#include <reg51.h>

sbit RS = P1^0;
sbit EN = P1^1;

void delay(unsigned int time) {
    int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1273; j++);
    }
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    RS = 0;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_data(unsigned char dat) {
    P2 = dat;
    RS = 1;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_init() {
    delay(20);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    delay(20);
}

void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

void lcd_display_time(unsigned char hour, unsigned char min, unsigned char sec) {
    lcd_cmd(0x80);

    lcd_data((hour / 10) + '0');
    lcd_data((hour % 10) + '0');
    lcd_data(':');

    lcd_data((min / 10) + '0');
    lcd_data((min % 10) + '0');
    lcd_data(':');

    lcd_data((sec / 10) + '0');
    lcd_data((sec % 10) + '0');
}

void main() {
    unsigned char hours = 0, minutes = 0, seconds = 0;

    lcd_init();

    while (1) {
        lcd_display_time(hours, minutes, seconds);
        delay(1000);

        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }
}
