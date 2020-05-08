#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

struct Answer {
    string answer;
    char choice;
    int score;
};

struct Question {
    string question;
    Answer answer1;
    Answer answer2;
    Answer answer3;
    Answer answer4;
};