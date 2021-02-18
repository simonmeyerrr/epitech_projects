package com.appdev.epicture

import android.content.Context
import android.content.Intent
import android.net.Uri
import androidx.core.content.ContextCompat.startActivity


object ImgurApi {

    private val clientId: String = "e8eecea4023016a"
    private val clientSecret: String = "edbcd2a7776864b80536fd76642b07a122c78b75"
    private val host = "api.imgur.com"
    private val credentials : HashMap<String, String> = HashMap()

    fun askCredentials(context: Context) {
        val url = "https://$host/oauth2/authorize?client_id=$clientId&response_type=token"
        val intent = Intent(Intent.ACTION_VIEW, Uri.parse(url))
        startActivity(context, intent, null)
    }

    fun validateCredentials(data: Uri) : Boolean {
        credentials.clear()
        val uriData = data.toString().split('#')
        if (uriData.size != 2) {
            return false
        }

        val params = uriData[1].split("&")
        for (element in params) {
            val pair = element.split("=")
            if (pair.size != 2) {
                return false
            }
            credentials[pair[0]] = pair[1]
        }
        if (credentials["access_token"].isNullOrBlank() || credentials["expires_in"].isNullOrBlank() ||
            credentials["token_type"].isNullOrBlank() || credentials["refresh_token"].isNullOrBlank() ||
            credentials["account_username"].isNullOrBlank() || credentials["account_id"].isNullOrBlank() ||
            credentials["token_type"] != "bearer") {
            credentials.clear()
            println("Something is not valid in credentials !!!!!!!")
            return false
        }
        return true
    }

    fun getUsername() : String? {
        return credentials["account_username"]
    }

    fun getUserId() : String? {
        return credentials["account_id"]
    }

    fun getToken() : String? {
        return credentials["access_token"]
    }
}