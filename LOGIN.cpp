#include <iostream>
#include <vector>
using namespace std;

class Logger {
public:
    static void log(const string& message) {
        cout << "[LOG]: " << message << endl;
    }
};

class MaTran {
private:
    vector<vector<int>> data;

public:
    // Constructor
    MaTran(const vector<vector<int>>& input) : data(input) {}

    MaTran operator+(const MaTran& other) const {
        Logger::log("Cong ma tran: ");
        vector<vector<int>> result(data.size(), vector<int>(data[0].size(), 0));
        
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return MaTran(result);
    }

    MaTran operator-(const MaTran& other) const {
        Logger::log("Tru ma tran");
        vector<vector<int>> result(data.size(), vector<int>(data[0].size(), 0));

        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return MaTran(result);
    }

    MaTran operator*(const MaTran& other) const {
        Logger::log("Nhan ma tran: ");
        vector<vector<int>> result(data.size(), vector<int>(other.data[0].size(), 0));

        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return MaTran(result);
    }

    
    

    void print() const {
        for (const auto& row : data) {
            for (int element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Sử dụng ma trận và xem log
    MaTran matrix1({{1, 2}, {3, 4}});
    MaTran matrix2({{5, 6}, {7, 8}});
    
    Logger::log("MaTran 1:");
    matrix1.print();
    
    Logger::log("MaTran 2:");
    matrix2.print();

    MaTran result_add = matrix1 + matrix2;
    Logger::log("Ket qua phep cong:");
    result_add.print();

    MaTran result_sub = matrix1 - matrix2;
    Logger::log("Ket qua phep tru:");
    result_sub.print();

    MaTran result_mul = matrix1 * matrix2;
    Logger::log("Ket qua phep nhan:");
    result_mul.print();

   // Matrix result_div = matrix1 / matrix2;
    //Logger::log("Ket qua phep chia:");
    //result_div.print()

    return 0;
}