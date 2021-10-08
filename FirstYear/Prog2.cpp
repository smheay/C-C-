//SHANNON MEYER
// CS 162
//This program will take in letters and output words to the user. 
//The word might not be real. The word will be a consonant and then a 
//vowel. "Th" doesn't have to follow a vowel and "Q" will always have 
// to have a "U", and "ED" when entered together will always be at the end.


#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// PROTOTYPES DECLARATION
void welcome(); 
void getLetter(char letter[]);
void split(char letter[], char cons[], char vowels[]);
void sizeSixWord(char con[], char vowels[], char six[]);
void sizeFourWord(char con[], char vowels[], char four[]);
void sizeThreeWord(char con[], char vowels[], char three[]);
void rulesTH(char argIn[]);
void rulesED(char argIn[]);
void rulesQU(char argIn[]);
void rulesAll(char argIn[]);
void mixArray(char argIn[]);

int main()
{
  const int SIZE = 20; // Note to change getLetter size as well to increase letters
  char letters[SIZE], cons[SIZE], vowels[SIZE], sixWord[7], fourWord[5], threeWord[4];
  char exitProgram;

  
  welcome();
do{
  getLetter(letters);
  
  split(letters, cons, vowels);
   
  sizeSixWord(cons, vowels, sixWord);
    mixArray(cons);
    mixArray(vowels);
  sizeSixWord(cons, vowels, sixWord);
  
  sizeFourWord(cons, vowels, fourWord);
    mixArray(cons);
    mixArray(vowels);
  sizeFourWord(cons, vowels, fourWord);
  
  sizeThreeWord(cons, vowels, threeWord);
    mixArray(cons);
    mixArray(vowels);
  sizeThreeWord(cons, vowels, threeWord);
  
  cout << "\nWould you like to enter in another set of letters? 'Y'= Yes 'N' = No " << endl;
  cin >> exitProgram;
  cin.ignore(100, '\n');
  
}while(toupper(exitProgram) == 'Y');
   
return 0; 
}
// *********************************************************************************************************
//This array will mix up consonants and vowels to try a second word so 
//its not the same.
void mixArray(char argIn[])
{
  int temp = strlen(argIn), count = temp-1, i = 0;
  char temp2;
  
  
  if(temp>1){
      temp2 = argIn[i];
      argIn[i] = argIn[count];
      argIn[count] = temp2;
  }

}   
//This function wil kill the bad words. This will apply the vowel and consonants cannot appear in a row and needs to 
// apply the already made rules. 
void rulesAll(char argIn[])
{
  int temp = strlen(argIn), qval, count = 1, hCheck = 2;
  char temp2;
  
  for(int i = 0 ; i < temp ; ++i){      // two vowels can never be together searches for two together
    if(argIn[i] == 'a' || argIn[i] == 'e' || argIn[i] == 'i' ||argIn[i] == 'o' ||argIn[i] == 'u'){
      qval = count;
      if(argIn[qval] == 'a' || argIn[qval] == 'e' || argIn[qval] == 'i' || argIn[qval] == 'o' || argIn[qval] == 'u'){
        argIn[0]= '\0';
        return;
      }
    }
  ++count;
  }

  count = 1;
  
  for(int i = 0 ; i < temp-1 ; ++i)// search for two consonants together
  {  
    if(argIn[i] != 'a' && argIn[i] != 'e' && argIn[i] != 'i' && argIn[i] != 'o' && argIn[i] != 'u')
	{
	    qval = count;
      hCheck = i + hCheck;     //need to make the "th" exception if it is first 
	  if(argIn[i] == 't' && argIn[qval] == 'h')
        ++i;
    else
	    if(argIn[i] != 'a' && argIn[i] != 'e' && argIn[i] != 'i' && argIn[i] != 'o' && argIn[i] != 'u' && argIn[qval] == 't' && argIn[hCheck] == 'h')
		    i = i + 2;
        else   //return blank if there is a double consonant
          if(argIn[count] != 'a' && argIn[count] != 'e' && argIn[count] != 'i' && argIn[count] != 'o' && argIn[count] != 'u')
		      {
            argIn[0]= '\0';
            return;
          }
	}
  ++count;
  }
  
}

//This function will apply the QU together rule 
void rulesQU(char argIn[])
{
  int temp = strlen(argIn), qval, uval, count;
  char temp2;
  bool true1 = false, true2 = false;
  
  for(int i = 0 ; i <temp ; ++i){    // find if q and u are elements of the array
    if(argIn[i] == 'q'){
      true1 = true;
      qval = i ;}
    if(argIn[i] == 'u'){
      true2 = true;
      uval = i; }
  }
  
  if(true1 == true && true2 == true){  // decided to make q the first letter always
    count = qval-1;
    for(int i = qval; i>0; --i){
      temp2 = argIn[i];
      argIn[i] = argIn[count];
      argIn[count] = temp2;
      --count;
    }
        
    for(int i = 0 ; i <temp ; ++i){   //incase u moved
      if(argIn[i] == 'u')
        uval = i ;
    }
    
    count = uval-1;                      // move the u to the q
    for(int i = uval; i>1; --i){
      temp2 = argIn[i];
      argIn[i] = argIn[count];
      argIn[count] = temp2;
      --count;
    }
  }  
  if (true1 == true && true2 == false)   // if there is a q and no u return empty
    argIn[0]='\0';
}


//This function will apply the ED together END rule ***************************************************************
void rulesED(char argIn[])
{
  int temp = strlen(argIn), eval, dval, count;
  char temp2;
  bool true1 = false, true2 = false;
  
  for(int i = 0 ; i <temp ; ++i){   // finding if the array contains both and finding locations
    if(argIn[i] == 'e'){
      true1 = true;
      eval = i ;}
    if(argIn[i] == 'd'){
      true2 = true;
      dval = i;
    }
  }
  
  if(true1 == true && true2 == true)
  {
      count = dval+1;
      for(int i = dval; i < temp-1; ++i){  //move the d to the end
        temp2 = argIn[i];
        argIn[i] = argIn[count];
        argIn[count] = temp2;
        ++count;}
       
      for(int i = 0 ; i <temp ; ++i){   //incase E moved
        if(argIn[i] == 'e')
          eval = i ;}
          
      count = eval +1;
      
      for(int i = eval; i < temp-2; ++i){  //move the e before the d
        temp2 = argIn[i];
        argIn[i] = argIn[count];
        argIn[count] = temp2;
        ++count;}
  }
}

//This function will apply the TH together rule *****************************************************************
void rulesTH(char argIn[])
{
  int temp = strlen(argIn), tval, hval, count = 1;
  char temp2;
  bool true1 = false, true2 = false;
  
  for(int i = 0 ; i <temp ; ++i){ // finding if the array contains both and finding locations
    if(argIn[i] == 't'){
      true1 = true;
      tval = i ;}
    if(argIn[i] == 'h'){
      true2 = true;
      hval = i; }
  }
  
  if(true1 == true && true2 == true)
    if(tval<hval){
      count = tval+1;
      for(int i = tval; i < hval-1; ++i)
       {
        temp2 = argIn[i];
        argIn[i] = argIn[count];        // swapping elements moves the tval to the hval
        argIn[count] = temp2;
        ++count;}
    }
    else{
      count = hval+1;                   //if the h val is entered first fix error not moving
      for(int i = hval; i < tval; ++i)
       {
        temp2 = argIn[i];
        argIn[i] = argIn[count];       // swapping elements moves the hval infront of the T
        argIn[count] = temp2;
        ++count;}
    }
}
//This function is to get a size 4 word.**************************************************************************
void sizeThreeWord(char con[], char vowels[], char three[])
{
  int temp, conCount = 0, vowCount = 0, count = 0;                  // All the word size repeat code 
                                                                    // will just explain one
  for(int i = 3; i>0 ; --i){            // loop to take vowels and consonants to make a word
    if(count%2 == 0){                   // odd and evens starting consonants first
      three[count] = con[conCount];     // take the remainder of the count 
      ++conCount;
    }
    else{
      three[count] = vowels[vowCount];
      ++vowCount;
    }
    ++count;
  three[count] = '\0';                 // end the array with the null
  }
  
  rulesQU(three);    // apply the rules
  rulesED(three);
  rulesTH(three);
  rulesAll(three);
  
  
  
  temp = strlen(three);    // output the word 
  
  if(temp < 3)
    cout << "\nERROR - Could not make a word of size 3." << endl;
  else
    cout << "\nA possible word is = " << three << endl;
}
//This function is to get a size 4 word.**************************************************************************
void sizeFourWord(char con[], char vowels[], char four[])
{
  int temp, conCount = 0, vowCount = 0, count = 0;
  
  for(int i = 4; i>0 ; --i){
    if(count%2 == 0){
      four[count] = con[conCount];
      ++conCount;
    }
    else{
      four[count] = vowels[vowCount];
      ++vowCount;
    }
    ++count;
  four[count] = '\0';
  }
  
  rulesQU(four);
  rulesED(four);
  rulesTH(four);
  rulesAll(four);
  
  
  
  temp = strlen(four);
  
  if(temp < 4)
    cout << "\nERROR - Could not make a word of size 4." << endl;
  else
    cout << "\nA possible word is = " << four << endl;

    
}

//This function is to get a size 5-6 word.**************************************************************************
void sizeSixWord(char con[], char vowels[], char six[])
{
  int temp, conCount = 0, vowCount = 0, count = 0;
  
  
  for(int i = 6; i>0 ; --i){
    if(count%2 == 0){
      six[count] = con[conCount];
      ++conCount;
    }
    else{
      six[count] = vowels[vowCount];
      ++vowCount;
    }
    ++count;
   
  }
  six[count] = '\0';
  
  rulesQU(six);
  rulesED(six);
  cout << "\nBEFORE RULE = " << six << endl;
  rulesTH(six);
  cout << "\nAFTER RULE = " << six << endl;
  rulesAll(six);
  
  
  temp = strlen(six);
  
  if(temp < 5)
    cout << "\nERROR - Could not make a word of size 5-6." << endl;
  else
    cout << "\nA possible word is = " << six << endl;

    
}
//This is to split into two arrays consonants and vowels************************************************************
void split(char letter[], char cons[], char vowels[])
{
  int temp= strlen(letter), vowcount = 0, concount = 0;
  
  for(int i = 0; i < temp; ++i) {
    if (letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'i' || letter[i] == 'o' || letter[i] == 'u') {
      vowels[vowcount] = (letter[i]);
      ++vowcount;}    
    else {
      cons[concount] = (letter[i]);
      ++concount;}
  }
  

  cons[concount]= '\0';
  vowels[vowcount] = '\0';
}

//This is to get letters from the user*****************************************************************************
void getLetter(char letter[])
{
  const int SIZE = 7;
  int lower;
  char temp;
  
  
  do{
    cout << "\nEnter in the letters to make 'word' combinations. Do not use spaces between the letters. \n" << endl;
    cin.width(SIZE);
    cin >> letter;
    cin.ignore(100, '\n');
    cout << "\nYou have entered in \"" << letter << "\". Is this correct? 'Y'= Yes 'N' = No \t";
    cin >> temp;
    cin.ignore(100, '\n');
   }while(toupper(temp) != 'Y');
   
   lower = strlen(letter);
   
   for(int i = 0; i <lower ; ++i){
     letter[i] = tolower(letter[i]);
   }

}

//Tell the user what the program is and what is does.**************************************************************
void welcome()
{
  cout << "\n\tWelcome to Scrabble Help. This program will take the letters inputted " 
       << "\nfrom the user and output random combinations of those letters. Two words of "
       << "\neach size (6-5, 4, and 3) will be outputted. If two words cannot be formed an error"
       << "\nwill display." << endl;
  cout << endl;
}





