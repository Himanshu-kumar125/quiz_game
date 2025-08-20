#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Question {
    string text;
    vector<string> options;
    int correctOption;
};

bool askQuestion(const Question& q) {
    cout << q.text << "\n";
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << "\n";
    }
    cout << "Your answer (1-" << q.options.size() << "): ";
    int userAnswer;
    cin >> userAnswer;
    return userAnswer == q.correctOption;
}

void runQuiz(const vector<Question>& questions) {
    int score = 0;
    for (const auto& q : questions) {
        if (askQuestion(q)) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong! The correct answer was " << q.correctOption << ".\n";
        }
        cout << "\n";
    }
    cout << "Quiz finished. Your score: " << score << "/" << questions.size() << "\n";
}

int main() {
    vector<Question> questions = {
        {"What is the capital of France?", {"Berlin", "Paris", "Madrid", "London"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"Shakespeare", "Dickens", "Hemingway", "Twain"}, 1},
        {"What is the largest planet?", {"Earth", "Saturn", "Jupiter", "Mars"}, 3},
        {"Which ocean is the deepest?", {"Atlantic", "Indian", "Southern", "Pacific"}, 4},
        {"What is H2O?", {"Hydrogen", "Water", "Oxygen", "Helium"}, 2},
        {"Which country hosts the Taj Mahal?", {"Nepal", "Pakistan", "India", "Bangladesh"}, 3},
        {"Who painted the Mona Lisa?", {"Dali", "da Vinci", "Picasso", "Van Gogh"}, 2},
        {"What year did World War II end?", {"1940", "1942", "1945", "1948"}, 3},
        {"What gas do plants breathe in?", {"Oxygen", "Carbon Dioxide", "Hydrogen", "Nitrogen"}, 2},
        {"How many continents are there?", {"5", "6", "7", "8"}, 3},
        {"What is the hardest natural substance?", {"Gold", "Diamond", "Iron", "Granite"}, 2},
        {"Who discovered penicillin?", {"Newton", "Einstein", "Fleming", "Pasteur"}, 3},
        {"Which planet is closest to the sun?", {"Venus", "Earth", "Mercury", "Mars"}, 3},
        {"Who is known as the 'Father of Computers'?", {"Turing", "Jobs", "Gates", "Babbage"}, 4},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Shark", "Rhino"}, 2},
        {"How many sides does a triangle have?", {"2", "3", "4", "5"}, 2},
        {"Which language is used in Japan?", {"Chinese", "Korean", "Japanese", "Thai"}, 3},
        {"E = mc^2 is associated with?", {"Newton", "Einstein", "Galileo", "Faraday"}, 2},
        {"Pyramids are in which country?", {"Greece", "Italy", "India", "Egypt"}, 4},
        {"What is the boiling point of water (°C)?", {"90", "80", "100", "120"}, 3}
    };

    runQuiz(questions);
    return 0;
}
