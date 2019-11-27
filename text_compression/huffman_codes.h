#include <string.h>
using namespace std;
#include "map.h"
#include "priority_queue.h"
Map<string> m;
Map<string> getHuffmanCodes(Node *root, string c)
{
    if (root == NULL)
        return m;
    root->setCode(root->getCode() + c);
    if (root->getIsTerminal())
    {
        m.insert(root->getKey(), root->getCode());
    }
    if (root->left != NULL)
        getHuffmanCodes(root->left, c + "0");
    if (root->right != NULL)
        getHuffmanCodes(root->right, c + "1");
    return m;
}
void printHuffmanCodes(Map<string> codes)
{
    string keys = codes.keys();
    for (int i = 0; i < codes.size(); i++)
    {
        string key = "";
        key += keys[i];
        cout << key << ":" << codes[key] << endl;
    }
}