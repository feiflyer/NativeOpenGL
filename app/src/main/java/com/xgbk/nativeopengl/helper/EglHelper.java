package com.xgbk.nativeopengl.helper;

import android.view.Surface;

public class EglHelper {

    public native void surfaceCreated(Surface surface);

    public native void surfaceChanged(int width, int height);

    public native void surfaceDestroyed();

}
