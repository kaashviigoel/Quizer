#include "Quiz.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

Quiz::Quiz() : score(0), totalMarks(0) {}

void Quiz::loadQuestions(const string &filename) {
  questions.clear();
  ifstream fin(filename);
  string line;
  while (getline(fin, line))
    if (!line.empty())
      questions.push_back(Question::deserialize(line));
}

void Quiz::addQuestion(const Question &q) { questions.push_back(q); }

void Quiz::saveQuestions(const string &filename) const {
  ofstream fout(filename);
  for (const auto &q : questions)
    fout << q.serialize() << '\n';
}

void Quiz::filterByCategory(const string &category) {
  filtered.clear();
  for (const auto &q : questions)
    if (q.getCategory() == category)
      filtered.push_back(q);
  if (filtered.empty())
    filtered = questions;
}

void Quiz::run() {
  cout << "Enter student name: ";
  getline(cin, studentName);
  if (studentName.empty())
    getline(cin, studentName);
  cout << "Enter category to attempt (or ALL): ";
  string cat;
  getline(cin, cat);
  if (cat == "ALL" || cat == "all")
    filtered = questions;
  else
    filterByCategory(cat);
  score = 0;
  totalMarks = 0;
  for (size_t i = 0; i < filtered.size(); i++) {
    cout << "\nQ" << i + 1 << ":\n";
    filtered[i].display();
    cout << "Your answer (1-4): ";
    int ans;
    cin >> ans;
    if (filtered[i].isCorrect(ans))
      score += filtered[i].getMarks();
    totalMarks += filtered[i].getMarks();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  showResults();
}

void Quiz::showResults() const {
  cout << "\n--- Result ---\n";
  cout << "Name: " << studentName << '\n';
  cout << "Score: " << score << "/" << totalMarks << '\n';
  cout << "Percentage: " << (totalMarks ? (100.0 * score / totalMarks) : 0)
       << "%\n";
}

void Quiz::saveResult(const string &filename) const {
  ofstream fout(filename, ios::app);
  time_t now = time(nullptr);
  fout << studentName << "|" << score << "|" << totalMarks << "|"
       << (totalMarks ? (100.0 * score / totalMarks) : 0) << "|" << ctime(&now);
}
