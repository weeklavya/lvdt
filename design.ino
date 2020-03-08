
void IntroScreen()
{
  tft.setCursor (50, 70);
  tft.setTextSize (2);
  tft.setTextColor(BLACK);
  tft.println("LVDT Based");
  tft.setCursor (50, 110);
  tft.println("Thickness ");
  tft.setCursor (50, 150);
  tft.println("Measurement");
  delay(1000);
}

void draw_BoxNButtons()
{

  

  
  tft.fillScreen(WHITE);
  tft.fillRect(50, 200, 130, 40, RED);
  tft.setTextColor(WHITE);
  tft.setCursor(80, 210);
  tft.print("Start");

 
  tft.setCursor(32, 70);
   tft.setTextColor(BLACK);
  tft.print("ANOLOG VALUE");

 tft.fillRect(10, 260, 50, 40, RED);
  tft.setTextColor(WHITE);
  tft.setCursor(12, 270);
  
  tft.print(" 1");


 tft.fillRect(90, 260, 60, 40, RED);
  tft.setTextColor(WHITE);
  tft.setCursor(100, 270);
  tft.print(" 2");

   tft.fillRect(180, 260, 50, 40, RED);
  tft.setTextColor(WHITE);
  tft.setCursor(190, 270);
  tft.print(" 3");

}
