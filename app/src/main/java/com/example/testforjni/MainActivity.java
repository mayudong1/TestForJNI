package com.example.testforjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static{
        System.loadLibrary("test");
    }

    private native int Add(int a, int b);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int c = Add(10, 20);
        TextView textView = (TextView) findViewById(R.id.textView);
        textView.setText(Integer.toString(c));
    }
}