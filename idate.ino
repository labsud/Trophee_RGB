#define R_LED P2_5
#define B_LED P2_2
#define G_LED P2_4

#define TILT P2_1
//#define TILT P2_0

#define DELAY 10*60*1000UL // 10 minutes

//#define DELAY 10*1000UL // 10 sec

#define SPEED 5 // vitesse respiration

//#define AFRICA
//#define ASIA
//#define AMERICA
//#define HEART
#define LABSUD

#if defined(ASIA) || defined(LABSUD)
#define MAX_LIGHT 250
#else
#define MAX_LIGHT 150
#endif
//int color[3]={255,40,0}; // orange, Asia
//int color[3]={255,0,0}; // rouge, coup de coeur
//int color[3]={0,255,0}; // vert, Afrique
//int color[3]={0,0,255}; // bleu Amérique

volatile unsigned long time;

void setup()
{
  pinMode(TILT,INPUT);
  
  digitalWrite(R_LED,LOW);
  digitalWrite(G_LED,LOW);
  digitalWrite(B_LED,LOW);
  
  pinMode(R_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);

  attachInterrupt(TILT,WAKE_UP,FALLING);

 setInputLow();
  
}

void loop()
{
 
 setInputLow();

  suspend();
  
  int inc=1;
  int consigne=0;
  
  while(millis()<=time+DELAY) {
  
     consigne+=inc;
     
     #ifdef AFRICA 
     analogWrite(G_LED,consigne);
     if(consigne>=MAX_LIGHT || consigne <=0) inc=-inc;
     #endif
     
     #ifdef AMERICA
     analogWrite(B_LED,consigne);
     if(consigne>=MAX_LIGHT || consigne <=0) inc=-inc;
     #endif
     
     #ifdef HEART
     analogWrite(R_LED,consigne);
     if(consigne>=MAX_LIGHT || consigne <=0) inc=-inc;
     #endif
     
     #ifdef ASIA
     analogWrite(R_LED,consigne);
     analogWrite(B_LED,consigne/8);
     if(consigne>=MAX_LIGHT || consigne <=0) inc=-inc;
     #endif
     
     #ifdef LABSUD
     unsigned int rgbColour[3];
       rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
     analogWrite(R_LED,rgbColour[0]);
     analogWrite(G_LED,rgbColour[1]);
     analogWrite(B_LED,rgbColour[2]);
     delay(SPEED);

//     analogWrite(R_LED,(MAX_LIGHT/2.0)+(consigne/2*-inc));
//     analogWrite(B_LED,MAX_LIGHT-consigne);
//     analogWrite(G_LED,(MAX_LIGHT/2.0)+(consigne/2*inc));
     
     
     //
     
    }
  }
     #endif
     delay(SPEED);
 
   }
  
}

//void setLED(int power) {
// 
//  power=constrain(power,0,255);
//  
//  long colorM[3]={0,0,0};
//  
// colorM[0]=constrain((float)color[0]*power/255.0,0,MAX_LIGHT);
// colorM[1]=constrain((float)color[1]*power/255.0,0,MAX_LIGHT);
// colorM[2]=constrain((float)color[2]*power/255.0,0,MAX_LIGHT);
// 
//     analogWrite(R_LED,colorM[0]);
//     analogWrite(G_LED,colorM[1]);
//     analogWrite(B_LED,colorM[2]);
//  
//}

void WAKE_UP() {
  
 wakeup();
 time=millis(); 
 
 
 
}

void setInputLow() {
  
  digitalWrite(R_LED,LOW);
  digitalWrite(G_LED,LOW);
  digitalWrite(B_LED,LOW);
  
  digitalWrite(P1_0,LOW);
  digitalWrite(P1_1,LOW);
  digitalWrite(P1_2,LOW);
  digitalWrite(P1_3,LOW);
  digitalWrite(P1_4,LOW);
  digitalWrite(P1_5,LOW);
  digitalWrite(P1_6,LOW);
  digitalWrite(P1_7,LOW);
 
  digitalWrite(P2_0,LOW);
  digitalWrite(P2_3,LOW);
  digitalWrite(P2_6,LOW);
  digitalWrite(P2_7,LOW);
  
  pinMode(P1_0,OUTPUT);
  pinMode(P1_1,OUTPUT);
  pinMode(P1_2,OUTPUT);
  pinMode(P1_3,OUTPUT);
  pinMode(P1_4,OUTPUT);
  pinMode(P1_5,OUTPUT);
  pinMode(P1_6,OUTPUT);
  pinMode(P1_7,OUTPUT);
 
  pinMode(P2_0,OUTPUT);
  pinMode(P2_3,OUTPUT);
  pinMode(P2_6,OUTPUT);
  pinMode(P2_7,OUTPUT);

}

  
