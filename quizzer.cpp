// Quizzing program by Tanner Winkelman

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const char QUESTIONS_FILE_NAME[] = "questions.txt";
const char QUESTION_ANSWER_SEPARATOR = ',';
const char QUESTION_SEPARATOR = '\n';

const short MAX_QUESTION_LENGTH = 300;
const short MAX_ANSWER_LENGTH = 300;
const short MAX_NUM_QUESTIONS = 300;


int main()
{
  char questions[MAX_NUM_QUESTIONS][MAX_QUESTION_LENGTH];
  char answers[MAX_NUM_QUESTIONS][MAX_ANSWER_LENGTH];
  short counter = 0;
  
  short question_choice;
  
  short char_index;

  char user_answer[MAX_ANSWER_LENGTH];
  
  ifstream fin;
  fin.open( QUESTIONS_FILE_NAME );
  
  
  srand(time(NULL));
  
  
  while(fin.getline( questions[counter], MAX_QUESTION_LENGTH-1, 
    QUESTION_SEPARATOR ))
  {
    char_index = strlen(questions[counter]) - 1;
    while( char_index >= 0 && questions[counter][char_index] != ',') {
      char_index--;
    }
    for( short k = char_index + 1; k < strlen(questions[counter]); k++ ) {
      answers[counter][k - char_index - 1] = questions[counter][k];
      answers[counter][k - char_index] = '\0';
    }
    questions[counter][char_index] = '\0';
    counter++;
  }
  
  fin.close();
  
  cout << endl << "Press CTRL+C to quit at any time" << endl << endl;
  
  while ( counter > 0 )
  {
    question_choice = rand() % counter;
  
    cout << endl << questions[question_choice] << " ";
    cin.getline( user_answer, MAX_ANSWER_LENGTH, '\n' );
    
    if ( strcmp( user_answer, answers[question_choice] ) )
    {
      cout << endl << "WRONG!!!!!!!!!!!!!!!!!!!!!!!!" << endl 
        << "It was " << answers[question_choice] << endl;
      strcpy( questions[counter], questions[question_choice] );
      strcpy( answers[counter], answers[question_choice] );
      counter++;
    }
    else
    {
      cout << endl << "Correct" << endl;
      counter--;
      strcpy( questions[question_choice], questions[counter] );
      strcpy( answers[question_choice], answers[counter] );
    }  
  }
  
  
  cout << endl << "You Win!!!!" << endl;
  
  return 0;
}
