#include <iostream>
#include "examples/hello_world/text/example_texts.h"

int main()
{
    std::cout << examples::hello_world::text::example1_txt() << "\n";
    std::cout << examples::hello_world::text::example2_txt() << "\n";
    return 0;
}
