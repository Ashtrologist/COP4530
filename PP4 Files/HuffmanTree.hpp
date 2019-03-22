
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <map>

#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"

using namespace std;

class HuffmanTree : public HuffmanTreeBase {
    public:
         string compress(const string inputStr);
         string serializeTree() const;
         string decompress(const string inputCode, const std::string serializedTree);
         void postOrder (HuffmanNode* root);
         void compute(HuffmanNode* root, string inputStr, map<char, string> &strMap);

    private:
        HuffmanNode *node;
        HuffmanNode *temp;

        string serialize = "";
        HeapQueue<HuffmanNode*, HuffmanNode::Compare> heap;

};

#endif 

