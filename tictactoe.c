#include <stdio.h>

// Var & Func declarations

int i, j, k, input, winner, player, row, col;

int checkForWin(), getColInput(), getRowInput(), isFieldTaken();

void printTitle();
void printField(int field[3][3]);
void printWinner(int winner);
void printCurrentPlayer(int player);
void takeField(int col, int row, int player);

// Init field

int field[3][3] = {  
   {0, 0, 0} ,
   {0, 0, 0} ,
   {0, 0, 0}
};

// Main Function

int main()
{
	// Starting Player: Player 1
	
	player = 1;

	// No winner yet
	
	winner = 0;
	
	// Game loop (running until there is a winner or a tie)
	
	while(winner == 0)
	{
		// Print title
		
		printTitle();
	
		// Print game field
		
		printField(field);
		
		// Print whose turn it is
		
		printCurrentPlayer(player);
		
		// Get column input
		
		col = getColInput();
		
		// Get row input
	
		row = getRowInput();
		
		// Give user another try to choose if field is already taken, if not take it
		
		if(isFieldTaken(col, row) == 0)
			takeField(col, row, player);
		else
			continue;
		
		// Check for winner
		
		// 0 = No winner yet, 1 = Player 1, 2 = Player 2, -1 = Tie
		
		winner = checkForWin(field);
		
		// Switch Player
		
		player = (player == 1) ? 2 : 1;
		
	}
	
	// Print title + field for the last time
	
	printTitle();
	
	printField(field);
	
	// Print win message
	
	printWinner(winner);
	
}


// Print whose turn it is

void printCurrentPlayer(int player)
{
	printf( (player == 1) ? "PLAYER ONE'S TURN (X)\n\n" : "PLAYER TWO'S TURN (O)\n\n" );
}

// Print the win message or, if nobody has won, print that it is a tie

void printWinner(int winner)
{
	if(winner == 1)
	{
		printf("PLAYER ONE HAS WON!\n\n\n");
	}
	else if(winner == 2)
	{
		printf("PLAYER TWO HAS WON!\n\n\n");
	}
	else
	{
		printf("IT'S A TIE!\n\n\n");
	}
}

// "Conquer" a field as a certain player

void takeField(int col, int row, int player)
{
	field[col - 97][row - 1] = player;
}

// Check if a field is already taken or still free

int isFieldTaken(int col, int row)
{
	return (field[col - 97][row - 1] != 0) ? 1 : 0;
}

// Get input for the column (a, b or c)

int getColInput()
{
	input = 0;
	while(input == 0 || input > 99 || input < 97)
	{
		printf("Enter character for column (a, b, c): ");
		scanf(" %c", &input);
		getchar();
	}
	return input;
}

// Get input for the row (1, 2 or 3)

int getRowInput()
{
	input = 0;
	while(input == 0 || input > 3 || input < 1)
	{
		printf("Enter number for row (1-3): ");
		scanf("%d", &input);
		getchar();
	}
	return input;
}

// Check if there is a winner or if there is a tie
// 0 = No winner yet, 1 = Player 1, 2 = Player 2, -1 = Tie

int checkForWin(int field[3][3])
{

	// vertical check
	
	if(field[0][0] == field[0][1] && field[0][1] == field[0][2])
	{
		return field[0][0];
	}
	if(field[1][0] == field[1][1] && field[1][1] == field[1][2])
	{
		return field[1][0];
	}
	if(field[2][0] == field[2][1] && field[2][1] == field[2][2])
	{
		return field[2][0];
	}
	
	// horizontal check
	
	if(field[0][0] == field[1][0] && field[1][0] == field[2][0])
	{
		return field[0][0];
	}
	if(field[0][1] == field[1][1] && field[1][1] == field[2][1])
	{
		return field[0][1];
	}
	if(field[0][2] == field[1][2] && field[1][2] == field[2][2])
	{
		return field[0][2];
	}
	
	// diagonal check
	
	if(field[0][0] == field[1][1] && field[1][1] == field[2][2])
	{
		return field[0][0];
	}
	if(field[2][0] == field[1][1] && field[1][1] == field[0][2])
	{
		return field[2][0];
	}
	
	// check for tie (search for unused space, if found resume game)
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(field[j][i] == 0)
				return 0;
		}
	}
	
	// return -1 if there is no space left (tie)
	
	return -1;
}

// Print the title

void printTitle()
{
	// Little hack to clear console window
	
	printf("\e[1;1H\e[2J");
	
	// title with some ascii art
	
	printf("████████╗██╗ ██████╗    ████████╗ █████╗  ██████╗    ████████╗ ██████╗ ███████╗\n");
	printf("╚══██╔══╝██║██╔════╝    ╚══██╔══╝██╔══██╗██╔════╝    ╚══██╔══╝██╔═══██╗██╔════╝\n");
	printf("   ██║   ██║██║            ██║   ███████║██║            ██║   ██║   ██║█████╗  \n");
	printf("   ██║   ██║██║            ██║   ██╔══██║██║            ██║   ██║   ██║██╔══╝  \n");
	printf("   ██║   ██║╚██████╗       ██║   ██║  ██║╚██████╗       ██║   ╚██████╔╝███████╗\n");
	printf("   ╚═╝   ╚═╝ ╚═════╝       ╚═╝   ╚═╝  ╚═╝ ╚═════╝       ╚═╝    ╚═════╝ ╚══════╝\n");
	
                                                                               
	
	printf("\n\n\n");
}

// Print the game field

void printField(int field[3][3])
{	
	printf("      A   B   C\n");
	
	// Loop through cols and rows
	
	for(i = 0; i < 3; i++)
	{
		printf("    -------------\n");
		
		printf("  %d |", i + 1);
		
		for(j = 0; j < 3; j++)
		{
			switch(field[j][i])
			{
				case 1:
					printf(" X |");
					break;
				case 2:
					printf(" O |");
					break;
				default:
					printf("   |");
					break;
			}
		}
		printf("\n");
	}
	printf("    -------------\n\n");
	
}
