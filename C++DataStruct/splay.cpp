#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib> // exit()
#include "genSplay.h"
#include <vector>
#include <algorithm>

class Word {
public:
    Word() {
        freq = 1;
    }
    int operator== (const Word& ir) const {
        return strcmp(word,ir.word) == 0;
    }
    int operator< (const Word& ir) const {
        return strcmp(word,ir.word) < 0;
    }
private:
    char *word;
    int freq;
    friend class WordSplay;
};

class WordSplay : public SplayTree<Word> {
public:
    WordSplay() {
        differentWords = wordCnt = 0;
    }
    void run(std::ifstream&,char*);
private:
    int differentWords, // counter of different words in a text file;
        wordCnt;        // counter of all words in the same file;
    void visit(SplayingNode<Word>*);
};

void WordSplay::visit(SplayingNode<Word> *p) {
    differentWords++;
    wordCnt += p->info.freq;
}

void WordSplay::run(std::ifstream& fIn, char *fileName) {
    char ch = ' ', i;
    char s[100];
    Word rec;
    while (!fIn.eof())
    {
        while (1)
        {
            if (!fIn.eof() && !isalpha(ch)) // skip nonletters
                fIn.get(ch);
            else break;
        }
        if (fIn.eof())       // spaces at the end of fIn;
             break;
        for (i = 0; !fIn.eof() && isalpha(ch); i++) {
             s[i] = toupper(ch);
             fIn.get(ch);
        }
        s[i] = '\0';
        if (!(rec.word = new char[strlen(s)+1])) {
             std::cerr << "No room for new words.\n";
             exit(1);
        }
        strcpy(rec.word,s);
        Word *p = search(rec);
        if (p == 0)
             insert(rec);
        else p->freq++;
    }
    inorder();
    std::cout << "\n\nFile " << fileName
         << " contains " << wordCnt << " words among which "
         << differentWords << " are different\n";
}

int main(int argc, char* argv[]) {
    char fileName[80];
    WordSplay *splayTree = new WordSplay();
    if (argc != 2) {
         std::cout << "Enter a file name: ";
         std::cin  >> fileName;
    }
    else strcpy(fileName,argv[1]);
    std::ifstream fIn(fileName);
    if (fIn.fail()) {
        std::cerr << "Cannot open " << fileName << std::endl;
        return 1;
    }
    auto time1 = clock();
    splayTree->run(fIn,fileName);
    auto time2 = clock();
    std::cout << "全程耗时：" << (float)(time2-time1)/1000 << "毫秒" << std::endl;
    fIn.close();
    delete splayTree;
    return 0;
}
