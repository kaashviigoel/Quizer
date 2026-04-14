# BACSE104 Micro-Project Report
## Structured and Object-Oriented Programming
### C++ Programming Track

**Project Title:** Smart Quiz Engine and Performance Analyzer

**Student Name:** Prerak Daga

**Registration Number:** ____________________

**Class / Section:** ____________________

**Faculty Name:** ____________________

**Date of Submission:** ____________________

---

## 1. Title of the Project
Smart Quiz Engine and Performance Analyzer.

## 2. Problem Statement
Many simple quiz programs only display questions and calculate a score, but they do not properly organize questions by type, save data, or analyze performance. This project aims to build a more complete quiz application that supports multiple question types, stores questions and results in files, and analyzes user performance in a structured way.

## 3. Objective of the Project
- To create a menu-driven quiz application in C++.
- To support different question types using inheritance and polymorphism.
- To store and load questions and results using file handling.
- To use STL containers and iterators for managing question objects.
- To calculate quiz scores and display performance summaries.

## 4. Track Chosen
C++ Programming Track.

## 5. Features of the Proposed System
- Add quiz questions.
- Support multiple question types such as MCQ and True/False.
- Load questions from a file.
- Save updated questions back to a file.
- Conduct a quiz for the user.
- Calculate score and percentage.
- Save result history to a file.
- Use STL vector and iterators for question management.

## 6. Concepts Used
The following C++ concepts are used in this project:
- Classes and objects.
- Constructors and destructors.
- Encapsulation.
- Inheritance.
- Polymorphism.
- Templates.
- STL containers and iterators.
- File handling.

## 7. System Design / Program Design
The project is divided into multiple classes. The base class `Question` stores common data such as question text, category, and marks. The derived classes `MCQQuestion` and `TFQuestion` implement different question formats and override virtual functions for display and answer checking. `QuizManager` stores the questions in a `vector<shared_ptr<Question>>`, runs the quiz, calculates results, and saves data to files. File organization is separated into header and implementation files for better modularity.

## 8. Algorithm / Logic
1. Start the program.
2. Load questions from the file.
3. Display the main menu.
4. Allow the user to take the quiz or save questions/results.
5. For each question, display the text and options.
6. Accept the user’s answer.
7. Compare the answer with the correct one.
8. Update the score and total marks.
9. Show the final score and percentage.
10. Save the result to a file.
11. End the program.

## 9. Sample Input and Output
### Sample Input
- Student Name: Prerak Daga
- Selected quiz category: All
- Answers entered for the questions

### Sample Output
```text
Enter student name: Prerak Daga

What is 2+2?
1) 3
2) 4
3) 5
4) 6
Your answer: 2

The earth is round.
1) True
2) False
Your answer: 1

Score: 10/10
Percentage: 100%
```

## 10. Testing
| Test Case | Input | Expected Result | Actual Result |
|---|---|---|---|
| Take quiz with correct answers | Valid name and correct options | Full score displayed | Full score displayed |
| Take quiz with wrong answers | Valid name and wrong options | Lower score displayed | Lower score displayed |
| Save questions | Menu option 2 | Questions written to file | Questions written to file |
| Save result | Menu option 3 | Result appended to result file | Result appended to result file |

## 11. Challenges Faced
- Designing multiple question types in a clean object-oriented way.
- Implementing polymorphism using a base class pointer.
- Managing file input and output correctly.
- Using `stoi()` and string parsing while loading data.
- Handling user input without leftover buffer issues.

## 12. Conclusion
This project helped in understanding object-oriented programming in C++ in a practical way. It demonstrates the use of inheritance, polymorphism, templates, STL containers, iterators, and file handling in a single application. The project also improved modular coding and problem-solving skills.

## 13. Future Enhancement
- Add login protection for admin mode.
- Add more question types such as fill-in-the-blank and matching.
- Add a leaderboard and advanced analytics.
- Improve the user interface and error handling.

## 14. References
- Course notes for Structured and Object-Oriented Programming.
- C++ reference documentation.
- STL and file handling examples discussed in class.
- Standard C++ library documentation.

---

## Submission Checklist
- Title page
- Problem statement and objectives
- Features and concepts used
- Design / algorithm
- Source code
- Sample output
- Test cases
- Conclusion
- References
