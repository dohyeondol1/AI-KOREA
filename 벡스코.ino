#include <Servo.h>

Servo servo;
Servo rock;
Servo scissors;
Servo paper;

#define TRIG 2
#define ECHO 3

char result = '0';
int i = 0;
char computer;
char ai[3] = {'1','2','3'};

long pre = 0;   //이전시간
long interval = 3000;  //간격 2초

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  servo.write(90);  

  //서보모터 초기화 작업
  rock.attach(5);
  scissors.attach(6);
  paper.attach(4);

  scissors.write(270);
  delay(1000);
  scissors.write(90);
  delay(1000);

  rock.write(220);
  delay(1000);
  rock.write(90);
  delay(1000);
    
  paper.write(270);    
  delay(1000);    
  paper.write(90);    
  delay(1000);
}

void loop() { 
  while(Serial.available()>0){   //트리거신호 off
    analogWrite(12, 255);
    analogWrite(11, 0);
    analogWrite(13, 0);
    analogWrite(12, 0);  
    i = random(0,2); //1 가위, 2 바위, 3 보 
    computer = ai[i];
    result = Serial.read();
    Serial.print(result);
    
    if(result=='1'||'2'||'3') {
      if(computer == '1'){
        scissors.write(270);
        delay(1000);
        scissors.write(90);
        delay(1000);

      }
      else if(computer == '2'){
        rock.write(220);
        delay(1000);
        rock.write(90);
        delay(1000);
      
      }
      else if(computer == '3'){
        paper.write(270);
        delay(1000);
        paper.write(90);
        delay(1000);

      }
    }

    if (Serial.available()) {  
      Serial.read();
      while(Serial.available() == 0){
      }
      result = Serial.read(); 
      Serial.println(result);
      if(computer == result){
          analogWrite(13, 0);
          analogWrite(12, 255);
          analogWrite(11, 0);
          delay(1000);
        
      }

      else if(result == '1' ){ //가위냈을때 
        if(computer == '2'){
          analogWrite(13, 255);
          analogWrite(12, 0);
          analogWrite(11, 0);
          delay(1000); 
                
        }
        else if(computer == '3'){
          analogWrite(13, 0);
          analogWrite(12, 0);
          analogWrite(11, 255);
          delay(1000);
          
        }        
      }
      else if(result == '2'){
        if(computer == '1'){
          analogWrite(13, 0);
          analogWrite(12, 0);
          analogWrite(11, 255);
          delay(1000);                
        }   
        else if(computer == '3'){
          analogWrite(13, 255);
          analogWrite(12, 0);
          analogWrite(11, 0);
          delay(1000);        
        }                   
      }
      else if(result =='3'){
        if(computer == '2'){
          analogWrite(13, 0);
          analogWrite(12, 0);
          analogWrite(11, 255);
          delay(1000);                
        }   
        else if(computer == '1'){
        analogWrite(13, 255);
          analogWrite(12, 0);
          analogWrite(11, 0);
          delay(1000);        
        }                      
      }   
      } 
  }
}