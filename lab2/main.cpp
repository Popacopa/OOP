#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Friend {
    int a, b, index;
};

int main() {
    ifstream input("../input.txt");
    ofstream output("../output.txt");

    int n, a0;
    input >> n >> a0;

    vector<Friend> nonNegativeFriends, negativeFriends;

    for (int i = 1; i <= n; ++i) {
        int a, b;
        input >> a >> b;
        Friend f = {a, b, i};
        if (b >= 0) {
            nonNegativeFriends.push_back(f);
        } else {
            negativeFriends.push_back(f);
        }
    }

    // Сортируем друзей с b_i >= 0 по возрастанию a_i
    sort(nonNegativeFriends.begin(), nonNegativeFriends.end(), [](const Friend& f1, const Friend& f2) { 
        return f1.a < f2.a;
    });

    // Сортируем друзей с b_i < 0 по убыванию (a_i + b_i)
    sort(negativeFriends.begin(), negativeFriends.end(), [](const Friend& f1, const Friend& f2) {
        return (f1.a + f1.b) > (f2.a + f2.b);
    });

    vector<int> result;
    int currentAuthority = a0;

    // Обрабатываем сначала друзей с b_i >= 0
    for (const Friend &f : nonNegativeFriends) {
        if (currentAuthority >= f.a) {
            currentAuthority += f.b;
            result.push_back(f.index);
        }
    }

    // Затем обрабатываем друзей с b_i < 0
    for (const Friend &f : negativeFriends) {
        if (currentAuthority >= f.a) {
            currentAuthority += f.b;
            result.push_back(f.index);
        }
    }

    // Выводим результат в файл
    output << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) {
            output << " ";
        }
        output << result[i];
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}