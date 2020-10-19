node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_TSL2591` class instance
        auto sensor = getValue<input_DEV>(ctx);
        uint32_t lum = sensor -> getFullLuminosity();
        uint16_t ir, full;
        ir = lum >> 16;
        full = lum & 0xFFFF;
        emitValue<output_FULL>(ctx, full);
        emitValue<output_IR>(ctx, ir);
        emitValue<output_LUX>(ctx, sensor->calculateLux(full, ir));
        emitValue<output_DONE>(ctx, 1);
    }
}

