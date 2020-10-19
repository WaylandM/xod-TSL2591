node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_TSL2591` class instance
        auto sensor = getValue<input_DEV>(ctx);
        emitValue<output_TIME>(ctx, sensor->getTiming());
        emitValue<output_DONE>(ctx, 1);
    }
}


