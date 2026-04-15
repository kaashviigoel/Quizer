# Quizer

A C++ micro-project developed for **BACSE104 - Structured and Object-Oriented Programming** under the **C++ Programming Track**. This project is a menu-driven quiz application that supports multiple question types, stores quiz data in files, and analyzes user performance.

## Course Context
This project is aligned with the BACSE104 micro-project requirements for the C++ track. It demonstrates meaningful object-oriented design using multiple classes, inheritance, polymorphism, STL containers and iterators, templates, and file handling.

## Project Overview
The application lets a user add quiz questions, take a quiz, and save results for later review. It uses an abstract base class for common question behavior and derived classes for different question types, which makes the design modular and easy to extend.

## Objectives
- Build a functional quiz application in C++.
- Apply object-oriented programming concepts in a meaningful way.
- Use inheritance and polymorphism for different question types.
- Use STL containers and iterators to manage question objects.
- Use file handling to store questions and results persistently.
- Demonstrate templates in a relevant way through percentage calculation.

## Features
- Menu-driven console interface.
- Add new quiz questions.
- Support for **MCQ** and **True/False** questions.
- Load questions from `questions.txt`.
- Save questions back to file.
- Conduct quizzes and calculate score.
- Save quiz results in `results.txt`.
- Display percentage and performance summary.

## C++ Concepts Used
This project includes the following required concepts:
- **Classes and Objects**
- **Constructors and Destructors**
- **Encapsulation**
- **Inheritance**
- **Polymorphism**
- **Templates**
- **STL Containers and Iterators**
- **File Handling**

## Class Design
### `Question`
Base abstract class containing common data such as question text, category, and marks, with virtual methods for display, answer checking, and serialization.

### `MCQQuestion`
Derived class for multiple-choice questions. It stores four options and the correct option index.

### `TFQuestion`
Derived class for true/false questions.

### `QuizManager`
Manages:
- Loading and saving questions.
- Adding questions.
- Running the quiz.
- Saving results.
- Calculating percentage using a template function.

## File Structure
```text
quiz_project/
├── main.cpp
├── Question.h
├── Question.cpp
├── MCQQuestion.h
├── MCQQuestion.cpp
├── TFQuestion.h
├── TFQuestion.cpp
├── QuizManager.h
├── QuizManager.cpp
├── questions.txt
└── results.txt
```

## How It Works
1. The program loads existing questions from `questions.txt`.
2. The user chooses an option from the menu.
3. New questions can be added and then saved.
4. The user can take the quiz.
5. The score and percentage are calculated.
6. The result is saved to `results.txt`.

## Menu Options
```text
1. Add Question
2. Take Quiz
3. Save Questions
4. Save Result
5. Add Sample Questions
6. Exit
```

## Sample Question File Format
### MCQ
```text
MCQ|What is 2+2?|Math|5|3|4|5|6|2
```

### True/False
```text
TF|The earth is round.|Science|5|1
```

## Compilation and Execution
Use the following command to compile the project:

```bash
g++ main.cpp Question.cpp MCQQuestion.cpp TFQuestion.cpp QuizManager.cpp -o quiz
```

Run the executable:

```bash
./quiz
```

## Example Workflow
- Choose **1** to add a question.
- Choose **3** to save the new question into `questions.txt`.
- Choose **2** to take the quiz.
- Choose **4** to save the quiz result into `results.txt`.

## Testing
Suggested test cases:
- Add an MCQ question and save it successfully.
- Add a True/False question and save it successfully.
- Attempt a quiz with correct answers.
- Attempt a quiz with wrong answers.
- Verify results are appended to `results.txt`.

## Challenges Faced
- Designing the system with proper inheritance and polymorphism.
- Handling input correctly using `cin`, `getline`, and `cin.ignore()`.
- Serializing and deserializing question data from files.
- Managing multiple source files in a C++ project.

## Future Enhancements
- Add more question types such as Fill in the Blank.
- Add admin login protection.
- Add category-wise result analysis.
- Add leaderboard and score history dashboard.
- Improve error handling and input validation.

## Conclusion
This project demonstrates the core C++ programming concepts required for the BACSE104 micro-project. It provides a practical quiz system with file storage, reusable class design, and result analysis features.

## References
- BACSE104 Structured and Object-Oriented Programming micro-project guideline.
- C++ standard library documentation.
- Course notes and class examples.

## Author
**Kaashvi Goel**
