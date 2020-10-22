#include <iostream>

using namespace std;

int main() {
    //магический квадрат 3x3 (для него существует только один ключ)

    string message, new_message;
    int iteration_9;
    int magic_3x3[3][3] = {
            2, 7, 6,
            9, 5, 1,
            4, 3, 8
    };

    cout << "Введите сообщение:" << endl;
    getline(cin, message, '\n');

    bool choose;
    cout << "Выберите, что вы хотите сделать:\n" << "0 - зашифровать\n1 - дешифровать" << endl;
    cin >> choose;

    int count_message = 0;

    if ((message.size() % 9) == 0)
        iteration_9 = (message.size() / 9);
    else iteration_9 = (message.size() / 9) + 1;
//динамический массив этих матриц
    char real_cube[iteration_9][3][3];
    for (int k = 0; k < iteration_9; ++k) {
        count_message = 0;
        while (count_message < 9) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (choose == 0) {
                        if (magic_3x3[i][j] - 1 == (count_message)) {
                            if (static_cast<int>(message[count_message]) != 0)
                                if ((message[count_message + k * 9]) != ' ') {
                                    real_cube[k][i][j] = message[count_message + k * 9];
                                } else real_cube[k][i][j] = ' ';
                            else
                                real_cube[k][i][j] = ' ';
                            ++count_message;
                        }
                    }
                    else{
                        if (static_cast<int>(message[count_message]) != 0)
                            if ((message[count_message + k * 9]) != ' ') {
                                real_cube[k][i][j] = message[count_message + k * 9];
                            } else real_cube[k][i][j] = ' ';
                        else
                            real_cube[k][i][j] = ' ';
                        ++count_message;
                    }
                }
            }
        }
    }

    for (int i = 0; i < iteration_9; ++i) {
        cout << i << " магический квадрат" << endl;
        if (choose == 0) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cout << real_cube[i][j][k] << ' ';
                }
                cout << endl;
            }
        }
        else {
            cout << real_cube[i][1][2];
            cout << real_cube[i][0][0];
            cout << real_cube[i][2][1];
            cout << real_cube[i][2][0];
            cout << real_cube[i][1][1];
            cout << real_cube[i][0][2];
            cout << real_cube[i][0][1];
            cout << real_cube[i][2][2];
            cout << real_cube[i][1][0];
        }
    }

    //cout << "Введите ключ:" << endl;
    //cin >> key;

    return 0;
}
