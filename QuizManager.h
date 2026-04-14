#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "Question.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;

class QuizManager {
private:
  vector<shared_ptr<Question>> questions;
  string studentName;
  int score;
  int total;

public:
  QuizManager();
  ~QuizManager();
  void loadQuestions(const string &filename);
  void saveQuestions(const string &filename) const;
  void addSampleQuestions();
  void runQuiz();
  void saveResult(const string &filename) const;
  template <typename T> T percentage() const {
    return total ? static_cast<T>(score) * 100 / total : 0;
  }
};

#endif