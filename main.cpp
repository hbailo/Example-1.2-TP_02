#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
  DigitalIn gasDetector(D2); // LLamada al constructor de la clase DigitalIn para instanciar el objeto gasDetector
  DigitalIn overTempDetector(D3); // LLamada al constructor de la clase DigitalIn para instanciar el objeto overTempDetector
   
  DigitalOut alarmLed(LED1); // LLamada al constructor de la clase DigitalOut para instanciar el objeto alarmLed
   
  gasDetector.mode(PullDown) ; // LLamada al método mode(), i.ee se le envía el mensaje mode() al objeto gasDetector
  overTempDetector.mode(PullDown) ; // LLamada al método mode(), i.ee se le envía el mensaje mode() al objeto overTempDetector

  while (true) {

    if (gasDetector || overTempDetector) { // Llamada implícita a los métodos operator int().
      alarmLed = ON ; // Llamada al operador sobrecargado de asignación.
    } else {
      alarmLed = OFF ; // Llamada al operador sobrecargado de asignación.
    }

    printf("Gas detector = %d | Alarm led = %d \n", gasDetector.read(), alarmLed.read()) ; // Llamada al método read de las clases DigitalIn y DigitalOut.
    
  }
}
