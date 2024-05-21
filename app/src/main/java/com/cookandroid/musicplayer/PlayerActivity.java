package com.cookandroid.musicplayer;

import android.annotation.SuppressLint;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.musicplayer.R;

public class PlayerActivity extends AppCompatActivity {

    ImageView albumArt;
    TextView songTitle;
    SeekBar seekBar;
    MediaPlayer mediaPlayer;

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_player);

        albumArt = findViewById(R.id.albumArt);
        songTitle = findViewById(R.id.songTitle);
        seekBar = findViewById(R.id.seekBar);

        String title = getIntent().getStringExtra("title");
        String artist = getIntent().getStringExtra("artist");
        int duration = getIntent().getIntExtra("duration", 0);

        songTitle.setText(title + " - " + artist);

        // 여기서 MediaPlayer를 초기화하고 노래를 재생합니다
        mediaPlayer = MediaPlayer.create(this, R.raw.sample_song); // 샘플 노래 파일
        mediaPlayer.start();

        seekBar.setMax(duration);
        // 더 많은 기능 추가: SeekBar 업데이트, MediaPlayer 리스너 설정 등
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }
    }
}

