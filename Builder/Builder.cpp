#include <iostream>

class House {
private:
    int room;
    int garage;
    int yard;

public:
    House(int room = 0, int garage = 0, int yard = 0)
        : room(room), garage(garage), yard(yard) {}

    int getRoom() const {
        return room;
    }

    void setRoom(int room_) {
        room = room_;
    }

    int getGarage() const {
        return garage;
    }

    void setGarage(int garage_) {
        garage = garage_;
    }

    int getYard() const {
        return yard;
    }

    void setYard(int yard_) {
        yard = yard_;
    }

    friend std::ostream& operator<<(std::ostream& os, const House& house) {
        os << "This is a house with " << house.getRoom() << " room, "
            << house.getGarage() << " garage, and " << house.getYard() << " yard.";
        return os;
    }
};

class IBuilderHouse {
public:
    virtual ~IBuilderHouse() = default;

    virtual void createNewHouse() = 0;
    virtual void buildRoom() = 0;
    virtual void buildGarage() = 0;
    virtual void buildYard() = 0;
    virtual House getHouse() = 0;
};

class ExpensiveHouseBuilder : public IBuilderHouse {
private:
    House house;

public:
    void createNewHouse() override {
        house = House();
    }

    void buildRoom() override {
        house.setRoom(5);
    }

    void buildGarage() override {
        house.setGarage(3);
    }

    void buildYard() override {
        house.setYard(1000);
    }

    House getHouse() override {
        return house;
    }
};

class CheapHouseBuilder : public IBuilderHouse {
private:
    House house;

public:
    void createNewHouse() override {
        house = House();
    }

    void buildRoom() override {
        house.setRoom(1);
    }

    void buildGarage() override {
        house.setGarage(0);
    }

    void buildYard() override {
        house.setYard(5);
    }

    House getHouse() override {
        return house;
    }
};

class HouseBuilderDirector {
public:
    void construct(IBuilderHouse& builder) {
        builder.createNewHouse();
        builder.buildRoom();
        builder.buildGarage();
        builder.buildYard();
    }
};

int main() {
    HouseBuilderDirector director;

    ExpensiveHouseBuilder expensiveBuilder;
    director.construct(expensiveBuilder);
    House expensiveHouse = expensiveBuilder.getHouse();
    std::cout << "Expensive House: " << expensiveHouse << std::endl;

    CheapHouseBuilder cheapBuilder;
    director.construct(cheapBuilder);
    House cheapHouse = cheapBuilder.getHouse();
    std::cout << "Cheap House: " << cheapHouse << std::endl;

    return 0;
}
