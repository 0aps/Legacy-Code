#include <iostream>

class cliente
{
    private:
    typedef void (*fun)();
    fun own_fun;

    public:
    cliente( fun my_fun): own_fun(my_fun) {};
    void call() { own_fun(); };


    private:
        int x;
};


void print (  ) {
  std::cout << "ho" << std::endl;
}


int main()
{
    cliente meh(&print);
    meh.call();

   return 0;
}
