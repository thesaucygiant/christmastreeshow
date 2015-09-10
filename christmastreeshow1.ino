//Created by Anthony Parone Nov 2014

int lightMode = 100; //100 is test mode
int lightScenes = 6;
int switchState = 0;
int lastSwitchState = 0;
int timer = 100;
int count = 0;

int pinTree[8] = {2,3,4,5,6,7,8,9};
const int pinColoredLightString = 10;

int pinNorthPole[2] = {11,12};
const int pinStar = 13;


void setup(){
  Serial.begin(9600); //open serial port
  //initialize pins - set direction and turn off
 //output 
   for(int count = 0; count<9; count++){
     pinMode(pinTree[count],OUTPUT); 
     digitalWrite(pinTree[count], LOW);
    } 
   for(int count = 0; count<9; count++){
     pinMode(pinNorthPole[count],OUTPUT); 
     digitalWrite(pinNorthPole[count], LOW);
    } 
   pinMode(pinStar,OUTPUT); //Star

}//setup


void loop (){
 // Serial.print("   Top of Loop:");
  Serial.print(lightMode);
   //turn on the tree
   digitalWrite(pinStar,HIGH);
   for (count=0;count<8;count++) {
    digitalWrite(pinTree[count], HIGH); //turn on
   } 

//implement light mode
switch(lightMode){
  case 100:
    digitalWrite(pinStar,LOW);
    digitalWrite(pinStar,HIGH);
  timer = 100;
  //cycle through pin numbers
  for (count=0;count<8;count++) {
    digitalWrite(pinTree[count], LOW); //turn OFF
    delay(timer);
    digitalWrite(pinTree[count], HIGH); //turn on
   } 
   break;
  
  
  
  
//////////////////////////////////////// 
  case 0: //Turn on the tree!
  digitalWrite(pinStar,HIGH);
  timer = 100;
  //cycle through pin numbers
  for (count=0;count<8;count++) {
    digitalWrite(pinTree[count], HIGH); //turn on
    delay(timer);
   } 
   break;

//////////////////////////////////////// 
  case 1: //rotate tree forward one light goes out
  digitalWrite(pinStar,HIGH);
  timer = 100;
  //cycle through pin numbers
  for (count=0;count<8;count++) {
    digitalWrite(pinTree[count], LOW); //turn OFF
    delay(timer);
    digitalWrite(pinTree[count], HIGH); //turn on
   } 
   break;
////////////////////////////////////////  
  case 2: //rotate tree forward one light goes on 
  timer = 500;
  //cycle through pin numbers
  for (count=0;count<9;count++) {
    digitalWrite(pinTree[count], HIGH); //turn ON
    delay(timer);
    digitalWrite(pinTree[count], LOW); //turn OFF
   } 
   break;
//////////////////////////////////////// 
  case 3: //Knight Rider
  timer = 100;
  for (count=0;count<8;count++) {
   digitalWrite(pinTree[count], HIGH);
   delay(timer);
   digitalWrite(pinTree[count + 1], HIGH);
   delay(timer);
   digitalWrite(pinTree[count], LOW);
   delay(timer*2);
  }
  for (count=8;count>0;count--) {
   digitalWrite(pinTree[count], HIGH);
   delay(timer);
   digitalWrite(pinTree[count - 1], HIGH);
   delay(timer);
   digitalWrite(pinTree[count], LOW);
   delay(timer*2);
  }
   break;
////////////////////////////////////////   
  case 4: //propeller
  timer = 500;
  for (count=0;count<4;count++) {
    for (int countOff=0;countOff<8;countOff++){
      digitalWrite(pinTree[countOff],LOW);
    }
    digitalWrite(pinTree[count], HIGH); //turn on
    digitalWrite(pinTree[count+4], HIGH); //turn on
    delay(timer);
  }
  break;
////////////////////////////////////////   
  case 5: //tree on with blinking star
  timer = 500;
  //turn on all green lights
  for (count=0;count<8;count++) {
   digitalWrite(pinTree[count], HIGH);
  }
  for (count=0;count<25;count++){
  digitalWrite(pinStar, LOW); //turn off
  delay(timer);
  digitalWrite(pinStar, HIGH); //turn on
  delay(timer);
  }
  break;
////////////////////////////////////////   
 // case 99: //tree off, pole on with blinking star
 // timer = 500;
  //turn off all green lights
 // for (count=0;count<8;count++) {
 //  digitalWrite(pinTree[count], LOW);
 // }
  //turn on all North Pole lights
//  for (count=0;count<2;count++) {
 //  digitalWrite(pinNorthPole[count], HIGH);
 // }
 // for (count=0;count<25;count++){
 // digitalWrite(pinStar, LOW); //turn off
 // delay(timer);
 // digitalWrite(pinStar, HIGH); //turn on
 // delay(timer);
 // }
  
  
}//Case

 //auto increment the light mode
   if (lightMode <> 100) {
   if (lightMode == 4) {
    lightMode=0;
   }else{
   lightMode++;
   }
   }
 //  Serial.print("   Bottom of Loop:");
   Serial.print(lightMode);

}//loop
