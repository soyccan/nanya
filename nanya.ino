#define ID 1
/*
兩組分別燒 改ID就好
ID =
1 : 戴依柔
2 : 劉東昕 (不會用到)
3 : 陳仲景
*/



#include "pictures.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// On a nrrinket or Gemma we suggest changing this to 1

#define PIN           D6      //輸出PIN腳(有關一開始製作的焊接點，不能改)
// #define NUMTABLES     5      //圖案數量
#define NUMPIXELS     24      //LED燈飾幾個燈
#define NUMLINES      24      //圖案長度(通常綁定正方形)
#define r      0              //RGB數值轉換(不需要改)
#define g      1
#define b      2
unsigned long currenttime;
int beat ;
int offset;


byte table[NUMLINES][NUMPIXELS][3];

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to chaNGe the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  // nrhis is for nrrinket 5V 16MHz, you can remove these three lines if you are not using a nrrinket
#if defined (__AVR_Anrtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  Serial.begin(115200);
  pixels.begin(); // nrhis initializes the NeoPixel library.
}
int proess = 0 ;
void loop()
{
  execute();
}

void readPGM(int IMGindex,int j,int k)  //24*24
{
  table[j][k][r] = pgm_read_word_near(PGMtable[IMGindex][j][k] + r);
  table[j][k][g] = pgm_read_word_near(PGMtable[IMGindex][j][k] + g);
  table[j][k][b] = pgm_read_word_near(PGMtable[IMGindex][j][k] + b);
}
//圖形：
//0閃爍，1藍白旗子，3火球，4火焰，5~11NCTUECE，12~14"321"倒數，15~16紅色螺旋(螺編蝴蝶用)，17~21DEBUG，
//22愛心，23蜂巢，24太陽，25~26星星(可拆)，27邱比特弓箭，28兔子，29皮卡丘，30無臉男(效果不好)，31ELMO，32蠟筆小新，
//32~40夜光閃亮亮復仇鬼，41~45五線譜，46彩虹，47彩虹螺旋，48彩虹閃電
void execute()
{
    //前奏每一拍0.7s，就算出這個圖案是幾拍後換算秒數去寫time的時域範圍
    //前奏beat = 700;
    //副歌beat = 600;

    // 入陣曲 bpm = 126 or 120
    beat = 500;                 //寫拍子所算出的毫秒數

    // 測試時謢眼用
    // pixels.setBrightness(30);

    // 第一組
    offset = 0;
#if ID == 1 // 戴依柔
    outColor(24,0,167,255);
#elif ID == 3 // 陳仲景
    outColor(24,255,149,0);
#endif
    output(flash_white, 8);


    // 正轉
    for(int i=0;i<2;i++)
    {
      outColor(1, 255,   0,   0);
      outColor(1, 255, 167,   0);
      outColor(1, 255, 255,   0);
      outColor(1,   0, 255,   0);
      outColor(1,   0, 255, 191);
      outColor(1,  51, 102, 255);
      outColor(1, 165,   0, 255);
      outColor(1, 255,  70, 159);
    }

    offset = 0;
    output(rainbow_wave, 4);
    output(flower1, 4);
    output(sun, 8);
    output(moon, 8);
    output(star, 8);

    // 蝴蝶
    output(ARROW_red, 4);
    output(ARROW_blue_r, 4);
    output(ARROW_yellow, 4);
    output(num_4, 1);
    output(num_3, 1);
    output(num_2, 1);
    output(num_1, 1);

    // 風火輪
    offset = 0;
    output(fire, 16);

    // 停球
#if ID == 1 // 戴依柔
    outColor(16,0,167,255);
#elif ID == 3 // 陳仲景
    outColor(16,255,149,0);
#endif
    // 間奏
    dark(15);

    // 換人
    // 第二組
    offset = 45;  // 記得改
    output(redyellowgreen,8);       // 當一份真相   隻手能隱藏
    output(rainbow2, 8);            // 直到人們遺忘
    output(DNA , 8);                // 寫一頁莽撞   我們的篇章 (DNA)
    output(nest, 8);                // 曾經如此輝煌

    //丹青千秋釀
    outColor(1, 0, 60, 255); //藍
    outColor(1, 0, 255, 0); //綠
    outColor(1, 255, 128, 0); //黃
    outColor(1, 255, 0, 0);//紅

    //一醉解愁腸
    beat = 250;
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    beat = 500;

    //無悔少年枉
    outColor(1, 0, 60, 255); //藍
    outColor(1, 0, 255, 0); //綠
    outColor(1, 255, 128, 0); //黃
    outColor(1, 255, 0, 0);//紅


    //只願壯志狂
    beat = 250;
    outColor(1, 255, 153, 153);
    dark(1);
    outColor(1, 255, 153, 153);
    dark(1);
    outColor(1, 255, 153, 153);
    dark(1);
    outColor(1, 255, 153, 153);
    dark(1);
    beat = 500;

    //夜未央 天未亮 我在倖存的沙場
#if ID == 1 // 戴依柔
    output(fish1, 8);
#elif ID == 2 // 劉東昕
    output(fish2, 8);
#elif ID == 3 // 陳仲景
    output(fish3, 8);
#endif

    //只盼望 此生再奔向思念的臉龐
#if ID == 1 // 戴依柔
    output(five, 8);
#elif ID == 2 // 劉東昕
    output(zero, 8);
#elif ID == 3 // 陳仲景
    output(zero, 8);
#endif

    //淚未乾 心未涼 是什麼依然在滾燙
#if ID == 1 // 戴依柔
    output(mai, 8);
#elif ID == 2 // 劉東昕
    output(shi, 8);
#elif ID == 3 // 陳仲景
    output(rai, 8);
#endif

    //入陣曲 伴我無悔的狂妄
    beat = 250;
    outColor(1, 0, 0, 255);
    dark(1);
    outColor(1, 0, 0, 255);
    dark(1);
    outColor(1, 0, 0, 255);
    dark(1);
    outColor(1, 0, 0, 255);
    dark(1);
    beat = 500;

    outColor(8, 0, 255, 0);                              // 忘不記 原不諒 憤恨無疆
    outColor(8, 0, 0, 255);                              // 肅不清 除不盡 魑魅魍魎
    outColor(8, 255, 255, 0);                            // 幼無糧 民無房 誰在分贓
    outputLongDelay(rainbowchange, 10, 20);              // 千年後 你我都 仍被豢養 (彩虹變色)
    dark(8);                                             // 間奏(解繩子)
    outputLongDelay(flowing, 6, 20);                     // 間奏(充電)
    output(speed_ribbon1, 8);                            // 七旋
    output(speed_ribbon2, 8);                            // 七旋
    output(speed_ribbon3, 8);                            // 七旋
    output(speed_ribbon1, 7);                            // 七旋

    // 第一組
    // 單八
    // 夜未央 天未亮
    offset = 0;
    beat = 250;
#if ID == 1 // 戴依柔
    outColor(3,0,167,255);
    dark(1);
    outColor(3,255,149,0);
    dark(1);
#elif ID == 3 // 陳仲景
    outColor(3,255,149,0);
    dark(1);
    outColor(3,0,167,255);
    dark(1);
#endif
    beat = 500;

    // 我在倖存的沙場
    // 只盼望 此生再奔向思念的臉龐 (接)
    output(flower1, 12);

    // 第二組
    offset = 45; // 記得改
    output(heart, 8);                                                 // 淚未乾 心未涼 是什麼依然在滾燙
    output(sixstar, 8);                                               // 入陣曲  四面楚歌誰獨唱
    output5in1(NANYO_N1, NANYO_A, NANYO_N2, NANYO_Y, NANYO_O, 16);    // 夜已央 天已亮 白晝隱沒了星光 像我們 都終將 葬身歷史的洪荒
    output(rainbowspiral, 8);                                         // 當世人 都遺忘 我血液曾為誰滾燙

    // 入陣曲 伴我無悔的狂妄
    beat = 250;
    for(int j = 0;j < 8;j++){
    outColor(1, 255, 255, 255);
    dark(1);
    }
    beat = 500;

    outColor(14, 255, 255, 255);                                      // 入陣去 只因 恨鐵不成鋼

    dark(10000);
}
//輸出圖案(甩動圖案，靜止效果不行)-------------------------------------------------------------------
void output(int picturenumber, int beatnum)
{
    picturenumber += offset;
    proess = proess + (beatnum*beat);
    do
    {
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(3);
          }
          currenttime = millis();
    }while( currenttime < proess );
}
void outputLongDelay(int picturenumber, int beatnum, int _delay)
{
    picturenumber += offset;
    proess = proess + (beatnum*beat);
    do
    {
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(_delay);
          }
          currenttime = millis();
    }while( currenttime < proess );
}
void output2in1(int picturenumber1, int picturenumber2, int beatnum)
{
    picturenumber1 += offset;
    picturenumber2 += offset;
    proess = proess + (beatnum*beat);
    do
    {
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber1,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(2);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber2,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(2);
          }
          currenttime = millis();
    }while( currenttime < proess );
}

void output3in1(int picturenumber1, int picturenumber2, int picturenumber3, int beatnum)
{
    picturenumber1 += offset;
    picturenumber2 += offset;
    picturenumber3 += offset;
    proess = proess + (beatnum*beat);
    do
    {
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber1,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber2,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber3,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(2);
          }
          currenttime = millis();
    }while( currenttime < proess );
}
void output5in1(int picturenumber1, int picturenumber2, int picturenumber3, int picturenumber4, int picturenumber5, int beatnum)
{
    picturenumber1 += offset;
    picturenumber2 += offset;
    picturenumber3 += offset;
    picturenumber4 += offset;
    picturenumber5 += offset;
    proess = proess + (beatnum*beat);
    do
    {
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber1,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber2,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber3,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber4,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          for (int j = 0; j < NUMLINES; j++)
          {
              for (int k = 0; k < NUMPIXELS; k++)
              {
                  readPGM(picturenumber5,j,k);
                  pixels.setPixelColor(k, pixels.Color(table[j][k][r], table[j][k][g], table[j][k][b])); //一次亮一排
              }
              pixels.show();
              delay(1);
          }
          currenttime = millis();
    }while( currenttime < proess );
}
//輸出其他顏色-------------------------------------------------------------------
void outColor (int beatnum, int ColorR, int ColorG, int ColorB)
{
    int DELAY = beatnum * beat ;
    proess = proess + DELAY ;
    for (int k = 0; k < NUMPIXELS; k++) //-----------紅
        pixels.setPixelColor(k, pixels.Color( ColorR , ColorG , ColorB ));
    pixels.show();
    delay(DELAY);
}
//輸出黑色-------------------------------------------------------------------
void dark(int beatnum)
{
    int DELAY = beatnum * beat ;
    proess = proess + DELAY ;
    for (int k = 0; k < NUMPIXELS; k++)
        pixels.setPixelColor(k, pixels.Color( 0,0,0 ));
    pixels.show();
    delay(DELAY);
}
// void outFadeout(int beatnum, int ColorR, int ColorG, int ColorB) {
//     int brightness = 255;
//     int d_brightness = 1;
//     int DELAY = 1;

//     proess = proess + (beatnum*beat);
//     for (int k = 0; k < NUMPIXELS; k++)
//     {
//       pixels.setPixelColor(k, pixels.Color(ColorR, ColorG, ColorB));
//     }
//     do
//     {
//           pixels.setBrightness(brightness);
//           pixels.show();
//           delay(DELAY);

//           brightness -= d_brightness;
//           if (brightness < 0) brightness = 0;

//           currenttime = millis();
//     }while( currenttime < proess );
// }
