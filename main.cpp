#include "Admin.h"
#include "Quiz.h"
#include <iostream>
using namespace std;

int main() {
  Quiz quiz;
  quiz.loadQuestions("questions.txt");
  int ch;
  while (true) {
    cout << "\n1. Add Question\n2. Take Quiz\n3. Save Questions\n4. "
            "Exit\nChoice: ";
    cin >> ch;
    if (ch == 1) {
      Admin::addQuestionFlow(quiz);
    } else if (ch == 2) {
      quiz.run();
      quiz.saveResult("results.txt");
    } else if (ch == 3) {
      quiz.saveQuestions("questions.txt");
      cout << "Saved.\n";
    } else if (ch == 4)
      break;
    else
      cout << "Invalid choice\n";
  }
  return 0;
}