package com.wang.androidlame;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.wang.androidlame.recorder.Mp3Recorder;

/**
 * 1、MP3录音
 * 2、PCM转换成MP3：通知进度
 */
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Mp3Recorder recorder = new Mp3Recorder();

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(recorder.stringFromJNI());
    }
}