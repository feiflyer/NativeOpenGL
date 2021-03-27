package com.xgbk.nativeopengl;

import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

import com.xgbk.nativeopengl.view.EGL3SurfaceView;


public class NativeEglActivity extends AppCompatActivity {

    private EGL3SurfaceView surface_view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_native_egl);
        surface_view = findViewById(R.id.surface_view);

    }

    public void drawTexture(View view){
        surface_view.drawTexture();
    }
}