#include "TFQuestion.h"
#include <iostream>
#include <sstream>
using namespace std;

TFQuestion::TFQuestion() : Question(), answer(false) {}
TFQuestion::TFQuestion(string t, string c, int m, bool a)
    : Question(t, c, m), answer(a) {}

void TFQuestion::display() const {
  cout << text << '\n';
  cout << "1) True\n2) False\n";
}

bool TFQuestion::checkAnswer(const string &ans) const {
  bool user = (ans == "1" || ans == "true" || ans == "True");
  return user == answer;
}

string TFQuestion::serialize() const {
  return "TF|" + text + "|" + category + "|" + to_string(marks) + "|" +
         string(answer ? "1" : "0");
}

TFQuestion TFQuestion::deserialize(const string &line) {
  string p[5], token;
  stringstream ss(line);
  int i = 0;
  while (getline(ss, token, '|') && i < 5)
    p[i++] = token;
  return TFQuestion(p[1], p[2], stoi(p[3]), p[4] == "1");
}