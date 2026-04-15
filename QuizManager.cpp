#include "QuizManager.h"
#include "MCQQuestion.h"
#include "TFQuestion.h"
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

QuizManager::QuizManager() : score(0), total(0) {}
QuizManager::~QuizManager() {}

void QuizManager::loadQuestions(const string &filename) {
  questions.clear();
  ifstream fin(filename);
  string line;
  while (getline(fin, line)) {
    if (line.rfind("MCQ|", 0) == 0)
      questions.push_back(
          make_shared<MCQQuestion>(MCQQuestion::deserialize(line)));
    else if (line.rfind("TF|", 0) == 0)
      questions.push_back(
          make_shared<TFQuestion>(TFQuestion::deserialize(line)));
  }
}

void QuizManager::saveQuestions(const string &filename) const {
  ofstream fout(filename);
  for (auto it = questions.begin(); it != questions.end(); ++it)
    fout << (*it)->serialize() << '\n';
}

void QuizManager::addQuestion() {
  cout << "Select type:\n1. MCQ\n2. True/False\nChoice: ";
  int type;
  cin >> type;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string text, category;
  int marks;
  cout << "Question text: ";
  getline(cin, text);
  cout << "Category: ";
  getline(cin, category);
  cout << "Marks: ";
  cin >> marks;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (type == 1) {
    string o1, o2, o3, o4;
    int correct;
    cout << "Option 1: ";
    getline(cin, o1);
    cout << "Option 2: ";
    getline(cin, o2);
    cout << "Option 3: ";
    getline(cin, o3);
    cout << "Option 4: ";
    getline(cin, o4);
    cout << "Correct option number (1-4): ";
    cin >> correct;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    questions.push_back(make_shared<MCQQuestion>(text, category, marks, o1, o2,
                                                 o3, o4, correct));
  } else if (type == 2) {
    int ans;
    cout << "Correct answer (1 for True, 0 for False): ";
    cin >> ans;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    questions.push_back(
        make_shared<TFQuestion>(text, category, marks, ans == 1));
  } else {
    cout << "Invalid type.\n";
  }
}

void QuizManager::runQuiz() {
  cout << "Enter student name: ";
  getline(cin, studentName);
  if (studentName.empty())
    getline(cin, studentName);
  score = 0;
  total = 0;
  for (auto it = questions.begin(); it != questions.end(); ++it) {
    cout << "\n";
    (*it)->display();
    cout << "Your answer: ";
    string ans;
    getline(cin, ans);
    if ((*it)->checkAnswer(ans))
      score += (*it)->getMarks();
    total += (*it)->getMarks();
  }
  cout << "\nScore: " << score << "/" << total << "\n";
  cout << "Percentage: " << percentage<double>() << "%\n";
}

void QuizManager::saveResult(const string &filename) const {
  ofstream fout(filename, ios::app);
  fout << studentName << "|" << score << "|" << total << "|"
       << percentage<double>() << '\n';
}
