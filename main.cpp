#include <iostream>

#include "board.hpp"
#include "player.hpp"
#include "human.hpp"

using namespace std;

class Controller{
    Board* chessBoard;
    vector<Player*> players;
    bool isGameSetup;

    void setupPlayers(istringstream& ss) {
        players.resize(2);
        string white, black;
        ss >> white;
        ss >> black;
        players[0] = new Human(WHITE_SIDE);
        players[1] = new Human(BLACK_SIDE);
    }

    void updateGameState(int side, int flag) {
        switch(flag) {
            case GAME_OVER:
                isGameSetup = false;
                cout << "Checkmate! " << (side == WHITE_SIDE ? "White" : "Black") << " won!" << endl;
                break;
            case DRAW:
                cout << "Draw!" << endl;
                break;
        }
    }

    void handleRunningGame(string& command, istringstream& ss) {
        int side = chessBoard->getSide();
        Player* curPlayer = players[side];

        if (command == "move") {
            curPlayer->move(chessBoard, ss);
            int flag = chessBoard->checkGameState(side ^ 1);
            updateGameState(side, flag);
            chessBoard->render();
        } else if (command == "undo") {
            int num = 1;
            if (!ss.str().empty()) {
                ss >> num;
            }
            for (int i = 0; i < num; ++i) {
                chessBoard->undoMove();
            }
            chessBoard->render();
        } else if (command == "forfeit") {
            updateGameState(side, GAME_OVER);
        } else {
            throw runtime_error("Command not recognized, try again!"); 
        }
    }

    void handleSetup(string& command, istringstream& ss) {
        if (command != "game" && command != "load") {
            throw runtime_error("Command not recognized, try again!"); 
        }
        chessBoard = new Board();
        setupPlayers(ss);
        isGameSetup = true;
        chessBoard->render();
    }

    public:
        void start() {
            string inputs;
            while (getline(cin, inputs)) {
                try {
                    istringstream ss{inputs};
                    string command;
                    ss >> command;
                    if (isGameSetup) {
                        handleRunningGame(command, ss);
                    } else {
                        handleSetup(command, ss);
                    }
                } catch(runtime_error& e) {
                    cerr << e.what() << endl;
                }
            }
    }
};

int main() {
#ifdef DEBUG
    cout << "(DEBUG MODE)" << endl;
#endif
    Controller game{};
    game.start();
    return 0;
}