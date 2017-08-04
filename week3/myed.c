// myed.c - a very simple, line-based text editor
// Written by John Shepherd, March 2013
// Last modified, August 2014
//
// Documentation:
//
// Usage: myed FileName
// Opens FileName and reads it into internal doubly-linked list
// Gives error message if no such file or not readable
//
// Editor commands:
// . = show current line
// % = show all lines
// p = move to previous line and show it
// n = move to next line and show it
// NN = move to line number NN
// +NN = move forward by NN lines and show line
// -NN = move backward by NN lines and show line
// i = read new line and insert in front of current
// a = read new line and insert after current
// d = delete current line
// w = write out contents of file to file FileName.new
// q = quit from the editor

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DLList.h"

// size of line buffers
#define MAX 100

int getCommand(char *s);
void showCurrLine(DLList);
void showHelp();


int main(int argc, char *argv[])
{
	// Variables used throughout main

	DLList lines;      // lines from input file as a DLList
	FILE *f;         // file handle
	char fname[MAX]; // file name
	char cmd[MAX];   // command typed by user
	int  n;          // line numbers/displacements
	int  done;       // flag for end-of-edit-session
	char new[MAX];   // buffer to hold newly inserted line

	// Check command-line args

	if (argc < 2) {
		fprintf(stderr, "Usage: %s FileName\n", argv[0]);
		return EXIT_FAILURE;
	}
	strcpy(fname,argv[1]);
	if ((f = fopen(fname,"r")) == NULL) {
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	lines = getDLList(f);
	fclose(f);

	// Main loop

	done = 0;
	while (!done && getCommand(cmd)) {
		switch (cmd[0]) {
		case '.':
			// show current line
			showCurrLine(lines);
			break;
		case '%':
			// show all lines
			putDLList(stdout,lines);
			break;
		case 'n':
			// move to next line
			DLListMove(lines,1);
			showCurrLine(lines);
			break;
		case 'p':
			// move to previous line
			DLListMove(lines,-1);
			showCurrLine(lines);
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			// move to line NN
			n = 0;  // just in case ...
			sscanf(cmd,"%d",&n);
			DLListMoveTo(lines,n);
			showCurrLine(lines);
			break;
		case '+': case '-':
			// move forward/backward NN lines
			sscanf(cmd,"%d",&n);
			DLListMove(lines,n);
			showCurrLine(lines);
			break;
		case 'i':
			// read new line and insert in front of current
			fgets(new,MAX,stdin);
			new[strlen(new)-1] = '\0';
			DLListBefore(lines,new);
			break;
		case 'a':
			// read new line and insert after current
			fgets(new,MAX,stdin);
			new[strlen(new)-1] = '\0';
			DLListAfter(lines,new);
			break;
		case 'd':
			// delete current line
			DLListDelete(lines);
			break;
		case 'w':
			// write lines to FileName.new
			strcat(fname,".new");
			if ((f = fopen(fname,"w")) == NULL)
				fprintf(stderr, "Can't write %s\n",fname);
			else {
				putDLList(f,lines);
				fclose(f);
			}
			break;
		case '?':
			showHelp();
			break;
		case 'q':
			done = 1;
			break;
		}
	}
	
	// Finish up cleanly

	return EXIT_SUCCESS;
}

// getCommand(buf)
// prompt for and read next user command
// store it in buf
// return 1 if got a command, 0 if EOF
int getCommand(char *buf)
{
	printf("> ");
	return (fgets(buf, MAX, stdin) != NULL);
}

// showCurrLine(lines)
void showCurrLine(DLList lines)
{
	printf("%s",DLListCurrent(lines));
	printf("\n");
}

// giveHelp()
// show help message
void showHelp()
{
	printf("Editor commands:\n");
	printf(". = show current line\n");
	printf("%% = show all lines\n");
	printf("p = move to previous line and show it\n");
	printf("n = move to next line and show it\n");
	printf("NN = move to line number NN\n");
	printf("+NN = move forward by NN lines and show line\n");
	printf("-NN = move backward by NN lines and show line\n");
	printf("i = read new line and insert in front of current\n");
	printf("a = read new line and insert after current\n");
	printf("d = delete current line\n");
	printf("w = write out contents of file to file FileName.new\n");
    printf("? = show this help message\n");
	printf("q = quit from the editor\n");
}
