// tiktaktoe sources

#include "tiktaktoe.h"

unsigned int tiktaktoe::tiktaktoe::placePice(unsigned int locationX, unsigned int locationY)
{
    // check, if the pice can actually be placed
    if (!preMoveChecks::onField(&locationX, &locationY) ||
        !preMoveChecks::locationEmpty(field[locationX][locationY]))
        return 1;

    writePice(&locationX,&locationY);

    moveCount++;

    // after move checks
    if (playerWon())
        return 2;
    else if (parsing::outOfMoves(&moveCount))
        return 3;

    // TODO check for standoff

    return 0;
}
void tiktaktoe::tiktaktoe::writePice(const unsigned int *locationX, const unsigned int *locationY)
{
    // get current player
    if (parsing::currentPlayer(&moveCount) == 1)
        // player 1
        field[*locationX][*locationY] = 1;
    else
        // player 2
        field[*locationX][*locationY] = 2;
}
bool tiktaktoe::tiktaktoe::playerWon()
{
    bool completeRowX;
    bool completeRowY;

    for (int i = 0; i < 3; ++i) {
        completeRowX = true;
        completeRowY = true;
        for (int j = 0; j < 3; ++j) {
            // complete row in X direction
            if (field[i][j] != parsing::currentPlayer(&moveCount))
                completeRowX = false;
            // complete row in Y direction
            else if (field[j][i] != parsing::currentPlayer(&moveCount))
                completeRowY = false;
        }
        if (completeRowX ||
            completeRowY)
            return true;
    }
    return false;
}
unsigned int tiktaktoe::tiktaktoe::getField(const unsigned int locationX, const unsigned int locationY)
{
    return field[locationX][locationY];
}
