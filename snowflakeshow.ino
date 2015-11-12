//Created by Anthony Parone Nov 2014
//10 Dec 2014
//14 Dec 2014 added scene 7
//15 Dec 2015 added scene 8
//10 Sep 2015 added github and comments
//11 Sep 2015 added variable greenLightStrands


int lightScene = 0;
int lightSceneTotal = 9;
int switchState = 0;
int lastSwitchState = 0;
int timer = 100;
int count = 0;
int countRepeat = 0;
int greenLightStrands = 8;

int pinTree[8] = {2,3,4,5,6,7,8,9};
const int pinColoredLightString = 10;
int pinNorthPole[4] = {11,12}; //11 White 12 RED
const int pinStar = 13;


void setup(){
  timer = 10000;
  //Serial.begin(9600); //open serial port
  //initialize pins - set pin direction and turn off
   for(int count = 0; count<9; count++){
     pinMode(pinTree[count],OUTPUT); 
     digitalWrite(pinTree[count], LOW);
    } 
   for(int count = 0; count<4; count++){
     pinMode(pinNorthPole[count],OUTPUT); 
     digitalWrite(pinNorthPole[count], LOW);
    } 
  pinMode(pinStar,OUTPUT); //Star
}//setup

void loop (){
  digitalWrite(pinStar,HIGH);
  
  for (count=0;count<greenLightStrands;count++) {
    digitalWrite(pinTree[count], HIGH); //turn tree on
   }
   delay(1000);
   
     for (count=0;count<greenLightStrands;count++) {
    digitalWrite(pinTree[count], LOW); //turn tree off
   } 
   delay(1000);
   
   for (count=0;count<2;count++) {
    digitalWrite(pinNorthPole[count], HIGH); //turn on center pole
   } 
   delay(1000);
   
   for (count=0;count<2;count++) {
    digitalWrite(pinNorthPole[count], LOW); //turn off center pole
   } 
   delay(1000);

//light scenes
switch(lightScene){
////////////////////////////////////////
  case 100: //test cycle through pin numbers
    timer = 1000;
    for (count=2;count<14;count++) {
    //  Serial.print(count);
      digitalWrite(count, LOW); //turn OFF
      delay(timer);
      digitalWrite(count, HIGH); //turn on
     } 
     break;
//////////////////////////////////////// 
  case 0: //Turn on the tree!
    timer = 5000;
    digitalWrite(pinStar,HIGH);
    for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], HIGH); //turn on
     } 
     delay(timer);
     break;
//////////////////////////////////////// 
  case 1: //rotate tree forward one light goes out
    timer = 250;
    digitalWrite(pinStar,HIGH);
    for (countRepeat=0;countRepeat<3;countRepeat++){
      for (count=0;count<greenLightStrands;count++) {
        digitalWrite(pinTree[count], LOW); //turn OFF
        delay(timer);
        digitalWrite(pinTree[count], HIGH); //turn on
       }
     } 
     break;
////////////////////////////////////////  
  case 2: //rotate tree forward slowly turning it off
    timer = 250;
    digitalWrite(pinStar,HIGH);
    for (countRepeat=0;countRepeat<3;countRepeat++){
      for (count=0;count<greenLightStrands;count++) {
        digitalWrite(pinTree[count], HIGH); //turn ON
        delay(timer);
        digitalWrite(pinTree[count], LOW); //turn OFF
      } 
    }
    break;
//////////////////////////////////////// 
  case 3: //Blink Tree
    timer = 250;
    digitalWrite(pinStar,HIGH);
    for (countRepeat=0;countRepeat<2;countRepeat++){
         for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], LOW); //turn off
    } 
    delay(timer);
        for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], HIGH); //turn off
    } 
      delay(timer);
    }
    break;
////////////////////////////////////////   
  case 4: //propeller
    timer = 250;
    digitalWrite(pinStar,HIGH);
    for (int countOff=0;countOff<greenLightStrands;countOff++){
      digitalWrite(pinTree[countOff],LOW);
      }
    for (countRepeat=0;countRepeat<2;countRepeat++) {
      for (count=0;count<4;count++){
      digitalWrite(pinTree[count], HIGH); //turn on
      digitalWrite(pinTree[count+4], HIGH); //turn on
      delay(timer);
      digitalWrite(pinTree[count], LOW); //turn off
      digitalWrite(pinTree[count+4], LOW); //turn off
      delay(timer);
      }
    }
  break;
////////////////////////////////////////   
  case 5: //tree on with blinking star
    timer = 500;
    for (count=0;count<greenLightStrands;count++) {
     digitalWrite(pinTree[count], HIGH);
    }
    for (countRepeat=0;countRepeat<2;countRepeat++){
      digitalWrite(pinStar, LOW); //turn off
      delay(timer);
      digitalWrite(pinStar, HIGH); //turn on
      delay(timer);
    }
    break;
////////////////////////////////////////   
  case 6: //tree off, pole on with blinking star
    timer = 500;
    for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], LOW);
    }
    for (count=0;count<2;count++) {
     digitalWrite(pinNorthPole[count], HIGH);
    }
    for (countRepeat=0;countRepeat<10;countRepeat++){
      digitalWrite(pinStar, LOW); //turn off
      delay(timer);
      digitalWrite(pinStar, HIGH); //turn on
      delay(timer);
    }
    break;
////////////////////////////////////////   
  case 7: //Pulse Rotate
    timer = 100;
    digitalWrite(pinStar,HIGH);
    for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], LOW); //turn off
     } 
     for (count=0;count<2;count++) {
      digitalWrite(pinNorthPole[count], LOW); //turn off
     } 

    for (countRepeat=0;countRepeat<3;countRepeat++){
      for (count=0;count<greenLightStrands;count++) {
        //if (count==0){digitalWrite(pinTree[7],LOW);}
        digitalWrite(pinTree[count],HIGH );
        delay(timer);
        digitalWrite(pinTree[count-1], LOW);
        delay(timer);
       }
        for (count=greenLightStrands;count>0;count--) {
        //if (count==0){digitalWrite(pinTree[7],LOW);}
        digitalWrite(pinTree[count-1],HIGH );
        delay(timer);
        digitalWrite(pinTree[count], LOW);
        delay(timer);
       }
     } 
     break;
////////////////////////////////////////   
  case 8: //alternate
    timer = 500;
    digitalWrite(pinStar,HIGH);
    for (count=0;count<greenLightStrands;count++) {
      digitalWrite(pinTree[count], LOW); //turn off
     } 
     for (count=0;count<2;count++) {
      digitalWrite(pinNorthPole[count], LOW); //turn off
     } 

    for (countRepeat=0;countRepeat<3;countRepeat++){
        digitalWrite(pinTree[0],HIGH);
        digitalWrite(pinTree[2],HIGH);
        digitalWrite(pinTree[4],HIGH);
        digitalWrite(pinTree[6],HIGH);
        delay(timer);
        digitalWrite(pinTree[0],LOW);
        digitalWrite(pinTree[2],LOW);
        digitalWrite(pinTree[4],LOW);
        digitalWrite(pinTree[6],LOW);
        delay(timer);
        digitalWrite(pinTree[1],HIGH);
        digitalWrite(pinTree[3],HIGH);
        digitalWrite(pinTree[5],HIGH);
        digitalWrite(pinTree[7],HIGH);
        delay(timer);
        digitalWrite(pinTree[1],LOW);
        digitalWrite(pinTree[3],LOW);
        digitalWrite(pinTree[5],LOW);
        digitalWrite(pinTree[7],LOW);
        delay(timer);
       } 
     break; 
////////////////////////////////////////       
  }//Case

//auto increment the light mode
if (lightScene< 100){
  if (lightScene == lightSceneTotal) {
    lightScene=0; //reset to first lightScene
   }else{
    lightScene++;
   }
 }
   //Serial.print(lightScene);

}//loop




  //  timer = 250;
 //   for (count=0;count<greenLightStrands;count++) {
   //   digitalWrite(pinTree[count], LOW); //turn on
  //  } 
  //  digitalWrite(pinStar,HIGH);
  //  for (countRepeat=0;countRepeat<2;countRepeat++){
   //   digitalWrite(pinNorthPole[0],LOW);
    //  delay(timer);
   //   digitalWrite(pinNorthPole[1],HIGH);
   //   delay(timer);
    //  digitalWrite(pinNorthPole[1],LOW);
    //  delay(timer);
    //  digitalWrite(pinNorthPole[0],HIGH);
    //  delay(timer);
  //  }
  //  break;
