#ifndef HUFFMANTREE_CPP
#define HUFFMANTREE_CPP
#include "HuffmanTree.hpp"

//Returns the serialized tree
string HuffmanTree::serializeTree() const{
    return serialize;
}

//Function is used to compress the string
string HuffmanTree::compress(const string inputStr){
    map<char, int> frequency;
    map<char, string> charMap;
    string output = "";
    int count = 0;
    
   
   // Review this for loop to ensure its properly getting the characters
    for(int i = 0; i < inputStr.length(); i ++){
        frequency[inputStr[i]]++;
    }

    //at might need to be tempNode
    // inserts frequencies
    for(auto at : frequency){
        heap.insert(new HuffmanNode(at.first, at.second));
    }

    while(heap.size() > 1){
        HuffmanNode* left = heap.min();
        heap.removeMin();

        HuffmanNode* right = heap.min();
        heap.removeMin();

        count = left -> getFrequency() + right -> getFrequency();
        heap.insert(new HuffmanNode('\0', count, tempNode, left, right));

    }

        HuffmanNode* root = heap.min();
        postOrder(root);
        compute(root, "", charMap);

        for(int i = 0; i < inputStr.length(); i++){
            output += charMap[inputStr[i]];

        }

        return output;
}


//function is responsible checking if it is a leaf or branch and adding L+char or B 
void HuffmanTree::compute(HuffmanNode* root, string inputStr, map<char, string> &strMap){
    if(root == NULL) return;

    if(root -> isLeaf())
        strMap[root -> getCharacter()] = inputStr;
    

    compute(root -> left, inputStr + "0", strMap);
    compute(root -> right, inputStr + "1", strMap);

    if(root -> isLeaf()){
        serialize.push_back('L');
        serialize.push_back(root -> getCharacter());
    }

    else
    {
        serialize.push_back('B');
    }
}


string HuffmanTree::decompress (const string inputCode, const string serializedTree){

    bool test = false;
    HuffmanNode* position;
    stack<HuffmanNode*> buffer;
    string solved = "";
    char temp;
    auto i = 0;

    for(auto i = 0; i < serializedTree.length(); i++){

        if(serializedTree[i] == 'L'){
            i++;
            temp = serializedTree[i];
            HuffmanNode* newN = new HuffmanNode(temp, 0, NULL, NULL, NULL);
            buffer.push(newN);
        }

        else{
            HuffmanNode *r = buffer.top();
            buffer.pop();
            HuffmanNode *l = buffer.top();
            buffer.pop();

            HuffmanNode* newNode = new HuffmanNode(0,0,NULL,l,r);

            buffer.push(newNode);
        }
    }

    HuffmanNode* root = buffer.top();
    
    while(i < inputCode.length()){
        if(!test){
            position = root;
            test = true;
        }

        else{
            if(position -> isLeaf()){
                solved.push_back(position -> getCharacter());
                test = false;
            }

            else{
                if(inputCode[i]=='1'){
                    position = position -> right;
                }

                else{
                    position = position -> left;
                }

                i++;
            }
        }
    }

    solved.push_back(position -> getCharacter());
    return solved;

}

//Recursive function to traverse through the binary trea
void HuffmanTree::postOrder(HuffmanNode* root){

    if(root == NULL){
        postOrder(root -> left);
        postOrder(root -> right);
    

        if(root -> isLeaf()){
            serialize.push_back('L');
            serialize.push_back(root -> getCharacter());
        }

        else{
            serialize.push_back('B');
        }
    }
}


#endif

