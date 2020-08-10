// ================
// TikTakToe header
// by MCWertGaming
// ================
#pragma once

namespace tiktaktoe {
    class tiktaktoe {
    private:
        // includes the field - field[X][Y]
        unsigned int field[3][3]{0, 0, 0, 0, 0, 0, 0, 0, 0};
        unsigned int moveCount{0};

        /* internal field-manipulation */
        void writePice(const unsigned int *, const unsigned int *);

        /* parsing functions */
        bool playerWon();

    public:
        tiktaktoe() = default;
        ~tiktaktoe() = default;

        /* game manipulation */
        unsigned int placePice(unsigned int, unsigned int);

        /* visualising */
        unsigned int getField(unsigned int, unsigned int);
    };
    // tiktaktoe additions
    namespace preMoveChecks {
        bool onField(const unsigned int *, const unsigned int *);

        bool locationEmpty(unsigned int);
    }
    namespace parsing {
        unsigned int currentPlayer(const unsigned int *);

        bool outOfMoves(const unsigned int *);
    }
}