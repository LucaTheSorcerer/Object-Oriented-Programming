//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Repository/fruit_repository.h"


class FruitFileRepository : public FruitRepository {
private:
    string filename;
    void loadFruits();
    void saveFruits();

public:
    explicit FruitFileRepository(const string& filename);
    void addFruit(shared_ptr<Fruit>& fruit) override;
    void updateFruit(shared_ptr<Fruit>& fruit) override;
};