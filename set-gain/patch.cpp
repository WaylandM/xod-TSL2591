node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_TSL2591` class instance
        auto sensor = getValue<input_DEV>(ctx);
        sensor -> setGain((tsl2591Gain_t)getValue<input_GAIN>(ctx));
        emitValue<output_DONE>(ctx, 1);
    }
}
