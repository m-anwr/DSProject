#ifndef REQUEST_H
#define REQUEST_H

#include <QHash>

class Request
{
public:
    Request(int time, int from, int to);

    int time() const;
    int from() const;
    int to() const;
    int getDirection();
    bool getState();
    void setState(bool s);
    Request &operator=(const Request &other);

private:
    int m_time;
    int m_from;
    int m_to;
    bool state;
};

inline bool operator==(const Request &lhs, const Request &rhs)
{
    return ((lhs.time() == rhs.time()) && (lhs.from() == rhs.from()) && (lhs.to() == rhs.to()));
}

inline uint qHash(const Request &r) { return (r.from() + r.to()) ^ (r.time() * r.time()); }

#endif // REQUEST_H
