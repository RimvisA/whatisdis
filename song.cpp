#include "song.h"

using namespace song;

int song::Song::id = 01250;

 Song::Song(string n){
    this->name = n;
    this->SongID = id;
    ++id;
}

bool song::Song::reviewSongName (string name)
{
    for (int i = 0; i < name.length(); ++i)
    {
        if ((!(isupper(name[0])) || !isalpha(name[i]) && name[i] != ' '))
        {
            throw invalid_argument ("Invalid name");
        }
    }
    return true;
}

bool Song::Song::reviewSongYear (int year)
{
    if (year <= CURRENT_YEAR && year >= FIRST_SONG_EVER)
    {
        return true;
    }
    else
    {
        throw invalid_argument ("Invalid year");
    }
}


string song::Song::toString ()
{
    stringstream ss;

    ss << name << endl;
    ss << " " << artist << endl;
    ss << " " << writer << endl;
    ss << " " << genre << endl;
    ss << " " << year << endl;

    return ss.str();
}
