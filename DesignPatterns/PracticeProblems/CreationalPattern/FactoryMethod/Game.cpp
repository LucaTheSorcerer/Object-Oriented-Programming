//
// Created by Luca Tudor on 14.06.2023.
//

#include "Game.h"

std::string GameCreator::playingATM() const {
    std::shared_ptr<Game> game = this->CreateGameMethod();

    std::string result = "The game being played at the moment is " + game->playOperation();
    return result;
}

std::shared_ptr<Game> ChessGame::CreateGameMethod() const {

    return std::make_shared<Chess>();
}

std::shared_ptr<Game> CheckersGame::CreateGameMethod() const {

    return std::make_shared<Checkers>();
}
