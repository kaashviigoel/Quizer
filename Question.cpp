#include "Question.h"

Question::Question() : text(""), category(""), marks(1) {}
Question::Question(string t, string c, int m)
    : text(t), category(c), marks(m) {}
Question::~Question() {}
string Question::getCategory() const { return category; }
int Question::getMarks() const { return marks; }