#include "Admin.h"
#include <iostream>
#include <limits>
using namespace std;

void Admin::addQuestionFlow(Quiz &quiz) {
  string t, o1, o2, o3, o4, cat, diff;
  int c, m;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Question: ";
  getline(cin, t);
  cout << "Option 1: ";
  getline(cin, o1);
  cout << "Option 2: ";
  getline(cin, o2);
  cout << "Option 3: ";
  getline(cin, o3);
  cout << "Option 4: ";
  getline(cin, o4);
  cout << "Correct option number: ";
  cin >> c;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Category: ";
  getline(cin, cat);
  cout << "Difficulty: ";
  getline(cin, diff);
  cout << "Marks: ";
  cin >> m;
  quiz.addQuestion(Question(t, o1, o2, o3, o4, c, cat, diff, m));
}