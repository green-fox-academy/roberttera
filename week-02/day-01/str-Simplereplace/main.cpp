#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string example("In a dishwasher far far away");

    std::string toReplace = "dishwasher";

    example.replace(example.find(toReplace), toReplace.length(), "galaxy");

    // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
    // Please fix it for me!
    // Expected output: In a galaxy far far away

    std::cout << example << std::endl;
    return 0;
}