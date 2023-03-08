#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;
string choice; //menu input
string input;  //input to translation
string error_continue;
string letter;

bool status = true; 

const map<char,string>Char_Morse={
   {'a', ".-"},{'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
   {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"},
   {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"},
   {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
   {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"},{'z', "--.."},
   {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
   {' ', " "}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'!', "-.-.--"}, {'/', "-..-."}, {'@', ".--.-."},
};
const map<string,char>Morse_Char={
   {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},
   {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
   {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},
   {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
   {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'},
   {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
   {"", ' '}, {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {"-.-.--", '!'}, {"-..-.", '/'}, {".--.-.", '@'},
};
void MainMenu(){
  cout << "Morse code translator\nSelect mode\n1 - DECODE - Morse to Char\n2 - CODE - Char to Morse\nelse - exit program\nYour option: ";
  cin >> choice;
}
void CharMorse(){
  try {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input stream
        cout << "The maximum size of the text is 65,535 characters\nOnly use english alphabet\nYour text: ";
        getline(cin, input);
        cout << "Translation\n";
        for(char x : input) {
          x = tolower(x);     
          cout << Char_Morse.at(x);
          cout << " ";
        }
        status = false;
  } 
  catch (std::out_of_range& e) {
    cout << "Invalid character\nTry again :)?\ny/N\n";
    cin >> error_continue;
    if (error_continue != "y"){
      status = false;
      }
        
  }
}

void MorseChar(){
  try {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input stream
    cout << "The maximum size of the text is 65,535 characters\nCode is in .- format separated by spaces\nYour code: ";
    getline(cin, input);
    cout << "Translation\n";
    for (int i = 0; i < input.length(); i++) {
      if (input[i] == ' ') {
        cout << Morse_Char.at(letter);
        letter = "";
      }
      else {
        letter += input[i];
      }
    }
    cout << Morse_Char.at(letter);
    status = false;
  }
  catch (std::out_of_range& e) {
    cout << "Invalid format of code\nTry again :)?\ny/N\n";
    cin >> error_continue;
    if (error_continue != "y"){
      status = false;
      }
        
  }
}


int main(){
  MainMenu();
  while (status) {
    if (choice == "1") {
      MorseChar();
      } 
    else if (choice == "2") {
      CharMorse();
      } 
    else {
      cout << "Application is closing\n";
      status = false;
      }
  }
  return 0;
}
