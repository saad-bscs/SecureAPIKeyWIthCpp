package com.example.secrureapiwithcpp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log

class MainActivity : AppCompatActivity() {

    object Keys {
        init {
            System.loadLibrary("native-lib")
        }
        external fun APIKey() : String
        external fun APIKey1() :String
        external fun APIKey2() : String
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        Log.e("API-Key: ",""+Keys.APIKey())
        Log.e("API-Key11: ",""+Keys.APIKey1())
        Log.e("API-Key12: ",""+Keys.APIKey2())
    }
}