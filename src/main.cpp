#include <iostream>
#include <fstream>
#include "person.pb.h"

int main() {
    // 创建一个 Person 对象
    Person person;
    person.set_name("Alice");
    person.set_id(1);
    person.set_email("alice@example.com");

    // 序列化为二进制数据并写入文件
    std::ofstream output("person_data.bin", std::ios::out | std::ios::binary);
    if (!person.SerializeToOstream(&output)) {
        std::cerr << "Failed to write person data." << std::endl;
        return -1;
    }
    output.close();

    // 读取文件并反序列化
    Person person_from_data;
    std::ifstream input("person_data.bin", std::ios::in | std::ios::binary);
    if (!person_from_data.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse person data." << std::endl;
        return -1;
    }
    input.close();

    // 输出反序列化的结果
    std::cout << "Name: " << person_from_data.name() << std::endl;
    std::cout << "ID: " << person_from_data.id() << std::endl;
    std::cout << "Email: " << person_from_data.email() << std::endl;

    return 0;
}