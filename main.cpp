#include <iostream>
#include <string>

using namespace std;


void shift(string &s, int n){
    char temp = s[0];
    for (int i = 0; i < s.size()-1; i++){
        s[i] = s[i+1];
    }
    s[n-1] = temp;
}



int main(int argc, char* argv[]) {
    string textFileInput;

    if(argc == 1){cout << "please enter ./run argument\n" << "[arguments: insertion, quick]\n"; return 0;}

// if argument = insertion
    if(string(argv[1]) == "insertion" && argc == 2){
        while(getline(cin, textFileInput)) {

            int sentenceSize = textFileInput.length();
            string sentence[sentenceSize];

            /*
             * populate the array sentence[i++] with each left cyclic shift
             * the population will stop when sentenceSize is reached,
             * which will be 1 shift before getting original sentence
             * */
            for (int i = 0; i < sentenceSize; i++) {
                sentence[i] = textFileInput;
                shift(textFileInput, sentenceSize);
            }

            /*
             * This is my insertion sort
             * each element is swapped everytime sentence[j] > sentence[i].
             * i saved the string stored in sentence[i] to populate the next element if swapping was needed.
             * temp is declared before while loop, but i will eventually save this part as a function.
             * insertionsort(Arg A, Arg B)
             * */
            string temp;
            for (int i = 1; i < sentenceSize; i++) {
                temp = sentence[i];
                int j = i - 1;
                while (j >= 0 && sentence[j].compare(temp) > 0) {
                    sentence[j + 1] = sentence[j];
                    j = j - 1;
                }
                sentence[j + 1] = temp;
            }
            /*
             * This is my for loop that detects and outputs which element
             * of sentence[i] has the original string.
             * It is just a simple for loop and if statement, if all chars of
             *  string from sentence[i] is the same as
             * textFileInput, we will output the virtual element number i.
             * Will try to create a function originalStringLocation(arg 1, arg2)
             * */
            for (int i = 0; i < sentenceSize; i++) {
                if (sentence[i] == textFileInput) {
                    cout << i << endl;
                }
            }
            /*
             * This is to create last string of all chars at the end of the array list sentence[i]
             * I used sentence[i][sentenceSize - 1] because this is the end element of each i, from 0 to sentenceSize
             *
             * */
            string lastString[sentenceSize];
            for (int i = 0; i < sentenceSize; i++) {
                lastString[i] = sentence[i][sentenceSize - 1];
            }
            /*
             * This function was a bit confusing to make, but hopefully I can clear things up.
             * the for loop i, starts at 0. we want to compare element 0 to element 1
             * we initialize count back to 1 for the arithmetic in the while loop.
             * we only reach the while loop if the comparison of i+1 and i are the same.
             * if they are the same, we will i++ and count++ to count how many elements have the same characters
             * after that count is done(while loop exits) we will output the count and the letter that was counted
             * the reason i++ is in the while loop, is because we dont want repeats of counting the same letter.
             * For example:
             * X X X X X <- there are 5 X's
             * if i++ was OUTSIDE of while loop (and inside for loop)
             * our output would be:
             * 5X 4X 3X 2X 1X
             * since we are incrementing by 1 in the for loop, we will always count from the next iteration
             * no matter if we counted it before.
             *
             * if i++ was INSIDE of while loop
             * out output would be:
             * 5X
             * since we are incrementing by 1 each time in the while loop, by the time we exit the while loop,
             * we will know when the last element was the same letter, and proceed to count the next elements after.
             * in the case we dont enter the while loop, our count will always be 1 because of the letter being read
             * at least once.
                */
            int clusters = 1;
            for (int i = 0; i < sentenceSize; i++) {
                int count = 1;
                while (lastString[i + 1] == lastString[i]) {
                    count++;
                    i++;
                }
                cout << count << lastString[i] << " ";
                clusters++;
            }

            cout << endl;
            /*
            cout << "t-c/t * 100%" << endl;
            cout << "c = " << clusters << endl;
            cout << "t = " << sentenceSize + 1 << endl;
            int ratio;
            ratio = (sentenceSize - (clusters/sentenceSize+1))/100;
            cout << "ratio = " << ratio << endl;
            cout << endl;
             */
        }
    }
    // if argument = quick
    else if(string(argv[1]) == "quick"){cout << "this area is under construction\n" << endl; return 0;}
    // all other arguments
    else {cout << "PLEASE USE ./run argument\n" << "[arguments: insertion, quick]\n"; return 0;}

    return 0;
}
// this is a test to see if gitlab updates 