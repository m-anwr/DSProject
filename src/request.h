#ifndef REQUEST_H
#define REQUEST_H


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

#endif // REQUEST_H
