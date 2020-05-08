#include <iostream>
#include <numeric>
#include "houses.hpp"
#include "question.hpp"

using std::cout;
using std::cin;

// questions
Question q1{
        "Which trait do you care about the most in a significant other?",
        {
                "Bravery",
                'a',
                6
        },
        {
            "Loyalty",
            'b',
            3
        },
        {
            "Intelligence",
            'c',
            -3
        },
        {
            "Ambition",
            'd',
            -6
        }
};

Question q2{
    "Which trait is most important for yourself to have?",
    {
            "Bravery",
            'b',
            6
    },
    {
            "Loyalty",
            'c',
            3
    },
    {
            "Intelligence",
            'd',
            -3
    },
    {
            "Ambition",
            'a',
            -6
    }
};

Question q3 {
    "How do you feel about your parents?",
    {
        "I love them dearly",
        'a',
        6
    },
    {
        "They are okay",
        'd',
        3
    },
    {
        "They are annoying at times",
        'c',
        -3
    },
    {
        "I can't stand them",
        'b',
        -6
    }
};

Question q4 {
    "What power would you rather have?",
    {
        "Super strength",
        'c',
        6
    },
    {
        "The ability to talk to plants",
        'd',
        3
    },
    {
        "The ability to fly",
        'a',
        -3
    },
    {
        "The ability to breathe under water",
        'b',
        -6
    }
};

Question q5 {
    "Favorite color?",
    {
        "Red",
        'd',
        6
    },
    {
        "Yellow",
        'a',
        3
    },
    {
        "Blue",
        'b',
        -3
    },
    {
        "Green",
        'c',
        -6
    }
};

Question q6 {
    "In science class when you were assigned to work on teams you were:",
    {
        "The one that wanted to lead the team and make sure everyone on your team got a good grade",
        'd',
        6
    },
    {
        "The one that just wanted to get everything done and get a good grade for yourself",
        'c',
        3
    },
    {
        "The one that didn't want to work on a team and wanted to work alone",
        'b',
        -3
    },
    {
        "The one that just sat back and let everyone else do the work and then take the credit",
        'a',
        -6
    }
};

Question q7 {
    "What drink would you rather have in the morning?",
    {
        "Tea",
        'c',
        6
    },
    {
        "Coffee with plant-based milk",
        'b',
        3
    },
    {
        "Black coffee",
        'a',
        -3
    },
    {
        "Whiskey",
        'd',
        -6
    }
};

Question q8 {
    "How do you tend to face your fears?",
    {
        "I face them head on",
        'b',
        6
    },
    {
        "I try not to think about them too much",
        'd',
        3
    },
    {
        "I avoid them at all costs",
        'a',
        -3
    },
    {
        "I don't have any fears",
        'c',
        -6
    }
};

Question q9 {
    "You would be most hurt if a person called you:",
    {
        "Weak",
        'c',
        6
    },
    {
        "Ignorant",
        'b',
        3
    },
    {
        "Unkind",
        'a',
        -3
    },
    {
        "Boring",
        'd',
        -6
    }
};

Question q10 {
    "The sorting hat also takes your consideration into account so which house would you like to be in?",
    {
        "Gryffindor",
        'a',
        6,
    },
    {
        "Hufflepuff",
        'b',
        3
    },
    {
        "Ravenclaw",
        'c',
        -3
    },
    {
        "Slytherin",
        'd',
        -6
    }
};


// print questions in answer choices in order a-d
void PrintChoices(Question* q){
    vector<Answer> answers{q->answer1, q->answer2, q->answer3, q->answer4};
    vector<char> choice_chars{'a', 'b', 'c', 'd'};

    for(int i = 0; i < choice_chars.size(); ++i){
        for(auto answer: answers){
            if (answer.choice == choice_chars[i]){
                cout << choice_chars[i] << ") " << answer.answer << "\n";
            }
        }
    }
}

int ScoreChoice(Question* q, char choice){
    vector<Answer> answers{q->answer1, q->answer2, q->answer3, q->answer4};
    int ret;
    for(auto answer: answers){
        if(choice == answer.choice){
            ret = answer.score;
        }
    }
    return ret;
}

// answer a question
void QuestionFunc(Question* q, vector<int>* scores){
    char answer;
    cout << "\n" << q->question << "\n";
    PrintChoices(q);
    cout << "\nYour choice (type a, b, c, or d): ";
    cin >> answer;
    char score = ScoreChoice(q, answer);
    scores->push_back(score);
}

// decide house
int PickHouse(float n){
    if(n > 3){
        return 0;
    } else if (n <= 3 && n > 0){
        return 1;
    } else if (n <= 0 && n > -3){
        return 2;
    } else {
        return 3;
    }
}

int main() {
    // init vector to store question scores for user
    vector<int> scores{};

    // init houses
    Houses houses{};

    // ask questions
    vector<Question> questions{q1, q2, q3, q4, q5, q6, q7, q8, q9, q10};
    for(auto question: questions){
        QuestionFunc(&question, &scores);
    }

    // tally the user's score
    float average = std::accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    int house = PickHouse(average);

    // test
    cout << average << "\n\n";

    // print out the results
    cout << "\nCongratulations! You have been assigned to " << houses.Name(house) << "\n";
    cout << "Student Info\n"
         << "---------------------------------------------------------\n"
         << "School name:       " << houses.SchoolName()       << "\n"
         << "Headmaster:        " << houses.Headmaster()       << "\n"
         << "School location:   " << houses.Location()         << "\n"
         << "Year founded:      " << houses.Founded()          << "\n"
         << "School motto:      " << houses.Motto()            << "\n"
         << "House name:        " << houses.Name(house)        << "\n"
         << "House founder:     " << houses.Founder(house)     << "\n"
         << "House ghost:       " << houses.Ghost(house)       << "\n"
         << "House symbol:      " << houses.Symbol(house)      << "\n"
         << "House colors:      " << houses.Color(house)       << "\n"
         << "House description: " << houses.Description(house) << "\n"
         << "House common room: " << houses.CommonRoom(house)  << "\n";
}