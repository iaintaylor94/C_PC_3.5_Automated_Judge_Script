#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <math.h>
#include <string.h>

// File Initialization
FILE *gInputFile;
void usage (char *);

// File Input
const int kMaxLineLength = 81;
const int kMaxNumLines = 100;
bool getNumLines (FILE *, int*);

int gTemplateNumLines;
char gAnswerTemplate [kMaxNumLines][kMaxLineLength];
char gAnswerTemplateDigits [kMaxNumLines][kMaxLineLength];

int gSubmissionNumLines;
char gSubmission [kMaxNumLines][kMaxLineLength];
char gSubmissionDigits [kMaxNumLines][kMaxLineLength];

void getSorT (FILE *, int, char [kMaxNumLines][kMaxLineLength]);
void removeCharsSorT (int, char [kMaxNumLines][kMaxLineLength], char [kMaxNumLines][kMaxLineLength]);

bool compareSorT (int numLines, char first[kMaxNumLines][kMaxLineLength], char second [kMaxNumLines][kMaxLineLength]);

void printSorT (int, char [kMaxNumLines][kMaxLineLength]);


int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
    fprintf (stderr, "%s opened for reading.\n\n" , argv[1]);
  }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/
  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  int run = 1;
  // Template
  while (getNumLines (gInputFile, &gTemplateNumLines)) {
    getSorT (gInputFile, gTemplateNumLines, gAnswerTemplate);
    removeCharsSorT (gTemplateNumLines, gAnswerTemplateDigits, gAnswerTemplate);

    // Submission
    getNumLines (gInputFile, &gSubmissionNumLines);
    getSorT (gInputFile, gSubmissionNumLines, gSubmission);
    removeCharsSorT (gSubmissionNumLines, gSubmissionDigits, gSubmission);

    // Equal number of lines
    if (gTemplateNumLines != gSubmissionNumLines) {
      printf ("Run #%d: Wrong Answer\n", run);
      run++;
      continue;
    }


    /*
    // Print Global Variables
    printf ("PRINT SORT\n");
    printf ("----------\n");
    printf ("> Template\n");
    printSorT (gTemplateNumLines, gAnswerTemplate);
    printf (">\n");
    printSorT (gTemplateNumLines, gAnswerTemplateDigits);

    printf ("> Submission\n");
    printSorT (gSubmissionNumLines, gSubmission);
    printf (">\n");
    printSorT (gSubmissionNumLines, gSubmissionDigits);
    */

    // Compare "Accepted"
    if (compareSorT (gTemplateNumLines, gAnswerTemplate, gSubmission)) {
      printf ("Run #%d: Accepted\n", run);
    }
    // Compare "Presentation Error"
    else if (compareSorT (gTemplateNumLines, gAnswerTemplateDigits, gSubmissionDigits)) {
      printf ("Run #%d: Presentation Error\n", run);
    }
    // Compare "Wrong Answer"
    else {
      printf ("Run #%d: Wrong Answer\n", run);
    }
    run++;
  }
  



  
  /*--------------------------------MAIN PROGRAM END--------------------------------------*/
  /*--------------------------------FILE CLEANUP START------------------------------------*/
  fclose (gInputFile);
  /*--------------------------------FILE CLEANUP END--------------------------------------*/
  return 0;
}

// File Initialization
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

// File Input
bool getNumLines (FILE *fp, int *i) {
  char line [kMaxLineLength];
  fgets (line, kMaxLineLength, fp);
  line[strcspn (line, "\n")] = '\0';
  *i = atoi (line);

  if (atoi (line) == 0) {
    return false;
  }
  else {
    return true;
  }
}

// Answer Template
void getSorT (FILE *fp, int numLines, char destination [kMaxNumLines][kMaxLineLength]) {
  for (int i = 0; i < numLines; i++) {
    fgets (destination[i], kMaxLineLength, fp);
    int newline = strcspn (destination[i], "\n");
    destination[i][newline] = '\0';
  }
}
void removeCharsSorT (int numLines, char destination [kMaxNumLines][kMaxLineLength], char source [kMaxNumLines][kMaxLineLength]) {
  char temp [numLines][kMaxLineLength];
  int tempI = 0;
  int tempJ = 0;

  // Build temp array
  for (int i = 0; i < numLines; i++) {
    for (int j = 0; j < strlen (source[i]); j++) {
      if (isdigit (source[i][j])) {
        temp [tempI][tempJ] = source[i][j];
        tempJ++;
      }
    }
    temp [tempI][tempJ] = '\0';
    tempI++;
    tempJ = 0;
  }

  
  // Copy temp array to gAnswerTemplateDigits
  for (int i = 0; i < numLines; i++) {
    strcpy (destination[i], temp[i]);
  }
}

bool compareSorT (int numLines, char first [kMaxNumLines][kMaxLineLength], char second [kMaxNumLines][kMaxLineLength]) {
  for (int i = 0; i < numLines; i++) {
    if (strcmp (first[i], second[i])) {
      return false;
    }
  }
  return true;
}
void printSorT (int numLines, char SorT [kMaxNumLines][kMaxLineLength]) {
  for (int i = 0; i < numLines; i++) {
    printf ("%s\n", SorT[i]);
  }
}