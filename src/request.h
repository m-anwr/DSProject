#ifndef REQUEST_H
#define REQUEST_H


class Request
{
public:
    Request(int time_, int from_, int to_);

    int getTime();
    int getFrom();
    int getTo();
    int getDirection();
    bool getState();
    void setState(bool s);
    bool operator ==(Request &req);

private:
    int time;
    int from;
    int to;
    bool state;
};

#endif // REQUEST_H
