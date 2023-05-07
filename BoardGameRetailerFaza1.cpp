#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <string>

using namespace std;



class Boardgame {
    string name;
    int min_players;
    int max_players;
    int duration;
    int price;
    int stock;
public:

    Boardgame()
    {
        name = "";
        min_players = 0;
        max_players = 0;
        duration = 0;
        price = 0;
        stock = 0;
    }

    Boardgame(const string &name, int min_players, int max_players, int duration, int price, int stock)
    {
        this->name = name;
        this->min_players = min_players;
        this->max_players = max_players;
        this->duration = duration;
        this->price = price;
        this->stock = stock;
    }

    Boardgame(const Boardgame& b)
    {
        this->name = b.name;
        this->min_players = b.min_players;
        this->max_players = b.max_players;
        this->duration = b.duration;
        this->price = b.price;
        this->stock = b.stock;
    }

    void decrease_stock()
    {
        this->stock = this->stock - 1;
    }

    string get_name() const
    {
        return this->name;
    }

    int get_price() const
    {
        return this->price;
    }

    int get_stock() const
    {
        return this->stock;
    }

    int get_duration() const
    {
        return this->duration;
    }

    int get_min_players() const
    {
        return this->min_players;
    }

    int get_max_players() const
    {
        return this->max_players;
    }

    Boardgame& operator=(const Boardgame& a)
    {
        if ( this != &a ) {
            this->name = a.name;
            this->min_players = a.min_players;
            this->max_players = a.max_players;
            this->duration = a.duration;
            this->price = a.price;
            this->stock = a.stock;
        }

        return *this;
    }

    friend istream& operator>>(istream& input, Boardgame& b) {

        string name;
        int min_players;
        int max_players;
        int duration;
        int price;
        int stock;
        cout << "Introdu numele jocului: ";
        input >> name;
        cout << "Introdu numarul minim de jucatori: ";
        input >> min_players;
        cout << "Introdu numarul maxim de jucatori: ";
        input >> max_players;
        cout << "Introdu durata jocului: ";
        input >> duration;
        cout << "Introdu pretul jocului: ";
        input >> price;
        cout << "Introdu stocul jocului: ";
        input >> stock;
        b.name = name;
        b.min_players = min_players;
        b.max_players = max_players;
        b.duration = duration;
        b.price = price;
        b.stock = stock;

        return input;
    }

};


using namespace std;

class ShoppingCart {
    vector<Boardgame> cart;

public:
    ShoppingCart()
    {
        cart.clear();
    }

    void add_to_cart(const Boardgame & boardgame) {
        cart.push_back(boardgame);
    }

    void remove_from_cart(int index) {
        if (index >= 0 && index < cart.size())
        {
            cart.erase(cart.begin() + index);
        }
        else {
            cout << "Index invalid" << endl;
        }
    }

    void print_cart() const{
        int total = 0;
        cout << "//////////////////////////" << endl;
        for (int i = 0; i < cart.size(); i++)
        {
            cout << i << ". " << cart[i].get_name() << " " << cart[i].get_price() << endl;
            total += cart[i].get_price();
        }
        if (cart.size() == 0)
        {
            cout << "Cosul este gol" << endl;
            cout << "//////////////////////////" << endl;
        }
        else
        {
            cout << "Totalul este: " << total << endl;
            cout << "//////////////////////////" << endl;
        }
    }

    int get_cart_total() const {
        int total = 0;
        for (int i = 0; i < cart.size(); i++)
        {
            total += cart[i].get_price();
        }
        return total;
    }

    int get_cart_size() const
    {
        return cart.size();
    }

    Boardgame get_cart_boardgame(int i) const
    {
        return cart[i];
    }

    void clear_cart()
    {
        cart.clear();
    }
};

class User {
    ShoppingCart cart;
    string name;
    string password;
    static int id_count;
    int balance;
    int id;

public:
    User() : name(" "), password(" "), balance(0), id(id_count++) {
        cart = ShoppingCart();
    }

    User(const string& name, const string& password, const int money)
            : name(name), password(password), balance(money), id(id_count++) {
        cart = ShoppingCart();
    }

    void add_money(int money) {
        balance += money;
    }

    int get_money() const {
        return balance;
    }

   string get_name() const {
        return name;
    }
    string get_password() const {
        return password;
    }

    int get_id() const {
        return id;
    }

    ShoppingCart& get_shopping_cart() {
        return cart;
    }

    void set_name(const string& name) {
        this->name = name;
    }

    void set_password(const string& password) {
        this->password = password;
    }

    void set_balance(int balance) {
        this->balance = balance;
    }

    void add_to_shopping_cart(const Boardgame& boardgame) {
        cart.add_to_cart(boardgame);
    }

    void print_shopping_cart() const {
        cart.print_cart();
    }

    void remove_from_shopping_cart(int index) {
        cart.remove_from_cart(index);
    }

    int get_cart_total() const {
        return cart.get_cart_total();
    }

    int get_cart_size() const {
        return cart.get_cart_size();
    }

    Boardgame get_cart_boardgame(int i) const {
        return cart.get_cart_boardgame(i);
    }

    void clear_cart() {
        cart.clear_cart();
    }

    int get_id_count() const {
        return id_count;
    }
};

int User::id_count = 0;

class Boardgame_List {
    vector<Boardgame> list;

public:
    Boardgame_List() {}

    int get_size() const {
        return list.size();
    }

    void add_boardgame(const Boardgame& new_boardgame) {
        list.push_back(new_boardgame);
    }

    void remove_if_no_stock() {
        vector<Boardgame> new_list;

        for (int i = 0; i < list.size(); i++) {
            if (list[i].get_stock() > 0) {
                new_list.push_back(list[i]);
            }
        }

        list = new_list;
    }

    Boardgame get_boardgame(int i) const {
        return list[i];
    }

    void additionalInformation(int i) const {
        cout << "Jocul " << list[i].get_name() << " se joaca intre " << list[i].get_min_players() ;
        cout << " si " << list[i].get_max_players() << " jucatori." << " Si dureaza cam " << list[i].get_duration() << " minute." << endl;
    }

    void pretty_print() const {
        cout << "============================" << endl;
        cout << "     CURRENT BOARDGAMES     " << endl;
        cout << "============================" << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << i << ") " << list[i].get_name() << " || Pret:" << list[i].get_price() << " || Stoc:" << list[i].get_stock() << endl;
            if (i != list.size() - 1)
                cout << "---------------------------" << endl;
        }
        cout << "============================" << endl << endl;
    }

    void decrease_stock(int i) {
        list[i].decrease_stock();
    }
};

class Menu {
    vector<User> users;
    int logged_user;
    Boardgame_List games;

public:
    Menu() {
        logged_user = -1;
        games = Boardgame_List();
        string admin_name = "admin";
        string admin_password = "admin";
        users.emplace_back(User(admin_name, admin_password, 1000000));
    }

    void add_user(const User& user) {
        users.emplace_back(user);
    }

    void login() {
        bool found = false;
        string name, password;
        cout << "Introduceti numele: ";
        cin >> name;
        cout << "Introduceti parola: ";
        cin >> password;

        for (int i = 0; i < users.size(); i++) {
            if (users[i].get_name() == name && users[i].get_password() == password) {
                logged_user = i;
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "===================================" << endl;
            cout << users[logged_user].get_name() << ", bine ai venit la Boardgame Store!(proiectul meu gen)" << endl;
            cout << "===================================" << endl;
        }
        else
            cout << "Numele sau parola incorecta!" << endl;
    }

    void logout() {
        logged_user = -1;
        cout << "Ati fost delogat cu succes!" << endl;
    }

    void add_money() {
        if (logged_user != -1) {
            int money;
            cout << "Introduceti suma de bani pe care doriti sa o adaugati: ";
            cin >> money;
            cout << endl;
            users[logged_user].add_money(money);
            cout << "Suma a fost adaugata cu succes!" << endl;
        }
        else {
            cout << "Trebuie sa fiti logat pentru a adauga bani!" << endl;
        }
    }

    void add_board(const Boardgame& joc) {
        this->games.add_boardgame(joc);
    }

    void add_to_cart() {
        if (logged_user != -1) {
            int index;
            cout << "Introduceti indexul jocului pe care doriti sa il adaugati in cos: ";
            cin >> index;
            if (index >= 0 && index < games.get_size()) {
                users[logged_user].add_to_shopping_cart(games.get_boardgame(index));
                cout << "Jocul a fost adaugat cu succes in cos!" << endl;
            }
            else {
                cout << "Index invalid!" << endl;
            }
        }
        else {
            cout << "Trebuie sa fiti logat pentru a adauga jocuri in cos!" << endl;
        }
    }

    void print_additional_info() {
        if (logged_user != -1) {
            int index;
            cout << "Introduceti indexul jocului pentru care doriti sa vedeti informatii suplimentare: ";
            cin >> index;
            if (index >= 0 && index < games.get_size()) {
                games.additionalInformation(index);
            }
            else {
                cout << "Index invalid!" << endl;
            }
        }
        else {
            cout << "Trebuie sa fiti logat pentru a vedea informatii suplimentare!" << endl;
        }
    }

    void calculate_balance(int money) {
        users[logged_user].set_balance(users[logged_user].get_money() - money);
    }

    void buy_cart() {
        if (logged_user != -1) {
            if (users[logged_user].get_cart_size() > 0) {
                int money = users[logged_user].get_cart_total();
                if (money <= users[logged_user].get_money())
                {
                    calculate_balance(money);
                    for (int i = 0; i < games.get_size(); i++) {
                        for (int j = 0; j < users[logged_user].get_cart_size(); j++) {
                            if (games.get_boardgame(i).get_name() == users[logged_user].get_cart_boardgame(j).get_name()) {
                                games.decrease_stock(i);
                            }
                        }
                    }
                    users[logged_user].clear_cart();
                    cout << "Jocurile au fost achizitionate cu succes!" << endl;
                }
                else {
                    cout << "Nu aveti suficienti bani pentru a cumpara jocurile!" << endl;
                }
            }
            else {
                cout << "Cosul este gol, nu ai cum sa cumperi daca cosul este gol" << endl;
            }
        }
        else {
            cout << "Trebuie sa fiti logat pentru a cumpara jocuri!" << endl;
        }
    }

    void print_menu1() {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }

    void print_menu2() {
        cout << "----------------------------------" << endl;
        cout << "Momentan ai " << users[logged_user].get_money() << " lei in cont." << endl;
        cout << "Ce doriti sa faceti?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Adauga bani" << endl;
        cout << "2. Vizualizeaza selectia de jocuri" << endl;
        cout << "3. Vizualizare cos" << endl;
        cout << "4. Logout" << endl;
    }

    void print_menu2_admin() {
        cout << "----------------------------------" << endl;
        cout << "Momentan ai " << users[logged_user].get_money() << " lei in cont." << endl;
        cout << "Ce doriti sa faceti?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Adauga bani" << endl;
        cout << "2. Vizualizeaza selectia de jocuri" << endl;
        cout << "3. Vizualizare cos" << endl;
        cout << "4. Adauga jocuri in magazin" << endl;
        cout << "5. Logout" << endl;
    }

    void print_menu_vizualizare_jocuri() {
        cout << "----------------------------------" << endl;
        cout << "Momentan ai " << users[logged_user].get_money() << " lei in cont." << endl;
        cout << "Ce doriti sa faceti?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Adauga in cos un joc" << endl;
        cout << "2. Afiseaza mai multe informatii despre un joc" << endl;
        cout << "3. Inapoi" << endl;
    }

    void print_menu_vizualizare_cart() {
        cout << "----------------------------------" << endl;
        cout << "Momentan aveti " << users[logged_user].get_money() << " lei in cont." << endl;
        cout << "Ce doriti sa faceti?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Cumpara" << endl;
        cout << "2. Sterge un joc" << endl;
        cout << "3. Inapoi" << endl;
    }

    void register_user() {
        string name, password;
        cout << "Introduceti numele: ";
        cin >> name;
        cout << "Introduceti parola: ";
        cin >> password;
        add_user(User(name, password, 0));
        cout << " ---------------------------------- " << endl;
        cout << "Contul dumneavoastra a fost creat cu succes!" << endl;
        cout << " ---------------------------------- " << endl;
    }

    Boardgame_List& get_boardgames() {
        return games;
    }

    User& get_user(int index) {
        return users[index];
    }

    int get_users_size() {
        return users.size();
    }

    bool is_admin() {
        if (logged_user == 0) {
            return true;
        }
        return false;
    }

    int get_logged_user() {
        return logged_user;
    }

};



int main() {

    // ----------------- TESTE STRING SI BOARDGAME -----------------

    string s1("Hello");
    string s2("World");
    string s3(s1);
    string s4("World");
    Boardgame b1(s1, 2, 4, 60, 100, 10);
    Boardgame b2(s2, 2, 4, 60, 100, 10);
    Boardgame b3(s3, 2, 4, 60, 100, 10);
    Boardgame b4(b1);
    //cout << b4.get_name().get_sir() << endl;
    Boardgame b5;
    b5 = b4;
    //cout << b5.get_name().get_sir() << endl;

    //cin >> b4;

    // ----------------- TESTE BOARDGAME_LIST -----------------

    //Boardgame_list bl;
    //bl.add_boardgame(b1);
    //bl.add_boardgame(b2);
    //bl.add_boardgame(b3);
    //bl.pretty_print();
    for (int i = 0; i < 10; i++)
    {
        //bl.scade_stoc(0);
    }
    //bl.additionalInformation(0);
    //bl.remove_if_no_stock();
    // bl.pretty_print();

    // ----------------- TESTE SHOPPING CART -----------------

    ShoppingCart sc;
    //sc.print_cart();
    sc.add_to_cart(b1);
    sc.add_to_cart(b2);
    sc.add_to_cart(b3);
    //sc.print_cart();
    sc.remove_from_cart(1);
    //sc.print_cart();
    sc.clear_cart();
    //sc.print_cart();

    // ----------------- TESTE USER -----------------

    /*  User u1(s1, s2, 100);
      User u2(s2, s3, 200);
      User u3(s3, s4, 300);
      u1.add_to_shopping_cart(b1);
      u1.add_to_shopping_cart(b2);
      u1.add_to_shopping_cart(b3);
      //u1.print_shopping_cart();
      u1.remove_from_shopping_cart(1);
      //u1.print_shopping_cart();
      u1.clear_cart();
      //u1.print_shopping_cart();
      */

    // ----------------- TESTE MENU -----------------

    Menu menu;
    Boardgame a1(string("Dune: Imperium"), 2, 5, 180, 300, 5);
    Boardgame a2(string("Calico"), 2, 4, 120, 150, 10);
    Boardgame a3(string ("Turncoats"), 2, 5, 60, 999, 1);
    Boardgame a6(string("Modern Art"), 3, 5, 120, 270, 1);
    Boardgame a7(string("Kakerlaken"), 2, 6, 60, 100, 3);
    Boardgame a4(a3);
    Boardgame a5;
    a5 = a4;
    menu.add_board(a1);
    menu.add_board(a2);
    menu.add_board(a3);
    menu.add_board(a6);
    menu.add_board(a7);
    menu.add_board(a4);
    menu.add_board(a5);
    // menu.get_boardgames().pretty_print();

    // ----------------- MAIN PROPRIU-ZIS -----------------
    string s("Jocul cu care index ai dori sa il scoti din cos? ");
    int choice1;
    while (true) {

        if (menu.get_logged_user() == -1) {
            menu.print_menu1();
            cin >> choice1;
            switch (choice1) {
                case 1:
                    menu.login();
                    break;
                case 2:
                    menu.register_user();
                    break;
                case 3:
                    cout << "Arrivederci !" << endl;
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        } else
        if (menu.is_admin())
        {
            cout << "Momentan sunteti logat ca administrator." << endl;
            cout << "Numarul de obiecte create de tip User este: " << menu.get_user(menu.get_logged_user()).get_id_count() << endl;
            cout << "Numarul de useri inregistrati este: " << menu.get_users_size() << endl;
            cout << "Din moment ce sunteti administrator, nu uitati ca puteti adauga jocuri la catalog" << endl;
            menu.print_menu2_admin();
            cin >> choice1;
            switch (choice1) {
                case 1:
                    menu.add_money();
                    break;
                case 2:
                    while (true) {
                        menu.get_boardgames().pretty_print();
                        menu.print_menu_vizualizare_jocuri();
                        // cout << menu.get_boardgames().get_size() << endl;
                        int choice2;
                        cin >> choice2;
                        switch (choice2) {
                            case 1:
                                menu.add_to_cart();
                                break;
                            case 2:
                                menu.print_additional_info();
                                break;
                            case 3:
                                goto end;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                case 3:
                    while (true) {
                        menu.get_user(menu.get_logged_user()).get_shopping_cart().print_cart();
                        menu.print_menu_vizualizare_cart();
                        int choice2;
                        cin >> choice2;
                        switch (choice2) {
                            case 1:
                                menu.buy_cart();
                                menu.get_boardgames().remove_if_no_stock();
                                break;
                            case 2:
                                cout << s << endl;
                                int nr;
                                cin >> nr;
                                menu.get_user(menu.get_logged_user()).get_shopping_cart().remove_from_cart(nr);
                                break;
                            case 3:
                                goto end;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                    break;
                case 4:
                {
                    cout << "Introduceti datele jocului pe care doriti sa il adaugati: " << endl;
                    Boardgame b;
                    cin >> b;
                    //cout << menu.get_boardgames().get_size() << endl;
                    menu.add_board(b);
                    //cout << menu.get_boardgames().get_size() << endl;
                    break;
                } end: break;
                case 5:
                    menu.logout();
                    break;
                default:
                {
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }

        } else
        {
            menu.print_menu2();
            cin >> choice1;
            switch (choice1) {
                case 1:
                    menu.add_money();
                    break;
                case 2:
                    while (true) {
                        menu.get_boardgames().pretty_print();
                        menu.print_menu_vizualizare_jocuri();
                        int choice2;
                        cin >> choice2;
                        switch (choice2) {
                            case 1:
                                menu.add_to_cart();
                                break;
                            case 2:
                                menu.print_additional_info();
                                break;
                            case 3:
                                goto end2;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                case 3:
                    while (true) {
                        menu.get_user(menu.get_logged_user()).get_shopping_cart().print_cart();
                        menu.print_menu_vizualizare_cart();
                        int choice2;
                        cin >> choice2;
                        switch (choice2) {
                            case 1:
                                menu.buy_cart();
                                menu.get_boardgames().remove_if_no_stock();
                                break;
                            case 2:
                                cout << s << endl;
                                int nr;
                                cin >> nr;
                                menu.get_user(menu.get_logged_user()).get_shopping_cart().remove_from_cart(nr);
                                break;
                            case 3:
                                goto end;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                end2:
                    break;
                case 4:
                    menu.logout();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
    }
    return 0;
}





