#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Question{
    public:
    Question(string text, int points){
        this->text = text;
        this->points = points;
        correct = false;
    }

    int getPointsScored() const {
        return points * correct;
    }

    virtual void askQuestion() = 0;

    protected:
    string text;
    int points;
    bool correct;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string text, bool correctAnswer, int points) : Question(text, points){
        this->correctAnswer = correctAnswer;
    }

    void askQuestion(){
        cout << text << endl;
        cout << "Answer T or F: " << endl;
        string userInput;
        bool userAnswer = false;
        cin >> userInput;
        if(userInput == "T"){
            userAnswer = true;
        }
        correct = userAnswer == correctAnswer;
    }

    private:
    bool correctAnswer;
};

class MathQuestion : public Question {
    public:
    MathQuestion(string text, double correctAnswer, int points) : Question(text, points) {
        this->correctAnswer = correctAnswer;
    }

    void askQuestion(){
        cout << text << endl;
        cout << "Enter in your numerical solution with at least 2 points of precision: " << endl;
        double userAnswer;
        cin >> userAnswer;
        if(abs(userAnswer - correctAnswer) < 0.01){
            correct = true;
        }
    }

    private:
    double correctAnswer;
};

int main(){

    vector<Question*> quiz;
    quiz.push_back(new TrueFalseQuestion("Investing in stocks is literally just gambling", true, 10));
    quiz.push_back(new TrueFalseQuestion("Rust will never replace C++.", true, 10));
    quiz.push_back(new TrueFalseQuestion("UNCC is a better institution than NC State.", true, 10));
    quiz.push_back(new MathQuestion("2 + 2 = ?", 4.0, 10));

    int score = 0;
    for(int i = 0; i < quiz.size(); i++){
        quiz.at(i)->askQuestion();
        score += quiz.at(i)->getPointsScored();
    }

    cout << "You scored: " << score << endl;

    return 0;
}