#include <iostream>
#include <cstring>

using namespace std;

class String{
    int size;
    char* sir;

public:

    String ()
    {
        size = 0;
        sir = nullptr;
    }
    String(const char* s)
    {
        size = strlen(s);
        sir = new char[size+1];
        strcpy(sir, s);
        sir[size] = '\0';

    }

    String(const String& s)
    {
        this->size = s.size;
        if (s.sir) {
            this->sir = new char[size + 1];
            strcpy(sir, s.sir);
        } else {
            this->sir = nullptr;
        }
    }

    ~String()
    {
        delete[] sir;
    }

    friend ostream& operator<<(ostream& output, const String& s) {
        output << s.sir;
        return output;
    }

    String& operator=(const String& a)
    {
        if ( this != &a ) {
            delete[] sir;

            size = a.size;
            sir = new char[size+1];
            strcpy(sir, a.sir);
            sir[size] = '\0';
        }

        return *this;
    }
    bool operator==(const String& a)
    {
        if ( this-> size != a.size ) {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (this->sir[i] != a.sir[i])
                return false;
        }
        return true;
    }

    friend istream& operator>>(istream& input, String& s) {

        if (s.size != 0)
            delete[] s.sir;
        char* temp = new char[100];
        input >> temp;
        s.size = strlen(temp);
        s.sir = new char[s.size+1];
        strcpy(s.sir, temp);
        s.sir[s.size] = '\0';
        delete[] temp;
        return input;
    }

    char* get_sir()
    {
        return sir;
    }


};

class Boardgame {
    String name;
    int min_players;
    int max_players;
    int duration;
    int price;
    int stock;
public:

    Boardgame()
    {
        name = " ";
        min_players = 0;
        max_players = 0;
        duration = 0;
        price = 0;
        stock = 0;
    }
    Boardgame(const String &name, int min_players, int max_players, int duration, int price, int stock)
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

    String get_name()
    {
        return this->name;
    }

    int get_price()
    {
        return this->price;
    }
    int get_stock()
    {
        return this->stock;
    }
   int get_duration()
    {
        return this->duration;
    }
   int get_min_players()
    {
        return this->min_players;
    }
    int get_max_players()
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

        String name;
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


class ShoppingCart {
    Boardgame* cart;
    int cart_size;

public:
    ShoppingCart()
    {
        cart_size = 0;
        cart = new Boardgame[cart_size];
    }

    void add_to_cart(const Boardgame & boardgame) {
        Boardgame *old_cart = new Boardgame[cart_size];
        for (int i = 0; i < cart_size; i++)
        {
            old_cart[i] = cart[i];
        }
        cart = new Boardgame[cart_size + 1];
        for (int i = 0; i < cart_size; i++)
        {
            cart[i] = old_cart[i];
        }
        cart[cart_size] = boardgame;
        cart_size++;
        delete[] old_cart;
    }

    void remove_from_cart(int index) {
        if (index >= 0 && index < cart_size)
        {
            Boardgame* old_cart = new Boardgame[cart_size];
            for (int i = 0; i < cart_size; i++)
            {
                old_cart[i] = cart[i];
            }
            cart = new Boardgame[cart_size - 1];
            int j = 0;
            for (int i = 0; i < cart_size ; i++)
            {
                if (i != index) {
                    cart[j] = old_cart[i];
                    j++;
                }
            }
            cart_size--;
            delete[] old_cart;
        }
        else {
            cout << "Index invalid" << endl;
        }
    }

    void print_cart() {
        int total = 0;
        cout << "//////////////////////////" << endl;
        for (int i = 0; i < cart_size; i++)
        {
            cout << i << ". " << cart[i].get_name().get_sir() << " " << cart[i].get_price() << endl;
            total += cart[i].get_price();
        }
        if (cart_size == 0)
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

    int get_cart_total() {
        int total = 0;
        for (int i = 0; i < cart_size; i++)
        {
            total += cart[i].get_price();
        }
        return total;
    }

    int get_cart_size()
    {
        return cart_size;
    }

    Boardgame get_cart_boardgame(int i)
    {
        return cart[i];
    }
    void clear_cart()
    {
        cart_size = 0;
        delete[] cart;
        cart = new Boardgame[cart_size];
    }


};

class User {
    ShoppingCart cart;
    String name;
    String password;
    static int id_count;
    int balance;
    int id;
public:
    User()
    {
        name = String(" ");
        password = String(" ");
        balance = 0;
        id = id_count++;
        cart = ShoppingCart();
    }
    User(const String& name, const String& parola, const int money)
    {
        this->name = name;
        this->password = parola;
        this->balance = money;
        this->id = id_count++;
        cart = ShoppingCart();
    }
    void add_money(int money)
    {
        this->balance = this->balance + money;
    }
    int get_money()
    {
        return this->balance;
    }
    String get_name()
    {
        return this->name;
    }
    String get_password()
    {
        return this->password;
    }
    int get_id_count()
    {
        return this->id_count;
    }
    void set_name(String name)
    {
        this->name = name;
    }
    void set_password(String password)
    {
        this->password = password;
    }
    void set_balance(int balance)
    {
        this->balance = balance;
    }
    void add_to_shopping_cart(const Boardgame& boardgame)
    {
        this->cart.add_to_cart(boardgame);
    }
    void print_shopping_cart()
    {
        this->cart.print_cart();
    }
    void remove_from_shopping_cart(int index)
    {
        this->cart.remove_from_cart(index);
    }

    int get_cart_total()
    {
        return this->cart.get_cart_total();
    }
    int get_cart_size()
    {
        return this->cart.get_cart_size();
    }
    Boardgame get_cart_boardgame(int i)
    {
        return this->cart.get_cart_boardgame(i);
    }
    void clear_cart()
    {
        this->cart.clear_cart();
    }


};

int User::id_count = 0;

class Menu {
    User* users;
    int size;
    int logged_user;
    class Boardgame_list{
        Boardgame* list;
        int size;

    public:

        Boardgame_list()
        {
            size = 0;
            list = new Boardgame[size];
        }

        int get_size(){

            return size;
        }

        void add_boardgame(const class Boardgame& new_boardgame)
        {

            Boardgame* old_list = new Boardgame[this->size];
            for ( int i = 0 ; i < this->size; i++)
                old_list[i] = this->list[i];
            this->size = this->size + 1;
            this->list = new class Boardgame[this->size];
            for ( int i = 0 ; i < this->size - 1 ; i++)
            {
                this->list[i] = old_list[i];
            }
            this->list[this->size - 1] = new_boardgame;
            delete[] old_list;
        }


        void remove_if_no_stock() {
            int newSize = 0;
            for (int i = 0; i < this->size; i++)
            {
                if (this->list[i].get_stock() > 0)
                {
                    newSize++;
                }
            }

            if (newSize != this->size) {
                Boardgame* newList = new Boardgame[newSize];
                int newIndex = 0;

                for (int i = 0; i < this->size; i++)
                {
                    if (this->list[i].get_stock() > 0)
                    {
                        newList[newIndex++] = this->list[i];
                    }
                }

                delete[] this->list;
                this->list = newList;
                this->size = newSize;
            }
        }

        Boardgame get_boardgame(int i)
        {
            return this->list[i];
        }

        void additionalInformation (int i)
        {
            cout << "Jocul " << this->list[i].get_name().get_sir() << " se joaca intre " << this->list[i].get_min_players() ;
            cout << " si " << this->list[i].get_max_players() << " jucatori." << " Si dureaza cam " << this->list[i].get_duration() << " minute." << endl;
        }

        void pretty_print() const {
            cout << "============================" << endl;
            cout << "     CURRENT BOARDGAMES     " << endl;
            cout << "============================" << endl;
            for (int i = 0; i < this->size; i++)
            {
                cout << i << ") " << this->list[i].get_name().get_sir() << " || Pret:" << this->list[i].get_price() << " || Stoc:" << this->list[i].get_stock() << endl;
                if (i != this->size - 1)
                    cout << "---------------------------" << endl;

            }
            cout << "============================" << endl << endl;
        }

        void scade_stoc(int i)
        {
            this->list[i].decrease_stock();
        }


    }games;

public:
    Menu() {
        size = 1;
        users = new User[size];
        logged_user = -1;
        games = Boardgame_list();
        String admin_name("admin");
        String admin_password("admin");
        users[0].set_name(admin_name);
        users[0].set_password(admin_password);
        users[0].set_balance(1000000);
    }


    void add_user(const User& user) {
        User* new_users = new User[size + 1];
        for (int i = 0; i < size; i++) {
            new_users[i] = users[i];
        }
        new_users[size] = user;
        size++;
        delete[] users;
        users = new_users;
    }


    void login() {
        bool found = false;
        char* string1 = new char[100];
        String name, password;
        cout << "Introduceti numele: ";
        cin >> string1;
        name = string1;
        cout << "Introduceti parola: ";
        cin >> string1;
        password = string1;
        delete[] string1;
        for (int i = 0; i < this->size; i++) {
            if (users[i].get_name() == name && users[i].get_password() == password) {
                logged_user = i;
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "===================================" << endl;
            cout << users[logged_user].get_name().get_sir() << ", bine ai venit la Boardgame Store!(proiectul meu gen)" << endl;
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

    void add_board( const Boardgame &joc)
    {
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
                                games.scade_stoc(i);
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

    void print_menu1(){
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

    void print_menu_vizualizare_cart(){
        cout << "----------------------------------" << endl;
        cout << "Momentan aveti " << users[logged_user].get_money() << " lei in cont." << endl;
        cout << "Ce doriti sa faceti?" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Cumpara" << endl;
        cout << "2. Sterge un joc" << endl;
        cout << "3. Inapoi" << endl;
    }


    void register_user() {

        char temp[100];
        String name, password;
        cout << "Introduceti numele: ";
        cin >> temp;
        name = temp;
        cout << "Introduceti parola: ";
        cin >> temp;
        password = temp;
        add_user(User(name, password, 0));
        cout << " ---------------------------------- " << endl;
        cout << "Contul dumneavoastra a fost creat cu succes!" << endl;
        cout << " ---------------------------------- " << endl;
    }

    Boardgame_list get_boardgames() {
        return games;
    }

    User get_user(int index) {
        return users[index];
    }

    int get_users_size() {
        return size;
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

    String s1("Hello");
    String s2("World");
    String s3(s1);
    String s4("World");
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
    Boardgame a1(String("Dune: Imperium"), 2, 5, 180, 300, 5);
    Boardgame a2(String("Calico"), 2, 4, 120, 150, 10);
    Boardgame a3(String ("Turncoats"), 2, 5, 60, 999, 1);
    Boardgame a6(String("Modern Art"), 3, 5, 120, 270, 1);
    Boardgame a7(String("Kakerlaken"), 2, 6, 60, 100, 3);
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
    String s("Jocul cu care index ai dori sa il scoti din cos? ");
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
                        menu.get_user(menu.get_logged_user()).print_shopping_cart();
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
                                menu.get_user(menu.get_logged_user()).remove_from_shopping_cart(nr);
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
                        menu.get_user(menu.get_logged_user()).print_shopping_cart();
                        menu.print_menu_vizualizare_cart();
                        int choice2;
                        cin >> choice2;
                        switch (choice2) {
                            case 1:
                                menu.buy_cart();
                                menu.get_boardgames().remove_if_no_stock();
                                break;
                            case 2:
                                cout << "Jocul cu care index ai dori sa il scoti din cos? " << endl;
                                int nr;
                                cin >> nr;
                                menu.get_user(menu.get_logged_user()).remove_from_shopping_cart(nr);
                                break;
                            case 3:
                                goto end2;
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





