#include <Servo.h>

Servo rock;
Servo scissors;
Servo paper;
#define TRIG 2
#define ECHO 3
long distance;
long pre = 0;   //이전시간
long interval = 2000;  //간격 2초
void setup() {
  Serial.begin(9600);

  //초음파센서 핀모드 설정
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  //서보모터 초기화 작업
  rock.attach(9);
  scissors.attach(10);
  paper.attach(11);

  rock.write(180);
  delay(1000);
  rock.write(90);
  delay(1000);

  scissors.write(180);
  delay(1000);
  scissors.write(90);
  delay(1000);

  paper.write(180);
  delay(1000);
  paper.write(90);
  delay(1000);
}
void loop() {
  digitalWrite(TRIG, HIGH);    //트리거 신호 On
  delayMicroseconds(10);       //10마이크로초 대기
  digitalWrite(TRIG, LOW);     //트리거신호 off
  distance = pulseIn(ECHO, HIGH) / 58;   //초음파값 수치화
  Serial.print(distance);
  Serial.println("cm");
  //delay(500);
if(distance < 7) {
    long current = millis();  //현재시간
    if (current-pre >= interval) {
      int num = random(1,4);
      Serial.println(num);

      switch(num){
        case 1:  //rock
          rock.write(180);
          delay(1000);
          rock.write(90);
          delay(500);
          break;
        
        case 2:  //scissors
          scissors.write(180);
          delay(1000);
          scissors.write(90);
          delay(1000);
          break;
        
        case 3:  //paper
          paper.write(180);
          delay(1000);
          paper.write(90);
          delay(1000);
          break;
      }
      pre = current;
    }
  }
}
