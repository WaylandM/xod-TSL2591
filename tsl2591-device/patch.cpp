// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_TSL2591_Library"

//Include C++ libraries
{{#global}}
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>
{{/global}}

// Reserve memory to store an instance of the Adafruit_TSL2591 class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_TSL2591)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_TSL2591*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    // Pass in a user-defined number for the sensor identifier.
    Type sensor = new (state->mem) Adafruit_TSL2591(2591);

    if (!sensor->begin()) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DEV>(ctx, sensor);
}
