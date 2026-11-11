#include "mycomplex.h"

int main() {
    const Complex c(3, 4);
    return static_cast<int>(c.abs());
}
