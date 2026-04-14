#include "QuizManager.h"
#include "MCQQuestion.h"
#include "TFQuestion.h"
#include <fstream>
#include <iostream>
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

void QuizManager::addSampleQuestions() {
  questions.push_back(make_shared<MCQQuestion>("What is 2+2?", "Math", 5, "3",
                                               "4", "5", "6", 2));
  questions.push_back(
      make_shared<TFQuestion>("The earth is round.", "Science", 5, true));
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