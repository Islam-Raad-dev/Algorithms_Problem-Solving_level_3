#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==========================================
// Enums & Structs
// ==========================================

enum enQuizzLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    MixLevel = 4
};
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOp = 5
};

struct stQuestions
{
    enOperationType OperationType;
    enQuizzLevel QuizzLevel;
    int Number1 = 0;
    int Number2 = 0;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestions QuestionsList[100];
    enQuizzLevel QustionsLevel;
    enOperationType OperationType;
    short NumberOfQuestions;
    short NumberOfRightAnswer = 0;
    short NumberOfWorngAnswer = 0;
    bool isPass = true;
};

// ==========================================
// Function Prototypes
// ==========================================

int RandomNumber(int From, int To);
short ReadQuestionNumber();
enQuizzLevel ReadQuestionLevel();
enOperationType ReadOperationType();
enOperationType GetRandomOperationType();
int SimpleCalculator(int Number1, int Number2, enOperationType OpType);
stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType);
void GeneratQuizzQuestions(stQuizz &Quizz);
string GetOperationTypeSymbol(enOperationType OpType);
void PrintTheQestions(stQuizz &Quizz, short QustionsNumber);
int ReadQuestionAnswer();
void SetScreenColor(bool isRight);
void CorrectTheQuestionAnswer(stQuizz &Quizz, short QustionsNumber);
void AskAndCorrectQuestionsListAnswer(stQuizz &Quizz);
string GetFinalResultText(bool Pass);
string GetQustionsLevelText(enQuizzLevel QuestionLevel);
void PrintQuizzReults(stQuizz Quizz);
void ShowFinalQuizzScreen(stQuizz Quizz);
void ClearScreen();
void PlayMathGame();
void StartGame();
void DrawHeader(string Title);

// ==========================================
// Main Function
// ==========================================

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}

// ==========================================
// Function Definitions
// ==========================================

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadQuestionNumber()
{
    short NumberOfQustions;
    DrawHeader("START NEW QUIZ");
    do
    {
        cout << "\033[33m[?]\033[0m How Many Questions Do You Want (1-100)? : ";
        cin >> NumberOfQustions;
    } while (NumberOfQustions < 1 || NumberOfQustions > 100);
    return NumberOfQustions;
}

enQuizzLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    cout << "\033[33m[?]\033[0m Choose Level:\n";
    cout << "    [1] Easy\n    [2] Medium\n    [3] Hard\n    [4] Mix\n";
    do
    {
        cout << "Enter Choice: ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuizzLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
    short OperationType;
    cout << "\n\033[33m[?]\033[0m Choose Operation:\n";
    cout << "    [1] +\n    [2] -\n    [3] *\n    [4] /\n    [5] Mix\n";
    do
    {
        cout << "Enter Choice: ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}

enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        if (Number2 == 0)
            Number2 = 1;
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType)
{
    stQuestions Question;
    if (QuizzLevel == enQuizzLevel::MixLevel)
        QuizzLevel = (enQuizzLevel)RandomNumber(1, 3);
    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;
    Question.QuizzLevel = QuizzLevel;

    switch (QuizzLevel)
    {
    case enQuizzLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuizzLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuizzLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    default:
        break;
    }
    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    return Question;
}

void GeneratQuizzQuestions(stQuizz &Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QustionsLevel, Quizz.OperationType);
    }
}

string GetOperationTypeSymbol(enOperationType OpType)
{
    string arr[] = {"", "+", "-", "x", "/", "Mix"};
    return arr[OpType];
}

void PrintTheQestions(stQuizz &Quizz, short QustionsNumber)
{
    cout << "\n\033[36m----------------------------\033[0m\n";
    cout << "Question [" << QustionsNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";
    cout << "\033[36m----------------------------\033[0m\n";
    cout << "  " << Quizz.QuestionsList[QustionsNumber].Number1 << "\n";
    cout << "  " << Quizz.QuestionsList[QustionsNumber].Number2 << "  " << GetOperationTypeSymbol(Quizz.QuestionsList[QustionsNumber].OperationType) << "\n";
    cout << "-----------\n";
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cout << "Result: ";
    cin >> Answer;
    return Answer;
}

void SetScreenColor(bool isRight)
{
    if (isRight)
        cout << "\033[32m"; // Green
    else
    {
        cout << "\033[31m";
        cout << "\a";
    } // Red + Beep
}

void CorrectTheQuestionAnswer(stQuizz &Quizz, short QustionsNumber)
{
    if (Quizz.QuestionsList[QustionsNumber].PlayerAnswer != Quizz.QuestionsList[QustionsNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = false;
        Quizz.NumberOfWorngAnswer++;
        SetScreenColor(false);
        cout << "[-] Wrong Answer! :( \n";
        cout << "[*] The Right Answer is: " << Quizz.QuestionsList[QustionsNumber].CorrectAnswer << "\n";
    }
    else
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswer++;
        SetScreenColor(true);
        cout << "[+] Correct Answer! :) \n";
    }
    cout << "\033[0m"; // Reset Color
}

void AskAndCorrectQuestionsListAnswer(stQuizz &Quizz)
{
    for (short Q = 0; Q < Quizz.NumberOfQuestions; Q++)
    {
        PrintTheQestions(Quizz, Q);
        Quizz.QuestionsList[Q].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Q);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswer >= (Quizz.NumberOfQuestions / 2.0));
}

string GetFinalResultText(bool Pass)
{
    return Pass ? "P A S S" : "F A I L";
}

string GetQustionsLevelText(enQuizzLevel QuestionLevel)
{
    string arr[] = {"Easy", "Med", "Hard", "Mix"};
    return arr[QuestionLevel - 1];
}

void PrintQuizzReults(stQuizz Quizz)
{
    cout << "Questions Total    : " << Quizz.NumberOfQuestions << "\n";
    cout << "Questions Level    : " << GetQustionsLevelText(Quizz.QustionsLevel) << "\n";
    cout << "Operation Type     : " << GetOperationTypeSymbol(Quizz.OperationType) << "\n";
    cout << "Right Answers      : \033[32m" << Quizz.NumberOfRightAnswer << "\033[0m\n";
    cout << "Wrong Answers      : \033[31m" << Quizz.NumberOfWorngAnswer << "\033[0m\n";
    cout << "--------------------------------------------------\n";
}

void DrawHeader(string Title)
{
    cout << "\n\033[36m==================================================\n";
    cout << "\t\t" << Title << "\n";
    cout << "==================================================\033[0m\n";
}

void ShowFinalQuizzScreen(stQuizz Quizz)
{
    ClearScreen();
    string Result = GetFinalResultText(Quizz.isPass);

    if (Quizz.isPass)
        cout << "\033[32m";
    else
        cout << "\033[31m";
    DrawHeader("FINAL RESULTS: " + Result);

    PrintQuizzReults(Quizz);
    cout << "\033[0m";
}

void ClearScreen()
{
    system("clear");
    cout << "\033[0m";
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadQuestionNumber();
    Quizz.QustionsLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GeneratQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswer(Quizz);
    ShowFinalQuizzScreen(Quizz);
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ClearScreen();
        PlayMathGame();
        cout << "\n\033[33m[?]\033[0m Do You Want To Play Again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}