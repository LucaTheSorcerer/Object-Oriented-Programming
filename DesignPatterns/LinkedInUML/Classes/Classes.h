//
// Created by Luca Tudor on 15.06.2023.
//

#ifndef LINKEDINUML_CLASSES_H
#define LINKEDINUML_CLASSES_H

#include <string>
#include <vector>

using namespace std;

class Group;
class User;
class Post;
class Discussion;
class Discussions;
class Promotions;
class Jobs;


class Group{
    friend class Discussions;
    friend class Promotions;
    friend class Jobs;
private:
    string name;

};

class User{
private:
    string firstName;
    string lastName;
    vector<std::shared_ptr<Group>> groups;
    vector<std::shared_ptr<User>> connections;
    vector<std::shared_ptr<Post>> posts;

};

class Post{
    friend class Discussion;
private:
    string text;
};

class Discussion{
    friend class Discussions;
    friend class Promotions;
    friend class Jobs;
    friend class Post;
private:
    string title;
    vector<std::shared_ptr<Discussions>> Discussions;
    vector<std::shared_ptr<Promotions>> Promotions;
    vector<std::shared_ptr<Jobs>> Jobs;

public:
};

class Discussions{
    friend class Discussion;
private:
    vector <shared_ptr<Discussion>> discussions;
};

class Promotions{
    friend class Discussion;

private:
    vector <shared_ptr<Discussion>> discussions;

};

class Jobs{
    friend class Discussion;

private:
    vector <shared_ptr<Discussion>> discussions;
};

class Engine;
class Battery;
class Car {
private:
    shared_ptr<Engine> engine;
    shared_ptr<Battery> battery;
public:

};

class Engine {

};

class Battery {

};

#endif //LINKEDINUML_CLASSES_H
