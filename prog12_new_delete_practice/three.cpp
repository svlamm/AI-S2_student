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
    Enemy* child;
    explicit Enemy(const int h ,const char* _n) : health(h) {
        // In de opdracht memory management (PROG VI) wordt strdup gebruikt, dit vereist een deletion mbv free ipv del
        // Strdup doet wel een allocatie, maar niet via new, dus voor het kunnen tellen van allocaties dmv het overriden van new gebruiken we hier een andere vorm
        name = new char[strlen(_n) + 1];
        strcpy(name, _n);
        child = nullptr;
    }
    ~Enemy() {
        s_deletions_count++; // count+1 for deletion of Enemy object itself
    }

    void set_child(int hp, const char* n) {
        child = new Enemy(hp, n);
    }
};

std::ostream& operator<<(std::ostream& os, const Enemy* e) {
    os << "Enemy: " << e->name << " (" << e->health << "HP)" << std::endl;
    Enemy* child = e->child;
    if (child) {
        std::cout << "     child: " << child;
        child = child->child;
    }
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
    for (int i = 0; i < nr_enemies; i++) {
        if (i%buddy_occurrence == 0) {
            const char name[5] {'B', 'e', 'e', char('0' + i/buddy_occurrence), '\0'};
            enemies[i]->set_child(50, name);
            if (i%buddy_buddy_occ == 0) {
                const char name2[5] {'C', 'a', 't', char('0' + i/buddy_buddy_occ), '\0'};
                enemies[i]->child->set_child(25, name2);
            }
        }
    }

    std::cout << "Before deletion" << std::endl;
    enemies_print(enemies, nr_enemies);

    std::cout << s_allocations_count << " allocations." << std::endl;
    std::cout << s_deletions_count << " deletions." << std::endl;
}
