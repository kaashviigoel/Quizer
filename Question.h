#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
private:
  string text;
  string options[4];
  int correct;
  string category;
  string difficulty;
  int marks;

public:
  Question();
  Question(string t, string o1, string o2, string o3, string o4, int c,
           string cat, string diff, int m);
  void display() const;
  bool isCorrect(int choice) const;
  string serialize() const;
  static Question deserialize(const string &line);
  string getCategory() const;
  string getDifficulty() const;
  int getMarks() const;
};

#endif