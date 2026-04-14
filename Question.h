#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
protected:
  string text;
  string category;
  int marks;

public:
  Question();
  Question(string t, string c, int m);
  virtual ~Question();
  virtual void display() const = 0;
  virtual bool checkAnswer(const string &ans) const = 0;
  virtual string serialize() const = 0;
  string getCategory() const;
  int getMarks() const;
};

#endif