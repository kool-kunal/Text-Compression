#include <bits/stdc++.h>
using namespace std;
#include "encoding.h"
#include "decoding.h"
#include "jsonify.h"

int main(){
    Map<int>* m1 = new Map<int>;
    m1 = create_map("text.txt", m1);
    Node *root = build_Huffman_Tree(*m1);
    Map<string> codes = getHuffmanCodes(root, "");
    printHuffmanCodes(codes);
    string ans = encoded(codes, "text.txt");
    int flush_bits = getfile(ans);
    createJson(codes, flush_bits);
    remove("text.txt");
    return 0;
}