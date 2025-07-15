#include<bits/stdc++.h>
using namespace std;
// SONG CLASS
class Song{
    private:
        string title;
        string artist;
        string genre;
        int playCount;
    public:
        Song(){
            title="";
            artist="";
            genre="";
            playCount=0;
        }
        Song(string title,string artist,string genre){
            this->title=title;
            this->artist=artist;
            this->genre=genre;
            playCount=0;
        }
        void playSong(){
            playCount++;
        }
        void displaySong() const {
            cout << "TITLE : " << title << " ARTIST : " << artist << " GENRE : " << genre << "\n";
        }
        string getGenre() const {
            return genre;
        }
        string getTitle() const {
            return title;
        }
        string getArtist() const {
            return artist;
        }
};
// PLAYLIST 
class Playlist{
    private:
        string name;
        vector<Song>songs;
    public:
        Playlist(string name){
            this->name=name;
        }
        void addSong(Song &song){
            
        }
};