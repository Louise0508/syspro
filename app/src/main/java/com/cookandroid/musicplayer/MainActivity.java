package com.cookandroid.musicplayer;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.musicplayer.R;

import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    RecyclerView recyclerView;
    SongAdapter songAdapter;
    List<Song> songList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        songList = new ArrayList<>();
        songList.add(new Song("음악 제목 음악 제목", "가수 이름", 200));
        songList.add(new Song("음악 제목 음악 제목", "가수 이름", 200));
        // 더 많은 노래 추가

        songAdapter = new SongAdapter(this, songList);
        recyclerView.setAdapter(songAdapter);
    }
}

