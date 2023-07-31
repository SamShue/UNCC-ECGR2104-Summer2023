#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Question {
    public:
    Question(string questionText, int points){
        this->questionText = questionText;
        this->points = points;
        correct = false;
    }
    
    int getPointsEarned() const {
        if(correct)
            return points;
        return 0;
    }
    
    int getPoints() const {
        return points;
    }
    
    virtual void askQuestion() = 0;
    
    protected:
    string questionText;
    int points;
    bool correct;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string questionText, bool correctAnswer, int points) : Question(questionText, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << questionText << endl;
        cout << "Please enter T for True or F for False" << endl;
        string temp;
        getline(cin, temp);
        bool userAnswer = (temp == "T") ? true : false;
        if(userAnswer == correctAnswer){
            correct = true;
        }
    }
    
    private:
    bool correctAnswer;
};

class NumericalQuestion : public Question {
    public:
    NumericalQuestion(string questionText, double correctAnswer, int points) : Question(questionText, points) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << questionText << endl;
        cout << "Please enter a number:" << endl;
        string temp;
        getline(cin, temp);
        double userAnswer = stod(temp);
        if(fabs(userAnswer - correctAnswer) < 0.001){
            correct = true;
        }
    }
    
    private:
    double correctAnswer;
};

int main(){
    
    vector<Question*> quiz;
    quiz.push_back(new TrueFalseQuestion("X is a better name than Twitter", false, 10));
    quiz.push_back(new NumericalQuestion("2 + 2 = ?", 4.0, 10));
    
    int totalPoints = 0;
    int scoredPoints = 0;
    for(int i = 0; i < quiz.size(); i++){
        quiz.at(i)->askQuestion();
        totalPoints += quiz.at(i)->getPoints();
        scoredPoints += quiz.at(i)->getPointsEarned();
    }
    
    cout << "You scored " << scoredPoints << " out of " << totalPoints << "." << endl;
    
    return 0;
}