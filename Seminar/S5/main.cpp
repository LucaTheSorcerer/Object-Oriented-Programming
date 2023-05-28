#include <algorithm>

class Customer {
public:
    // Eigenschaften des Kunden
    std::string name;
    int age;
    std::string address;
};

class CustomerRepository {
public:
    virtual void create(Customer customer) = 0;
    virtual std::vector<Customer> findAll() = 0;
    virtual void update(Customer customer) = 0;
    virtual void remove(Customer customer) = 0;
};

template<typename T>
class CrudRepository {
public:
    virtual void create(T obj) = 0;
    virtual std::vector<T> findAll() = 0;
    virtual void update(T obj) = 0;
    virtual void remove(T obj) = 0;
};


template<typename T>
class InMemoryRepository: public CrudRepository<T> {
private:
    std::vector<T> objects;
public:
    void create(T obj) override {
        objects.push_back(obj);
    }

    std::vector<T> findAll() override {
        return objects;
    }

    void update(T obj) override {
        for(int i = 0; i < objects.size(); i++) {
            if(objects[i] == obj) {
                objects[i] = obj;
                break;
            }
        }
    }

    void remove(T obj) override {
        auto it = std::find(objects.begin(), objects.end(), obj);
        if(it != objects.end()) {
            objects.erase(it);
        }
    }
};