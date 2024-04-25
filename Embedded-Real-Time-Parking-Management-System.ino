#include <Arduino.FreeRTOS.h>
#include <semphr.h>

int freeplaces = 53;
bool ticketPrinted false;
bool ticketTaken false;
bool fireDetector false;

int pfire = 2;
int pentrance = 3;
int pexit = 4;
int pinButton1 = 5;
int PinTicket1 = 6;
int pinPinProblem = 7;
int PinSensorIn = 8;
int PinPaiement = 9;
int PinSensorOut = 10
//int carnumber = 0;

SemaphoreHandle_t inoutmutex;
SemaphoreHandle_t freeplaces

TaskHandle_t enter;
TaskHandle_t exit;
TaskHandle_t fireDetect;


void setup() {

  serial.begin(9600);
  PinMode(pfire, OUTPUT);
  digitalwrite (pfire, LOW);

  PintMode(pentrance, OUTPUT);
  digitalwrite (pentrance, LOW);

  PinMode(pexit, OUTPUT);
  digitalwrite (pexit, LOW);

  PinMode(pinButton1, INPUT)
  PintMode(pinPinProblem, OUTPUT);
  PintMode(PinSensorIn, OUTPUT);
  pinMode(PinPaiement, OUTPUT);
  pinMode(PinSensorOut, OUTPUT);
  pinMode(carnumber, OUTPUT);

  datamutex = xSemaphoreCreateMutex();
  xTaskCreate(fire, "fire", 100, NULL, 1, &fireDetect);
  xTaskCreate(pentrance, "enter", 100, NULL, 2, &enter);
  xTaskCreate(pexit, "exit", 100, NULL, 2, &exit);

    Serial.println(freeplaces)

)


}
void fire (void *param){
  while(1){
  if(fireDetector = true){
  digitalWrite(pfire, HIGH);
  digitalWrite(pentrance, LOW);
  digitalWrite(pexit, HIGH);
  }
  vTaskDelay(pdMS_TICKS_TO_DELAY(100))

  }
}

void pentrance(void *param){
  while(1){

    if(digitalRead((PinButton1) == HIGH)){
    if((pfire = LOW) && (freeplaces > 0) (&& pinPinProblem = LOW)) {

          digitalWrite(PinPrint, HIGH)
          vTaskDelay(pdMS_TICKS_TO_DELAY(20))
          digitalWrite(PinPrint, LOW)
          Delay(3000);

      if(ticketPrinted = true){
      digitalWrite(pinTicket1, HIGH);
      Delay(60000)

        if(digitalRead((pinTicket1) == LOW)){
        ticketTaken = true
        digitalWrite(pentrance, HIGH)
        Delay(10000)

          if(digitalRead((pinSensorIn) == LOW)){
            Delay(150)
            digitalWrite (pentrance, LOW)
            xSemaphoreTake(freeplaces, portMAX_DELAY)
            freeplaces ++;
            xSemaphoreGive(freeplaces)

          }
          else{
          vTaskDelay(pdMS_TICKS_TO_DELAY(20000))
          digitalWrite(pentrance, LOW)

        }
      }
        else(digitalRead((pinTicket1) == HIGH)){
        Serial.println("you must take the ticket")
      }
      else {
        digitalWrite (pinPinProblem, HIGH);
      }
      }
  }
}
    else{
    Serial.println("will not oper")

  }
  }
}


void pexit(void *param){
  while(1){
    if(digitalRead((PinPaiement) == true))
    vTaskDelay(pdMS_TICK_TO_DELAY(100))
    digitalWrite(pexit, HIGH);
    Delay(10000)
        if(digitalRead((PinSensorOut) == LOW)){
          Delay(150)
          digitalWrite (pexit, LOW)
          xSemaphoreTake(freeplaces, portMAX_DELAY)
          freeplaces --;
          xSemaphoreGive(freeplaces)

        }
        else{
        vTaskDelay(pdMS_TICKS_TO_DELAY(20000))
        digitalWrite(pexit, LOW)

  }
      Serial.println(freeplaces)

}

void loop() {

}
