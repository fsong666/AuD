#include "steel.hpp"

int main () {
    for (int i = 0; i < 11; ++i) {
        SteelBar steelBar(i);
        steelBar.print_solution();
    }
    return 0;
}