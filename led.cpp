#include "led.h"

LED::LED(const std::string& port) : portName(port) {
    file.open("/home/data.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open data file");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
LED::~LED() {
    file.close();
}

void LED::processUserInput(double choice) {
    std::vector<uint8_t> data;
    std::string line;
    while (std::getline(file, line)) {
        size_t colonPos = line.find(':');
        std::string label = line.substr(0, colonPos);
        std::string hexData = line.substr(colonPos + 1);

        if ((label == "ON" && choice == 1) ||
            (label == "OFF" && choice == 2) ||
            (label == "GAIN1" && choice == 3) ||
            (label == "GAIN2" && choice == 4) ||
            (label == "GAIN3" && choice ==5) ||
            (label == "GAIN4" && choice == 6) ||
            (label == "GAIN5" && choice == 7) ||
            (label == "GAIN6" && choice == 8) ||
            (label == "GAIN7" && choice == 9) ||
            (label == "GAIN8" && choice == 10) ||
            (label == "GAIN9" && choice == 11) ||
            (label == "GAIN10" && choice == 12) ||
            (label == "GAIN11" && choice == 13) ||
            (label == "GAIN12" && choice == 14) ||
            (label == "GAIN13" && choice == 15) ||
            (label == "GAIN14" && choice == 16) ||
            (label == "GAIN15" && choice == 17) ||
            (label == "GAIN16" && choice == 18) ||
            (label == "GAIN17" && choice == 19) ||
            (label == "GAIN18" && choice == 20) ||
            (label == "GAIN19" && choice == 21) ||
            (label == "GAIN20" && choice == 22) ||
            (label == "GAIN21" && choice == 23) ||
            (label == "GAIN22" && choice == 24) ||
            (label == "GAIN23" && choice == 25) ||
            (label == "GAIN24" && choice == 26) ||
            (label == "GAIN25" && choice == 27) ||
            (label == "GAIN26" && choice == 28) ||
            (label == "GAIN27" && choice == 29) ) {
                    data = hexStringToBytes(hexData);
                    std::string res = bytesToHexString(data);
                    std::cout << "Data for choice " << choice << ": " << res << std::endl;
                    writeToSerialPort(data);
        }
    }

    file.clear(); // Clear any error flags
    file.seekg(0, std::ios::beg); // Reset file pointer to the beginning
}

void LED::writeToSerialPort(const std::vector<uint8_t>& data) {
    int serial_port = open(portName.c_str(), O_RDWR);
    if (serial_port == -1) {
        std::cerr << "Error: Unable to open serial port" << std::endl;
        return;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(serial_port, &tty) != 0) {
        std::cerr << "Error: Unable to get serial port attributes" << std::endl;
        close(serial_port);
        return;
    }

    tty.c_cflag &= ~PARENB; // Disable parity
    tty.c_cflag &= ~CSTOPB; // One stop bit
    tty.c_cflag &= ~CSIZE;  // Clear data size bits
    tty.c_cflag |= CS8;     // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS;// Disable hardware flow control

    tty.c_cc[VMIN] = 1;     // Minimum number of characters to read
    tty.c_cc[VTIME] = 5;    // Time to wait for data (tenths of a second)

    cfsetospeed(&tty, B115200); // Set baud rate

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        std::cerr << "Error: Unable to set serial port attributes" << std::endl;
        close(serial_port);
        return;
    }

    ssize_t bytes_written = write(serial_port, data.data(), data.size());
    if (bytes_written < 0) {
        std::cerr << "Error writing to serial port" << std::endl;
        close(serial_port);
        return;
    }

    std::cout << "Data sent to serial port successfully." << std::endl;

    close(serial_port);
}

std::vector<uint8_t> LED::hexStringToBytes(const std::string& hex) {
    std::istringstream iss(hex);
    std::vector<uint8_t> bytes;

    std::string byteString;
    while (iss >> byteString) {
        if (byteString.size() != 4) {
            throw std::invalid_argument("Invalid hex string format");
        }
        if (byteString.substr(0, 2) != "0x") {
            throw std::invalid_argument("Invalid hex string format");
        }
        try {
            uint8_t byte = static_cast<uint8_t>(std::stoul(byteString.substr(2), nullptr, 16));
            bytes.push_back(byte);
        } catch (const std::exception& e) {
            throw std::invalid_argument("Invalid hex string format");
        }
    }

    return bytes;
}

std::string LED::bytesToHexString(const std::vector<uint8_t>& bytes) {
    std::ostringstream oss;
    oss << "{";
    for (size_t i = 0; i < bytes.size(); ++i) {
        oss << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        if (i != bytes.size() - 1)
            oss << ", ";
    }
    oss << "}";
    return oss.str();
}
