#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26

int are_anagrams(char[], char[]);

int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";

    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");

    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";

    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");
    
    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";

    assert(are_anagrams(listen, silent));
    printf("passed!\n");

    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";

    assert(!are_anagrams(mole, meal));
    printf("passed!\n");

    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";

    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}

int are_anagrams(char first_word[], char second_word[]) {
    /* your code goes here */
    int s1_length = strlen(first_word);
    int s2_length = strlen(second_word);
    if (s1_length != s2_length) {
        return false;
    }
    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; i < s1_length; i++) {
        count1[first_word[i]]++;
        count2[second_word[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;

}