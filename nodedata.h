#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class NodeData {
    friend ostream & operator<<(ostream &, const NodeData &);

    private:
        string data;
        int nodeStock;

    public:
        NodeData();
        ~NodeData();
        NodeData(const string &);
        NodeData(const string&, int);
        NodeData(const NodeData &);
        NodeData& operator=(const NodeData &);

        int getStock();
        void setStock(int);

        bool operator==(const NodeData &) const;
        bool operator!=(const NodeData &) const;
        bool operator<(const NodeData &) const;
        bool operator>(const NodeData &) const;
        bool operator<=(const NodeData &) const;
        bool operator>=(const NodeData &) const;
};
#endif
