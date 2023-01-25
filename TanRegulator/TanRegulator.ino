#include "7segments.h"
#include "MyLib.h"
#include "Buttons.h"
#include <GyverTimers.h>
#include <GyverDimmer.h>
Segmentor segment(5, 6, 7, 8, 9, 10, 11);
unsigned long currentDisplay = 0;

MyRelayOut firstTrans(A7);
MyRelayOut secondTrans(3);
MyRelayOut thirdTrans(4);

Button buttonUp(A0);
Button buttonDown(A1);

const int nullDetector = 2; // детектор нуля
const int simistr = 12;
Dimmer<simistr> dim;
int valuePercent = 0;
void setup() {
  attachInterrupt(0, isr, RISING);
  Timer2.enableISR();
}

void loop() {
  if(buttonUp.click()){valuePercent++;}
  if(buttonDown.click()){valuePercent--;}
  if(valuePercent < 0){valuePercent = 0;}
  else if(valuePercent > 100){valuePercent = 100;}
  Display(valuePercent);
  dim.write(map(valuePercent, 0, 100, 0, 255));
}

void isr() {
  // вызывать в прерывании детектора нуля
  // если tickZero() - true - нужно перезапустить таймер с периодом getPeriod()
  if (dim.tickZero()) Timer2.setPeriod(dim.getPeriod());
  else Timer2.restart();
  // иначе перезапустить со старым
}

// прерывание таймера
ISR(TIMER2_A) {
  dim.tickTimer();    // вызвать tickTimer()
  Timer2.stop();      // останавливаем таймер
}

void Display(int value){
  if(millis() - currentDisplay >= 10){
    currentDisplay = millis();
    int firstNumber = value%10;
    int secondNumber = value%100/10;
    int thirdNumber = value/100;
    firstTrans.on();
    segment.chooseNumber(firstNumber);
    firstTrans.off();
    secondTrans.on();
    segment.chooseNumber(secondNumber);
    secondTrans.off();
    thirdTrans.on();
    segment.chooseNumber(thirdNumber);
    thirdTrans.off();
  }
}
