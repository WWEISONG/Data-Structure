// prefixes.c
// print all the prefixes of a command-line arg, including itself.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   char *start, *end;

   if (argc == 2) {
      start = argv[1];
      end = argv[1];
      while (*end != '\0') {    // find address of terminating '\0'
         end++;
      }
      while (start != end) {
         printf("%s\n", start); // print string from start to '\0'
         end--;                 // move end pointer up
         *end = '\0';           // overwrite last char by '\0'
      }
   }
   return EXIT_SUCCESS;
}