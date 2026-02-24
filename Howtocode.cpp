#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

//================= โครงสร้างข้อมูล =================
struct TableOrder {
    vector<string> List;
    vector<int> Price;
    vector<int> Amount;
    int count = 0;
    int total = 0;
};

//================= Global variables =================
string food;
int Num;
int table = 0;
int price[10];
int menu;
int more;
int amount;
int check;

vector<TableOrder> tables;
vector<int> useTable;

//================= prototypes =================
void home();
void employ();
void menuu();
void customer();
int moree();
void selectTable();
void showBill();
void Host();
void summarize();
void checktable();
void Bestselling();
void payslip(int tableID);
void backtohome();
void viewSavedData();
void saveData();
void loadData();
void resetData();
void manageTables();
int Helpercode(int min, int max);

//============================================

void home() {
    cout << "\n============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|          >>> RESTAURANT MANAGEMENT SYSTEM <<<            |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|   (1) CUSTOMER                                           |" << endl;
    cout << "|   (2) EMPLOYEE                                           |" << endl;
    cout << "|   (3) HOST / ADMIN                                       |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|   (0) EXIT                                               |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;
    cout << "SELECT OPTION >> ";
    cin >> Num;
}

void backtohome() {
    cout << endl;
    cout << ">>> [0] BACK TO HOME <<<" << endl;
    cout << ">>> [9] CHANGE TABLE <<< " << endl;
    cout << "SELECT OPTION >> ";
}

void selectTable() {
    while (true) {
        cout << endl << endl;
        cout << "================== SELECT TABLE ==================" << endl;

        for (int i = 1; i < tables.size(); i++) {
            cout << "  (" << i << ") TABLE " << i << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << " [0] BACK TO HOME " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "CHOOSE YOUR TABLE >> ";

        if (!(cin >> table)) {
            cout << "\n---------- PLEASE ENTER NUMBERS ONLY ----------" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (table >= 1 && table < tables.size()) {
            useTable[table]++;
            break;
        }
        else if (table == 0) {
            break;
        }
        else {
            cout << "\n---------- INVALID TABLE NUMBER ----------" << endl;
        }
    }
}

void customer() {
    while (true) {
        if (table == 0) {
            selectTable();
            if (table == 0) return;
        }

        cout << endl << endl << endl;
        cout << "========================================" << endl;
        cout << "            ORDER CATEGORIES            " << endl;
        cout << "========================================" << endl;
        cout << "[1] RECOMMENDED MENU " << endl;
        cout << "[2] MAIN COURSES" << endl;
        cout << "[3] BEVERAGES" << endl;
        cout << "[4] DESSERTS" << endl;
        cout << "----------------------------------------" << endl;
        cout << "[0] HOME     |   [9] CHANGE TABLE " << endl;
        cout << "----------------------------------------" << endl;
        cout << "SELECT MENU >> ";

        if (!(cin >> menu)) {
            cout << ">>> INVALID INPUT! <<<" << endl;
            cin.clear(); cin.ignore(1000, '\n'); continue;
        }

        if (menu == 0) {
            return;
        }
        if (menu == 9) {
            table = 0; continue;
        }

        if (menu >= 1 && menu <= 4) {
            menuu();
            cout << "AMOUNT >> ";
            while (!(cin >> amount) || amount <= 0) {
                cout << "INVALID AMOUNT! : ";
                cin.clear(); cin.ignore(1000, '\n');
            }

            tables[table].List.push_back(food);
            tables[table].Price.push_back(price[menu]);
            tables[table].Amount.push_back(amount);
            tables[table].total += (price[menu] * amount);
            tables[table].count++;

            cout << endl;
            cout << ">> ADDED : " << food << " x" << amount << " - " << (price[menu] * amount) << " BAHT <<" << endl;
        }
        else {
            cout << ">>> INVALID CATEGORY! <<<" << endl;
            continue;
        }

        if (moree() == 0) return;
    }
}

void menuu() {
    int item, size;

    if (menu == 1) { // หมวด RECOMMENDED
        cout << "\n\n";
        cout << "\n\n\n==================== RECOMMENDED ====================" << endl;
        cout << " 1) SPICY TOM YUM GOONG SOUP WITH RICE   80/85 BTH" << endl;
        cout << " 2) MANGO STICKY RICE                    50/55 BTH" << endl;
        cout << " 3) SOM TAM THAI                         50/60 BTH" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "SELECT MENU (1-3) >> ";
        item = Helpercode(1, 3);

        if (item == 1) {
            food = "SPICY TOM YUM GOONG SOUP WITH RICE";
            cout << "SELECT SIZE (1) NORMAL 80 / (2) EXTRA 85 >> ";
            size = Helpercode(1, 2);
            if (size == 1) {
                price[menu] = 80;
            }
            else {
                price[menu] = 85;
            }
        }
        else if (item == 2) {
            food = "MANGO STICKY RICE";
            cout << "SELECT SIZE (1) NORMAL 50 / (2) EXTRA 55 >> ";

            size = Helpercode(1, 2);
            if (size == 1) {
                price[menu] = 50;
            }
            else {
                price[menu] = 55;
            }
        }
        else { // item == 3
            food = "SOM TAM THAI";
            cout << "SELECT SIZE (1) NORMAL 50 / (2) EXTRA 60 >> ";
            size = Helpercode(1, 2);
            if (size == 1) {
                price[menu] = 50;
            }
            else {
                price[menu] = 60;
            }
        }
    }
    else if (menu == 2) { // หมวด MAIN COURSES
        cout << "\n\n\n========== MAIN COURSES ==========" << endl;
        cout << " 1) FRIED PORK RICE      30/35 BTH" << endl;
        cout << " 2) FRIED CHICKEN RICE   30/35 BTH" << endl;
        cout << "----------------------------------" << endl;
        cout << "SELECT MENU (1-2) >> ";

        item = Helpercode(1, 2);

        if (item == 1) {
            food = "FRIED PORK RICE";
        }
        else {
            food = "FRIED CHICKEN RICE";
        }

        cout << "SELECT SIZE (1) NORMAL 30 / (2) EXTRA 35 >> ";
        size = Helpercode(1, 2);
        if (size == 1) {
            price[menu] = 30;
        }
        else {
            price[menu] = 35;
        }
    }
    else if (menu == 3) { // หมวด BEVERAGES
        cout << "\n\n\n=============== BEVERAGES ===============" << endl;
        cout << " 1) WATER                         10 BTH " << endl;
        cout << " 2) SOFT DRINK                    20 BTH " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "SELECT MENU (1-2) >> ";


        item = Helpercode(1, 2);

        if (item == 1) {
            food = "WATER";
            price[menu] = 10;
        }
        else {
            food = "SOFT DRINK";
            price[menu] = 20;
        }
    }
    else if (menu == 4) { // หมวด DESSERTS
        cout << "\n\n\n================ DESSERTS ===============" << endl;
        cout << " 1) ICE CREAM                     15 BTH" << endl;
        cout << " 2) CAKE                          30 BTH" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "SELECT MENU (1-2) >> ";

        item = Helpercode(1, 2);

        if (item == 1) {
            food = "ICE CREAM";
            price[menu] = 15;
        }
        else {
            food = "CAKE";
            price[menu] = 30;
        }
    }
}
int moree() {
    while (true) {
        cout << "\nMORE ORDER? (1) YES / (2) NO" << endl;
        backtohome();
        cin >> more;
        if (more == 1) return 1;
        if (more == 2) {
            showBill();
            return 0;
        }
        if (more == 0) return 0;
        if (more == 9) {
            table = 0;
            return 1;
        }
    }
}

void showBill() {
    cout << "\n============ BILL SUMMARY (TABLE " << table << ") ===========" << endl;
    for (int i = 0; i < tables[table].count; i++) {
        cout << i + 1 << ". " << tables[table].List[i] << " x" << tables[table].Amount[i]
            << " = " << tables[table].Price[i] * tables[table].Amount[i] << " BAHT" << endl;
    }
    cout << "TOTAL PRICE : " << tables[table].total << " BAHT" << endl;
    cout << "-------------------------------------\n" << endl;
}

void employ() {
    while (true) {
        int cep;
        cout << "--------EMPLOYEE MENU ---------" << endl;
        cout << "1.Check Table Status" << endl;
        cout << "2." << endl;
        cout << "0.Back" << endl;
        cout << "SELECT >> ";
        cin >> cep;
        if (cep == 1) {
            cout << "\n====================================================================\n";
            cout << "                       TABLE STATUS DASHBOARD                       \n";
            cout << "====================================================================\n";

            cout << left << setw(8) << "TABLE"
                << setw(20) << "STATUS"
                << setw(12) << "ORDERS"
                << setw(15) << "TOTAL(BAHT)"
                << endl;

            cout << "--------------------------------------------------------------------\n";

            for (int i = 1; i < tables.size(); i++) {
                string status;
                // เช็กสถานะ 3 แบบ: จอง / ไม่ว่าง / ว่าง
                if (tables[i].total == -1) status = "RESERVED";
                else if (tables[i].count > 0) status = "NOT AVAILABLE";
                else status = "AVAILABLE";

                cout << left << setw(8) << i
                    << setw(20) << status
                    << setw(12) << (tables[i].total == -1 ? "-" : to_string(tables[i].count))
                    << right << setw(10) << (tables[i].total == -1 ? "-" : to_string(tables[i].total))
                    << endl;
            }

            cout << "--------------------------------------------------------------------\n";
            cout << "SELECT TABLE TO MANAGE (0 = BACK) >> ";

            cin >> check;

            if (check == 0) return;

            if (check < 1 || check >= tables.size()) {
                cout << "\n!!! INVALID TABLE NUMBER !!!\n";
                continue;
            }

            // --- กรณีโต๊ะว่าง: ให้เลือกว่าจะ "จอง" หรือไม่ ---
            if (tables[check].count == 0 && tables[check].total != -1) {
                cout << "\nTable " << check << " is Empty.\n";
                cout << "1. Reserve Table (For Booking)\n0. Back\nSelect >> ";
                int reserve; cin >> reserve;
                if (reserve == 1) {
                    tables[check].total = -1;
                    cout << "\n>>> TABLE " << check << " RESERVED SUCCESSFULLY <<<\n";
                }
            }
            // --- กรณีโต๊ะโดนจอง: ให้เลือกว่าจะ "ยกเลิกการจอง" หรือไม่ ---
            else if (tables[check].total == -1) {
                cout << "\n!!! TABLE " << check << " IS CURRENTLY RESERVED !!!\n";
                cout << "1. Unreserve (Cancel Booking)\n0. Back\nSelect >> ";
                int unreserve; cin >> unreserve;
                if (unreserve == 1) {
                    tables[check].total = 0;
                    cout << "\n>>> TABLE " << check << " IS NOW AVAILABLE <<<\n";
                }
            }
            // --- กรณีโต๊ะมีออเดอร์: แสดงรายละเอียดและถามเรื่องเคลียร์โต๊ะ ---
            else if (tables[check].count > 0) {
                cout << "\nTABLE " << check << " DETAILS :\n";
                cout << left << setw(5) << "No"
                    << setw(20) << "Item"
                    << setw(10) << "Price"
                    << setw(8) << "Qty"
                    << setw(12) << "Subtotal"
                    << endl;

                cout << "---------------------------------------------------------------\n";

                for (int i = 0; i < tables[check].count; i++) {
                    cout << left << setw(5) << i + 1
                        << setw(20) << tables[check].List[i]
                        << setw(10) << tables[check].Price[i]
                        << setw(8) << tables[check].Amount[i]
                        << setw(12) << tables[check].Price[i] * tables[check].Amount[i] << endl;
                }

                cout << "---------------------------------------------------------------\n";
                cout << right << setw(50) << "TOTAL : "
                    << tables[check].total << " BAHT\n";

                cout << "\nCLEAR TABLE? (1 = YES / 0 = NO) >> ";

                int clear;
                cin >> clear;

                if (clear == 1) {
                    tables[check].List.clear();
                    tables[check].Price.clear();
                    tables[check].Amount.clear();
                    tables[check].count = 0;
                    tables[check].total = 0;
                    cout << "\n>>> TABLE CLEARED SUCCESSFULLY <<<\n";
                }
            }
        }
    }
}


void Host() {
    int choose;
    while (true) {
        cout << "\n\n";
        cout << "==================================================\n";
        cout << "                 HOST CONTROL PANEL               \n";
        cout << "==================================================\n";
        cout << "  [1] SUMMARY\n";
        cout << "  [2] TABLE USAGE\n";
        cout << "  [3] BEST SELLING MENU\n";
        cout << "  [4] DAILY PAYSLIP REPORT\n";
        cout << "  [5] VIEW SAVED DATA\n";
        cout << "  [6] SAVE & RESET ALL DATA\n";
        cout << "  [8] RESETDATA\n";
        cout << "--------------------------------------------------\n";
        cout << "  [0] BACK TO MAIN MENU\n";
        cout << "==================================================\n";
        cout << "SELECT OPTION >> ";
        cin >> choose;

        if (choose == 0) return;
        else if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 3) Bestselling();
        else if (choose == 4) {
            int tableID;
            cout << "ENTER TABLE ID: ";
            cin >> tableID;
            if (tableID >= 1 && tableID < tables.size()) payslip(tableID);
            else cout << "INVALID ID!" << endl;
        }
        else if (choose == 5) viewSavedData();
        else if (choose == 6) {
            saveData();
            cout << ">>> DATA SAVED <<<" << endl;
        }
        else if (choose == 7) manageTables();
        else if (choose == 8) resetData();
    }
}

void summarize() {
    int grand = 0;
    for (int i = 1; i < tables.size(); i++) grand += tables[i].total;
    cout << "\nTOTAL REVENUE : " << grand << " Baht" << endl;
}

void checktable() {
    for (int i = 1; i < tables.size(); i++)
        cout << "Table " << i << " used " << useTable[i] << " times" << endl;
}

void Bestselling() {

    if (tables.size() == 0) {
        cout << "No data\n";
        return;
    }

    vector<string> name;
    vector<int> totalQty;

    // วนทุกโต๊ะ
    for (int t = 1; t <= 5; t++) {

        // วนทุก order ในโต๊ะ
        for (int i = 0; i < tables[t].count; i++) {

            string item = tables[t].List[i];
            int qty = tables[t].Amount[i];

            bool found = false;

            // เช็คว่าเคยมีใน list หรือยัง
            for (int j = 0; j < name.size(); j++) {

                if (name[j] == item) {

                    totalQty[j] += qty;
                    found = true;
                    break;
                }
            }

            // ถ้ายังไม่เคยมี
            if (!found) {

                name.push_back(item);
                totalQty.push_back(qty);

            }
        }
    }

    // หาเมนูขายดีที่สุด
    if (name.size() == 0) {
        cout << "No orders yet\n";
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < totalQty.size(); i++) {

        if (totalQty[i] > totalQty[maxIndex]) {

            maxIndex = i;

        }
    }

    cout << "\n===== BEST SELLING MENU =====\n";

    cout << name[maxIndex]
        << " | Sold: "
        << totalQty[maxIndex]
        << endl;
}

void payslip(int tableID) {
    if (tables[tableID].count == 0) { cout << "No orders!" << endl; return; }
    double cash;
    cout << "TOTAL: " << tables[tableID].total << " | CASH: "; cin >> cash;
    cout << "\n--- RECEIPT TABLE " << tableID << " ---\nTotal: " << tables[tableID].total << "\nChange: " << (cash - tables[tableID].total) << endl;
}

void manageTables() {
    int choice;
    cout << "\n--- TABLE MANAGEMENT ---\n1. Add 1 Table | 2. Remove Last | 0. Back\nSELECT >> ";
    cin >> choice;
    if (choice == 1) {
        tables.push_back(TableOrder());
        useTable.push_back(0);
        cout << ">>> ADDED TABLE " << tables.size() - 1 << " <<<" << endl;
    }
    else if (choice == 2 && tables.size() > 2) {
        if (tables.back().count == 0) {
            tables.pop_back(); useTable.pop_back();
            cout << ">>> REMOVED LAST TABLE <<<" << endl;
        }
        else cout << "!!! CANNOT REMOVE: TABLE NOT EMPTY !!!" << endl;
    }
}

int Helpercode(int min, int max) {
    int input;
    while (!(cin >> input) || input < min || input > max) {
        cout << "Invalid! Enter " << min << "-" << max << " >> ";
        cin.clear(); cin.ignore(1000, '\n');
    }
    return input;
}

//================ JSON ================

void saveData() {
    json j;
    for (int i = 1; i < tables.size(); i++) {
        j["useTable"][to_string(i)] = useTable[i];
        json tJ;
        tJ["count"] = tables[i].count;
        tJ["total"] = tables[i].total;
        for (int k = 0; k < tables[i].count; k++) {
            tJ["orders"].push_back({ {"item", tables[i].List[k]}, {"price", tables[i].Price[k]}, {"qty", tables[i].Amount[k]} });
        }
        j["tables"][to_string(i)] = tJ;
    }
    ofstream file("database.json");
    file << j.dump(4);
}

void loadData() {
    ifstream file("database.json");
    if (!file.is_open()) {
        tables.resize(6); // เริ่มต้น 5 โต๊ะ
        useTable.assign(6, 0);
        return;
    }
    json j; file >> j;
    int savedTableCount = j["tables"].size();
    tables.resize(savedTableCount + 1);
    useTable.resize(savedTableCount + 1);
    for (int i = 1; i < tables.size(); i++) {
        string s = to_string(i);
        useTable[i] = j["useTable"].value(s, 0);
        if (j["tables"].contains(s)) {
            tables[i].count = j["tables"][s].value("count", 0);
            tables[i].total = j["tables"][s].value("total", 0);
            for (auto& o : j["tables"][s]["orders"]) {
                tables[i].List.push_back(o.value("item", ""));
                tables[i].Price.push_back(o.value("price", 0));
                tables[i].Amount.push_back(o.value("qty", 0));
            }
        }
    }
}

void viewSavedData() {
    cout << "--- CURRENT SYSTEM DATA ---" << endl;
    summarize();
    checktable();
}
void resetData() {
    int confirm;
    cout << "\n!!! WARNING: This will delete ALL current orders and history !!!" << endl;
    cout << "Are you sure you want to reset? (1.yes/2.no): ";
    cin >> confirm;

    if (confirm == 1) {
        // 1. ล้างข้อมูลใน Vector ของ tables และ useTable ใน RAM
        for (int i = 0; i < tables.size(); i++) {
            tables[i].List.clear();
            tables[i].Price.clear();
            tables[i].Amount.clear();
            tables[i].count = 0;
            tables[i].total = 0;
        }

        // 2. รีเซ็ตจำนวนครั้งที่ใช้โต๊ะเป็น 0
        fill(useTable.begin(), useTable.end(), 0);


        cout << ">>> ALL DATA HAS BEEN RESET <<<" << endl;
    }
    else if (confirm == 2) {
        cout << ">>> RESET CANCELLED <<<" << endl;
    }
    else {
        cout << ">>> INVALID INPUT <<<" << endl;
    }
}

int main() {
    loadData();
    while (true) {
        home();
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (Num == 0) {
            saveData();
            return 0;
        }
        if (Num == 1) {
            table = 0;
            customer();
        }
        else if (Num == 2) {
            string pass;
            cout << "Password: ";
            cin >> pass;

            if (pass == "555") employ();

        }
        else if (Num == 3) {
            string pass;
            cout << "Password: ";
            cin >> pass;

            if (pass == "999") Host();

        }
        else cout << "Input valid error" << endl;
    }
}
