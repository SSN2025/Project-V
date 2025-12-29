#include <iostream>
#include <cstdlib>
void draw_board(int board[8][8]){
    system("clear"); 
    for(int i=0; i<8;i++){
        printf("\n   ");
        for (int j = 0; j < 8; j++)
        {   /*
            pawn = 1
            eleph = 2
            horse =  3
            camel = 4
            queen = 5
            king = 6
            */
            switch (board[i][j])
            {
            case 0:
                printf("_ ");
                break;
            case 1:
                printf("p ");
                break;
            case 2:
                printf("r ");
                break;
            case 3:
                printf("n ");
                break;
            case 4:
                printf("b ");
                break;
            case 5:
                printf("q ");
                break;
            case 6:
                printf("k ");
                break;
            case -1:
                printf("P ");
                break;
            case -2:
                printf("R ");
                break;
            case -3:
                printf("N ");
                break;
            case -4:
                printf("B ");
                break;
            case -5:
                printf("Q ");
                break;
            case -6:
                printf("K ");
                break;
            }
        }
       ;
    }
}

void move(int brd[8][8],int c_fr, int r_fr, int c_to, int r_to){
    brd[7-r_to][c_to] = brd[7-r_fr][c_fr];
    brd[7-r_fr][c_fr] = 0;

}


int main(){
    int board[8][8]={{-2,-3,-4,-5,-6,-4,-3,-2}, //8
                     {-1,-1,-1,-1,-1,-1,-1,-1}, //7
                     { 0, 0, 0, 0, 0, 0, 0, 0}, //6
                     { 0, 0, 0, 0, 0, 0, 0, 0}, //5
                     { 0, 0, 0, 0, 0, 0, 0, 0}, //4
                     { 0, 0, 0, 0, 0, 0, 0, 0}, //3
                     { 1, 1, 1, 1, 1, 1, 1, 1}, //2
                     { 2, 3, 4, 5, 6, 4, 3, 2}};//1
                     //a  b  c  d  e  f  g  h
    draw_board(board);
    //char c;
    char str[5];
    int count=1;
    int game_state=1;
    int row_fr,column_fr,row_to,column_to;
    while(game_state ==1){
        if(count>0){printf("\nWhite>");}
    else if(count<0){printf("\nBlack>");}
    // while((c=getchar()!='\n')){
    //     if(c==' '){
    //         c=getchar();
    //         column_to = c-'a';
    //         c=getchar();
    //         row_to = c-'1';
        
    //     }
    //     else{
    //         column_fr = c-'a';
    //         c=getchar();
    //         row_fr = c-'1';
    //         }}
    gets(str);
    column_fr = str[0]-'a';
    row_fr = str[1]-'1';
    column_to = str[3]-'a';
    row_to = str[4]-'1';
    column_fr *= count;
    row_fr *= count;
    column_to *= count;
    row_to *= count;

    (count>0)?(count=-1):(count=1);
    move(board,column_fr,row_fr,column_to,row_to);
    printf("\n");
    draw_board(board);}
    //game_state =0;}

return 0;
}