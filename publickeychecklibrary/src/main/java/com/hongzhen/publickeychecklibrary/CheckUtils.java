package com.hongzhen.publickeychecklibrary;

import android.content.Context;

public class CheckUtils {
    static {
        System.loadLibrary("PublicKCheck");
    }

    public native static String getKey(Context context);
}
