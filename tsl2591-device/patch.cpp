// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_TSL2591_Library"

//Include C++ libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_TSL2591*;
    }

    // Create an object of class Adafruit_TSL2591
    Adafruit_TSL2591 sensor = Adafruit_TSL2591();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        // Try to initialize sensor
        if (!sensor.begin()) {
            raiseError(ctx);
            return;
        }
        emitValue<output_DEV>(ctx, &sensor);
    }
}

