#ifndef MCQQUESTION_H
#define MCQQUESTION_H

#include "Question.h"
#include <string>
using namespace std;

class MCQQuestion : public Question {
private:
  string options[4];
  int correctIndex;

public:
  MCQQuestion();
  MCQQuestion(string t, string c, int m, string o1, string o2, string o3,
              string o4, int correct);
  void display() const override;
  bool checkAnswer(const string &ans) const override;
  string serialize() const override;
  static MCQQuestion deserialize(const string &line);
};

#endif