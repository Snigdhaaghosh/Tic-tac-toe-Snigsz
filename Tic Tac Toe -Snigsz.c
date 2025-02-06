
#include <stdio.h>
char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void game_board()
{
   printf("%c  |  %c  |  %c \n", board[0], board[1], board[2]);
   printf("%c  |  %c  |  %c \n", board[3], board[4], board[5]);
   printf("%c  |  %c  |  %c \n", board[6], board[7], board[8]);
}
void player_move(char player)
{
   int move;
   printf("enter your move:");
   scanf("%d", &move);
   if ((move < 1 || move > 9) || (board[move - 1] == 'X' || board[move - 1] == 'O'))  
   //Condition to check if the required block is already occupied by a player or not 
   {
      printf("Invalid move!!\n");
   }
   else
   {
      board[move - 1] = player;
   }
}
int check_win()
{
   if (board[0] == board[1] && board[1] == board[2] || board[3] == board[4] && board[4] == board[5] || board[6] == board[7] && board[7] == board[8] || board[0] == board[4] && board[4] == board[8] || board[2] == board[4] && board[4] == board[6] || board[0] == board[3] && board[3] == board[6] || board[1] == board[4] && board[4] == board[7] || board[2] == board[5] && board[5] == board[8])
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int main()
{
   char player_name[20];
   printf("-----------Welcome to Tic Tac Toe - Snigsz------------ \n \n");
   printf("enter player name :\n");
   fgets(player_name, 20, stdin);
   int move = 0;
   while (1)
   {
      game_board();
      player_move(move % 2 == 0 ? 'X' : 'O');
      if (check_win())
      {
         game_board();
         printf("%c player wins the game", move % 2 == 0 ? 'X' : 'O');
         break;
      }
      move++;
      if (move == 9)
      {
         game_board();
         printf("Draw! Play again!!\n");
         break;
      }
   }
   return 0;
}
