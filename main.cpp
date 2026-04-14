#include "QuizManager.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  QuizManager qm;
  qm.loadQuestions("questions.txt");
  ifstream test("questions.txt");
  if (!test)
    qm.addSampleQuestions();
  int ch;
  while (true) {
    cout << "\n1. Take Quiz\n2. Save Questions\n3. Save Result\n4. "
            "Exit\nChoice: ";
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (ch == 1)
      qm.runQuiz();
    else if (ch == 2)
      qm.saveQuestions("questions.txt");
    else if (ch == 3)
      qm.saveResult("results.txt");
    else if (ch == 4)
      break;
  }
  return 0;
}