class Spreadsheet {
private:
    int _rows;
    std::vector<std::vector<int>> _data;

    std::pair<int, int> parseCell(const std::string& cell) {
        int col = cell[0] - 'A';
        int row = std::stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    int getTokenValue(const std::string& token) {
        if (std::isalpha(token[0])) {
            auto [row, col] = parseCell(token);
            if (row >= 0 && row < _rows && col >= 0 && col < 26)
                return _data[row][col];
            return 0;
        } else {
            return std::stoi(token);
        }
    }

public:
    Spreadsheet(int rows) : _rows(rows) {
        _data.resize(rows, std::vector<int>(26, 0));
    }

    void setCell(const std::string& cell, int value) {
        auto [row, col] = parseCell(cell);
        if (row >= 0 && row < _rows && col >= 0 && col < 26) {
            _data[row][col] = value;
        }
    }

    void resetCell(const std::string& cell) {
        auto [row, col] = parseCell(cell);
        if (row >= 0 && row < _rows && col >= 0 && col < 26) {
            _data[row][col] = 0;
        }
    }

    int getValue(const std::string& formula) {
        size_t opPos = formula.find('+');
        std::string token1 = formula.substr(1, opPos);
        std::string token2 = formula.substr(opPos + 1);
        return getTokenValue(token1) + getTokenValue(token2);
    }
};
