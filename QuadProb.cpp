#include <iostream>
#include <vector>

using namespace std;

class Color {
    string val;
public:
    Color(string v=""):val{v} {}
    string getColor() { return val; }
};

template<class T1, class T2>
class Hash {
    vector<T2> hm;
    vector<int> loc;
    vector<bool> flag;
public:
    Hash() {
        hm.resize(40);
        loc.resize(40);
        flag.resize(40);
    }

    int put(T1 k, T2 &v) {
        int i=0;
        int fx=k % 40;
        int h1x;
        do {
            int hx = i * i;
            h1x = (fx + hx)%40;
            i++;
        } while(flag[h1x] && loc[h1x]);
        hm[h1x] = v;
        loc[h1x] = k;
        flag[h1x] = true;
        return h1x;
    }

    T2 get(int k) {
        T2 c("KEY_NOT_POPULATED");
        int i=0;
        int fx=k % 40;
        int h1x;
        do {
            int hx = i * i;
            h1x = (fx + hx)%40;
            if(flag[h1x] && loc[h1x] == k) return hm[h1x];
            i++;
        } while(loc[h1x]);
        
        return c;
    }

    T2 Remove(int k) {
        T2 c("KEY_NOT_POPULATED");
        int i=0;
        int fx=k % 40;
        int h1x;
        do {
            int hx = i * i;
            h1x = (fx + hx)%40;
            if(flag[h1x] && loc[h1x] == k) {
                flag[h1x] = false;
                return hm[h1x];
            }
            i++;
        } while(loc[h1x]);

        return c;
    }
};


int main() {
    Hash<int, Color> h;
    Color c1("Red");
    Color c2("Blue");
    Color c3("Pink");
    Color c4("Orange");
    Color c5("Black");
    Color c6("Purple");
    Color c7("Saffron");
    Color c8("Maroon");
    Color c9("Cyan");
    Color c10("Violet");


    cout << "\n c1(Red) is inserted at 1" <<"("<< h.put(1,c1)<<")";
    cout << "\n c2(Blue) is inserted at 22" << "("<<h.put(22,c2)<<")";
    cout << "\n c3(Pink) is inserted at 3" << "("<<h.put(3,c3)<<")";
    cout << "\n c4(Orange) is inserted at 222" << "("<<h.put(222,c4)<<")";
    cout << "\n c5(Black) is inserted at 2222" << "("<<h.put(2222,c5)<<")";
    cout << "\n c6(Purple) is inserted at 22222" << "("<<h.put(22222,c6)<<")";
    cout << "\n c7(Saffron) is inserted at 31" << "("<<h.put(31,c7)<<")";
    cout << "\n c8(Maroon) is inserted at 38" << "("<<h.put(38,c8)<<")";
    cout << "\n c9(Cyan) is inserted at 7" << "("<<h.put(7,c9)<<")";
    cout << "\n c10(Violet) is inserted at 222222" << "("<<h.put(222222,c10)<<")";

    Color d1=h.get(22);
    cout << "\n\nGet Color at " << 22 << ": " << d1.getColor() << endl;

    Color d2=h.get(222);
    cout << "Get Color at " << 222 << ": " << d2.getColor() << endl;

    Color d3=h.get(2222);
    cout << "Get Color at " << 2222 << ": " << d3.getColor() << endl;

    Color d4=h.Remove(222);
    cout << "\nRemoved Color at " << 222 << " : " << d4.getColor() << endl;

    Color d5=h.get(2222);
    cout << "\nGet Color at " << 2222 << ": " << d5.getColor() << endl;

    Color d6=h.get(22222);
    cout << "Get Color at " << 22222 << ": " << d6.getColor() << endl;

    Color d7=h.get(222222);
    cout << "Get Color at " << 222222 << ": " << d7.getColor() << endl;


    return 0;
}
