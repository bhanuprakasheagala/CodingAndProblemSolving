#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int rollNo;
    std::string department;
};

int main() {

    std::ifstream file("students.txt");
    if(!file.is_open()) {
        std::cerr << "Error openint file " << file << '\n';
        return 1;
    }

    std::vector<Student> students;
    Student temp;

    // Read student records from the file
    while(file >> temp.name >> temp.rollNo >> temp.department) {
        students.push_back(temp);
    }

    file.close();

    int choice;
    std::string searchName;

    do {
        // Display Menu
        std::cout << "\nOptions: \n1. Merge Sort\n2. Quick Sort\n3. Binary Search\n4. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                mergeSort(students, 0, students.size()-1);
                
            }
        }
    }

    return 0;
}