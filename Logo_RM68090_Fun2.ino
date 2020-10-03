   //////////////////////////////////////////////
  //        2.8" TOUCH SCREEN DEMO            //
 //             http://intmain.xyz +                             //
//           http://www.educ8s.tv           //
/////////////////////////////////////////////

#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 204
#define TS_MINY 195
#define TS_MAXX 948
#define TS_MAXY 910

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

boolean buttonEnabled = true;

void setup() {
  Serial.begin(9600);
  Serial.print("Starting..!.");
  
  tft.reset();
  tft.begin(0x9325);
  tft.setRotation(1);
  
  tft.fillScreen(BLACK);

  //Draw white frame
  tft.drawRect(0,0,319,240,WHITE);
    tft.drawRect(319,240,638,480,WHITE);
  //Print "Hello" Text
  tft.setCursor(100,30);
  tft.setTextColor(GREEN);
  tft.setTextSize(4);
  tft.print("say:#_");
  
  //Print "hacks int!" text 
  tft.setCursor(80,100);
  tft.setTextColor(MAGENTA);
  tft.setTextSize(1);
  tft.print(" tft.setCursor(80,100);x1");


 //Create Key A Button
  tft.fillRect(70,100, 12, 10, BLUE);
  tft.drawRect(70,100,12,10,GREEN);
  tft.setCursor(70,100);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("AaaA");

 //Create Key B Button
  tft.fillRect(82,100, 12, 10, MAGENTA);
  tft.drawRect(82,100,12,10,CYAN);
  tft.setCursor(67,138);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("BbbB");


 //Create Key C Button
  tft.fillRect(94,100, 12, 10, MAGENTA);
  tft.drawRect(94,100,12,10,GREEN);
  tft.setCursor(67,138);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("CccC");


 //Create Key D Button
  tft.fillRect(106,100, 12, 10, BLUE);
  tft.drawRect(106,100,12,10,GREEN);
  tft.setCursor(67,138);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("DddD");
    
 //Create Key Z Button
  tft.fillRect(118,100, 12, 10, BLUE);
  tft.drawRect(118,100,12,10,WHITE);
  tft.setCursor(118,103);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("ZzzZ");
      
  //Create Blue Button
  tft.fillRect(50,130, 250, 54, BLUE);
  tft.drawRect(50,130,250,54,GREEN);
  tft.setCursor(55,138);
  tft.setTextColor(YELLOW);
  tft.setTextSize(4);
  tft.print("||  | [7][8][9] |");


  
  TSPoint p = ts.getPoint();  //Get touch point
  
  //Create Red Button
  tft.fillRect(60,180, 200, 40, RED);
  tft.drawRect(60,180,200,40,WHITE);
  tft.setCursor(80,188);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("" + p.x);
  tft.setCursor(90,188);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.print(p.y);
}

void loop() 
{
  TSPoint p = ts.getPoint();  //Get touch point
  
  if (p.z > ts.pressureThreshhold) {

   Serial.print("X = "); Serial.print(p.x);
   Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tZ = "); Serial.print(p.z);
     Serial.print("\tts.pressureThreshhold = "); Serial.print(ts.pressureThreshhold);
   Serial.print("\n");
   
  // p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
  // p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);
       tft.setCursor(p.x, p.y);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print(" p.x  p.y!");
    
   if(p.x>600 && p.x<674 && p.y>650 && p.y<660 && buttonEnabled)// The user has pressed inside the red rectangle
   {
    buttonEnabled = false; //Disable button
        
    //This is important, because the libraries are sharing pins
   pinMode(XM, OUTPUT);
   pinMode(YP, OUTPUT);
    
    //Erase the screen
    tft.fillScreen(BLACK);
    
    //Draw frame
    tft.drawRect(0,0,319,240,WHITE);
    
    tft.setCursor(50,100);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print("reprogram me0xFFFFFF!");
   }
   else
   {
   //delay(10);  
   }
  }
}
