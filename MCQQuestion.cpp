#include "MCQQuestion.h"
#include <iostream>
#include <sstream>
using namespace std;

MCQQuestion::MCQQuestion() : Question(), correctIndex(1) {}

MCQQuestion::MCQQuestion(string t, string c, int m, string o1, string o2,
                         string o3, string o4, int correct)
    : Question(t, c, m), correctIndex(correct) {
  options[0] = o1;
  options[1] = o2;
  options[2] = o3;
  options[3] = o4;
}

void MCQQuestion::display() const {
  cout << text << '\n';
  for (int i = 0; i < 4; i++)
    cout << i + 1 << ") " << options[i] << '\n';
}

bool MCQQuestion::checkAnswer(const string &ans) const {
  try {
    return stoi(ans) == correctIndex;
  } catch (...) {
    return false;
  }
}

string MCQQuestion::serialize() const {
  return "MCQ|" + text + "|" + category + "|" + to_string(marks) + "|" +
         options[0] + "|" + options[1] + "|" + options[2] + "|" + options[3] +
         "|" + to_string(correctIndex);
}

MCQQuestion MCQQuestion::deserialize(const string &line) {
  string p[9], token;
  stringstream ss(line);
  int i = 0;
  while (getline(ss, token, '|') && i < 9)
    p[i++] = token;
  return MCQQuestion(p[1], p[2], stoi(p[3]), p[4], p[5], p[6], p[7],
                     stoi(p[8]));
}