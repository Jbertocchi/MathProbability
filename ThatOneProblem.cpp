//include files
#include <iostream>
#include <random>
#include <ctime>

using namespace std;


//function declarations/////////////////////////////////////////////////////////////////////////////////////////
int randomNum();
void intro();
void randomTester();
bool simulator(int input);
void results (int correct, int runs);


//main function/////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
   srand(time(NULL)); //sets the seed for the random function to the time of the clock
   //randomTester();  //this line is used to check that the random generator works


   intro();

}



//functions/////////////////////////////////////////////////////////////////////////////////////////////////////
int randomNum()
{
   int output = rand() % 4 + 1; //gives a number 1-4
   return output;
}


void intro()
{

   int correctNum = 0;
   int runs = 0;
   int answer = 0;

   cout << " Welcome, please enter the number of times to run: ";
   cin >> runs;
   cout << endl;

   while (runs < 10000)
   {
      cout << endl << " Number too low, please try again: ";
      cin >> runs;
      cout << endl;
   }

   while (runs > 2100000000)
   {
      cout << endl << " Number too high, please try again: ";
      cin >> runs;
      cout << endl;
   }

   cout << endl << " Please enter a correct answer (1-4): ";
   cin >> answer;
   cout << endl;

   while (answer < 1 || answer > 4)
   {
      cout << endl << " Please try again: ";
      cin >> answer;
      cout << endl;
   }


   for (int i = 0; i < runs; i++)
   {
      if (simulator(answer))
      {
         correctNum++;
      }
   }

   results(correctNum, runs);

}


bool simulator(int input)
{
   int random = randomNum();
   int temp = random;

   if (random == input)
   {
      return true;
   }

   else
   {
      while (temp == random)
      {
         random = randomNum();
      }

      if (random == input)
      {
         return true;
      }
   }

   return false;
}


void randomTester()
{
   int test = 0;
   int testCount1 = 0;
   int testCount2 = 0;
   int testCount3 = 0;
   int testCount4 = 0;

   for (int i = 0; i < 10000; i++)
   {
      test = randomNum();

      if (test == 1)
      {
         testCount1++;
      }
      if (test == 2)
      {
         testCount2++;
      }
      if (test == 3)
      {
         testCount3++;
      }
      if (test == 4)
      {
         testCount4++;
      }
   }
   cout << "A Results: " <<testCount1 <<endl
        << "B Results: " <<testCount2 <<endl
        << "C Results: " <<testCount3 <<endl
        << "D Results: " <<testCount4 <<endl;
}

void results (int correct, int runs)
{
   double temp = (float) correct / (float) runs;
   temp = temp * 100;


   cout << endl << endl
        << " RESULTS: " << endl
        << " The program ran " << runs << " simulations, with " << correct << " correct guesses." << endl
        << " This is closest to " << temp << " percent accuracy. Thanks for playing!" << endl;
}








