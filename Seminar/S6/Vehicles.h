//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class VehicleComponent {
//public:
//    virtual void displayInfo() = 0;
//    virtual void add_vehicle_component(VehicleComponent* vehicleComponent) = 0;
//    virtual void remove_vehicle_component(VehicleComponent* vehicleComponent) = 0;
//};
//
//class RoadVehicle : public VehicleComponent {
//private:
//    int id;
//    string brand;
//    string model;
//
//public:
//    RoadVehicle(int _id, string _brand, string _model)
//            : id(_id), brand(_brand), model(_model) {}
//
//    void set_id(int id);
//
//    void set_brand(string _brand);
//
//    void set_model(string _model);
//
//    int const get_id();
//
//    string const get_brand();
//
//    string const get_model();
//
//    //Implement the methods from the abstract class
//    void displayInfo() override {
//        cout << "ID: " << id << endl;
//        cout << "Brand: " << brand << endl;
//        cout << "Model: " << model << endl;
//    }
//
//    void add_vehicle_component(VehicleComponent* vehicleComponent) override {
//        cout << "Cannot add vehicle component to a road vehicle" << endl;
//    }
//
//    void remove_vehicle_component(VehicleComponent* vehicleComponent) override {
//        cout << "Cannot remove vehicle component from a road vehicle" << endl;
//    }
//
//
//};
//
///* ------------------------------------------------- */
//
//class Truck : public RoadVehicle {
//private:
//    int totalWeight;
//    string name;
//
//public:
//    Truck(int _id, string _brand, string _model, int _totalWeight, string _name)
//            : RoadVehicle(_id, _brand, _model), totalWeight(_totalWeight), name(_name) {}
//
//    Truck load(int totalWeight);
//
//    Truck unload(int totalWeight);
//};
//
///* ------------------------------------------------- */
//
//class Car : public RoadVehicle {
//private:
//    string additionals;
//
//public:
//    Car(int _id, string _brand, string _model, string _additionals)
//            : RoadVehicle(_id, _brand, _model), additionals(_additionals) {}
//
//    void set_additionals(string _additionals);
//
//    string get_additionals();
//};
//
//class TransporterTruck : public RoadVehicle {
//private:
//    int capacity;
//    vector <RoadVehicle::add_vehicle_component()
//
//    //add method that loads cars into the transporter truck
//
//public:
//
//    //Constructor
//    TransporterTruck(int _id, string _brand, string _model, int _capacity)
//            : RoadVehicle(_id, _brand, _model), capacity(_capacity) {}
//
//    //add method that loads cars into the transporter truck
//
//    void add_car(Car* car) {
//        if(cars.size() < capacity) {
//            cars.push_back(car);
//            cout << "Car with ID: " << car->get_id() << " " << "has been successfully added to the transporter truck"
//                 << endl;
//        } else {
//            cout << "The transporter truck is full!";
//        }
//
//    }
//
//    void remove_car(Car* car) {
//        auto iterator = find(cars.begin(), cars.end(), car);
//
//        if(iterator != cars.end()) {
//            cars.erase(iterator);
//            cout << "Car with ID: " << car->get_id() << " " << "has been successfully removed from the transporter truck"
//                 << endl;
//        } else {
//            cout << "Car with ID: " << car->get_id() << " " << "is not in the transporter truck" << endl;
//        }
//    }
//
//};

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class VehicleComponent {
public:
    virtual void addVehicle(VehicleComponent* vehicle) = 0;
    virtual void removeVehicle(VehicleComponent* vehicle) = 0;
    virtual void displayInfo() = 0;
};

class RoadVehicle : public VehicleComponent {
private:
    int id;
    string brand;
    string model;

public:
    RoadVehicle(int _id, string _brand, string _model)
            : id(_id), brand(_brand), model(_model) {}

    void set_id(int id);
    void set_brand(string _brand);
    void set_model(string _model);
    int const get_id();
    string const get_brand();
    string const get_model();

    // Implement the VehicleComponent interface
    void addVehicle(VehicleComponent* vehicle) {}
    void removeVehicle(VehicleComponent* vehicle) {}
    void displayInfo();
};

void RoadVehicle::displayInfo() {
    cout << "ID: " << id << ", Brand: " << brand << ", Model: " << model << endl;
}

class Truck : public RoadVehicle {
private:
    int totalWeight;
    string name;

public:
    Truck(int _id, string _brand, string _model, int _totalWeight, string _name)
            : RoadVehicle(_id, _brand, _model), totalWeight(_totalWeight), name(_name) {}
};

class Car : public RoadVehicle {
private:
    string additionals;

public:
    Car(int _id, string _brand, string _model, string _additionals)
            : RoadVehicle(_id, _brand, _model), additionals(_additionals) {}
};

class TransporterTruck : public RoadVehicle {
private:
    int capacity;
    vector<VehicleComponent*> vehicles;

public:
    TransporterTruck(int _id, string _brand, string _model, int _capacity)
            : RoadVehicle(_id, _brand, _model), capacity(_capacity) {}

    void addVehicle(VehicleComponent* vehicle);
    void removeVehicle(VehicleComponent* vehicle);
    void displayInfo();
};

void TransporterTruck::addVehicle(VehicleComponent* vehicle) {
    if (vehicles.size() < capacity) {
        vehicles.push_back(vehicle);
        cout << "Vehicle added to the transporter truck." << endl;
    } else {
        cout << "Transporter truck is already at full capacity." << endl;
    }
}

void TransporterTruck::removeVehicle(VehicleComponent* vehicle) {
    auto it = find(vehicles.begin(), vehicles.end(), vehicle);
    if (it != vehicles.end()) {
        vehicles.erase(it);
        cout << "Vehicle removed from the transporter truck." << endl;
    } else {
        cout << "Vehicle is not loaded on the transporter truck." << endl;
    }
}

void TransporterTruck::displayInfo() {
    RoadVehicle::displayInfo();
    cout << "Transported vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
    }
}

int main() {
    Car car1(1, "Brand1", "Model1", "Additional1");
    Car car2(2, "Brand2", "Model2", "Additional2");
    Car car3(3, "Brand3", "Model3", "Additional3");

    TransporterTruck truck(1, "TruckBrand", "TruckModel", 2);
    truck.addVehicle(&car1);
    truck.addVehicle(&car2);
    truck.addVehicle(&car3);

    truck.displayInfo();

    return 0;
}
