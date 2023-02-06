#include <Segmentor.h>
#include "Buttons.h"
#include <GyverTimers.h>
#include <GyverDimmer.h>
Segmentor segment(7, 5, 9, 10, 11, 6, 8);

Button buttonUp(A0);
Button buttonDown(A1);

const int nullDetector = 2; // детектор нуля
const int simistr = 12;
Dimmer<simistr> dim;
int valuePercent = 0;
void setup() {
  attachInterrupt(0, isr, RISING);
  Timer2.enableISR();
  segment.discharge(4, 3, 13);
}

void loop() {
  if(buttonUp.click()){valuePercent++;}
  if(buttonDown.click()){valuePercent--;}
  if(valuePercent <= 0){valuePercent = 0;}
  else if(valuePercent >= 100){valuePercent = 100;}
  segment.displayThree(valuePercent);
  dim.write(map(valuePercent, 0, 100, 0, 255));
  //dim.write(100);
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
