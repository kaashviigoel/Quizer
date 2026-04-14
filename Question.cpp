#include "Question.h"
#include <iostream>
#include <sstream>
using namespace std;

Question::Question()
    : text(""), correct(1), category(""), difficulty(""), marks(1) {}

Question::Question(string t, string o1, string o2, string o3, string o4, int c,
                   string cat, string diff, int m) {
  text = t;
  options[0] = o1;
  options[1] = o2;
  options[2] = o3;
  options[3] = o4;
  correct = c;
  category = cat;
  difficulty = diff;
  marks = m;
}

void Question::display() const {
  cout << text << '\n';
  for (int i = 0; i < 4; i++)
    cout << i + 1 << ") " << options[i] << '\n';
}

bool Question::isCorrect(int choice) const { return choice == correct; }

string Question::serialize() const {
  return text + "|" + options[0] + "|" + options[1] + "|" + options[2] + "|" +
         options[3] + "|" + to_string(correct) + "|" + category + "|" +
         difficulty + "|" + to_string(marks);
}

Question Question::deserialize(const string &line) {
  string parts[9];
  string token;
  stringstream ss(line);
  int i = 0;
  while (getline(ss, token, '|') && i < 9)
    parts[i++] = token;
  return Question(parts[0], parts[1], parts[2], parts[3], parts[4],
                  stoi(parts[5]), parts[6], parts[7], stoi(parts[8]));
}

string Question::getCategory() const { return category; }
string Question::getDifficulty() const { return difficulty; }
int Question::getMarks() const { return marks; }