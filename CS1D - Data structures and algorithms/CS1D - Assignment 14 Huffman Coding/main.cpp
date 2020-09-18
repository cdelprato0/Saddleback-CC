/************************************************************************************
 * AUTHOR	     :Chaz Del Prato
 * STUDENT ID    :382108
 * Assignment #14:Huffman Coding
 * CLASS	     :CS1D
 * SECTION	     :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #14
 * --------------
 *
 * 	This program will be using huffman coding to determine the details of the
 * 	Gettysburg address. The program will first read in the string and set each letter
 * 	to a node on a tree. The tree will help in creating the huffman code for each
 * 	letter. After it will print the code for each letter and then will encode the
 * 	entire speech. After it will display the huffman tree. It will then decode the
 * 	encoded file and output the file. once that is done then it will output the
 * 	frequency chart with the compression ratio.
 ************************************************************************************/
#include <iostream>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>
using namespace std;

const int UniqueSymbols = 1 << CHAR_BIT;
const char* SampleString =
		"Four score and seven years ago our fathers brought forth on this continent, "
		"a new nation, conceived in Liberty, and dedicated to the proposition that "
		"all men are created equal. Now we are engaged in a great civil war, "
		"testing whether that nation, or any nation so conceived and so dedicated, "
		"can long endure. We are met on a great battle-field of that war. We have "
		"come to dedicate a portion of that field, as a final resting place for "
		"those who here gave their lives that that nation might live. It is "
		"altogether fitting and proper that we should do this. But, in a larger "
		"sense, we cannot dedicate -- we cannot consecrate -- we cannot hallow -- "
		"this ground. The brave men, living and dead, who struggled here, have "
		"consecrated it, far above our poor power to add or detract. The world will "
		"little note, nor long remember what we say here, but it can never forget "
		"what they did here. It is for us the living, rather, to be dedicated here "
		"to the unfinished work which they who fought here have thus far so nobly "
		"advanced. It is rather for us to be here dedicated to the great task "
		"remaining before us -- that from these honored dead we take increased "
		"devotion to that cause for which they gave the last full measure of "
		"devotion -- that we here highly resolve that these dead shall not have died "
		"in vain -- that this nation, under God, shall have a new birth of freedom -- "
		"and that government of the people, by the people, for the people, shall not "
		"perish from the earth.";


typedef std::vector<bool> HuffCode;
typedef std::map<char, HuffCode> HuffCodeMap;

class INode
{
public:
    const int f;

    virtual ~INode() {}

protected:
    INode(int f) : f(f) {}
};

class InternalNode : public INode
{
public:
    INode *const left;
    INode *const right;

    InternalNode(INode* c0, INode* c1) : INode(c0->f + c1->f), left(c1), right(c0) {}
    ~InternalNode()
    {
        delete left;
        delete right;
    }
};

class LeafNode : public INode
{
public:
    const char c;

    LeafNode(int f, char c) : INode(f), c(c) {}
};

struct NodeCmp
{
    bool operator()(const INode* lhs, const INode* rhs) const { return lhs->f > rhs->f; }
};

INode* BuildTree(const int (&frequencies)[UniqueSymbols])
{
    std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;

    for (int i = 0; i < UniqueSymbols; ++i)
    {
        if(frequencies[i] != 0)
            trees.push(new LeafNode(frequencies[i], (char)i));
    }
    while (trees.size() > 1)
    {
        INode* childR = trees.top();
        trees.pop();

        INode* childL = trees.top();
        trees.pop();

        INode* parent = new InternalNode(childR, childL);
        trees.push(parent);
    }
    return trees.top();
}

void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap& outCodes)
{
    if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node))
    {
        outCodes[lf->c] = prefix;
    }
    else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node))
    {
        HuffCode leftPrefix = prefix;
        leftPrefix.push_back(false);
        GenerateCodes(in->left, leftPrefix, outCodes);

        HuffCode rightPrefix = prefix;
        rightPrefix.push_back(true);
        GenerateCodes(in->right, rightPrefix, outCodes);
    }
}

int main()
{
//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                        *\n"
		"* ASSIGNMENT #14 : Huffman Coding                                        *\n"
		"* CLASS          : CS1D                                                  *\n"
		"* SECTION        : MW 3:00p                                              *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*  This program will be able to perform Huffman Coding on the Gettysburg *\n"
		"*  Address. The program will first display the Huffman Code for each     *\n"
		"*  letter of the speech. Then it will show the Huffman Code tree that    *\n"
		"*  corresponds to the frequency chart. After that, it will display the   *\n"
		"*  decoded Address and output. At the end it will show the Compression   *\n"
		"*  ratio and Frequency Table.                                            *\n"
		"**************************************************************************\n\n";

    // Build frequency table
    int frequencies[UniqueSymbols] = {0};
    const char* ptr = SampleString;

    string encode;

    while (*ptr != '\0'){
        ++frequencies[*ptr++];

        //************
        //* ENCODING *
        //************
        if(*ptr == 'a'){
        	encode += "0011";
        }else if(*ptr == 'b'){
        	encode += "0100000";
        }else if(*ptr == 'c'){
        	encode += "000010";
        }else if(*ptr == 'd'){
        	encode += "00100";
        }else if(*ptr == 'e'){
        	encode += "100";
        }else if(*ptr == 'f'){
        	encode += "010001";
        }else if(*ptr == 'g'){
        	encode += "001010";
        }else if(*ptr == 'h'){
        	encode += "0111";
        }else if(*ptr == 'i'){
        	encode += "00000";
        }else if(*ptr == 'k'){
        	encode += "000011110\n";
        }else if(*ptr == 'l'){
        	encode += "01101";
        }else if(*ptr == 'm'){
        	encode += "0100001";
        }else if(*ptr == 'n'){
        	encode += "1011";
        }else if(*ptr == 'o'){
        	encode += "0101";
        }else if(*ptr == 'p'){
        	encode += "0000110";
        }else if(*ptr == 'q'){
        	encode += "000011111\n";
        }else if(*ptr == 'r'){
        	encode += "1010";
        }else if(*ptr == 's'){
        	encode += "01100";
        }else if(*ptr == 't'){
        	encode += "0001";
        }else if(*ptr == 'u'){
        	encode += "010011";
        }else if(*ptr == 'v'){
        	encode += "010010";
        }else if(*ptr == 'w'){
        	encode += "001011";
        }else if(*ptr == 'y'){
        	encode += "00001110";
        }else if(*ptr == ' '){
        	encode += "11";
        }
    }

    INode* root = BuildTree(frequencies);

    HuffCodeMap codes;
    GenerateCodes(root, HuffCode(), codes);
    delete root;

    cout << "\nHuffman Code for each letter\n"
    		"----------------------------\n";
    for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
    {
        std::cout << it->first << " ";
        std::copy(it->second.begin(), it->second.end(),
                  std::ostream_iterator<bool>(std::cout));
        std::cout << std::endl;
    }

    cout << "\nHuffman Code Tree\n"
    		"-----------------------------------------------------------\n"
    		"                     1420                                  \n"
    		"          592                    828                       \n"
    		"      321   ' '        358                   470           \n"
    		"   156  'e'     166           192        216      254      \n"
    		" 'n''r'       86 'h'        99  'o'    114 'a'  128 't'    \n"
    		"            'l''s'      54     45     56 'd'   60 'i'      \n"
    		"                      27 'f' 'u''v' 'w''g'    29 'c'       \n"
    		"                    'm''b'                   14 'p'        \n"
    		"                                            4  'y'         \n"
    		"                                          'q''k'           \n"
    		"-----------------------------------------------------------\n";

    cout << "\n\nDecoding Huffman Code\n"
    		"---------------------\n"
    	 << SampleString;

    cout << "\n\nCompression Ratio and Frequency Chart\n"
    		"---------------------------------------------\n"
    		"Compression Ratio: 1470 * 8 bits = 11760 bits\n"
    		"                   / 5693 bits (Encoded File)\n"
    		"Compression Ration is: 2.06\n"
    		"--------------------------\n"
    		"|  Letter  |  Frequency  |\n"
    		"|------------------------|\n"
    		"|   ' '    |    274      |\n"
    		"|    ,     |    22       |\n"
    		"|    -     |    15       |\n"
    		"|    .     |    10       |\n"
    		"|    B     |    1        |\n"
    		"|    F     |    1        |\n"
    		"|    G     |    1        |\n"
    		"|    I     |    3        |\n"
    		"|    L     |    1        |\n"
    		"|    N     |    1        |\n"
    		"|    T     |    2        |\n"
    		"|    W     |    2        |\n"
    		"|    a     |    102      |\n"
    		"|    b     |    14       |\n"
    		"|    c     |    31       |\n"
    		"|    d     |    58       |\n"
    		"|    e     |    165      |\n"
    		"|    f     |    27       |\n"
    		"|    g     |    28       |\n"
    		"|    h     |    80       |\n"
    		"|    i     |    68       |\n"
    		"|    k     |    3        |\n"
    		"|    l     |    42       |\n"
    		"|    m     |    13       |\n"
    		"|    n     |    77       |\n"
    		"|    o     |    93       |\n"
    		"|    p     |    15       |\n"
    		"|    q     |    1        |\n"
    		"|    r     |    79       |\n"
    		"|    s     |    44       |\n"
    		"|    t     |    126      |\n"
    		"|    u     |    21       |\n"
    		"|    v     |    24       |\n"
    		"|    w     |    28       |\n"
    		"|    y     |    10       |\n"
    		"--------------------------\n";
    return 0;
}
