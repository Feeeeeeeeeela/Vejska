#include <iostream>
#include <string>
#include <map>

using namespace std;
string input;  //input to translation
string letter; 

bool status = true; //application is running

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
void CharMorse(){ //char to morse
  try {
        cout << "Code\n";
        for(char x : input) {
          x = tolower(x);     
          cout << Char_Morse.at(x);
          cout << " ";
        }
        status = false;
  } 
  catch (std::out_of_range& e) {
        cout << "Invalid character";
        status = false;
  }
    
  
}

void MorseChar(){
  try {
    cout << "Decode\n";
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
    cout << "Invalid format of code";
    status = false;
  }
}


int main(){
  
  cout << "Morse code translator\nSelect mode by writing c/d + space before your text\nc/C - for code\nd/D - for decode\nMorse is in .- format\nYour text:\n";
  while (status) {
    /*cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input stream*/
    getline(cin, input);
    if (tolower(input[0]) == 'd') {
      input.erase(0,1);
      input.erase(0,1);
      MorseChar();
      } 
    else if (tolower(input[0]) == 'c') {
      input.erase(0,1);
      input.erase(0,1);
      CharMorse();
      } 
    else {
      cout << "invalid mode\nClosing application";
      status = false;
      }
  }
  return 0;
}
