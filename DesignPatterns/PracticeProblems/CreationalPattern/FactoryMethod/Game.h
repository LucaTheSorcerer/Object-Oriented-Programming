//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_GAME_H
#define PRACTICEPROBLEMS_GAME_H

#include <string>
#include <iostream>
#include <utility>

/**
 * Factory Method:
 Create a simple game using the Factory Method pattern.
 Define an abstract Game class with a play() method.
 Create two concrete classes, Chess and Checkers, which inherit from the Game class and implement their own play()
 methods. Create a GameFactory class with a createGame() method that takes a game type
 as input (e.g., "Chess" or "Checkers") and returns the corresponding Game object.
 */


class Game {
public:
    virtual ~Game() = default;
    virtual std::string playOperation() = 0;

};

class Chess : public Game {
public:
    std::string playOperation() override {
        return "Playing Chess!";
    }
};

class Checkers : public Game {
public:
    std::string playOperation() override {
        return "Playing Checkers!";
    }
};


class GameCreator {
public:
    virtual ~GameCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<Game> CreateGameMethod() const = 0;

    [[nodiscard]] std::string playingATM() const;
};

class ChessGame : public GameCreator {
public:
    [[nodiscard]] std::shared_ptr<Game> CreateGameMethod() const override;
};

class CheckersGame : public GameCreator {
public:
    [[nodiscard]] std::shared_ptr<Game> CreateGameMethod() const override;
};


#endif //PRACTICEPROBLEMS_GAME_H
