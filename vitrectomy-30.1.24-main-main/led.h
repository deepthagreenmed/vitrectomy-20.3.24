#ifndef LED_H
#define LED_H

#include <iostream>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

#define PORT1 "/dev/ttyUL1"
#define PORT2 "/dev/ttyUL2"

class LED {
public:
    LED(const std::string& port);
    ~LED();
    void processUserInput(double choice);
    void writeToSerialPort(const std::vector<uint8_t>& data);
    std::vector<uint8_t> hexStringToBytes(const std::string& hex);
    std::string bytesToHexString(const std::vector<uint8_t>& bytes);

private:
    std::string portName;
    std::ifstream file;

};


#endif // LED_H
