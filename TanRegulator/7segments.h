#pragma once
#include <Arduino.h>

class Segmentor{
  private:
    int _pinA;
    int _pinB;
    int _pinC;
    int _pinD;
    int _pinE;
    int _pinF;
    int _pinG;
  public:
    Segmentor(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG){
      pinMode(pinA, OUTPUT);
      pinMode(pinB, OUTPUT);
      pinMode(pinC, OUTPUT);
      pinMode(pinD, OUTPUT);
      pinMode(pinE, OUTPUT);
      pinMode(pinF, OUTPUT);
      pinMode(pinG, OUTPUT);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      _pinA = pinA;
      _pinB = pinB;
      _pinC = pinC;
      _pinD = pinD;
      _pinE = pinE;
      _pinF = pinF;
      _pinG = pinG;
    }
    void one(){
      digitalWrite(_pinA, LOW);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, LOW);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, LOW);
      digitalWrite(_pinG, LOW);
    }
    void two(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, LOW);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, HIGH);
      digitalWrite(_pinF, LOW);
      digitalWrite(_pinG, HIGH);
    }
    void three(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, LOW);
      digitalWrite(_pinG, HIGH);
    }
    void four(){
      digitalWrite(_pinA, LOW);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, LOW);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, HIGH);
    }
    void five(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, LOW);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, HIGH);
    }
    void six(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, LOW);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, HIGH);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, HIGH);
    }
    void seven(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, LOW);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, LOW);
      digitalWrite(_pinG, LOW);
    }
    void eight(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, HIGH);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, HIGH);
    }
    void nine(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, LOW);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, HIGH);
    }
    void zero(){
      digitalWrite(_pinA, HIGH);
      digitalWrite(_pinB, HIGH);
      digitalWrite(_pinC, HIGH);
      digitalWrite(_pinD, HIGH);
      digitalWrite(_pinE, HIGH);
      digitalWrite(_pinF, HIGH);
      digitalWrite(_pinG, LOW);
    }
    void chooseNumber(int k){
      switch(k){
        case 0:
          zero();
          break;
        case 1:
          one();
          break;
        case 2:
          two();
          break;
        case 3:
          three();
          break;
        case 4:
          four();
          break;
        case 5:
          five();
          break;
        case 6:
          six();
          break;
        case 7:
          seven();
          break;
        case 8:
          eight();
          break;
        case 9: 
          nine();
          break;   
      }
    }
};
