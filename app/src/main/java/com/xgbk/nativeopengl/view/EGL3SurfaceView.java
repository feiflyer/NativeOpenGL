package com.xgbk.nativeopengl.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

import com.xgbk.nativeopengl.helper.EglHelper;

public class EGL3SurfaceView extends SurfaceView implements SurfaceHolder.Callback {

    private EglHelper eglHelper;

    public EGL3SurfaceView(Context context) {
        this(context,null);
    }

    public EGL3SurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        eglHelper = new EglHelper();
        getHolder().addCallback(this);
    }

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder surfaceHolder) {
        eglHelper.surfaceCreated(surfaceHolder.getSurface());
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder surfaceHolder, int i, int width, int height) {
        eglHelper.surfaceChanged(width,height);
    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder surfaceHolder) {
        eglHelper.surfaceDestroyed();
    }
}
