// sources not included inside the tiktaktoe class itself
#include "tiktaktoe.h"

bool tiktaktoe::preMoveChecks::onField(const unsigned int *locationX, const unsigned int *locationY)
{
    if (*locationX > 2 || *locationY > 2)
        return false;
    else
        return true;
}
bool tiktaktoe::preMoveChecks::locationEmpty(const unsigned int fieldValue)
{
    if (fieldValue == 0)
        return true;
    else
        return false;
}
unsigned int tiktaktoe::parsing::currentPlayer(const unsigned int *moveCount)
{
    if (*moveCount % 2 == 0)
        return 1;
    else
        return 2;
}
bool tiktaktoe::parsing::outOfMoves(const unsigned int *moveCount)
{
    if (*moveCount >= 9)
        return true;
    else
        return false;
}