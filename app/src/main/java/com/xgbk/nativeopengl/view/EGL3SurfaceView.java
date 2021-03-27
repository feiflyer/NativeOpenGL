package com.xgbk.nativeopengl.view;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

import com.xgbk.nativeopengl.R;
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

    public void drawTexture(){
        BitmapFactory.Options options = new BitmapFactory.Options();
        // 注意这句，不然可会会在某些机型上面无法显示
        options.inScaled = false;
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.aaaa,options);
        eglHelper.drawImage(bitmap);
    }
}
