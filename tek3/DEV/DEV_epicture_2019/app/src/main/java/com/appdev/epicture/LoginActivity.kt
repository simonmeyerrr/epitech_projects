package com.appdev.epicture

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class LoginActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)

        val btnLogin = findViewById<Button>(R.id.btn_login)
        btnLogin.setOnClickListener {
            ImgurApi.askCredentials(this)
        }
        // clear dat imgur
    }

    override fun onResume() {
        super.onResume()
        val data = intent.data
        intent.data = null
        if (data != null && ImgurApi.validateCredentials(data)) {
            startActivity(Intent(this, MainActivity::class.java))
            finish()
        }
    }
}
