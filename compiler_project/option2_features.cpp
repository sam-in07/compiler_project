void displayFIRSTFOLLOW() {
    cout << "\nFIRST sets:\n";
    for (auto nt : nonTerminals) {
        cout << "FIRST(" << nt << ") = ";
        printSet(FIRST[nt]);
        cout << "\n";
    }
    cout << "\nFOLLOW sets:\n";
    for (auto nt : nonTerminals) {
        cout << "FOLLOW(" << nt << ") = ";
        printSet(FOLLOW[nt]);
        cout << "\n";
    }
}

void displayParsingTable() {
    cout << "\nParsing Table:\n\t";
    vector<char> termList(terminals.begin(), terminals.end());
    termList.push_back('$');
    for (auto t : termList) cout << t << "\t";
    cout << "\n";

    for (auto nt : nonTerminals) {
        cout << nt << "\t";
        for (auto t : termList) {
            if (parsingTable[nt].count(t))
                cout << parsingTable[nt][t] << "\t";
            else
                cout << " \t";
        }
        cout << "\n";
    }
}

bool LL1Parse(const string &input) {
    string stack = "$";
    stack += productions.begin()->first; // Start symbol
    int ip = 0;
    string inp = input + "$";

    cout << "\nParsing Steps:\n";
    while (!stack.empty()) {
        char X = stack.back();
        char a = inp[ip];

        if (terminals.count(X) || X == '$') {
            if (X == a) {
                cout << "Match: " << X << "\n";
                stack.pop_back();
                ip++;
            } else {
                cout << "Error: Unexpected symbol " << a << "\n";
                return false;
            }
        } else if (nonTerminals.count(X)) {
            if (parsingTable[X].count(a)) {
                string prod = parsingTable[X][a];
                cout << X << " -> " << prod.substr(3) << "\n";
                stack.pop_back();
                string rhs = prod.substr(3);
                if (rhs != "#") {
                    for (int i = (int)rhs.size() - 1; i >= 0; i--) {
                        stack.push_back(rhs[i]);
                    }
                }
            } else {
                cout << "Error: No rule for " << X << " with input " << a << "\n";
                return false;
            }
        } else {
            cout << "Error: Invalid symbol " << X << " on stack\n";
            return false;
        }
    }

    if (ip == (int)inp.size()) {
        cout << "Input string accepted by LL(1) parser ✅\n";
        return true;
    }
    return false;
}

void runOption2() {
    productions.clear();
    nonTerminals.clear();
    terminals.clear();
    FIRST.clear();
    FOLLOW.clear();
    parsingTable.clear();

    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    cout << "Enter productions (example: E=TR):\n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        if (line.size() < 3 || line[1] != '=') {
            cout << "Invalid format. Try again.\n";
            i--;
            continue;
        }
        char nt = line[0];
        nonTerminals.insert(nt);
        string rhs = line.substr(2);
        size_t pos = 0, found;
        while ((found = rhs.find('|', pos)) != string::npos) {
            productions[nt].push_back(rhs.substr(pos, found - pos));
            pos = found + 1;
        }
        productions[nt].push_back(rhs.substr(pos));

        for (char c : rhs) {
            if (!isupper(c) && c != '#' && c != '(' && c != ')' && !isdigit(c))
                terminals.insert(c);
        }
    }

    computeFIRST();
    computeFOLLOW();

    displayFIRSTFOLLOW();

    buildParsingTable();
    displayParsingTable();

    cout << "\nEnter input string to parse: ";
    string input;
    getline(cin, input);

    LL1Parse(input);
}