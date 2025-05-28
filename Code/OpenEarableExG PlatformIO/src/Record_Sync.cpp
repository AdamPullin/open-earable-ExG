#include "Record_Sync.h"
#include "Flags.h"

Record_Sync::Record_Sync() {

}

Record_Sync::~Record_Sync() {

}

void Record_Sync::setup(bool master) {
    MASTER = master;
    if (MASTER) {
        pin = EPIN_SDA;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    } else {
        pin = EPIN_SDA;
        pinMode(pin, INPUT);
        attachInterrupt(digitalPinToInterrupt(pin), handleInterrupt, RISING);
    };
}

void Record_Sync::send_interrupt() {
    if (MASTER) {
        digitalWrite(pin, HIGH);
        delay(1000);
        digitalWrite(pin, LOW);
        Serial.println("Interrupt sent");
    }
}

void Record_Sync::handleInterrupt() {
    PLAYING = true;
}

// Remove the global instance definition
Record_Sync record_sync;