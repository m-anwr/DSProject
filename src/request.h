#ifndef REQUEST_H
#define REQUEST_H

#include <QHash>

class Request
{
public:
    Request(int time, int from, int to);
    Request &operator=(const Request &other);

    int time() const;
    int from() const;
    int to() const;

private:
    int m_time;
    int m_from;
    int m_to;
};

inline bool operator==(const Request &lhs, const Request &rhs)
{
    return ((lhs.time() == rhs.time()) && (lhs.from() == rhs.from()) && (lhs.to() == rhs.to()));
}

inline uint qHash(const Request &r) { return (r.from() + r.to()) ^ (r.time() * r.time()); }

#endif // REQUEST_H
