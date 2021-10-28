// list of tasks 

// 1. Lights turn off after 12 hours and stay on for 12 hours (Done)
// 2. Water is pumped into the monotub 3 times a day for XX minutes (Done)
// 3. Fans come on after the water is pumped in and stay on for 30 seconds (Done)
// 4. Humidity controller comes on when the humidity drops bellow 80% (Done)



// * list of sensors*// 
    const int ledStrip = 16;// Define pin value in brackets
        const int waterPump = 15; // Define pin value in brackets
         const int fans = 16; // Define pin value in brackets
            const int humidifier = 17; // Define pin 
              int sensorPin = A0; // select the input pin for LDR
                int LED = 13;
                    int sensorValue = 0; // variable to store the value coming from the sensor
                        int interval=1000;

// Variables for the sensors 
#include "DHT.h"
    #define Type DHT11
        int sensePin=A0;
          DHT HT(sensePin,Type);
              float humidity;
                float tempC;
                  float tempF;
                    int setTime=500;
                      int dt=1000;
    
//*Variables for the timers* //
 unsigned const long eventTime_1_LDR = 43200000; // (60000ms * 60 = 3,600,000 * 12 = 43,200,000) LED Strips 
      unsigned long startTime = 0; // Water Pump 
        unsigned long startTimeFans = 0;


  
 // previous Millis values for humidity loop
unsigned long previousMillis=0;
    unsigned long previousTime_1 = 0; 
        unsigned long previousTime_3 = 0; 

 // Time on and off for water pump
   unsigned long offDuration = 5000; // Period of time the water pump stays off for 
      unsigned long onDuration = 8000; // Period of time the water pump stays on for 

   // Previous Millis values for fans loop 
   // Time on and off for fans 
      unsigned long offDurationFans = 28800000;
        unsigned long onDurationFans = onDuration + 30000; 
        


  
      
       

 //library code:
#include <LiquidCrystal.h>
      

// Millis define functions
#define LCDrefresh 1000

// Pin values for LCD display 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



 

    
    void setup() {
      pinMode(ledStrip, OUTPUT);
        pinMode(waterPump, OUTPUT);
            pinMode(fans, OUTPUT);
              pinMode(humidifier, OUTPUT);
                Serial.begin(9600);
                 pinMode(sensorPin, OUTPUT); // Output for pin 
                     pinMode(LED, OUTPUT);  // Output for pin 
                        pinMode(sensorPin, INPUT); // input for pin 

 HT.begin(); 

lcd.autoscroll();
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Humidity Temp");


  


     

    }

    
    void loop() {

// Millis loop for lights (in1)
      unsigned long currentTime = millis();
      if(currentTime - previousTime_1 >= eventTime_1_LDR) {
             digitalWrite(ledStrip, !digitalRead(ledStrip)); // Lights are on for 12 hours 
            
           previousTime_1 = currentTime;
}

humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);
 
// Millis loop for humidity sensor displaying on screen 
  unsigned long currentMillis = millis();
   if ((unsigned long)(currentMillis - previousMillis) >= interval) {
     lcd.setCursor(0, 10);
      // print the number of seconds since reset:
        lcd.print(humidity);
        lcd.print("%   ");
        lcd.print(tempC);
        lcd.print("C");
        
        // Use the snapshot to set track time until next event
      previousMillis = currentMillis;
    }
   





// millis loop for fans (in3)
      if(digitalRead(15) == LOW)
{

  //4000m - 15000
    if(millis() - startTimeFans >= onDurationFans)
    {
        startTimeFans += onDurationFans;
        digitalWrite(15, HIGH);
    }
}
else
{
    if(millis() - startTimeFans >= offDurationFans)
    {
        startTimeFans += offDurationFans;
        digitalWrite(15, LOW);
    }
}


    }
   
