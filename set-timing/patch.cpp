node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_TSL2591` class instance
        auto sensor = getValue<input_DEV>(ctx);
        sensor -> setTiming((tsl2591IntegrationTime_t)getValue<input_TIME>(ctx));
        emitValue<output_DONE>(ctx, 1);
    }
}

