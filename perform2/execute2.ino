//圖形：
//0閃爍，1藍白旗子，3火球，4火焰，5~11NCTUECE，12~14"321"倒數，15~16紅色螺旋(螺編蝴蝶用)，17~21DEBUG，
//22愛心，23蜂巢，24太陽，25~26星星(可拆)，27邱比特弓箭，28兔子，29皮卡丘，30無臉男(效果不好)，31ELMO，32蠟筆小新，
//32~40夜光閃亮亮復仇鬼，41~45五線譜，46彩虹，47彩虹螺旋，48彩虹閃電
void execute()
{
    //前奏每一拍0.5s，就算出這個圖案是幾拍後換算秒數去寫time的時域範圍
    //前奏beat = 500;
    //proess = 0 ;                //時間
    beat = 500;                 //寫拍子所算出的毫秒數
    
    dark(96);                   //85 1 丟 淚未乾 心未涼 是什麼依然在滾燙 入陣曲 伴我無悔的狂妄
    dark(2);
    dark(24);
    dark(4);
    dark(1);
    outColor(17,255,255,255);   //白1 8 8 間奏solo
    /*outColor(2, 255, 0, 0);     //紅 當一份真相
    outColor(2, 255, 45, 0);   //橙 
    outColor(2, 255, 128, 0);   //黃 隻手能隱藏
    outColor(2, 0, 255, 0);     //綠*/
    
    output(fire,8);// 當一份真相   隻手能隱藏
    output(fireball,8);// 直到人們遺忘
    //outColor(2, 0, 255, 255);   //藍 直到人們
    //outColor(2, 127, 0, 255);   //紫
    //output(rainbowlight,4);     //彩虹 遺忘
    
    output(star1,4); //寫一頁莽撞
    output(moon,4);  //我們的篇章
    output(arrow, 4);
    output(heart, 3); //曾經如此輝煌
    //output(flash1,3);

    outColor(1, 127, 0, 255); //紫
    //丹青千秋釀
    outColor(1, 0, 60, 255); //藍 
    outColor(1, 0, 255, 0); //綠
    outColor(1, 255, 128, 0); //黃 
    outColor(1, 255, 0, 0);//紅
    beat = 250; //一醉解愁腸
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    outColor(1, 255, 255, 255);
    dark(1);
    beat = 500; //無悔少年枉
    outColor(1, 0, 60, 255); //藍
    outColor(1, 0, 255, 0); //綠
    outColor(1, 255, 128, 0); //黃
    outColor(1, 255, 0, 0);//紅
    
    //output(flash1,4); //只願壯志狂
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

    output(fish, 8);                               //夜未央 天未亮 我在倖存的沙場
    output(zero, 8);                //只盼望 此生再奔向思念的臉龐
    output(shi, 8);                                // 淚未乾 心未涼 是什麼依然在滾燙()
    //output(flash1, 4);          // 入陣曲 伴我無悔的狂妄

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
    
    outColor(8, 255, 0, 0);     // 忘不記 原不諒 憤恨無疆
    outColor(8, 255, 255, 0);     // 肅不清 除不盡 魑魅魍魎
    outColor(8, 0, 0, 255);  // 幼無糧 民無房 誰在分贓
    outputflowing(rainbowchange, 10);                 // 千年後 你我都 仍被豢養 (彩虹變色)
    dark(70);
    outColor(8, 255, 255, 255);
    output5in1(NANYO_N1, NANYO_A, NANYO_N2, NANYO_Y, NANYO_O, 16);   // 夜已央 天已亮 白晝隱沒了星光 像我們 都終將 葬身歷史的洪荒
    output(rainbowspiral, 8);   // 當世人 都遺忘 我血液曾為誰滾燙
    //output(flash1, 8);          // 入陣曲 伴我無悔的狂妄
    beat = 250;
    for(int j = 0;j < 8;j++){
    outColor(1, 255, 255, 255);
    dark(1);      
    }
    beat = 500;
    outColor(14, 255, 255, 255);    // 入陣去 只因 恨鐵不成鋼
    dark(1000);


}
//輸出圖案(甩動圖案，靜止效果不行)-------------------------------------------------------------------
void output(int picturenumber, int beatnum)
{
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
void output2in1(int picturenumber1, int picturenumber2, int beatnum)
{
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

void outputflowing(int picturenumber, int beatnum)
{
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
              delay(20);
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
    /*outColor(1, 255, 255, 255); //白 寫一頁莽撞
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); 
    outColor(1, 255, 255, 255);
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); 

    outColor(1, 255, 255, 255); //白 我們的篇章
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); 
    outColor(1, 255, 255, 255);
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); 

    outColor(1, 255, 255, 255); //白 曾經如此輝煌
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); 
    outColor(1, 255, 255, 255);
    outColor(1, 170, 170, 170); 
    outColor(1, 85, 85, 85); 
    dark(1);
    dark(1);
    outColor(1, 85, 85, 85); 
    outColor(1, 170, 170, 170);
    outColor(1, 255, 255, 255); */
    //beat = 500;
    //outColor(3, 255, 255, 255); //煌
