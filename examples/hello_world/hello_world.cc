#include <iostream>
#include "examples/hello_world/example_texts.h"

int main()
{
    std::cout << examples::hello_world::example1_txt() << "\n";
    std::cout << examples::hello_world::example2_txt() << "\n";
    return 0;
}
