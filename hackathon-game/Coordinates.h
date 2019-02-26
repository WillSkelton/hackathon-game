
class Coordinates
{
public:

//constructor
Coordinates();
Coordinates(int x, int y);

//destructor
~Coordinates();

//getters
int getx(void);
int gety(void);

//setters
void setx(int newdata);
void sety(int newdata);

private:
    int x;
    int y;
};