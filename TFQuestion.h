#ifndef TFQUESTION_H
#define TFQUESTION_H

#include "Question.h"
#include <string>
using namespace std;

class TFQuestion : public Question {
private:
  bool answer;

public:
  TFQuestion();
  TFQuestion(string t, string c, int m, bool a);
  void display() const override;
  bool checkAnswer(const string &ans) const override;
  string serialize() const override;
  static TFQuestion deserialize(const string &line);
};

#endif