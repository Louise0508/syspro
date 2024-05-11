package com.cookandroid.music;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Bitmap;
import android.media.MediaMetadataRetriever;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import java.io.File;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ListView listViewMP3;
    private ArrayList<String> mp3List;
    private String mp3Path;
    private android.graphics.BitmapFactory BitmapFactory;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("DCU Music");


        mp3Path = "/storage/6166-3166/Music/";


        listViewMP3 = findViewById(R.id.listViewMP3);


        ActivityCompat.requestPermissions(this, new String[]{android.Manifest.permission.READ_EXTERNAL_STORAGE}, Context.MODE_PRIVATE);


        mp3List = new ArrayList<>();
        File[] listFiles = new File(mp3Path).listFiles();
        for (File file : listFiles) {
            mp3List.add(file.getName());
        }

        CustomAdapter adapter = new CustomAdapter(this, R.layout.custom_list_item, mp3List);
        listViewMP3.setAdapter(adapter);

        listViewMP3.setOnItemClickListener((parent, view, position, id) -> {
            String selectedSong = mp3List.get(position);
            String songPath = mp3Path + selectedSong;

            playSong(songPath);
        });
    }


    private void playSong(String songPath) {

    }


    private class CustomAdapter extends ArrayAdapter<String> {

        public CustomAdapter(Context context, int resource, ArrayList<String> items) {
            super(context, resource, items);
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            View view = convertView;
            if (view == null) {
                view = getLayoutInflater().inflate(R.layout.custom_list_item, null);
            }


            ImageView albumImageView = view.findViewById(R.id.albumImageView);
            TextView songNameTextView = view.findViewById(R.id.songNameTextView);


            String songName = getItem(position);


            Bitmap albumArt = getAlbumArt(songName);
            if (albumArt != null)
            {
                albumImageView.setImageBitmap(albumArt);
            }
            else
            {
                albumImageView.setImageResource(R.drawable.default_album_art);
            }


            songNameTextView.setText(songName);

            return view;
        }
    }

    private Bitmap getAlbumArt(String songName) {
        String songPath = mp3Path + songName;
        MediaMetadataRetriever retriever = new MediaMetadataRetriever();
        retriever.setDataSource(songPath);
        byte[] albumArt = retriever.getEmbeddedPicture();
        if (albumArt != null) {
            return BitmapFactory.decodeByteArray(albumArt, 0, albumArt.length);
        } else {
            return null;
        }
    }
}