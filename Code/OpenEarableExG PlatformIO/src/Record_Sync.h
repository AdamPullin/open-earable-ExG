#ifndef RECORD_SYNC_H
#define RECORD_SYNC_H

#include <Arduino.h>
#include "Earable_Pins.h"

class Record_Sync {
public:
    Record_Sync();
    ~Record_Sync();

    void setup(bool role);

    void send_interrupt();
    static void handleInterrupt();

    int pin;
    bool MASTER;
};
extern Record_Sync record_sync;

#endif // RECORD_SYNC_H