#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
/*______End of Libraries_______*/

/*______Define LCD pins (I have asigned the default values)_______*/
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
/*_______End of defanitions______*/

/*______Assign names to colors and pressure_______*/
//#define WHITE   0x0000 //Black->White
//#define YELLOW    0x001F //Blue->Yellow
//#define CYAN     0xF800 //Red->Cyan
//#define PINK   0x07E0 //Green-> Pink
//#define RED    0xFFE0 //Cyan -> Red
//#define GREEN 0xF81F //Pink -> Green
//#define BLUE  0x07FF  //Yellow->Blue
//#define BLACK   0xFFFF //White-> Black
#define MINPRESSURE 10
#define MAXPRESSURE 1000
/*_______Assigned______*/

/*____Calibrate TFT LCD_____*/
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905
/*______End of Calibration______*/

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); //300 is the sensitivity
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //Start communication with LCD

int X, Y;
long Num1, Num2, Number;
char action;
boolean result = false;



//// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0xF800
#define RED      0x001F
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF



#define BOXSIZE 60

#define BOXSIZEW 100
#define PENRADIUS 3
void setup() {
  Serial.begin(9600); //Use serial monitor for debugging
  tft.reset(); //Always reset at start
  tft.begin(0x9341); // My LCD uses LIL9341 Interface driver IC
 // tft.setRotation(1); // I just roated so that the power jack faces up - optional
  tft.fillScreen(WHITE);

  IntroScreen();

  draw_BoxNButtons();
}

void loop() {
  //  TSPoint p = waitTouch();
  //  X = p.y; Y = p.x;
  //   Serial.print(X); Serial.print(','); Serial.println(Y);// + " " + Y);

  DetectButtons();
 
  delay(300);
   draw_BoxNButtons();
}

//TSPoint waitTouch() {
//  TSPoint p;
//  do {
//    p = ts.getPoint();
//    pinMode(XM, OUTPUT);
//    pinMode(YP, OUTPUT);
//  } while ((p.z < MINPRESSURE ) || (p.z > MAXPRESSURE));
//  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
//  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);;
//  return p;
//}
 

void CalculateResult()
{
  if (action == 1)
    Number = Num1 + Num2;

  if (action == 2)
    Number = Num1 - Num2;

  if (action == 3)
    Number = Num1 * Num2;

  if (action == 4)
    Number = Num1 / Num2;
}

void DisplayResult()
{
  tft.fillRect(0, 0, 240, 80, BLACK);  //clear result box
  tft.setCursor(10, 20);
  tft.setTextSize(4);
  tft.setTextColor(WHITE);
  tft.println(Number); //update new value
}
 
