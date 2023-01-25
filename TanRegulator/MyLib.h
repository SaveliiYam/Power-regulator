#pragma once
#include <Arduino.h>

class MyRelayOut{
public:
  MyRelayOut(int pin){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, false);
    _pin = pin;
  }

  void on(){
    if(_state){
      return;
    }
    _state = true;
    digitalWrite(_pin, _state);
  }

  void off(){
    if(!_state){
      return;
    }
    _state = false;
    digitalWrite(_pin, _state);
  }
private:
  int _pin;
  bool _state;
};

class MyRelayIn{
public:
  MyRelayIn(int pin){
    pinMode(pin, INPUT);
    _pin = pin;
  }

  bool read(){
    if(digitalRead(_pin) == LOW){
      return false;
    }
    if(digitalRead(_pin) == HIGH){
      return true;
    }
  }
private:
  int _pin;
};

class MyOpticSensor{
public:
  MyOpticSensor(int pin){
    pinMode(pin, INPUT);
    _pin = pin;
  }

  bool read(){
    if(digitalRead(_pin) == LOW){ //если перед датчиком нет препятствий
      return true;
    }
    if(digitalRead(_pin) == HIGH){ // если препятсивя есть
      return false;
    }
  }
private:
  int _pin;
};
