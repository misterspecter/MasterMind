#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/////////////////////////////
const int NUM_PAWNS = 5;
const int NUM_COLORS = 8;
const int NUM_ATTEMPTS = 10;
const int ATTEMPT = 0;
char name_box[] = {'A', 'B', 'C', 'D', 'E'};

const char *color_t[] = {
    "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE", "GRAY", "PURPLE"
};

// You can change this value ^^^ 
////////////////////////////



///////////////////////// retrieve_proposition /////////////////////

void retrieve_proposition(char *selectedColors[], int numberOfColors)
{
    srand(time(NULL));

    for (int i = 0; i < numberOfColors; i++)
    {
        int randomIndex = rand() % NUM_COLORS;

        selectedColors[i] = (char *)color_t[randomIndex];
    }
}



//////////////////////// evaluate_proposition //////////////////////

int evaluate_proposition(const char *selectedColors[], const char *userColors[], int num_pawns)
{
    int correctPlace = 0;
    int correctColor = 0;
int win;
    for (int i = 0; i < num_pawns; i++)
    {
        if (strcmp(selectedColors[i], userColors[i]) == 0)
        {
            correctPlace++;
        }
        else
        {
            for (int j = 0; j < num_pawns; j++)
            {
                if (i != j && strcmp(selectedColors[i], userColors[j]) == 0)
                {
                    correctColor++;
                }
            }
        }
    }

    printf(">>> Correct colors in correct place: %d\n", correctPlace);
    printf(">>> Correct colors in wrong place: %d\n", correctColor);

    if (correctPlace == num_pawns && correctColor == 0)
    {
        win = 1;
        printf("║ (0_0) Grait. You win ║ : \n");
    }
    return win;
}
//////////////////////// game ///////////////////////////
int game(int win, int ttm)
{
    int complete = 0;

    if (win == 0)
    {
        if (ttm < NUM_ATTEMPTS)
        {
            complete = 0;
        }
        else
        {
            complete = 1;
            printf("║ Stop: You have finished trying ║ : \n");
        }
    }
    else
    {
        complete = 1;
    }

    return complete;
}

/////////////////////////// main //////////////////////////////

int main()
{
    int ttm = 0; // its the nember of Current attempt
    int win = 0;
    int complete = 0;
    printf("\t  ║║║ MasterMind ║║║");


    printf("- First: The computer/codemaker will choose 5 colors out of 8 colors.\n");
    printf("  Available colors are: white, black, red, green, blue, yellow, orange, violet, brown.\n\n");

    printf(" * You only have 10 attempts.\n");
    printf(" * We'll let you know if you've placed a color in the right place.\n");
    printf(" * We'll let you know if you put the correct color but it's not in the right place.\n");

    int access;
    printf("║ Press 0 to start ║ : ");
    scanf("%d", &access);

    while (access != 0)
    {
        printf("Press 0 to start \n");
        scanf("%d", &access);
    }

    char *selectedColors[NUM_PAWNS];
    retrieve_proposition(selectedColors, NUM_PAWNS);

    printf("║ The computer/codemaker selected his colors, good luck ║\n");
    printf("\n");

    printf("You need to see his choice? \n >> Yes = 0 / No = 1 \n\n ");
    int yes;
    scanf("%d", &yes);
    if (yes == 0)
    {
        for (int i = 0; i < NUM_PAWNS; i++)
        {
            printf("[%c]:%s \t", name_box[i], selectedColors[i]);
        }
    }

    printf("\n\n");
    printf("║ You have 10 attempts ║ : \n");
    printf(" * For each box[A,B,C,D,E]: Choose the number of color (from 0 to 7) \n\n");

    printf("   The list of Colors are:\n");
    for (int i = 0; i < NUM_COLORS; i++)
    {
        printf("color[%d]:%s \t", i, color_t[i]);
    }
    printf("\n\n");

    printf("ــــــــــ \n");

    // the codebreaker enter his choice
    const char *choice_color[NUM_PAWNS];
    int x;       // the value of codebreaker (0-7) of colors
    

    game(win, ttm);
    while (game(win, ttm) == 0)
    {
        printf(">> %d << attempt\n", ttm);
        for (int s = 0; s < NUM_PAWNS; s++)
        {
            printf("Box[%c] = ", name_box[s]);
            scanf("%d", &x);
            if (x >= 0 && x < NUM_COLORS)
            {
                choice_color[s] = color_t[x];
            }
            else
            {
                printf("Invalid color number. Please choice a number between 0 and %d.\n", NUM_COLORS - 1);
                s--;
            }
        }

        for (int i = 0; i < NUM_PAWNS; i++)
        {
            printf("Box[%c]= ", name_box[i]);
            printf("%s   ", choice_color[i]);
        }

        printf("\nــــــــــ \n");
        printf("\n");

        ttm++ ;
        evaluate_proposition(selectedColors, choice_color, NUM_PAWNS);
        win = evaluate_proposition(selectedColors, choice_color, NUM_PAWNS);
        game(win,ttm);
    }


////////////////////////////////

   char name[] = "By Mohammed Benmerbi L2 G6";
   int len = strlen(name);
   int z, d;

   printf("╔");
   for (z = 0; z < len + 2; z++) {
      printf("=");
   }
   printf("╗\n");

   printf("║ ");
   for (z = 0; z < len; z++) {
      printf("%c", name[z]);
   }
   printf(" ║\n");

   printf("╚");
   for (z = 0; z < len + 2; z++) {
      printf("=");
   }
   printf("╝\n");

///////////////////////////////////////
    return 0;
}