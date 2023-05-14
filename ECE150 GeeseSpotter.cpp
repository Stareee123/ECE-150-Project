#include "geesespotter_lib.h"

// Written By Jongwon (Isaac) Kim

char *createBoard(std::size_t xdim, std::size_t ydim){
    char *board{new char [xdim * ydim]};
    for(int i = 0; i < xdim * ydim; i = i + 1){
        board [i] =0;
    }
    return board;
}

void cleanBoard(char *board){
    delete[] board;
    board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){
    int conxdim = static_cast <int>(xdim);
    int conydim = static_cast <int> (ydim);
    int conconxdim = static_cast <double> (xdim);
    int a {conxdim * conydim};
    int bit_5 {32};
    int bit_4 {16};
    int bit_3 {8};
    int bit_2 {4};
    int bit_1 {2};
    int bit_0 {1};
    for (int i = 0; i < a; i++){
        int hidden {board [i] & bit_5};
        int marked {board [i] & bit_4};
        if (hidden > 0){
            if (marked > 0){
                std::cout << "M";
            } else {
                std::cout << "*";
            }
        }
        if (hidden == 0){
            int c {board [i] & bit_3};
            int d {board [i] & bit_2};
            int e {board [i] & bit_1};
            int f {board [i] & bit_0};
            int g {c + d + e + f};
            std::cout << g;
        }
        /*int x {i};
        if (x == (conxdim * conydim)-1){
            break;
        }*/
        int coni = static_cast <double> (i);
        double multi {(coni+1.0) / conconxdim };
        int multiprove {(i+1) / conxdim};
        if (multi == multiprove){
            std::cout << std::endl;
        }
    }

}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim){
    int xxdim = static_cast <int> (xdim);
    int yydim = static_cast <int> (ydim);
    int xloc {0};
    int yloc {0};
    int xloop {0};
    int yloop {1};
    int gn {0};
    for (int i = 0; i < yydim; i ++){

        for (int a = 0; a < xxdim; a ++){
            
            /*오른쪽*/
            int newxloc {xloc + 1};
            int newyloc {yloc};

            if (newxloc >= xxdim){

            }else{
                int newloc {(newxloc)+(newyloc * xxdim)};
                if (board [newloc] == 9){
                    gn = gn + 1;
                }
            }
            


            /*왼쪽*/
            newxloc = xloc - 1;
            newyloc = yloc;

            if (newxloc < 0){

            }else{
                int newloc {(newxloc) + (newyloc * xxdim)};
                if (board [newloc] == 9){
                    gn = gn + 1;
                }
            }
            


            /*위*/
            newxloc = xloc;
            newyloc = yloc - 1;

            if (newyloc < 0){

            }else{
                int newloc {(newxloc) + (newyloc * xxdim)};
                if (board [newloc] == 9){
                    gn = gn + 1;
                }
            }
            


            /*위 오른쪽*/
            newxloc = xloc + 1;
            newyloc = yloc - 1;

            if (newyloc < 0){

            }else{
                if (newxloc < xxdim){
                    int newloc {(newxloc) + (newyloc * xxdim)};
                    if (board [newloc] == 9){
                        gn = gn + 1;
                    }
                }
            }
            


            /*위 왼쪽*/
            newxloc = xloc - 1;
            newyloc = yloc - 1;

            if (newyloc < 0){

            }else{
                if (newxloc < 0){

                }else{
                    int newloc {(newxloc) + (newyloc * xxdim)};
                    if (board [newloc] == 9){
                        gn = gn + 1;
                    }
                }
            }
            


            /*아래*/
            newxloc = xloc;
            newyloc = yloc + 1;

            if (newyloc >= yydim){

            }else{
                int newloc {(newxloc) + (newyloc * xxdim)};
                if (board [newloc] == 9){
                    gn = gn + 1;
                }
            }
            


            /*아래 오른쪽*/
            newxloc = xloc + 1;
            newyloc = yloc + 1;

            if (newyloc >= yydim){

            }else{
                if (newxloc < xxdim){
                    int newloc {(newxloc) + (newyloc * xxdim)};
                    if (board [newloc] == 9){
                        gn = gn + 1;
                    }
                }
            }
            


            /*아래 왼쪽*/
            newxloc = xloc - 1;
            newyloc = yloc + 1;

            if (newyloc >= yydim){

            }else{
                if (newxloc < 0){

                }else{
                    int newloc {(newxloc)+ (newyloc * xxdim)};
                    if (board [newloc] == 9){
                        gn = gn + 1;
                    }
                }
            }
            

            int orloc {(xloc) + (yloc * xxdim)};
            if (board [orloc] == 9){
                
            }else{
                board [orloc] = gn;
            }

            xloc = xloc + 1;
            
            gn = 0;
        }
        
        xloc = 0;
        yloc = yloc + 1;

    }

}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim){
    int bit_5{32};
    for(int i = 0; i < xdim * ydim; i++){
        board[i] |= bit_5;
    }
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    int xxdim = static_cast <int> (xdim);
    int yydim = static_cast <int> (ydim);
    int xxloc = static_cast <int> (xloc);
    int yyloc = static_cast <int> (yloc);
    int bit_5 {32};
    int bit_4 {16};
    int bit_3 {8};
    int bit_2 {4};
    int bit_1 {2};
    int bit_0 {1};

    int exactloc {(xxloc) + (yyloc * xxdim)};

    if ((board[exactloc] & bit_4) > 0){
        return 1;
    }

    if ((board[exactloc] & bit_5) == 0){
        return 2;
    }

    int a {board[exactloc] & bit_0};
    int b {board[exactloc] & bit_1};
    int c {board[exactloc] & bit_2};
    int d {board[exactloc] & bit_3};
    int total {a + b + c + d};

    if (total == 9){
        board[exactloc] ^= bit_5;
        return 9;
    }

    if (total == 0){

        /*오른쪽*/
        int newxloc {xxloc +1};
        int newyloc {yyloc};

        if (newxloc >= xxdim){

        }else{
            int newloc {(newxloc)+(newyloc * xxdim)};
            if ((board[newloc] & bit_5) > 0){
                board[newloc] ^= bit_5;
            }
        }


        /*왼쪽*/
        newxloc = xloc - 1;
        newyloc = yloc;

        if (newxloc < 0){

        }else{
            int newloc {(newxloc)+(newyloc * xxdim)};
            if ((board[newloc] & bit_5) > 0){
                board[newloc] ^= bit_5;
            }
        }


        /*위*/
        newxloc = xloc;
        newyloc = yloc - 1;

        if (newyloc < 0){

        }else{
            int newloc {(newxloc)+(newyloc * xxdim)};
            if ((board[newloc] & bit_5) > 0){
                board[newloc] ^= bit_5;
            }
        }


        /*위 오른쪽*/
        newxloc = xloc + 1;
        newyloc = yloc - 1;

        if (newyloc < 0){

        }else{
            if (newxloc < xxdim){
            int newloc {(newxloc)+(newyloc * xxdim)};
            if ((board[newloc] & bit_5) > 0){
                board[newloc] ^= bit_5;
            }
            }
        }


        /*위 왼쪽*/
        newxloc = xloc - 1;
        newyloc = yloc - 1;

        if (newyloc < 0){

        }else{
            if (newxloc < 0){

            }else{
                int newloc {(newxloc)+(newyloc * xxdim)};
                if ((board[newloc] & bit_5) > 0){
                    board[newloc] ^= bit_5;
                }
            }
        }


        /*아래*/
        newxloc = xloc;
        newyloc = yloc + 1;

        if (newyloc >= yydim){

        }else{
            int newloc {(newxloc)+(newyloc * xxdim)};
            if ((board[newloc] & bit_5) > 0){
                board[newloc] ^= bit_5;
            }
            
        }


        /*아래 오른쪽*/
        newxloc = xloc + 1;
        newyloc = yloc + 1;

        if (newyloc >= yydim){

        }else{
            if (newxloc < xxdim){
                int newloc {(newxloc)+(newyloc * xxdim)};
                if ((board[newloc] & bit_5) > 0){
                    board[newloc] ^= bit_5;
                }
            }
        }


        /*아래 왼쪽*/
        newxloc = xloc - 1;
        newyloc = yloc + 1;

        if (newyloc >= yydim){

        }else{
            if (newxloc < 0){

            }else{
                int newloc {(newxloc)+(newyloc * xxdim)};
                if ((board[newloc] & bit_5) > 0){
                    board[newloc] ^= bit_5;
                }
            }
        }
    
    }
    int Fnewloc {(xxloc)+(yyloc * xxdim)};
    if ((board[Fnewloc] & bit_5) > 0){
        board[Fnewloc] ^= bit_5;
    }
    return 0;
    
}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    int bit_5{32};
    int bit_4{16};
    int i = (xloc) + (yloc * xdim);
    int a = (board[i] & bit_5);
    if (a > 0){
        board [i] ^= bit_4;
        return 0;
    }else{
        return 2;
    }

}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim){
    int xxdim = static_cast <int> (xdim);
    int yydim = static_cast <int> (ydim);
    int a {xxdim * yydim};
    int bit_5 {32};
    int bit_4 {16};
    int bit_3 {8};
    int bit_2 {4};
    int bit_1 {2};
    int bit_0 {1};
    for (int i = 0; i < a; i++){
        int determine {board[i] & bit_5};
        if (determine > 0){
            int b {board[i] & bit_0};
            int c {board[i] & bit_1};
            int d {board[i] & bit_2};
            int e {board[i] & bit_3};
            int f {b + c + d + e};
            if (f == 9){
                
            }else{
                return false;
            }
        }
    }

    return true;
}
