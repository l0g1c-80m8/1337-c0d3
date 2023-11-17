//
// Created by Rutvik Patel on 11/17/23.
//

#ifndef INC_1337_C0D3_INCLUDE_H
#define INC_1337_C0D3_INCLUDE_H

#include <iostream>

#define assert_m(exp, msg) assert(((void)msg, exp))

template<typename ...Args>
void log(Args && ...args) {
    std::cout << "[INFO]: ";
    // logger with variadic template - https://stackoverflow.com/a/29326784
    (std::cout << ... << args);
    std::cout << std::endl << std::flush;
}

#endif //INC_1337_C0D3_INCLUDE_H
