#ifndef PAIR_H
#define PAIR_H


class pair
{
public:
    pair(int f,int t);
    ~pair();
    int getFloor(){return floor;}
    int getTime(){return time;}
    bool operator ==(pair &pair);

private:
    int floor;
    int time;
};

#endif // PAIR_H
