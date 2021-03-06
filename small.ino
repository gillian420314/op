//include library
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Define Variables
#define OLED_MOSI 11 //D1
#define OLED_CLK 12 //D0
#define OLED_DC 9 //DC
#define OLED_CS 8 //CS
#define OLED_RESET 10 //RES
#define Light_PIN A0
#define Button 2
int buttonState = 0;
int x = 0;
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
static const unsigned char PROGMEM LOGO[] = {
0x00,0x00,0x01,0x80,0x00,0x00,
0x00,0x03,0xff,0xff,0x80,0x00,
0x00,0x1f,0xff,0xff,0xf8,0x00,
0x00,0xff,0xf8,0x1f,0xfe,0x00,
0x03,0xff,0xf8,0x0f,0xff,0x80,
0x07,0xff,0xf8,0x0f,0xff,0xc0,
0x0f,0xff,0xff,0x7f,0xfe,0x00,
0x1f,0xff,0xff,0xff,0xf0,0x00,
0x3f,0xff,0xff,0xff,0x80,0x00,
0x7f,0xff,0xff,0xfe,0x00,0x00,
0x7f,0xff,0xff,0xf0,0x00,0x00,
0x7f,0xff,0xff,0x80,0x00,0x00,
0x7f,0xff,0xff,0xc0,0x00,0x00,
0x7f,0xff,0xff,0xf8,0x00,0x00,
0x3f,0xff,0xff,0xff,0x00,0x00,
0x3f,0xff,0xff,0xff,0xe0,0x00,
0x1f,0xff,0xff,0xff,0xfc,0x00,
0x0f,0xff,0xff,0xff,0xff,0x80,
0x07,0xff,0xff,0xff,0xff,0xc0,
0x01,0xff,0xff,0xff,0xff,0x80,
0x00,0x7f,0xff,0xff,0xfe,0x00,
0x00,0x0f,0xff,0xff,0xf0,0x00,
0x00,0x01,0xff,0xff,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
};
static const unsigned char PROGMEM LOGO1[] = {
0x00,0x00,0x01,0x80,0x00,0x00,
0x00,0x03,0xff,0xff,0x80,0x00,
0x00,0x1f,0xff,0xff,0xf8,0x00,
0x00,0xff,0xf8,0x1f,0xfe,0x00,
0x03,0xff,0xf8,0x0f,0xff,0x80,
0x07,0xff,0xf8,0x0f,0xff,0xe0,
0x0f,0xff,0xff,0x7f,0xff,0xf0,
0x1f,0xff,0xff,0xff,0xff,0xf8,
0x3f,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xf8,
0x1f,0xff,0xff,0xff,0xff,0xf8,
0x0f,0xff,0xff,0xff,0xff,0xf0,
0x07,0xff,0xff,0xff,0xff,0xc0,
0x01,0xff,0xff,0xff,0xff,0x80,
0x00,0x7f,0xff,0xff,0xfe,0x00,
0x00,0x0f,0xff,0xff,0xf0,0x00,
0x00,0x01,0xff,0xff,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
};

void text() { 
  display.setTextColor(WHITE);
  display.setTextSize(1.5);
  display.setCursor(60,15);
  display.print("Food");
  display.display();
}

void hunger() {
  /*display.clearDisplay();*/
  display.drawBitmap(x, 5, LOGO, 48, 24, WHITE);
  display.display();
  delay(300);
  /*display.clearDisplay();*/
  display.drawBitmap(x, 5, LOGO1, 48, 24, WHITE);
  display.display();
  delay(300);
  display.clearDisplay();
}

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  pinMode(Button, INPUT);
}

void loop() {
// put your main code here, to run repeatedly:
  buttonState = digitalRead(Button);
  if ( buttonState == HIGH ){
  x+=10;
  if(x>=140) x=0;
  }
  
  if (x <= 40) {text(); hunger();}
  else hunger();
}
