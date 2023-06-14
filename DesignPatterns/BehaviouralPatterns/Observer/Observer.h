//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef BEHAVIOURALPATTERNS_OBSERVER_H
#define BEHAVIOURALPATTERNS_OBSERVER_H

/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects about any
 * events that happen to the object they're observing
 */

#include <iostream>
#include <list>
#include <string>

class IObserver { //=Subscriber
public:
    virtual ~IObserver() {};
    virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject { //Publisher
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject {

private:
    std::list<IObserver *> list_observer_;
    std::string message_;

public:
    virtual ~Subject();

    /**
     * The subscription management methods.
     */

    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
    void Notify() override;
    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();
    void SomeBusinessLogic();
};

class Observer : public IObserver {

private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number;

public:
    explicit Observer(Subject &subject);
    virtual ~Observer();
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();
};




#endif //BEHAVIOURALPATTERNS_OBSERVER_H
