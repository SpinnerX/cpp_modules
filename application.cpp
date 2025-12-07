// #include <print>
import test;

class box {
public:
    box() {
        atlas::register_start(this, &box::test);
    }

    void test() {}
};

int main(){
    print_hello();

    return 0;
}
