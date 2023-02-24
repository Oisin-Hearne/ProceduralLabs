#include <stdio.h>

#define COLS 4
#define ROWS 5

void readVotes(int v[][COLS], int r);
int findStateWinners(int v[][COLS], int r);
void displayMayor(int s[], int r);
void printVotes(int v[][COLS], int r);

//Lab 3 - Array Access
void main() {
	int votes[ROWS][COLS];
	int stateWinners[ROWS];

	readVotes(votes, ROWS);

	//Print table of votes to console.
	printf("\n");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("| %d ", votes[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
	printVotes(votes, ROWS);

	//Store state winners using the findStateWinners function
	for (int i = 0; i < ROWS; i++)
	{
		stateWinners[i] = findStateWinners(votes, i);
	}

	//Display the overall winner.
	displayMayor(stateWinners, ROWS);

}

//Reads user input into the 2d array.
void readVotes(int v[][COLS], int r) {
	for(int i = 0; i < r; i++)
		for (int j = 0; j < COLS; j++)
		{
			do { 
				printf(" * Enter votes for Candidate %d in State %d: ", j + 1, i + 1);
				scanf("%d", &v[i][j]);

				if (v[i][j] < 0) //Input validation
					printf(" ! Please do not enter a negative number.\n");
			} while (v[i][j] <= 0);
		}
}

//Reads the 2d array to find the highest number on each row.
int findStateWinners(int v[][COLS], int r) {
	int winner=0;
	int maxValue = 0;

	for (int i = 0; i < COLS; i++)
	{
		if (v[r][i] > maxValue)
		{
			winner = i+1;
			maxValue = v[r][i];
		}
	}

	printf(" * Candidate %d won state %d with %d votes!\n", winner, r + 1, maxValue);
	return winner;
}

//Reads the stateWinners array to tally state votes and find who won.
void displayMayor(int s[], int r) {
	int scoreA=0, scoreB = 0, scoreC = 0, scoreD = 0;

	//Tally how many states each candidate won.
	for (int i = 0; i < r; i++)
	{
		if (s[i] == 1)
			scoreA++;
		if (s[i] == 2)
			scoreB++;
		if (s[i] == 3)
			scoreC++;
		if (s[i] == 4)
			scoreD++;
	}

	//Compare the number of states each candidate won and output the winner.
	if (scoreA > scoreB && scoreA > scoreC && scoreA > scoreD)
	{
		printf("\n * The winner is Candidate %d with %d States won!\n", 1, scoreA);
	}
	else if (scoreB > scoreA && scoreB > scoreC && scoreB > scoreD)
	{
		printf("\n * The winner is Candidate %d with %d States won!\n", 2, scoreB);
	}
	else if (scoreC > scoreA && scoreC > scoreB && scoreB > scoreD)
	{
		printf("\n * The winner is Candidate %d with %d States won!\n", 3, scoreC);
	}
	else if (scoreD > scoreA && scoreD > scoreC && scoreD > scoreB)
	{
		printf("\n * The winner is Candidate %d with %d States won!\n", 4, scoreD);
	}
	else
		printf("\n ! There was a draw?");
}

//Prints votes table to a file.
void printVotes(int v[][COLS], int r) {
	FILE* fp;

	fp = fopen("votes.txt", "w");

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			fprintf(fp, "| %d ", v[i][j]);
		}
		fprintf(fp, "|\n");
	}

	fclose(fp);
	printf(" ! File Saved !\n");
}