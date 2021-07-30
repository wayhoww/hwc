#include <iostream>
#include <optional>

int main(){
    using namespace std;
    optional<int> a;
    a.emplace(1);

    auto c = make_optional(2);
    cout << a.value() << " " << c.value() << endl;
}