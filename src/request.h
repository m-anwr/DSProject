#ifndef REQUEST_H
#define REQUEST_H
#include <QHash>

class Request
{
public:
    Request(int time_, int from_, int to_);

    int getTime();
    int getFrom();
    int getTo();

    bool operator ==(Request &req);
    //Operator== should be overloaded to check for equal requests and remove duplicates
     Request &operator=(const Request &other);
private:
    int time;
    int from;
    int to;
};
int qHash(const Request &r);
bool operator ==(const Request,const Request &req);
#endif // REQUEST_H
