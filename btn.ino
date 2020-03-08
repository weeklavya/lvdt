
void DetectButtons()
{


  TSPoint p;
  do {
    p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  } while ((p.z < MINPRESSURE ) || (p.z > MAXPRESSURE));
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);
  if (p.x > 40 && p.x < 200 && p.y > 150 && p.y < 180)
  {
    tft.fillScreen(WHITE);
    tft.setCursor (50, 100);
    tft.setTextSize (2);
    tft.setTextColor(BLACK);
    tft.println("START");
  }

  if (p.x > 50 && p.x < 70 && p.y > 180 && p.y < 270)
  {
    tft.setCursor (50, 100);
    tft.fillScreen(WHITE);
    tft.setTextSize (2);
    tft.setTextColor(BLACK);
    tft.println("Button One");
  }

    if (p.x > 110 && p.x < 170 && p.y > 200 && p.y < 250)
  {
    tft.setCursor (50, 100);
    tft.fillScreen(WHITE);
    tft.setTextSize (2);
    tft.setTextColor(BLACK);
    tft.println("Button TWO");
  }

      if (p.x > 250 && p.x < 300 && p.y > 200 && p.y < 250)
  {
    tft.setCursor (50, 100);
    tft.fillScreen(WHITE);
    tft.setTextSize (2);
    tft.setTextColor(BLACK);
    tft.println("Button THree");
  }
  Serial.print(p.x);



}
