#include<bits/stdc++.h>
using namespace std;
// SONG CLASS 
class Song{
    private:
        string title;
        string artist;
        string genre;
    public:
        // default constructor for the song
        Song(){
            title="";
            artist="";
            genre="";
        }
        // parameterised constructor for the song
        Song(string title,string artist,string genre){
            this->title=title;
            this->artist=artist;
            this->genre=genre;
        }
        // getter function to get the title of the song
        string getTitle()const {
            return title;
        }
        // getter function to get the artist of the song
        string getArtist()const {
            return artist;
        }
        // getter function to get the genre of the song
        string getGenre()const {
            return genre;
        }
        // function to display the song details
        void displaySong(){
            cout << "[NAME][ARTIST][GENRE]" << "\n";
            cout << title << " " << artist << " " << genre << "\n";
        }
};
// MUSIC SYSTEM CLASS 
class MusicSystem{
    private:
        vector<Song>songs;
    public:
        void addSong(Song &song){
            songs.push_back(song);
        }
        void showAllSongs(){
            cout << "\n";
            cout << "ALL SONGS" << "\n";
            for(int i=0;i<songs.size();i++){
                songs[i].displaySong();
            }
            cout << "\n";
        }
        void recommendSong(string genre){
            cout << "SONGS OF GENRE : " << genre << "\n";
            bool found=false;
            for(int i=0;i<songs.size();i++){
                string gen = songs[i].getGenre();
                if(gen==genre){
                    songs[i].displaySong();
                    found=true;
                }
            }
            if(found==false){
                cout << "NO SONG OF " << genre << "GENRE FOUND" << "\n";
            }
        }
};
int main() {
    MusicSystem system;
    Song s1("Blinding lights","The weekend","pop");
    Song s2("Believer","Imagine Dragons","Rock");
    Song s3("Livitating","Dua Lipa","Pop");
    Song s4("Back to Black","AC/DC","Rock");
    Song s5("No time to Die","Billie Eillish","Soundtrack");
    system.addSong(s1);
    system.addSong(s2);
    system.addSong(s3);
    system.addSong(s4);
    system.addSong(s5);
    system.showAllSongs();
    string genre;
    cout << "\nEnter genre to get recommendations: ";
    cin >> genre;
    system.recommendSong(genre);
    return 0;
}
