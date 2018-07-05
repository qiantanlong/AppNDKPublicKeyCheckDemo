package com.hongzhen.ndk.key;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.hongzhen.publickeychecklibrary.CheckUtils;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String key = CheckUtils.getKey(this);
        Log.i("Main:",key);
    }
}
