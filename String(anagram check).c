#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if two strings are anagrams
bool areAnagrams(char *str1, char *str2) {
    int count1[256] = {0};
    int count2[256] = {0};
    int i;

    // If lengths of strings are not same, they cannot be anagrams
    if (strlen(str1) != strlen(str2))
        return false;

    // Count frequency of characters in both strings
    for (i = 0; str1[i] && str2[i]; i++) {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }

    // Compare character counts of both strings
    for (i = 0; i < 256; i++) {
        if (count1[i] != count2[i])
            return false;
    }

    return true;
}

int main() {
    char str1[100], str2[100];

    // Input strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove trailing newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Check if strings are anagrams
    if (areAnagrams(str1, str2))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
