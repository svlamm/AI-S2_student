#include <array>
#include <iostream>
#include <string.h>
#include <vector>

static int s_allocations_count  = 0;
static int s_deletions_count    = 0;

void* operator new(size_t size){
    s_allocations_count++;
    return malloc(size);
}

void* operator new[](size_t size) {
    s_allocations_count++;
    return malloc(size);
}

void operator delete[](void* ptr){
    if (ptr) {
        s_deletions_count++;
        free(ptr);  
    }
}

void operator delete(void* ptr){
    if (ptr) {
        s_deletions_count++;
        free(ptr); 
    }
}

// oefening 0: alleen obj
// oefening 1: met char*
// oefening 2: met child
struct Enemy {
    int health;
    char* name;
    explicit Enemy(const int h ,const char* _n) : health(h) {
        // In de opdracht memory management (PROG VI) wordt strdup gebruikt, dit vereist een deletion mbv free ipv del
        // Strdup doet wel een allocatie, maar niet via new, dus voor het kunnen tellen van allocaties dmv het overriden van new gebruiken we hier een andere vorm
        name = new char[strlen(_n) + 1];
        strcpy(name, _n);
    }
    ~Enemy() {
        s_deletions_count++; // count+1 for deletion of Enemy object itself
    }
};

std::ostream& operator<<(std::ostream& os, const Enemy* e) {
    os << "Enemy: " << e->name << " (" << e->health << "HP)" << std::endl;
    return os;
}

void enemies_print(Enemy** enemies, size_t nr_enemies)  {
    for (int i = 0; i < nr_enemies; i++) {
        std::cout << enemies[i];
    }
}
int main() {
    constexpr size_t    nr_enemies          = 40;
    constexpr size_t    buddy_occurrence    = 5;
    constexpr size_t    buddy_buddy_occ     = 20;

    Enemy** enemies = new Enemy*[nr_enemies]{};
    for (int i = 0; i < nr_enemies; i++) {
        char name[5] = {'G', 'i', 'n', char('0' + i), '\0'};
        enemies[i] = new Enemy(100, name);
    }


    std::cout << "Before deletion" << std::endl;
    enemies_print(enemies, nr_enemies);

    std::cout << s_allocations_count << " allocations." << std::endl;
    std::cout << s_deletions_count << " deletions." << std::endl;
}
