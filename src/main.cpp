#include <iostream>
#include <memory>
#include "Map.h"

int main() {
    Map hello = new Map();

    // Add a territory : with its id, its name and the continent's id to which it belongs
    // Doing so, you can keep a reference to via the object returned from the add()
    std::shared_ptr<Territory> t1 = hello.add(Territory(0, "Canada", 0));
    std::shared_ptr<Territory> t2 = hello.add(Territory(1, "U.S.", 0));

    // Add a Continent : id and name only
    // Same for keeping a reference
    std::shared_ptr<Continent> c1 = hello.add(Continent(0, "America"));

    // You can add territories and Continents in any order, but you have to make sure that all territories map to an existing continent
    hello.add(Territory(2, "Mexico", 0));

    // Link two country's borders
    // Same for two continents
    hello.link(t1, t2);

    for (int b : t1->borders) {
        std::cout << b << std::endl;
    }

    for (int b : t2->borders) {
        std::cout << b << std::endl;
    }

    // You can get the shared ptr to a territory or continent with
    // the methods findTerritory, findContinent, getTerritory, getContinent
    // the find ones look through all territories/continent and return
    // the first one with a corresponding name (linear)
    // the get ones return based on the id provided (constant time)
    std::shared_ptr<Territory> p = hello.findTerritory("Mexico");
    p->units = 1;

    // Map has a to_string method
    // Same for Territory's and Continent's
    std::cout << hello.to_string() << std::endl;

    // Release a shared ptr
    p.reset(new Territory(*p.get()));

    // Validate will fail and throw if:
    // some territories belong to a non-existing continent
    // some continents dont have any territories
    // TODO: finish this validate
    if (hello.validate()) {
        // start game
    }
}