package com.example.testforjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static{
        System.loadLibrary("test");
    }

    private native int Add(int a, int b);
    private native void StringAdd(String str1, String str2);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int c = Add(10, 20);
        TextView textView = (TextView) findViewById(R.id.textView);
        textView.setText(Integer.toString(c));
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if(event.getAction() == MotionEvent.ACTION_DOWN){
            StringAdd("this is ", "a test");
        }
        return super.onTouchEvent(event);
    }

    private void callByNative(String str){
        TextView textView = (TextView) findViewById(R.id.textView);
        textView.setText(str);
    }
}