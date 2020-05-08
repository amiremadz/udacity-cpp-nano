#pragma once

#include <vector>
#include "school.hpp"

using std::vector;

class Houses : public School {
public:
    // constructor
    Houses();

    // public member functions
    string Name(int i)        {return names_[i];}
    string Founder(int i)     {return founders_[i];}
    string Ghost(int i)       {return ghosts_[i];}
    string Symbol(int i)      {return symbols_[i];}
    string Color(int i)       {return colors_[i];}
    string Description(int i) {return descriptions_[i];}
    string CommonRoom(int i)  {return common_rooms_[i];}

private:
    vector<string> names_{
        "Gryffindor",
        "Hufflepuff",
        "Ravenclaw",
        "Slytherin"
    };
    vector<string> founders_{
        "Godric Gryffindor",
        "Helga Hufflepuff",
        "Rowena Ravenclaw",
        "Salazar Slytherin"
    };
    vector<string> ghosts_{
        "Nearly Headless Nick",
        "Fat Friar",
        "The Grey Lady",
        "The Bloody Baron"
    };
    vector<string> symbols_{
        "Lion",
        "Badger",
        "Eagle",
        "Serpent"
    };
    vector<string> colors_{
        "Deep red and gold",
        "Yellow and black",
        "Blue and bronze",
        "Green and silver"
    };
    vector<string> descriptions_{
        "Well known for courage, bravery, daring, nerve, and chivalry",
        "Well known for loyalty, patience, hard work, fair-play, honesty, and tolerance",
        "Values intelligence, wit, cleverness, creativity, and wisdom",
        "Values ambition, leadership, cunning, determination, and resourcefulness"
    };
    vector<string> common_rooms_{
        "The entrance to the common room is on the seventh floor hidden behind a portrait of the Fat Lady. To enter, the correct password must be provided",
        "Located near the kitchens. To enter, one must tap a fake barrel in the rhythm \"Helga Hufflepuff.\" It is the only common room to have a way to keep students from other houses out (by dumping vinegar on them)",
        "Located in a high tower, and the interior is decorated with blue and bronze. To enter, one must answer a riddle from an eagle door knocker",
        "Located in the dungeons, underneath the Black Lake, and hidden behind a stone wall. To enter, the correct password must be provided"
    };
};