//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_RUNGAME_H
#define PRACTICEPROBLEMS_RUNGAME_H

#include "Game.h"

void ClientCode(const GameCreator& creator) {

    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.playingATM() << std::endl;
}

void runGame() {

    std::cout << "App: Launched with the ChessGame.\n";
    std::shared_ptr<GameCreator> creator = std::make_shared<ChessGame>();
    ClientCode(*creator);
    std::cout << std::endl;

    std::cout << "App: Launched with the CheckersGame.\n";

    std::shared_ptr<GameCreator> creator2 = std::make_shared<CheckersGame>();
    ClientCode(*creator2);
}
#endif //PRACTICEPROBLEMS_RUNGAME_H
