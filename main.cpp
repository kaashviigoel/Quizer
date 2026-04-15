#include "QuizManager.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
  QuizManager qm;
  qm.loadQuestions("questions.txt");

  int ch;
  while (true) {
    cout << "\n=== Quiz Menu ===\n";
    cout << "1. Add Question\n";
    cout << "2. Take Quiz\n";
    cout << "3. Save Questions\n";
    cout << "4. Save Result\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (ch == 1)
      qm.addQuestion();
    else if (ch == 2)
      qm.runQuiz();
    else if (ch == 3) {
      qm.saveQuestions("questions.txt");
      cout << "Questions saved.\n";
    } else if (ch == 4) {
      qm.saveResult("results.txt");
      cout << "Result saved.\n";
    } else if (ch == 5)
      break;
    else
      cout << "Invalid choice.\n";
  }
  return 0;
}