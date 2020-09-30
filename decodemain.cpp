#include <iostream>
#include <string>
using namespace std;

/*
 *              The Decoding Algorithm
 *
 * There are three steps in the recovery:
 *
 * 1. Read the integer giving the index of the row in which the original string appears in the Sorted column
 * 2. Recover the string: last
 * 3. using the index, last, and knowledge of the next column, recover the original string.
 *
 * */

/*
 * this is partition function, copy and pasted from encode main.cpp.
 * the partition function is needed to help quickSort become recursive by using a pivot to help divide the array
 * as a divide and conquer algorithm.
 */
int partition (char array[], int left, int right){
    char pivot = array[right];
    char temp;
    int i = left-1;
    for (int j = left; j < right; j++){
        if(array[j]< pivot){
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
/*
 * quickSort is a divide and conquer algorithm. It solves the divided arrays recursively
 * also copy and pasted from encode main.cpp
 * */
void quickSort(char s[], int left, int right){
    if(left < right){
        int partitionIndex = partition(s, left, right);
        quickSort(s, left, partitionIndex-1);
        quickSort(s, partitionIndex+1, right);
    }
}
/*
 * insertionSort is a linear algorithm.
 * also copy and pasted from encode main.cpp
 * */
void insertionSort(char A[], int n){
    char temp;
    char *pointer = A;
    for (int i = 1; i < n; i++) {
        temp = A[i]; // *(pointer + i)
        int j = i - 1;
        while (j >= 0 && A[j] > temp) { //A[j] > temp
            /* A[j + 1] = A[j]; */ *(pointer + j + 1) = *(pointer + j);
            j = j - 1;
        }
        /* A[j + 1] = temp; */ *(pointer + j + 1) = temp;
    }
}



int main(int argc, char* argv[]) {
    string textFileInput;
    int index = 0;
    // if user did not specify argument, have them retry
    if(argc == 1){cout << "please enter ./run argument\n" << "[argument: insertion, quick]\n"; return 0;}
    // if user chose insertion
    if(string(argv[1]) == "insertion" && argc == 2){
        while (getline(cin, textFileInput)) {
            /*
             * if the string read from .txt contains nothing, it will output a new line.
             * "continue;" brings the program back to the start of the while loop
             */
            if (textFileInput[0] == '\0') {cout << endl; continue; }
                /*
                 * This if statement checks if there is a space(the character: ' ') in the second element.
                 * This is because as we are reading the encoded info, index will have any size number, and encoded lines
                 * typically have a space after a number.
                 * for example:
                 * encoded lines can be 1 a 2 b 3 c.
                 * this if statement checks if there's a space(' ') between '1' and 'a'
                 * this helps determine if the line is an encoded line or an index.
                 * index can be any number, whether its '9' or '100' or in the case of a string array. '100' is '1''0''0'
                 * this if statement becomes true when we know for sure there is no ' ', which means the current line
                 * is not an encoded string, but an index.
                 * we use the stoi() function to convert the string into an integer since we have determined the current
                 * line is an index, and not an encoded string.
                 * continue; goes back to the beginning of the while loop, with our newfound index.
                 *
                 * */
            else if (isdigit(textFileInput[0]) == true && textFileInput[1] != ' ') {
                index = stoi(textFileInput);
                continue;
            }


            /*
             * this current for loop counts the number of characters by adding all cluster sizes together.
             * Since we know the encoding scheme follows "1 a 2 b 3 c" then we know that every cluster number is
             * three positions away from each other. This helps iterate the for loop fewer times.
             * The reason for this for loop is to create a totalCharacters variable so we can initialize
             * last[], first[], and next[] with the amount of characters needed to decode the encoded string.
             * */
            int totalCharacters = 0;
            int nextNumberofChar;
            for (int i = 0; i < textFileInput.length(); i++) {
                nextNumberofChar = textFileInput[i] - '0';
                totalCharacters = totalCharacters + nextNumberofChar;
                i = i + 3;
            }
            /*
             * this for loop is similar to the previous one. (above) we now have our last[] initialized with
             * the correct amount of elements for each different line.
             * we follow the same process as the above element, but we also populate the last array with the encoded
             * string decompressed. I introduced the remember variable to remember where we last left
             * off in the last[] before the for loop iterates.
            */
            char last[totalCharacters];
            int currentAmount;
            char letter;
            int remember = 0;
            for (int i = 0; i < textFileInput.length(); i++) {
                currentAmount = textFileInput[i] - '0';
                letter = textFileInput[i + 2];
                for (int j = i; j < i + currentAmount; j++) {
                    last[remember] = letter;
                    remember++;
                }
                i = i + 3;
            }
            /*
             * at this point we have created and saved last[]
             * next, we need to sort the array and save it into another, call it first.
             * I will first initialize first[] and populate it with the same elements and positions as last[]
             * I did this becauase we are going to use last[] as it currently is in the decoding section.
             * any changes to last[] will result in errors for the decode section.
             * once we have the array copied from last[] to first[], we will sort first[]
             * in this case we use insertion sort, but we also have the quick sort option.
             * */
            char first[totalCharacters];
            for (int i = 0; i < totalCharacters; i++) { first[i] = last[i]; }

            insertionSort(first, totalCharacters);
            // first[] is now a sorted version of last[]
            /*
             * This is where the decoding starts.
             * We now have last[] which is the encoded string decompressed.
             * We also now have first[] which is the sorted version of last[]
             * the outer loop is to iterate through first[].
             * each time we have an element of first[i], we go into the inner loop to search through last[]
             * once we find the first element in last[j] that matches first[i], we save the element location of last[j]
             * into next[]
             * as we save it into next, I make the found location in last[j] = '\0'. This helps make sure that we don't
             * use the same element from last[] twice or more. This also helps make sure that I keep last[] to reuse
             * later.
             * I introducted the nextRemember variable to remember which element location we left off.
             * */
            int next[totalCharacters];
            int nextRemember = 0;
            for (int i = 0; i < totalCharacters; i++) {
                //char temp = first[i];
                for (int j = 0; j < totalCharacters; j++) {
                    if (last[j] == first[i]) {
                        next[nextRemember] = j;
                        nextRemember++;
                        last[j] = '\0';
                        break;
                    }
                }
            }
            /*
             * I make last[0] = first[index].
             * The index is an indicator of where to start putting together the string.
             * once we have the first element being the start of the string we start the for loop.
             * I also made the variable pos = next[index] because this is our initial position.
             * The for loop starts at 1, because we already made last[0] = first[index]
             * last[] is the array that is going to be reused and populated with the new string.
             * the number saved in next[] is used as the element location of first[].
             * the character saved in the element location of first[] is then copied into last[i]
             * for example, pos = next[0]. next[0] has the element 4. so pos = 4.
             * last[i] = first[4]. last[i] becomes the character saved in element 4.
             * */
            last[0] = first[index];
            int pos = next[index];
            for (int i = 1; i < totalCharacters; i++) {
                last[i] = first[pos];
                pos = next[pos];
            }
            // print last
            for (int i = 0; i < totalCharacters; i++) {
                cout << last[i];
            }
            cout << endl;
        }

    }
        /*
         * This is the same as above, only difference is quicksort instead of insertion.
         * */
    else if(string(argv[1]) == "quick") {
        while (getline(cin, textFileInput)) {

            if (textFileInput[0] == '\0') { cout << endl; continue; }

            else if (isdigit(textFileInput[0]) == true && textFileInput[1] != ' ') {
                index = stoi(textFileInput);
                continue;
            }

            int totalCharacters = 0;
            int nextNumberofChar;
            for (int i = 0; i < textFileInput.length(); i++) {
                nextNumberofChar = textFileInput[i] - '0';
                totalCharacters = totalCharacters + nextNumberofChar;
                i = i + 3;
            }

            char last[totalCharacters];
            int currentAmount;
            char letter;
            int remember = 0;
            for (int i = 0; i < textFileInput.length(); i++) {
                currentAmount = textFileInput[i] - '0';
                letter = textFileInput[i + 2];
                for (int j = i; j < i + currentAmount; j++) {
                    last[remember] = letter;
                    remember++;
                }
                i = i + 3;
            }

            char first[totalCharacters];
            for (int i = 0; i < totalCharacters; i++) { first[i] = last[i]; }
            quickSort(first, 0, totalCharacters - 1);
            // first[] is now a sorted version of last[]

            int next[totalCharacters];
            int nextRemember = 0;
            for (int i = 0; i < totalCharacters; i++) {
                char temp = first[i];
                for (int j = 0; j < totalCharacters; j++) {
                    if (last[j] == temp) {
                        next[nextRemember] = j;
                        nextRemember++;
                        last[j] = '\0';
                        break;
                    }
                }
            }

            last[0] = first[index];
            int pos = next[index];
            for (int i = 1; i < totalCharacters; i++) {
                last[i] = first[pos];
                pos = next[pos];
            }
            // print last
            for (int i = 0; i < totalCharacters; i++) {
                cout << last[i];
            }
            cout << endl;
        }
    }
    else{cout << "PLEASE USE ./run argument < input.txt > output.txt \n" << "[arguments: insertion, quick]\n"; return 0;}
    return 0;
}
