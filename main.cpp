#include <iostream>
#include <vector>

struct GPSCoordinate { //initialize the x and y coordinate values
    double x;
    double y;
};

int main() {
    GPSCoordinate *coordinates  = nullptr; //assign a pointer to a dynamically sized array
    int coordinateCount = 0; //a count for the # of stored coordinates

    int userInput;
    double x, y;
    int index;

    do {
        std::cout << "\nChoose an option:\n";
        std::cout << "1) Store a new location\n"; //introduction menu
        std::cout << "2) Remove a location\n";
        std::cout << "3) Show stored locations\n";
        std::cout << "4) Exit program\n";
        std::cin >> userInput;

        switch (userInput) {
            case 1: { //allocate memory and resize the array for each new coordinate
                auto *newCoordinates = new GPSCoordinate[coordinateCount + 1];
                for (int i = 0; i < coordinateCount; i++) {
                    newCoordinates[i] = coordinates[i];
                }
                delete[] coordinates; //deallocate old memory in order to save memory
                coordinates = newCoordinates;

                std::cout << "\nEnter X coordinate: "; //user inputs coordinates that are saved to memory
                std::cin >> x;
                std::cout << "Enter Y coordinate: ";
                std::cin >> y;

                coordinates[coordinateCount].x = x;
                coordinates[coordinateCount].y = y;
                coordinateCount++;

                std::cout << "\nLocation " << x << ", " << y << " has been stored.\n";
                break;
            }

            case 2: {
                std::cout << "The following locations are stored: \n";
                for (int i = 0; i < coordinateCount; i++) {
                    std::cout << i + 1 << ": " << coordinates[i].x << " " << coordinates[i].y << "\n";
                }

                std::cout << "\nWhich location do you want to remove? \n";

                std::cin >> index;
                index = index - 1;

                if (index >= 0 && index < coordinateCount) { // Store the values of the coordinate before erasing from memory
                    double deletedX = coordinates[index].x;
                    double deletedY = coordinates[index].y;

                    for (int i = index; i < coordinateCount - 1; i++) {
                        coordinates[i] = coordinates[i + 1];
                    }
                    coordinateCount--;

                    std::cout << "Location " << deletedX << ", " << deletedY << " has been removed from memory.\n"; // Print erased values
                } else {
                    std::cout << "There is no valid location in that index.\n";
                }
                break;
            }

            case 3: {
                std::cout << "\nThe following locations are stored: \n";
                for (int i = 0; i < coordinateCount; i++) {
                    std::cout << i + 1 << ": " << coordinates[i].x << " " << coordinates[i].y << "\n";
                }
                break;
            }

            case 4: {
                std::cout << "Exiting program.\n";
                break;
            }

            default:
                std::cout << "Invalid input. Try again.\n";
        }
    } while (userInput != 4);

    delete[] coordinates; // deallocate dynamic array

    return 0;
}