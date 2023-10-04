#include <iostream> 
#include <cstring>
int main() {
    int sds;
    int message_length;
    int x = 0;
    char message[20];
    const char arr[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Используйте const для массива

    std::cout << "Выберите действие: 1 шифровка 2 дешифровка" << std::endl;
    std::cin >> sds;
    std::cout << "Введите длину сообщения" << std::endl;
    std::cin >> message_length;
    std::cout << "Введите сдвиг" << std::endl;
    std::cin >> x;
    std::cout << "Введите сообщение" << std::endl;
    std::cin.ignore(); // Очистка буфера перед считыванием строки
    std::cin.getline(message, sizeof(message)); // Считывание строки

    switch (sds) {
        case 1:
            for (int i = 0; i < strlen(message); ++i) {
                char c = message[i];
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    message[i] = base + ((c - base + x) % 26); // Шифрование
                }
            }

            std::cout << message << std::endl;
            break;

        case 2:
            for (int i = 0; i < strlen(message); i++) {
                char c = message[i];
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    message[i] = base + ((c - base - x + 26) % 26); // Дешифрование
                }
            }

            std::cout << message << std::endl;
            break;

        default:
            std::cout << "Error" << std::endl;
    }

    return 0;
}

