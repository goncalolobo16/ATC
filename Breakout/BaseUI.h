#include"Base.h"
class BaseUI
{
private:
    int x;
    int y;
    Base base;
    int ch;
    float largura;

public:
    BaseUI();
    void inicializar();  
    void printar();
    void moverBase(int tecla);  
};
