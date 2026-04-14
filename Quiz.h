#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <string>
#include <vector>
using namespace std;

class Quiz {
private:
  vector<Question> questions;
  vector<Question> filtered;
  string studentName;
  int score;
  int totalMarks;

public:
  Quiz();
  void loadQuestions(const string &filename);
  void addQuestion(const Question &q);
  void saveQuestions(const string &filename) const;
  void run();
  void filterByCategory(const string &category);
  void showResults() const;
  void saveResult(const string &filename) const;
};

#endif