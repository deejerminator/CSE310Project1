#include <iostream>
#include <string>

using namespace std;

/*
 * in this shift function. we store the element in [0] to temp.
 * when we shift all chars the left once, the element originally
 * in [0] falls off, and the last element becomes empty.
 * once the shifting is complete, we add the element stored in temp
 * back to the end element.
 * */
void shift(string &s, int n){
    char temp = s[0];
    for (int i = 0; i < s.size()-1; i++){
        s[i] = s[i+1];
    }
    s[n-1] = temp;
}

/*
* This is my insertion sort
* each element is swapped everytime sentence[j] > sentence[i].
* i saved the string stored in sentence[i] to populate the next element if swapping was needed.
* temp is declared before while loop
* */
void insertionSort(string s[], int n) {
    string *pointer = s;
    string temp;
    for (int i = 1; i < n; i++) {
        temp = *(pointer + i);
        int j = i - 1;
        while (j >= 0 && s[j].compare(temp) > 0) {
            *(pointer + j + 1) = *(pointer + j);
            j = j - 1;
        }
        *(pointer + j + 1) = temp;
    }
}

int partition (string array[], int left, int right){
    string pivot = array[right];
    string temp;
    int i = left-1;
    for (int j = left; j < right; j++){
        if(array[j].compare(pivot) <= 0){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[right];
    array[right] = temp;

    return i+1;
}

void quickSort(string s[], int left, int right){
    if(left < right){
        int partitionIndex = partition(s, left, right);
        quickSort(s, left, partitionIndex-1);
        quickSort(s, partitionIndex+1, right);
    }
}

int main(int argc, char* argv[]) {

    string textFileInputInsertion;
    string textFileInputQuick;

    if(argc == 1){cout << "please enter ./run argument\n" << "[argument: insertion, quick]\n"; return 0;}

// if argument = insertion
    if(string(argv[1]) == "insertion" && argc == 2){
        /*
         * we use while loop for get line, so everytime there is a new line, it will loop through the program.
         * the loop will terminate when it reaches the last delimiter
        */
        while(getline(cin, textFileInputInsertion)) {

            int sentenceSize = textFileInputInsertion.length();
            string sentence[sentenceSize];

            /*
             * populate the array sentence[i++] with each left cyclic shift
             * the population will stop when sentenceSize is reached,
             * which will be 1 shift before getting original sentence
             * everytime we loop, the newly shifted string will be in sentence[i+1]
             * */
            for (int i = 0; i < sentenceSize; i++) {
                sentence[i] = textFileInputInsertion;
                shift(textFileInputInsertion, sentenceSize);
            }

            // calls insertionSort
            insertionSort(sentence, sentenceSize);

            /*
             * This is to create last string of all chars at the end of the array list sentence[i]
             * I used sentence[i][sentenceSize - 1] because this is the end element of each i, from 0 to sentenceSize
             * */
            string lastString[sentenceSize];
            for (int i = 0; i < sentenceSize; i++) { lastString[i] = sentence[i][sentenceSize - 1];}

            /*
             * This is my for loop that detects and outputs which element
             * of sentence[i] has the original string.
             * It is just a simple for loop and if statement, if all chars of
             *  string from sentence[i] is the same as
             * textFileInput, we will output the virtual element number i.
             * Will try to create a function originalStringLocation(arg 1, arg2)
             * added the break function so when the index is found, we exit the for loop
             * */
            for (int i = 0; i < sentenceSize; i++) {
                if (sentence[i] == textFileInputInsertion) {
                    cout << i << endl;
                    break;
                }
            }

            /*
             * This function was a bit confusing to make, but hopefully I can clear things up.
             * In the for loop, i starts at 0. we want to compare element i to element i+1
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
             * we will know when the last element was the same letter, and proceed to count from the next letter after.
             * in the case we dont enter the while loop, our count will always be 1 because of the letter being read
             * at least once.
                */
            for (int i = 0; i < sentenceSize; i++) {
                int count = 1;
                while (lastString[i + 1] == lastString[i]) {
                    count++;
                    i++;
                }
                cout << count << " " << lastString[i] << " ";
            }
            cout << endl;
        }
    }
        // if argument = quick
    else if(string(argv[1]) == "quick"){
        while(getline(cin, textFileInputQuick)){
            int sentenceSize = textFileInputQuick.length();
            string sentence[sentenceSize];

            for (int i = 0; i < sentenceSize; i++) {
                sentence[i] = textFileInputQuick;
                shift(textFileInputQuick, sentenceSize);
            }

            // call quickSort
            quickSort(sentence, 0, sentenceSize-1);

            // copy and paste from insertion
            string lastString[sentenceSize];
            for (int i = 0; i < sentenceSize; i++) { lastString[i] = sentence[i][sentenceSize - 1];}

            for (int i = 0; i < sentenceSize; i++) {
                if (sentence[i] == textFileInputQuick) { cout << i << endl; break;}
            }

            for (int i = 0; i < sentenceSize; i++) {
                int count = 1;
                while (lastString[i + 1] == lastString[i]) {count++; i++; }
                cout << count << " " << lastString[i] << " ";
            }
            cout << endl;
        }
    }
        // all other arguments
    else {cout << "PLEASE USE ./run argument < input.txt > output.txt \n" << "[arguments: insertion, quick]\n"; return 0;}

    return 0;
}
