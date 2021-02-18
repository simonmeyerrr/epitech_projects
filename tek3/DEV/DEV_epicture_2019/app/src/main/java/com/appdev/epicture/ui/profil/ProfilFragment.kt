package com.appdev.epicture.ui.profil

import android.content.Intent
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.fragment.app.Fragment
import com.appdev.epicture.ImgurApi
import com.appdev.epicture.LoginActivity
import com.appdev.epicture.R
import kotlinx.android.synthetic.main.fragment_profil.*

class ProfilFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val root = inflater.inflate(R.layout.fragment_profil, container, false)
        val textId: TextView = root.findViewById(R.id.text_profil_id)
        val textUsername: TextView = root.findViewById(R.id.text_profil_username)
        textId.text = ImgurApi.getUserId()
        textUsername.text = ImgurApi.getUsername()
        return root
    }

    override fun onStart() {
        super.onStart()
        btn_logout.setOnClickListener {
            startActivity(Intent(this.activity, LoginActivity::class.java))
            this.activity?.finish()
        }
    }
}