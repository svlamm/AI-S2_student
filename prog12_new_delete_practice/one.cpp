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

struct Enemy {
    int health;

    explicit Enemy(const int h ) : health(h) {    }

//    ~Enemy() {
//        s_deletions_count++; // count+1 for deletion of Enemy object itself
//    }

};

std::ostream& operator<<(std::ostream& os, const Enemy* e) {
    os << "Enemy: (" << e->health << "HP)" << std::endl;
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
        enemies[i] = new Enemy(100);
    }

    std::cout << "Before deletion" << std::endl;
    enemies_print(enemies, nr_enemies);

    std::cout << s_allocations_count << " allocations." << std::endl;
    std::cout << s_deletions_count << " deletions." << std::endl;
}
